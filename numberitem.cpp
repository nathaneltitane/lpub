
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
 * This file describes the graphical representation of a number displayed
 * in the graphics scene that is used to describe a building instruction
 * page.
 *
 * Please see lpub.h for an overall description of how the files in LPub
 * make up the LPub program.
 *
 ***************************************************************************/

#include "numberitem.h"
#include "metatypes.h"
#include <QColor>
#include <QPixmap>
#include <QAction>
#include <QMenu>
#include <QGraphicsSceneContextMenuEvent>
#include "color.h"
#include "name.h"
#include "placementdialog.h"
#include "commonmenus.h"

#include "ranges.h"
#include "step.h"

void NumberItem::setAttributes(
  PlacementType  _relativeType,
  PlacementType  _parentRelativeType,
  Meta          *_meta,
  NumberMeta    &_number,
  const char    *_format,
  int            _value,
  QString       &toolTip,
  QGraphicsItem *_parent,
  QString        _name)
{
  relativeType = _relativeType;
  parentRelativeType = _parentRelativeType;
  meta         =  _meta;
  font         = &_number.font;
  color        = &_number.color;
  margin       = &_number.margin;
  value        = _value;
  name         = _name;

  QFont qfont;
  qfont.fromString(_number.font.valueFoo());
  setFont(qfont);

  QString foo;
  foo.sprintf(_format,_value);
  setPlainText(foo);
  setDefaultTextColor(LDrawColor::color(color->value()));
  setToolTip(toolTip);
  setParentItem(_parent);
}

NumberItem::NumberItem()
{
  relativeType = PageNumberType;
  meta = NULL;
  font = NULL;
  color = NULL;
  margin = NULL;
}

NumberItem::NumberItem(
  PlacementType  _relativeType,
  PlacementType  _parentRelativeType,
  Meta          *_meta,
  NumberMeta    &_number,
  const char    *_format,
  int            _value,
  QString       &_toolTip,
  QGraphicsItem *_parent,
  QString        _name)
{
  setAttributes(_relativeType,
                _parentRelativeType,
                _meta,
                _number,
                _format,
                _value,
                _toolTip,
                _parent,
                _name);
}

NumberPlacementItem::NumberPlacementItem()
{
  relativeType = PageNumberType;
  setFlag(QGraphicsItem::ItemIsMovable,true);
  setFlag(QGraphicsItem::ItemIsSelectable,true);
}

NumberPlacementItem::NumberPlacementItem(
  PlacementType  _relativeType,
  PlacementType  _parentRelativeType,
  NumberPlacementMeta &_number,
  const char    *_format,
  int            _value,
  QString       &toolTip,
  QGraphicsItem *_parent,
  QString        _name)
{
  setAttributes(_relativeType,
                _parentRelativeType,
                _number,
                _format,
                _value,
                toolTip,
                _parent,
                _name);
}

void NumberPlacementItem::setAttributes(
  PlacementType  _relativeType,
  PlacementType  _parentRelativeType,
  NumberPlacementMeta &_number,
  const char    *_format,
  int            _value,
  QString       &toolTip,
  QGraphicsItem *_parent,
  QString        _name)
{
  relativeType = _relativeType;
  parentRelativeType = _parentRelativeType;
  font         =  _number.font;
  color        =  _number.color;
  margin       =  _number.margin;
  placement    =  _number.placement;
  value        =  _value;
  name         =  _name;

  QFont qfont;
  qfont.fromString(_number.font.valueFoo());
  setFont(qfont);

  QString foo;
  foo.sprintf(_format,_value);
  setPlainText(foo);
  setDefaultTextColor(LDrawColor::color(color.value()));

  setToolTip(toolTip);
  setParentItem(_parent);
}
void NumberPlacementItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{     
  QGraphicsItem::mousePressEvent(event);
  positionChanged = false;
  position = pos();
} 
  
void NumberPlacementItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{ 
  QGraphicsItem::mouseMoveEvent(event);
  if (isSelected() && (flags() & QGraphicsItem::ItemIsMovable)) {
    positionChanged = true;
  }   
}     
      
void NumberPlacementItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{     
  QGraphicsItem::mouseReleaseEvent(event);
} 

PageNumberItem::PageNumberItem(
  Page          *_page,
  NumberPlacementMeta &_number,
  const char    *_format,
  int            _value,
  QGraphicsItem *_parent)
{
  page = _page;
  QString toolTip("Page Number - use popu menu");
  setAttributes(PageNumberType,
                SingleStepType,
                _number,
                _format,
                _value,
                toolTip,
                _parent);
}

void PageNumberItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
  QMenu menu;

  PlacementData placementData = placement.value();
  QString name = "Move Page Number";
  QAction *placementAction  = menu.addAction(name);
  placementAction->setWhatsThis(
    commonMenus.naturalLanguagePlacementWhatsThis(PageNumberType,placementData,name));

  QAction *fontAction       = menu.addAction("Change Page Number Font");
  QAction *colorAction      = menu.addAction("Change Page Number Color");
  QAction *marginAction     = menu.addAction("Change Page Number Margins");

  fontAction->setWhatsThis("You can change the font or the size of the page number");
  colorAction->setWhatsThis("You can change the color of the page number");
  marginAction->setWhatsThis("You can change how much empty space their is around the page number");

  QAction *selectedAction   = menu.exec(event->screenPos());

  if (selectedAction == placementAction) {

    changePlacement(PageType,
                    PageNumberType,
                    "Page Number Placement",
                    page->topOfSteps(),
                    page->bottomOfSteps(),
                  &placement);

  } else if (selectedAction == fontAction) {

    changeFont(page->topOfSteps(),page->bottomOfSteps(),&font);

  } else if (selectedAction == colorAction) {

    changeColor(page->topOfSteps(),page->bottomOfSteps(),&color);

  } else if (selectedAction == marginAction) {

    changeMargins("Page Number Margins",
                  page->topOfSteps(),page->bottomOfSteps(),
                &margin);
  }
}

void PageNumberItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
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

      changePlacementOffset(page->topOfSteps(),&placement,StepNumberType);
    }
  }
}

StepNumberItem::StepNumberItem(
  Step          *_step,
  PlacementType  parentRelativeType,
  NumberPlacementMeta    &_number,
  const char    *_format,
  int            _value,
  QGraphicsItem *_parent,
  QString        name)
{
  step = _step;
  QString toolTip("Step Number - popup menu");
  setAttributes(StepNumberType,
                parentRelativeType,
                _number,
                _format,
                _value,
                toolTip,
                _parent,
                name);
}

void StepNumberItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
  QMenu menu;
  QAction *placementAction = commonMenus.placementMenu(menu,name);
  QAction *fontAction      = commonMenus.fontMenu(menu,name);
  QAction *colorAction     = commonMenus.colorMenu(menu,name);
  QAction *marginAction    = commonMenus.marginMenu(menu,name);

  QAction *selectedAction   = menu.exec(event->screenPos());
  
  Where topOfStep = step->topOfStep();
  Where bottomOfStep = step->bottomOfStep();
  Where topOfSteps = step->topOfSteps();
  Where bottomOfSteps = step->bottomOfSteps();
  
  Where top, bottom;
  bool  local;
  MetaItem mi;
  
  switch (parentRelativeType) {
    case StepGroupType:
      top    = step->topOfSteps();
      mi.scanForward(top,StepGroupMask);
      bottom = step->bottomOfSteps();
      local  = false;
    break;
    case CalloutType:
      top    = step->topOfCallout();
      bottom = step->bottomOfCallout();
      local  = false;
    break;
    default:
      top    = step->topOfStep();
      bottom = step->bottomOfStep();
      local  = true;
    break;
  }

  if (selectedAction == placementAction) {

    changePlacement(parentRelativeType,
                    StepNumberType,
                    "Move Step Number", 
                    top,
                    bottom,
                   &placement,
                    true,
                    1,
                    local);

  } else if (selectedAction == fontAction) {

    changeFont(top, bottom, &font, 1, local);

  } else if (selectedAction == colorAction) {

    changeColor(top,bottom, &color, 1, local);

  } else if (selectedAction == marginAction) {

    changeMargins("Change Step Number Margins",top,bottom,&margin,true,1,local);
  } 
}

void StepNumberItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
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

      changePlacementOffset(step->topOfStep(),&placement,StepNumberType);
    }
  }
}

