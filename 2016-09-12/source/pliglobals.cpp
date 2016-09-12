
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
#include <QTabWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QDialogButtonBox>

#include "globals.h"
#include "meta.h"
#include "metagui.h"
#include "metaitem.h"

/*****************************************************************
 *
 * Global to pli
 *
 ****************************************************************/

class GlobalPliPrivate
{
public:
  Meta      meta;
  QString    topLevelFile;
  QList<MetaGui *> children;
  MetaGui *viewAngle;
  MetaGui *scale;
  bool     bom;

  GlobalPliPrivate(QString &_topLevelFile, Meta &_meta, bool _bom = false)
  {
    topLevelFile = _topLevelFile;
    meta = _meta;
    bom = _bom;
    MetaItem mi; // examine all the globals and then return

    mi.sortedGlobalWhere(meta,topLevelFile,"ZZZZZZZ");
  }
};

GlobalPliDialog::GlobalPliDialog(
  QString &topLevelFile, Meta &meta, bool bom)
{
  data = new GlobalPliPrivate(topLevelFile,meta,bom);

  if (bom) {
    setWindowTitle(tr("Bill of Materials Setup"));
  } else {
    setWindowTitle(tr("Parts List Setup"));
  }

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

  PliMeta *pliMeta = bom ? &data->meta.LPub.bom : &data->meta.LPub.pli;

  if ( ! bom) {
    child = new CheckBoxGui("Show Parts List",&pliMeta->show);
    data->children.append(child);
    grid->addWidget(child);
  }

  box = new QGroupBox("Background",this);
  grid->addWidget(box);
  child = new BackgroundGui(&pliMeta->background,box);
  data->children.append(child);

  box = new QGroupBox("Border",this);
  grid->addWidget(box);
  child = new BorderGui(&pliMeta->border,box);
  data->children.append(child);
  
  box = new QGroupBox("Margins",this);
  grid->addWidget(box);
  child = new UnitsGui("",&pliMeta->margin,box);
  data->children.append(child);
  
  box = new QGroupBox("Constrain",this);
  grid->addWidget(box);
  child = new ConstrainGui("",&pliMeta->constrain,box);
  data->children.append(child);

  tab->addTab(widget,"Background/Border");

  widget = new QWidget(this);
  grid = new QGridLayout(this);
  widget->setLayout(grid);

  /*
   * Part
   */

  box = new QGroupBox("Part Pictures",this);
  grid->addWidget(box);
  QVBoxLayout *partsLayout = new QVBoxLayout(this);
  box->setLayout(partsLayout);

  child = new DoubleSpinGui(
    "Scale",&pliMeta->modelScale,
    pliMeta->modelScale._min,
    pliMeta->modelScale._max,
    0.01);
  data->children.append(child);
  partsLayout->addWidget(child);
  data->scale = child;

  child = new FloatsGui("Lattitude","Longitude",&pliMeta->angle);
  data->children.append(child);
  partsLayout->addWidget(child);
  data->viewAngle = child;

  child = new UnitsGui("Margins",&pliMeta->part.margin);
  data->children.append(child);
  partsLayout->addWidget(child);

  if ( ! bom) {
    box = new QGroupBox("Submodels",this);
    grid->addWidget(box);
    child = new CheckBoxGui("Show in Parts List",&pliMeta->includeSubs,box);
    data->children.append(child);
  }

  box = new QGroupBox("Part Counts",this);
  grid->addWidget(box);
  child = new NumberGui(&pliMeta->instance,box);
  data->children.append(child);

  box = new QGroupBox("Part Length",this);
  grid->addWidget(box);
  child = new NumberGui(&pliMeta->annotate,box);
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

void GlobalPliDialog::getPliGlobals(
  QString topLevelFile, Meta &meta)
{
  GlobalPliDialog *dialog = new GlobalPliDialog(topLevelFile, meta, false);
  dialog->exec();
}

void GlobalPliDialog::getBomGlobals(
  QString topLevelFile, Meta &meta)
{
  GlobalPliDialog *dialog = new GlobalPliDialog(topLevelFile, meta, true);
  dialog->exec();
}

void GlobalPliDialog::accept()
{
  if (data->scale->modified ||
      data->viewAngle->modified) {
    clearPliCache();
  }

  MetaItem mi;

  mi.beginMacro("Global Pli");

  MetaGui *child;

  foreach(child,data->children) {
    child->apply(data->topLevelFile);
  }
  mi.endMacro();
  QDialog::accept();
}

void GlobalPliDialog::cancel()
{
  QDialog::reject();
}
