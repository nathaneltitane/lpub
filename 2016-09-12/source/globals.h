
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

/***************************************************************************
 
 * This header file describes the global setup dialogs used to configur
 * global settings for page, assembly, parts lists, callouts, step groups
 * and projects
 *
 * Please see lpub.h for an overall description of how the files in LPu
 * make up the LPub program
 *
 ***************************************************************************/

#ifndef GLOBAL_H
#define GLOBAL_H

#include <QDialog>

class Meta;

/*****************************************************************
 *
 * Global to page
 *
 ****************************************************************/

class GlobalPagePrivate;
class GlobalPageDialog : public QDialog
{
  Q_OBJECT
private:
  GlobalPagePrivate *data;

public:
  GlobalPageDialog(QString &topLevelModel, Meta &meta);
  ~GlobalPageDialog() {};
  static void getPageGlobals(QString topLevelFile, Meta &meta);

public slots:
  void accept();
  void cancel();
};

/*****************************************************************
 *
 * Global to single step assem and step number
 *
 ****************************************************************/

class GlobalAssemPrivate;
class GlobalAssemDialog : public QDialog
{
  Q_OBJECT
private:
  GlobalAssemPrivate *data;

public:
  GlobalAssemDialog(QString &topLevelFile, Meta &meta);
  ~GlobalAssemDialog() {}
  static void getAssemGlobals(QString topLevelFile, Meta &meta);

public slots:
  void accept();
  void cancel();
};

/*****************************************************************
 *
 * Global to pli
 *
 ****************************************************************/

class GlobalPliPrivate;
class GlobalPliDialog : public QDialog
{
  Q_OBJECT
private:
  GlobalPliPrivate *data;

public:
  GlobalPliDialog(QString &topLevelFile, Meta &meta, bool);
  ~GlobalPliDialog() {}
  static void getPliGlobals(QString topLevelFile, Meta &meta);
  static void getBomGlobals(QString topLevelFile, Meta &meta);

public slots:
  void accept();
  void cancel();
};

/*****************************************************************
 *
 * Global to callout
 *
 ****************************************************************/

class GlobalCalloutPrivate;
class GlobalCalloutDialog : public QDialog
{
  Q_OBJECT
private:
  GlobalCalloutPrivate *data;

public:
  GlobalCalloutDialog(QString &topLevelFile, Meta &meta);
  ~GlobalCalloutDialog() {}
  static void getCalloutGlobals(QString topLevelFile, Meta &meta);

public slots:
  void accept();
  void cancel();
};

/*****************************************************************
 *
 * Global to multiStep
 *
 ****************************************************************/

class GlobalMultiStepPrivate;
class GlobalMultiStepDialog : public QDialog
{
  Q_OBJECT
private:
  GlobalMultiStepPrivate *data;

public:
  GlobalMultiStepDialog(QString &topLevelFile, Meta &meta);
  ~GlobalMultiStepDialog() {}
  static void getMultiStepGlobals(QString topLevelFile, Meta &meta);

public slots:
  void accept();
  void cancel();
};


/*****************************************************************
 *
 * Global to project
 *
 ****************************************************************/

class GlobalProjectPrivate;
class GlobalProjectDialog : public QDialog
{
  Q_OBJECT
private:  
  GlobalProjectPrivate *data;

public:

  GlobalProjectDialog(const QString &topLevelFile, Meta &meta);
  ~GlobalProjectDialog() {};  
  static void getProjectGlobals(const QString topLevelFile, Meta &meta);
  
public slots:
  void accept();
  void cancel();
};
#endif
