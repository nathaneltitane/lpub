
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
 * This class provides a simple mechanism for displaying arbitrary text
 * on the page.  
 *
 ***************************************************************************/

#ifndef textItemH
#define textItemH

#include <QGraphicsTextItem>
#include <QFont>
#include "placement.h"
#include "meta.h"
#include "metaitem.h"
#include "lpub.h"

class TextItem : public QGraphicsTextItem, public Placement, public MetaItem
{
public:
  QFont selectedFont;
  InsertMeta meta;

  TextItem()
  {
  }
  TextItem(
    InsertMeta meta,
    QGraphicsItem *parent) :  meta(meta)
  {
    InsertData data = meta.value();
    setPlainText(data.text);
    setParentItem(parent);

    QFont font(data.textFont);
    setFont(font);
    QColor color(data.textColor);
    setDefaultTextColor(color);
  }

protected:
  void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
};

#endif
