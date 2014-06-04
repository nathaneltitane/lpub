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
#ifndef PREFERENCES_DIALOG_H
#define PREFERENCES_DIALOG_H

#include "ui_preferences.h"

class PreferencesDialog : public QDialog
{
  Q_OBJECT
  
  public:
    PreferencesDialog(QWidget *parent = 0);
	
	QString const ldrawPath();
	QString const pliFile();
	QString const ldgliteExe();
	QString const ldviewExe();
	QString const preferredRenderer();
  bool    const centimeters();
	
  private slots:
  void on_browseLDraw_clicked();
	void on_browsePli_clicked();
	void on_browseLDView_clicked();
	void on_browseLDGLite_clicked();
		
  private:
    QWidget *parent;
    Ui::PreferencesDialog ui;
};

#endif
