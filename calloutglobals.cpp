
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

#include <QDialogButtonBox>
#include <QTabWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QGroupBox>

#include "globals.h"
#include "meta.h"
#include "metagui.h"
#include "metaitem.h"

class GlobalCalloutPrivate
{
public:
  Meta       meta;
  QString    topLevelFile;
  QList<MetaGui *> children;

  GlobalCalloutPrivate(QString &_topLevelFile, Meta &_meta)
  {
    topLevelFile = _topLevelFile;
    meta = _meta;

    MetaItem mi; // examine all the globals and then return

    mi.sortedGlobalWhere(meta,topLevelFile,"ZZZZZZZ");
  }
};

GlobalCalloutDialog::GlobalCalloutDialog(QString &topLevelFile, Meta &meta)
{
  data = new GlobalCalloutPrivate(topLevelFile, meta);

  setWindowTitle(tr("Callout Globals Setup"));

  QTabWidget  *tab = new QTabWidget(this);
  QVBoxLayout *layout = new QVBoxLayout(this);  
  setLayout(layout);
  layout->addWidget(tab);

  QWidget *widget;
  QGridLayout *grid;

  widget = new QWidget(this);
  grid = new QGridLayout(this);
  widget->setLayout(grid);

  MetaGui *child;
  QGroupBox *box;

  CalloutMeta *calloutMeta = &data->meta.LPub.callout;

  box = new QGroupBox("Background",this);
  grid->addWidget(box);
  child = new BackgroundGui(&calloutMeta->background,box);
  data->children.append(child);

  box = new QGroupBox("Border",this);
  grid->addWidget(box);
  child = new BorderGui(&calloutMeta->border,box);
  data->children.append(child);
  
  box = new QGroupBox("Margins",this);
  grid->addWidget(box);
  child = new UnitsGui("",&calloutMeta->margin,box);
  data->children.append(child);
  
  box = new QGroupBox("Divider",this);
  grid->addWidget(box);
  child = new SepGui(&calloutMeta->sep,box);
  data->children.append(child);

  tab->addTab(widget,"Background/Border");

  widget = new QWidget(this);
  grid = new QGridLayout(this);
  widget->setLayout(grid);
  
  box = new QGroupBox("Assembly Margins",this);
  grid->addWidget(box);
  child = new UnitsGui("",&calloutMeta->csi.margin,box);
  data->children.append(child);
  
  box = new QGroupBox("Parts List",this);
  grid->addWidget(box);
  QVBoxLayout *tempLayout = new QVBoxLayout(this);
  box->setLayout(tempLayout);
  child = new UnitsGui("Margins",&calloutMeta->pli.margin);
  data->children.append(child);
  tempLayout->addWidget(child);

  child = new CheckBoxGui("Per Step",&calloutMeta->pli.perStep);
  data->children.append(child);
  tempLayout->addWidget(child);

  box = new QGroupBox("Step Number",this);
  grid->addWidget(box);
  child = new NumberGui(&calloutMeta->stepNum,box);
  data->children.append(child);

  box = new QGroupBox("Times Used",this);
  grid->addWidget(box);
  child = new NumberGui(&calloutMeta->instance,box);
  data->children.append(child);

  tab->addTab(widget,"Contents");

  QDialogButtonBox *buttonBox;

  buttonBox = new QDialogButtonBox(this);
  buttonBox->addButton(QDialogButtonBox::Ok);
  connect(buttonBox,SIGNAL(accepted()),SLOT(accept()));
  buttonBox->addButton(QDialogButtonBox::Cancel);
  connect(buttonBox,SIGNAL(rejected()),SLOT(cancel()));

  layout->addWidget(buttonBox);

  setModal(true);
}

void GlobalCalloutDialog::getCalloutGlobals(
  QString topLevelFile, Meta &meta)
{
  GlobalCalloutDialog *dialog = new GlobalCalloutDialog(topLevelFile,meta);
  dialog->exec();
}

void GlobalCalloutDialog::accept()
{
  MetaItem mi;

  mi.beginMacro("Global Callout");

  MetaGui *child;

  foreach(child,data->children) {
    child->apply(data->topLevelFile);
  }
  mi.endMacro();
  QDialog::accept();
}

void GlobalCalloutDialog::cancel()
{
  QDialog::reject();
}
