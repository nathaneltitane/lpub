/****************************************************************************
**
** Copyright (C) 2007-2008 Kevin Clague. All rights reserved.
**
** This file may be used under the terms of the GNU General Public
** License version 2.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of
** this file.  Please review the following information to ensure GNU
** General Public Licensing requirements will be met:
** http://www.trolltech.com/products/qt/opensource.html
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

/***************************************************************************
 *
 * This file invokes the traverse function to count pages, and to gather
 * the contents of a given page of your building instructions.  Once 
 * gathered, the contents of the page are translated to graphical representation
 * and presented to the user for editing.
 *
 **************************************************************************/
 
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QScrollBar>
#include <QPixmap>
#include <QColor>
#include "callout.h"
#include "lpub.h"
#include "ranges.h"
#include "range.h"
#include "step.h"
#include "meta.h"
#include "color.h"
#include "pagebackgrounditem.h"
#include "numberitem.h"
#include "csiitem.h"
#include "calloutbackgrounditem.h"
#include "textitem.h"

/*
 * We need to draw page every time there is change to the LDraw file.
 *   Changes can come from Menu->dialogs, people editing the file.
 *
 * Gui tracks modified, so whenever things go modified, we need to
 * delete all the GraphicsItems and do a freeranges.h.
 */

void Gui::clearPage(
  LGraphicsView  *view,
  QGraphicsScene *scene)
{
  page.freePage();
  page.pli.clear();

  if (view->pageBackgroundItem) {
    delete view->pageBackgroundItem;
    view->pageBackgroundItem = NULL;
  }
  scene->clear();
}

/*********************************************
 *
 * given a ranges.h for a page, format the
 * entire page.
 *
 ********************************************/
 
class SubmodelInstanceCount : public NumberPlacementItem
{
  Page *page;
  
  public:
  
    SubmodelInstanceCount(
      Page                *pageIn,
      NumberPlacementMeta &numberMetaIn,
      const char          *formatIn,
      int                  valueIn,
      QGraphicsItem       *parentIn)    {
      page = pageIn;
      QString toolTip("Times used - popup menu");
      setAttributes(PageNumberType,
                    SingleStepType,
                    numberMetaIn,
                    formatIn,
                    valueIn,
                    toolTip,
                    parentIn);
    }
  protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

void SubmodelInstanceCount::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
  QMenu menu;

  PlacementData placementData = placement.value();

  QAction *fontAction       = menu.addAction("Change Submodel Count Font");
  QAction *colorAction      = menu.addAction("Change Submodel Count Color");
  QAction *marginAction     = menu.addAction("Change Submodel Count Margins");
  QAction *placementAction  = menu.addAction("Move this number");

  fontAction->setWhatsThis("You can change the font or the size of the page number");
  colorAction->setWhatsThis("You can change the color of the page number");
  marginAction->setWhatsThis("You can change how much empty space their is around the page number");
  placementAction->setWhatsThis("You can move this submodel count around");

  QAction *selectedAction   = menu.exec(event->screenPos());

  if (selectedAction == fontAction) {

    changeFont(page->topOfSteps(),page->bottomOfSteps(),&font);

  } else if (selectedAction == colorAction) {

    changeColor(page->topOfSteps(),page->bottomOfSteps(),&color);

  } else if (selectedAction == marginAction) {

    changeMargins("Submodel Count Margins",
                  page->topOfSteps(),page->bottomOfSteps(),
                  &margin);
  } else if (selectedAction == placementAction) {
    changePlacement(PageType,
                    SubmodelInstanceCountType,
                    "Submodel Count Placement",
                    page->topOfSteps(),
                    page->bottomOfSteps(),
                  &placement);
  }
}

void SubmodelInstanceCount::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
  QGraphicsItem::mouseReleaseEvent(event);

  if (isSelected() && (flags() & QGraphicsItem::ItemIsMovable)) {

    QPointF newPosition;

    // back annotate the movement of the PLI into the LDraw file.
    newPosition = pos() - position;
    
    if (newPosition.x() || newPosition.y()) {
      positionChanged = true;

      PlacementData placementData = placement.value();

      placementData.offsets[0] += newPosition.x()/relativeToSize[0];
      placementData.offsets[1] += newPosition.y()/relativeToSize[1];

      placement.setValue(placementData);

      changePlacementOffset(page->topOfSteps(),&placement,PageType);
    }
  }
}

int Gui::addGraphicsPageItems(
  Steps          *steps,
  bool            coverPage,
  bool            endOfSubmodel,
  int             instances,
  LGraphicsView  *view,
  QGraphicsScene *scene,
  bool            printing)
{
  Page *page = dynamic_cast<Page *>(steps);

  PageBackgroundItem *pageBg = new PageBackgroundItem(page);

  view->pageBackgroundItem = pageBg;

  Placement plPage;
  plPage.relativeType = PageType;

  int pW, pH;

  if (printing) {
    if (view->maximumWidth() < page->meta.LPub.page.size.valuePixels(0)) {
      pW = view->maximumWidth();
    } else {
      pW = page->meta.LPub.page.size.valuePixels(0);
    }
    if (view->maximumHeight() < page->meta.LPub.page.size.valuePixels(1)) {
      pH = view->maximumHeight();
    } else {
      pH = page->meta.LPub.page.size.valuePixels(1);
    }
  } else {
    pW = page->meta.LPub.page.size.valuePixels(0);
    pH = page->meta.LPub.page.size.valuePixels(1);
  }

  plPage.setSize(pW,pH);
  plPage.margin  = page->meta.LPub.page.margin;
  plPage.loc[XX] = 0;
  plPage.loc[YY] = 0;

  if (page->meta.LPub.page.dpn.value() && ! coverPage) {

    // allocate QGraphicsTextItem for page number

    PageNumberItem  *pageNumber = 
      new PageNumberItem(
                      page,
                      page->meta.LPub.page.number, 
                     "%d", 
                     stepPageNum,
                     pageBg);
    
    pageNumber->relativeType = PageNumberType;
    pageNumber->size[XX]     = (int) pageNumber->document()->size().width();
    pageNumber->size[YY]     = (int) pageNumber->document()->size().height();
    
    PlacementData placementData = pageNumber->placement.value();
    
    if (page->meta.LPub.page.togglePnPlacement.value() && ! (stepPageNum & 1)) {
      switch (placementData.placement) {
        case TopLeft:
          placementData.placement = TopRight;
        break;
        case Top:
        case Bottom:
          switch (placementData.justification) {
            case Left:
              placementData.justification = Right;
            break;
            case Right:
              placementData.justification = Left;
            break;
            default:
            break;
          }
        break;
        case TopRight:
          placementData.placement = TopLeft;
        break;
        case Left:
          placementData.placement = Right;
        break;
        case Right:
          placementData.placement = Left;
        break;
        case BottomLeft:
          placementData.placement = BottomRight;
        break;
        case BottomRight:
          placementData.placement = BottomLeft;
        break;
        default:
        break;
      }

      pageNumber->placement.setValue(placementData);
    }
    
    plPage.appendRelativeTo(pageNumber);
    plPage.placeRelative(pageNumber);
    pageNumber->setPos(pageNumber->loc[XX],pageNumber->loc[YY]);
    
    // if this page contains the last step of the page, 
    // and instance is > 1 then display instance

    // allocate QGraphicsTextItem for instance number 
    
    SubmodelInstanceCount *instanceCount;
    
    if (endOfSubmodel&& instances > 1) {
      instanceCount = new SubmodelInstanceCount(
        page,
        page->meta.LPub.page.instanceCount,
        "x%d  ",
        instances,
        pageBg);
        
      /*
       * To make mousemove always know how to calculate offset, I modified
       * SubmodelInstanceClass to be derived from Placement.  The relativeToSize
       * offset calculation are in Placement.
       *
       * The offset calculation works great, but we end up with a problem
       * SubmodelInstanceCount gets placement from NumberPlacementItem, and
       * placement from Placement.  To work around this, I had to hack (and I mean
       * ugly) SubmodelInstanceCount to Placement.
       */
        
      if (instanceCount) {
        instanceCount->setSize(instanceCount->document()->size().width(),
                               instanceCount->document()->size().height());
        instanceCount->loc[XX] = 0;
        instanceCount->loc[YY] = 0;
        instanceCount->tbl[0] = 0;
        instanceCount->tbl[1] = 0;
        
        instanceCount->placement = page->meta.LPub.page.instanceCount.placement;
                        
        PlacementData placementData = instanceCount->placement.value();
        
        if (placementData.relativeTo == PageType) {
          plPage.placeRelative(instanceCount);
        } else {
          pageNumber->placeRelative(instanceCount);
        }
        instanceCount->setPos(instanceCount->loc[XX],instanceCount->loc[YY]);
      }
    }
  }
  
  /* Create any graphics items in the insert list */
  
  int nInserts = page->inserts.size();
  
  if (nInserts) {
    QFileInfo fileInfo;    
    for (int i = 0; i < nInserts; i++) {
      InsertData insert = page->inserts[i].value();  
      switch (insert.type) {
        case InsertData::InsertPicture:
          {
            fileInfo.setFile(insert.picName);
            if (fileInfo.exists()) {

              QPixmap qpixmap;
              qpixmap.load(insert.picName);
              InsertPixmapItem *pixmap = new InsertPixmapItem(qpixmap,page->inserts[i],pageBg);
              
              page->addInsertPixmap(pixmap);
              pixmap->setTransformationMode(Qt::SmoothTransformation);
              pixmap->scale(insert.picScale,insert.picScale);
              
              PlacementData pld;
              
              pld.placement    = TopLeft;
              pld.justification    = Center;
              pld.relativeTo      = PageType;
              pld.preposition   = Inside;
              pld.offsets[0]    = insert.offsets[0];
              pld.offsets[1]    = insert.offsets[1];
              
              pixmap->placement.setValue(pld);

              plPage.placeRelative(pixmap);
              pixmap->setPos(pixmap->loc[XX],pixmap->loc[YY]);
              pixmap->relativeToSize[0] = plPage.size[XX];
              pixmap->relativeToSize[1] = plPage.size[YY];
            }
          }
        break;
        case InsertData::InsertText:
          {
            TextItem *text = new TextItem(page->inserts[i],pageBg);

            PlacementData pld;

            pld.placement    = TopLeft;
            pld.justification    = Center;
            pld.relativeTo      = PageType;
            pld.preposition   = Inside;
            pld.offsets[0]    = insert.offsets[0];
            pld.offsets[1]    = insert.offsets[1];

            text->placement.setValue(pld);

            plPage.placeRelative(text);
            text->setPos(text->loc[XX],text->loc[YY]);
            text->relativeToSize[0] = plPage.size[XX];
            text->relativeToSize[1] = plPage.size[YY];
          }
        break;
        case InsertData::InsertArrow:
        break;
        case InsertData::InsertBom:
          {
            Where current(ldrawFile.topLevelFile(),0);
            QStringList bomParts;
            getBOMParts(current,bomParts);
            page->pli.bom = true;
            page->pli.pliMeta = page->meta.LPub.bom;
            page->pli.setParts(bomParts,page->meta,true);
            bomParts.clear();
            page->pli.sizePli(&page->meta,PageType,false);
            page->pli.relativeToSize[0] = plPage.size[XX];
            page->pli.relativeToSize[1] = plPage.size[YY];
          }
        break;
      }
    }
  }
  
  if (page->relativeType == SingleStepType) {
    if (page->list.size()) {
      Range *range = dynamic_cast<Range *>(page->list[0]);
      if (range->relativeType == RangeType) {        
        Step *step= dynamic_cast<Step *>(range->list[0]);
        if (step && step->relativeType == StepType) {
       
          if ( ! step->onlyChild()) {
            step->stepNumber.sizeit();
          }
          step->pli.addPli(step->submodelLevel, pageBg);
          
          /* Size the callouts */   
          for (int i = 0; i < step->list.size(); i++) {
            step->list[i]->sizeIt();
          }
          
          step->csiItem = new CsiItem(step,
                                 &page->meta, 
                                  step->csiPixmap,
                                  step->submodelLevel,
                                  pageBg,
                                  page->relativeType);
          step->csiItem->assign(&step->csiPlacement);  
        
          if (step->csiItem == NULL) {
            exit(-1);
          }

          step->csiItem->boundingSize[XX] = step->csiItem->size[XX];
          step->csiItem->boundingSize[YY] = step->csiItem->size[YY];
          
          plPage.relativeTo(step);      // place everything
                    
          plPage.placeRelativeBounding(step->csiItem);

          for (int j = 0; j < steps->list.size(); j++) {
            if (steps->list[j]->relativeType == RangeType) {
              Range *range = dynamic_cast<Range *>(steps->list[j]);
              for (int i = 0; i < range->list.size(); i++) {
                if (range->list[i]->relativeType == StepType) {
                  Step *step = dynamic_cast<Step *>(range->list[i]);
            
                  /* callouts */

                  for (int i = 0; i < step->list.size(); i++) {
                    if (step->list[i]->relativeType == CalloutType) {
                      Callout *callout = dynamic_cast<Callout *>(step->list[i]);

                      PlacementData placementData = callout->placement.value();

                      if (placementData.relativeTo == CsiType) {
                        step->csiItem->placeRelativeBounding(callout);
                      }
                    } // if callout
                  } // callouts
                } // if step
              } // foreach step
            } // if range
          } // foreach range
          
          if (step->pli.placement.value().relativeTo == CsiType) {
            step->csiItem->placeRelative(&step->pli);
          }

          step->csiItem->setPos(step->csiItem->loc[XX],
                                step->csiItem->loc[YY]);

          step->pli.setPos(step->pli.loc[XX],
                           step->pli.loc[YY]);
    
          // allocate QGraphicsTextItem for step number
      
          if ( ! step->onlyChild()) {
            StepNumberItem *stepNumber =
              new StepNumberItem(step,
                                 page->relativeType,
                                 page->meta.LPub.stepNumber,
                                 "%d",
                                 step->stepNumber.number,
                                 pageBg);
            stepNumber->setPos(step->stepNumber.loc[XX],
                               step->stepNumber.loc[YY]);
            stepNumber->relativeToSize[0] = step->stepNumber.relativeToSize[0];
            stepNumber->relativeToSize[1] = step->stepNumber.relativeToSize[1];
          }
              
          // foreach callout
              
          for (int i = 0; i < step->list.size(); i++) {
            Callout *callout = step->list[i];

            QRect    csiRect(step->csiItem->loc[XX]-callout->loc[XX],
                             step->csiItem->loc[YY]-callout->loc[YY],
                             step->csiItem->size[XX],
                             step->csiItem->size[YY]);
                             
            // foreach pointer
              
            callout->addGraphicsItems(0,0,csiRect,pageBg);
            for (int i = 0; i < callout->pointerList.size(); i++) {
              Pointer *pointer = callout->pointerList[i];
              callout->addGraphicsPointerItem(pointer,callout->background);
            }
          }
        }
      }
    }
  } else {
  
    PlacementData data = page->meta.LPub.multiStep.placement.value();
    page->placement.setValue(data);
    page->sizeIt();             // multi-step

    plPage.relativeToSg(page);  // place callouts relative to PAGE
    plPage.placeRelative(page); // place multi-step relative to the page    

    page->relativeToSg(page);   // place callouts relative to MULTI_STEP
    
    plPage.placeRelativeBounding(page); // center multi-step in page's bounding box
    
    page->relativeToSg(page);           // place callouts relative to MULTI_STEP

    page->addGraphicsItems(0,0,pageBg);

    if (page->pli.tsize()) {
      if (page->pli.bom) {
        page->pli.setFlag(QGraphicsItem::ItemIsSelectable,true);
        page->pli.setFlag(QGraphicsItem::ItemIsMovable,true);

        PlacementData pld;

        pld = page->pli.pliMeta.placement.value();

        page->pli.placement.setValue(pld);
        plPage.placeRelative(page->pli.background);
        page->pli.loc[XX] = page->pli.background->loc[XX];
        page->pli.loc[YY] = page->pli.background->loc[YY];
      }
      page->pli.setPos(page->pli.loc[0],page->pli.loc[1]);
    }
  }
  
  scene->addItem(pageBg);
  
  view->setSceneRect(pageBg->sceneBoundingRect());

  if ( ! printing) {
  
    view->horizontalScrollBar()->setRange(0,page->meta.LPub.page.size.valuePixels(0));
    view->verticalScrollBar()->setRange(0,page->meta.LPub.page.size.valuePixels(1));

    if (fitMode == FitWidth) {
      fitWidth(view);
    } else if (fitMode == FitVisible) {
      fitVisible(view);
    }
  }
  page->relativeType = SingleStepType;
  statusBarMsg("");
  return 0;
}
