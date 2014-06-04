
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

/****************************************************************************
 *
 * This file describes the data structure that represents an LPub callout
 * (the steps of a submodel packed together and displayed next to the
 * assembly where the submodel is used).  
 *
 * Please see lpub.h for an overall description of how the files in LPub
 * make up the LPub program.
 *
 ***************************************************************************/

#include <QtGui>

#include "callout.h"
#include "calloutbackgrounditem.h"
#include "pointer.h"
#include "pointeritem.h"
#include "numberitem.h"
#include "ranges.h"
#include "range.h"
#include "step.h"
#include "lpub.h"
#include "placementdialog.h"
#include "commonmenus.h"

//---------------------------------------------------------------------------

Callout::Callout(
  Meta                 &_meta,
  QGraphicsView        *view)
  : view(view)
{
  relativeType  = CalloutType;
  meta = _meta;
  instances = 1;
  shared = false;
}

Callout::~Callout()
{
  Steps::list.clear();
  pointerList.clear();
}

AllocEnc Callout::allocType()
{
  if (relativeType == CalloutType) {
    return meta.LPub.callout.alloc.value();
  } else {
    return meta.LPub.multiStep.alloc.value();
  }
}

AllocMeta &Callout::allocMeta()
{
  if (relativeType == CalloutType) {
    return meta.LPub.callout.alloc;
  } else {
    return meta.LPub.multiStep.alloc;
  }
}

void Callout::appendPointer(const Where &here, CalloutMeta &attrib)
{
  Pointer *pointer = new Pointer(here,attrib);
  pointerList.append(pointer);
}

void Callout::sizeIt()
{
  AllocEnc allocEnc = meta.LPub.callout.alloc.value();
  if (allocEnc == Vertical) {
    Steps::sizeit(allocEnc,XX,YY);
  } else {
    Steps::sizeit(allocEnc,YY,XX);
  }

  BorderData borderData = meta.LPub.callout.border.valuePixels();

  size[XX] += borderData.margin[XX];
  size[YY] += borderData.margin[YY];

  size[XX] += borderData.thickness;
  size[YY] += borderData.thickness;
  
  /* If we've got multiple instances of a submodel, we need to add
     the usage count in the lower right corner.  for assem, pli, and
     step number, determine if bottom right corner overlaps with the
     top left corner of the count.  If it fits, place the count
     inside.  If not, calculate the area created by adding to side,
     and compare the area created by adding to the bottom.  Add the
     smaller area to the callout, and place the count accordingly */

  if (instances > 1) {
    instanceCount.number = instances;
    instanceCount.placement = meta.LPub.callout.instance.placement;
    instanceCount.margin    = meta.LPub.callout.instance.margin;
    instanceCount.font = meta.LPub.callout.instance.font.valueFoo();
    instanceCount.sizeit();
    
    for (int j = 0; j < list.size(); j++) {
      if (list[j] && list[j]->relativeType == RangeType) {
        Range *range = dynamic_cast<Range *>(list[j]);
        for (int i = 0; i < range->list.size(); i++) {
          if (range->list[i]->relativeType == StepType) {
            Step *step = dynamic_cast<Step *>(range->list[i]);
            
            /* Describe the instance count rectangle */
            
            int  instanceTop, instanceLeft, instanceWidth, instanceHeight;
              
            instanceWidth  = instanceCount.size[XX] + instanceCount.margin.valuePixels(XX);
            instanceHeight = instanceCount.size[YY] + instanceCount.margin.valuePixels(YY);
            instanceLeft = size[XX] - instanceWidth;
            instanceTop  = size[YY] - instanceHeight;

            /* if there is something yo work with */
            
            int  right;
            int  bottom;
            bool          fit = true;
            
            // Overlap count with CSI?
              
            right  = step->csiPlacement.loc[XX] + step->csiPlacement.size[XX];
            bottom = step->csiPlacement.loc[YY] + step->csiPlacement.size[YY];
              
            if (right > instanceLeft && bottom > instanceTop) {
              fit = false;
            } else {      
              right  = step->pli.loc[XX] + step->pli.size[XX];
              bottom = step->pli.loc[YY] + step->pli.size[YY];

              // Overlap with PLI?
                
              if (right > instanceLeft && bottom > instanceTop) {
                fit = false;
              } else {
                right  = step->stepNumber.loc[XX] + step->stepNumber.size[XX];
                bottom = step->stepNumber.loc[YY] + step->stepNumber.size[YY];

                // Overlap with Step Number?
                  
                fit = ! (right > instanceLeft && bottom > instanceTop);
                if (fit) {
                  for (int i = 0; i < step->list.size(); i++) {
                    Callout *callout = step->list[i];
                    if (callout) {
                      right = callout->loc[XX] + callout->size[XX];
                      bottom = callout->loc[YY] + callout->size[YY];
                      if (right > instanceLeft && bottom > instanceTop) {
                        fit = false;
                        break;
                      }
                    }
                  }
                }
              }
            }
            if (fit) {
              instanceCount.loc[XX] = instanceLeft + instanceCount.margin.valuePixels(XX);
              instanceCount.loc[YY] = instanceTop + instanceCount.margin.valuePixels(YY);
            } else {
              // enlarge the callout to make room
                    
              int a = instanceWidth  * size[YY];
              int b = instanceHeight * size[XX];
              
              if (a < b) {
                instanceCount.loc[XX] = size[XX] + instanceCount.margin.valuePixels(XX);
                instanceCount.loc[YY] = instanceTop + instanceCount.margin.valuePixels(YY);
                size[XX] += instanceWidth;
              } else {
                instanceCount.loc[XX] = instanceLeft + instanceCount.margin.valuePixels(XX);
                instanceCount.loc[YY] = size[YY] + instanceCount.margin.valuePixels(YY);
                size[YY] += instanceHeight;
              }
            }
          } // if step
        } // foreach step
      } // if range
    } // foreach range
  }

  size[XX] += borderData.margin[XX];
  size[YY] += borderData.margin[YY];

  size[XX] += borderData.thickness;
  size[YY] += borderData.thickness;
}

void Callout::addGraphicsItems(
  int            offsetX,
  int            offsetY,
  QRect         &csiRect,
  QGraphicsItem *parent)
{
  PlacementData placementData = placement.value();
  
  if (placementData.relativeTo == PageType ||
      placementData.relativeTo == StepGroupType) {
    offsetX = 0;
    offsetY = 0;
  }
  
  int newLoc[2] = { offsetX + loc[XX], offsetY + loc[YY] };
  
  QRect calloutRect(newLoc[XX],newLoc[YY],size[XX],size[YY]);

  background = new CalloutBackgroundItem(
                     this,
                     calloutRect,
                     csiRect,
                     parentRelativeType,
                    &meta,
                     meta.submodelStack.size(),
                     path(),
                     parent,
                     view);

  background->setPos(newLoc[XX],newLoc[YY]);

  int saveX = loc[XX];
  int saveY = loc[YY];

  BorderData borderData = meta.LPub.callout.border.valuePixels();

  loc[XX] = borderData.margin[0];
  loc[YY] = borderData.margin[1];
 
  if (meta.LPub.callout.alloc.value() == Vertical) {
    addGraphicsItems(Vertical,0,borderData.thickness,background);
  } else {
    addGraphicsItems(Horizontal,borderData.thickness,0,background);
  }
  loc[XX] = saveX;
  loc[YY] = saveY;
}

void Callout::addGraphicsItems(
  AllocEnc       allocEnc,
  int            offsetX,
  int            offsetY,
  QGraphicsItem *parent)
{
  int margin;

  if (instanceCount.number > 1) {
    PlacementData placementData = instanceCount.placement.value();
    switch (placementData.placement) {
      case TopLeft:
      case Left:
      case BottomLeft:
        margin   = meta.LPub.callout.instance.margin.valuePixels(XX);
        offsetX += instanceCount.size[XX] + margin;
      break;
      default:
      break;
    }

    switch (placementData.placement) {
      case TopLeft:
      case Top:
      case TopRight:
        margin   = meta.LPub.callout.instance.margin.valuePixels(YY);
        offsetY += instanceCount.size[YY] + margin;
      break;
      default:
      break;
    }
    CalloutInstanceItem *item = new CalloutInstanceItem(
      this,&meta,"x%d",instanceCount.number,parent);
    item->setPos(offsetX + instanceCount.loc[0], offsetY + instanceCount.loc[1]);
    item->setZValue(1000);
  }

  Steps::addGraphicsItems(allocEnc,
                          offsetX,
                          offsetY,
                          parent);
}

void Callout::sizeitFreeform(
  int xx,
  int yy)
{
  Steps::sizeitFreeform(xx,yy);

  size[XX] += 2*meta.LPub.callout.border.valuePixels().thickness;
  size[YY] += 2*meta.LPub.callout.border.valuePixels().thickness;

  if (instanceCount.number > 1) {
    instanceCount.sizeit("%1x");
    PlacementData placementData = instanceCount.placement.value();
    if (placementData.preposition == Outside) {

      switch (placementData.placement) {
        case TopLeft:
        case Left:
        case BottomLeft:
        case TopRight:
        case Right:
        case BottomRight:
          size[XX] += margin.valuePixels(XX) + instanceCount.size[XX];
        break;
        default:
        break;
      }
      switch (placementData.placement) {
        case TopLeft:
        case Top:
        case TopRight:
        case BottomLeft:
        case Bottom:
        case BottomRight:
          size[YY] += margin.valuePixels(YY) + instanceCount.size[YY];
        break;
        default:
        break;
      }
      placementData.preposition = Inside;
      instanceCount.placement.setValue(placementData);

      placeRelative(&instanceCount);

      placementData = instanceCount.placement.value();
      placementData.preposition = Inside;
      instanceCount.placement.setValue(placementData);
    } else {
      size[YY] += margin.valuePixels(YY);
      placeRelative(&instanceCount);
    }
  }
}

CalloutInstanceItem::CalloutInstanceItem(
  Callout             *_callout,
  Meta                *_meta,
  const char          *_format,
  int                  _value,
  QGraphicsItem       *_parent)
{
  callout = _callout;
  QString toolTip("Times used - popup menu");
  setAttributes(PageNumberType,
                CalloutType,
                _meta->LPub.callout.instance,
                _format,
                _value,
                toolTip,
                _parent);
}

void Callout::addGraphicsPointerItem(
  Pointer *pointer,
  QGraphicsItem *parent)
{
  CalloutPointerItem *t = 
    new CalloutPointerItem(
          this,
         &meta,
          pointer,
           parent,
          view);
  graphicsPointerList.append(t);
}

void Callout::updatePointers(QPoint &delta)
{
  for (int i = 0; i < graphicsPointerList.size(); i++) {
    CalloutPointerItem *pointer = graphicsPointerList[i];
    pointer->updatePointer(delta);
  }
}

void Callout::drawTips(QPoint &delta)
{
  for (int i = 0; i < graphicsPointerList.size(); i++) {
    CalloutPointerItem *pointer = graphicsPointerList[i];
    pointer->drawTip(delta);
  }
}

void CalloutInstanceItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
  QMenu menu;
  QString ci = "Callout Instance Count";
  QAction *fontAction   = commonMenus.fontMenu(menu,ci);
  QAction *colorAction  = commonMenus.colorMenu(menu,ci);
  QAction *marginAction = commonMenus.marginMenu(menu,ci);

  QAction *selectedAction   = menu.exec(event->screenPos());

  if (selectedAction == NULL) {
    return;
  }

  if (selectedAction == fontAction) {

    changeFont(callout->topOfCallout(), callout->bottomOfCallout(),&font);

  } else if (selectedAction == colorAction) {

    changeColor(callout->topOfCallout(), callout->bottomOfCallout(),&color);

  } else if (selectedAction == marginAction) {

    changeMargins("Times Used Margin",
                  callout->topOfCallout(), callout->bottomOfCallout(),
                  &margin, false);
  }
}

void CalloutInstanceItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
  QGraphicsItem::mouseReleaseEvent(event);
  QPointF newPosition;
  if (isSelected() && (flags() & QGraphicsItem::ItemIsMovable) && positionChanged) {
    // back annotate the movement of the PLI into the LDraw file.
    newPosition = pos() - position;
    PlacementData placementData = placement.value();
    placementData.offsets[0] += newPosition.x()/relativeToSize[0];
    placementData.offsets[1] += newPosition.y()/relativeToSize[1];
    placement.setValue(placementData);
    changePlacementOffset(callout->topOfCallout(),&placement,CalloutType,false);
  }
}
