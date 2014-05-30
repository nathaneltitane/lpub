
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

#include "color.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QRegExp>
#include "lpub_preferences.h"

QHash<QString, QColor>  LDrawColor::name2color;
QHash<QString, QString> LDrawColor::color2name;

/*
 * This constructor reads in the LDraw ldconfig.ldr file and extracts
 * the color codes, color names, and color values and puts them in
 * the xlate (name to color translate) hash table.
 */
LDrawColor::LDrawColor ()
{
  name2color.clear();
  color2name.clear();
  QString fileName(Preferences::ldrawPath + "/ldconfig.ldr");
  QFile file(fileName);
  if (! file.open(QFile::ReadOnly | QFile::Text)) {
    QMessageBox::warning(NULL,QMessageBox::tr("LDrawColor"),
                              QMessageBox::tr("Cannot read file %1\n%2.")
                                          .arg(fileName)
                                          .arg(file.errorString()));
    return;
  }
  QRegExp rx("^\\s*0\\s+!COLOUR\\s+(\\w+)\\s+"
             "CODE\\s+(\\d+)\\s+VALUE\\s+#([\\da-fA-F]+)");
  QTextStream in(&file);
  while ( ! in.atEnd()) {
    QString line = in.readLine(0);
    if (line.contains(rx)) {
      bool ok;
      QRgb hex = rx.cap(3).toLong(&ok,16);
      QColor color(hex);
      color.setAlpha(0xff);
      QString name = rx.cap(1).toLower();
      name2color.insert(name,color);
      name = rx.cap(2).toLower();
      name2color.insert(name,color);
      name = rx.cap(1);
      QString code = rx.cap(2);          
      color2name.insert(code,name);
      color2name.insert(color.name(),name);
    }
  }
}

/*
 * This function provides the translate from LDraw color names and codes
 * to QColor.
 */
QColor LDrawColor::color(QString nickname)
{
  QString lower(nickname.toLower());
  if (name2color.contains(lower)) {
    return name2color[lower];
  } else {
    QRegExp rx("\\s*(0x|#)([\\da-fA-F]+)\\s*$");
    if (nickname.contains(rx)) {
      QString prefix("0xf"+rx.cap(2));
      bool ok;
      QRgb rgb = prefix.toLong(&ok,16);
      QColor color(rgb);
      color.setAlpha(0xff);
      return color;
    } else {
      return Qt::black;
    }
  }
}

/*
 * This function provides the translate from QColor back to LDraw color
 * names.  If there is no translation the hexadecimal value for the
 * color is returned as a string.
 */
QString LDrawColor::name(QString code)
{
  if (color2name.contains(code)) {
    return color2name[code];
  } else {
    return "";
  }
}
