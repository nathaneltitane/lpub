
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

#include <QString>
#include <QWidget>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QDialogButtonBox>

#include "globals.h"
#include "meta.h"
#include "metagui.h"
#include "metaitem.h"

class GlobalMultiStepPrivate
{
public:
  Meta       meta;
  QString    topLevelFile;
  QList<MetaGui *> children;

  GlobalMultiStepPrivate(QString &_topLevelFile, Meta &_meta)
  {
    topLevelFile = _topLevelFile;
    meta = _meta;

    MetaItem mi; // examine all the globals and then return

    mi.sortedGlobalWhere(meta,topLevelFile,"ZZZZZZZ");
  }
};

/*
 * margin
 * csi margin
 * pli margin, perStep
 * stepNumber font,color,margins
 * divider 
 */

GlobalMultiStepDialog::GlobalMultiStepDialog(
  QString &topLevelFile,
  Meta &meta)
{
  data = new GlobalMultiStepPrivate(topLevelFile,meta);

  setWindowTitle(tr("Step Group Globals Setup"));

  QVBoxLayout *grid = new QVBoxLayout(this);
  setLayout(grid);

  MetaGui *child;
  QGroupBox *box;

  MultiStepMeta *multiStepMeta = &data->meta.LPub.multiStep;
  
  box = new QGroupBox("Margins",this);
  grid->addWidget(box);
  child = new UnitsGui("",&multiStepMeta->margin,box);
  data->children.append(child);
  
  box = new QGroupBox("Divider",this);
  grid->addWidget(box);
  child = new SepGui(&multiStepMeta->sep,box);
  data->children.append(child);
  
  box = new QGroupBox("Assembly Margins",this);
  grid->addWidget(box);
  child = new UnitsGui("",&multiStepMeta->csi.margin,box);
  data->children.append(child);
  
  box = new QGroupBox("Parts List",this);
  grid->addWidget(box);
  QVBoxLayout *tempLayout = new QVBoxLayout(this);
  box->setLayout(tempLayout);
  child = new UnitsGui("Margins",&multiStepMeta->pli.margin);
  data->children.append(child);
  tempLayout->addWidget(child);

  child = new CheckBoxGui("Per Step",&multiStepMeta->pli.perStep);
  data->children.append(child);
  tempLayout->addWidget(child);

  box = new QGroupBox("Step Number",this);
  grid->addWidget(box);
  child = new NumberGui(&multiStepMeta->stepNum,box);
  data->children.append(child);

  QDialogButtonBox *buttonBox;

  buttonBox = new QDialogButtonBox(this);
  buttonBox->addButton(QDialogButtonBox::Ok);
  connect(buttonBox,SIGNAL(accepted()),SLOT(accept()));
  buttonBox->addButton(QDialogButtonBox::Cancel);
  connect(buttonBox,SIGNAL(rejected()),SLOT(cancel()));

  grid->addWidget(buttonBox);

  setModal(true);
  setModal(true);
}

void GlobalMultiStepDialog::getMultiStepGlobals(
  QString topLevelFile, Meta &meta)
{
  GlobalMultiStepDialog *dialog = new GlobalMultiStepDialog(topLevelFile, meta);
  dialog->exec();
}

void GlobalMultiStepDialog::accept()
{
  MetaItem mi;

  mi.beginMacro("Global MultiStep");

  MetaGui *child;

  foreach(child,data->children) {
    child->apply(data->topLevelFile);
  }
  mi.endMacro();
  QDialog::accept();
}
void GlobalMultiStepDialog::cancel()
{
  QDialog::reject();
}

