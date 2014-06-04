
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
 * This file describes a set of classes that implement graphical user
 * interfaces for some of the configuration meta classes described in meta.h
 *
 * Please see lpub.h for an overall description of how the files in LPub
 * make up the LPub program.
 *
 ***************************************************************************/

#ifndef metagui_h
#define metagui_h

#include <QWidget>
#include "resolution.h"
#include "metatypes.h"

void clearPliCache();

class QWidget;
class QString;
class QHBoxLayout;
class LeafMeta;
class UnitsMeta;

class MetaGui  : public QWidget
{
  Q_OBJECT
public:
  MetaGui()
  {
    modified = false;
  }
  ~MetaGui() {}

  virtual void apply(QString &topLevelFile) = 0;

  bool      modified;

protected:
  LeafMeta *_meta;
};

/***********************************************************************
 *
 * Bool
 *
 **********************************************************************/

class QGroupBox;
class QLabel;
class QCheckBox;
class BoolMeta;
class CheckBoxGui : public MetaGui
{
  Q_OBJECT
public:

  CheckBoxGui(
    QString const  &heading,
    BoolMeta      *meta,
    QGroupBox      *parent = NULL);
  ~CheckBoxGui() {}

  void setEnabled(bool enabled);

  virtual void apply(QString &modelName);

private:
  BoolMeta  *meta;
  QCheckBox *check;

public slots:
  void stateChanged(int state);
};

/***********************************************************************
 *
 * Bool
 *
 **********************************************************************/

class QRadioButton;
class BoolRadioGui : public MetaGui
{
  Q_OBJECT
public:

  BoolRadioGui(
    QString const &trueHeading,
    QString const &falseHeading,
    BoolMeta      *meta,
    QGroupBox     *parent);

  ~BoolRadioGui() {}

  virtual void apply(QString &modelName);

private:
  BoolMeta     *meta;
  QRadioButton *trueRadio;
  QRadioButton *falseRadio;

public slots:
  void trueClicked(bool clicked);
  void falseClicked(bool clicked);
};

/***********************************************************************
 *
 * Units
 *
 **********************************************************************/

class QGroupBox;
class QLabel;
class QLineEdit;
class UnitsGui : public MetaGui
{
  Q_OBJECT
public:

  UnitsGui(
    QString const  &heading,
    UnitsMeta      *meta,
    QGroupBox      *parent = NULL);
  ~UnitsGui() {}

  void setEnabled(bool enabled);

  virtual void apply(QString &modelName);

private:
  UnitsMeta *meta;
  QLabel    *label;
  QLineEdit *value0;
  QLineEdit *value1;

public slots:
  void value0Change(QString const &);
  void value1Change(QString const &);
};

/***********************************************************************
 *
 * Float Pair
 *
 **********************************************************************/

class FloatPairMeta;
class FloatsGui : public MetaGui
{
  Q_OBJECT
public:

  FloatsGui(
    QString const &heading0,
    QString const &heading1,
    FloatPairMeta *meta,
    QGroupBox     *parent = NULL);
  ~FloatsGui() {}

  void setEnabled(bool enabled);

  virtual void apply(QString &modelName);

private:
  FloatPairMeta *meta;
  QLabel        *label0;
  QLabel        *label1;
  QLineEdit     *value0;
  QLineEdit     *value1;

public slots:
  void value0Change(QString const &);
  void value1Change(QString const &);
};

/***********************************************************************
 *
 * Number
 *
 **********************************************************************/

class NumberMeta;
class QGroupBox;
class QPushButton;
class NumberGui : public MetaGui
{
  Q_OBJECT
public:

  NumberGui(
    NumberMeta *meta,
    QGroupBox  *parent = NULL);
  ~NumberGui() {}

  virtual void apply(QString &modelName);

private:
  NumberMeta  *meta;

  bool        fontModified;
  bool        colorModified;
  bool        marginsModified;

  QLabel      *fontLabel;
  QLabel      *fontExample;
  QPushButton *fontButton;
  QLabel      *colorLabel;
  QLabel      *colorExample;
  QPushButton *colorButton;  
  QLabel      *marginsLabel;
  QLineEdit   *value0;
  QLineEdit   *value1;

public slots:
  void browseFont(bool clicked);
  void browseColor(bool clicked);
  void value0Changed(QString const &);
  void value1Changed(QString const &);
};

/***********************************************************************
 *
 * Spin Box
 *
 **********************************************************************/

class FloatMeta;
class QLabel;
class QDoubleSpinBox;
class DoubleSpinGui : public MetaGui
{
  Q_OBJECT
public:
  
  DoubleSpinGui(
    QString const &heading,
    FloatMeta     *meta,
    float          min,
    float          max,
    float          step,
    QGroupBox     *parent = NULL);
  ~DoubleSpinGui() {}

  virtual void apply(QString &modelName);

  void setEnabled(bool enabled);

private:
  FloatMeta      *meta;
  QLabel         *label;
  QDoubleSpinBox *spin;

public slots:
  void valueChanged(double);
};
  
/***********************************************************************
 *
 * Background
 *
 **********************************************************************/

class BackgroundMeta;
class QLabel;
class QPushButton;
class QLineEdit;
class QRadioButton;
class QGroupBox;

class BackgroundGui : public MetaGui
{
  Q_OBJECT
public:

  BackgroundGui(
    BackgroundMeta  *meta,
    QGroupBox       *parent);

  ~BackgroundGui() {}

  BackgroundMeta *meta;

  virtual void apply(QString &modelName);

private:
  QString picture;
  QString color;

  QLabel       *colorLabel;
  QPushButton  *colorButton;
  QLineEdit    *pictureEdit;
  QPushButton  *pictureButton;
  QRadioButton *stretchRadio;
  QRadioButton *tileRadio;
  QGroupBox    *fill;

  void enable();

public slots:
  void typeChange(QString const &);
  void pictureChange(QString const &);
  void browsePicture(bool);
  void browseColor(bool);
  void stretch(bool);
  void tile(bool);
};

/***********************************************************************
 *
 * Border
 *
 **********************************************************************/

class BorderMeta;
class QSpinBox;
class BorderGui : public MetaGui
{
  Q_OBJECT
public:

  BorderGui(
    BorderMeta *meta,
    QGroupBox  *parent);
  ~BorderGui() {}

  virtual void apply(QString &modelName);

private:
  BorderMeta *meta;

  QLineEdit   *thicknessEdit;
  QLabel      *thicknessLabel;
  QLabel      *colorLabel;
  QPushButton *colorButton;
  QSpinBox    *spin;
  QLabel      *spinLabel;

  void enable();

public slots:
  void typeChange(QString const &);
  void thicknessChange(QString const &);
  void browseColor(bool);
  void radiusChange(int);
  void marginXChange(QString const &);
  void marginYChange(QString const &);
};

/***********************************************************************
 *
 * Constrain PLI
 *
 **********************************************************************/

class ConstrainMeta;
class QComboBox;
class ConstrainGui : public MetaGui
{
  Q_OBJECT
public:

  ConstrainGui(
    QString const &heading,
    ConstrainMeta *meta,
    QGroupBox     *parent = NULL);
  ~ConstrainGui() {}

  virtual void apply(QString &modelName);

  void setEnabled(bool enable);

private:
  ConstrainMeta *meta;

  QLabel    *headingLabel;
  QComboBox *combo;
  QLineEdit *value;

  void enable();

public slots:
  void typeChange( QString const &);
  void valueChange(QString const &);
};

/***********************************************************************
 *
 * Divider
 *
 **********************************************************************/

class SepMeta;
class SepGui : public MetaGui
{
  Q_OBJECT
public:

  SepGui(
    SepMeta *meta,
    QGroupBox     *parent);
  ~SepGui() {}

  virtual void apply(QString &modelName);

private:
  SepMeta *meta;
  QLabel  *colorExample;

public slots:
  void thicknessChange(QString const &);
  void browseColor(bool clicked);
  void marginXChange(QString const &);
  void marginYChange(QString const &);
};

/***********************************************************************
 *
 * Resolution
 *
 **********************************************************************/

class ResolutionMeta;
class QIntValidator;
class ResolutionGui : public MetaGui
{
  Q_OBJECT
public:

  ResolutionGui(
    ResolutionMeta *meta,
    QGroupBox      *parent);
  ~ResolutionGui() {}

  virtual void apply(QString &modelName);

private:
  ResolutionMeta *meta;
  ResolutionType  type;
  float           value;
  QLineEdit      *valueEdit;
  QIntValidator  *validator;

  void differences();

public slots:
  void unitsChange(QString const &);
  void valueChange(QString const &);
};

/***********************************************************************
 *
 * Renderer
 *
 **********************************************************************/

class RendererGui : public MetaGui
{
  Q_OBJECT
public:

  RendererGui(QGroupBox *parent = NULL);
  ~RendererGui() {}

  virtual void apply(QString &modelName);

private:
  QComboBox *combo;
  QString    pick;

public slots:
  void typeChange(QString const &);
};

#endif
