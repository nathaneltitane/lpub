
/****************************************************************************
**
** Copyright (C) 2007-2009 Kevin Clague. All rights reserved.
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

#include "textitem.h"
#include <QMenu>
#include <QAction>
#include <QGraphicsSceneContextMenuEvent>
#include <QFontDialog>

void TextItem::contextMenuEvent(
  QGraphicsSceneContextMenuEvent *event)
{
  QMenu menu;

  QAction *editFontAction = menu.addAction("Edit Font");
  editFontAction->setWhatsThis("Edit this text's font");

  QAction *editColorAction = menu.addAction("Edit Color");
  editColorAction->setWhatsThis("Edit this text's color");

  QAction *deleteTextAction = menu.addAction("Delete This Text");
  deleteTextAction->setWhatsThis("Delete this text");

  QAction *selectedAction  = menu.exec(event->screenPos());

  if (selectedAction == NULL) {
    return;
  }

  if (selectedAction == editFontAction) {
    InsertData data = meta.value();

    QFont font(data.textFont);
    bool ok;

    font = QFontDialog::getFont(&ok,font);

    if (ok) {
      data.textFont = font.toString();
      meta.setValue(data);
      replaceMeta(meta.here(),meta.format(false,false));
    }
  } else if (selectedAction == editColorAction) {
  } else if (selectedAction == deleteTextAction) {
    deleteMeta(meta.here());
  }
}
