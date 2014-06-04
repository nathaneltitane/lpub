/****************************************************************************
**
** Copyright (C) 2004-2009 Kevin Clague. All rights reserved.
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

#include <QApplication>

#include "lpub_preferences.h"
#include "lpub.h"
#include "resolution.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(lpub);

    QApplication app(argc, argv);
	
    //QMessageBox::information(NULL,QMessageBox::tr("LPub"),QMessageBox::tr("Startup"));
    
    Preferences::ldrawPreferences(false);
    Preferences::unitsPreferences();
    defaultResolutionType(Preferences::preferCentimeters);
    setResolution(150);  // DPI

    Gui     LPubWin;
    LPubWin.show();
    LPubWin.sizeit();

    return app.exec();
}
