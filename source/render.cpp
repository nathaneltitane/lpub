
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
 * This class encapsulates the external renderers.  For now, this means
 * only ldglite.
 *
 * Please see lpub.h for an overall description of how the files in LPub
 * make up the LPub program.
 *
 ***************************************************************************/

#include <QtGui>
#include <QString>
#include <QStringList>
#include <QPixmap>
#include <QProcess>
#include <QFile>
#include <QTextStream>
#include "render.h"
#include "resolution.h"
#include "meta.h"
#include "math.h"
#include "lpub.h"
#include "lpub_preferences.h"
#include "paths.h"

Render *renderer;

LDGLite ldglite;
LDView  ldview;

QString const Render::getRenderer()
{
  if (renderer == &ldglite) {
    return "LDGLite";
  } else {
    return "LDView";
  }
}

void Render::setRenderer(QString const &name)
{
  if (name == "LDGLite") {
    renderer = &ldglite;
  } else {
    renderer = &ldview;
  }
}

/***************************************************************************
 *
 * The math for zoom factor.  1.0 is true size.
 *
 * 1 LDU is 1/64 of an inch
 *
 * LDGLite produces 72 DPI
 *
 * Camera angle is 0.01
 *
 * What distance do we need to put the camera, given a user chosen DPI,
 * to get zoom factor of 1.0?
 *
 **************************************************************************/

/***************************************************************************
 *
 * LDGLite renderer
 *
 **************************************************************************/

//#define LduDistance 5729.57
#define CA "-ca0.01"

static double pi = 4*atan(1.0);
// the default camera distance for real size
static float LduDistance = 10.0/tan(0.005*pi/180);

float LDGLite::cameraDistance(
  Meta &meta,
  float scale)
{
  float onexone;
  float factor;
  float resolution = meta.LPub.resolution.value();

  // Do the math in pixels

  onexone  = 20*meta.LPub.resolution.ldu(); // size of 1x1 in units
  onexone *= resolution;                  // size of 1x1 in pixels
  onexone *= scale;
  factor   = meta.LPub.page.size.valuePixels(0)/onexone; // in pixels;
  
  return factor*LduDistance; 
}

int LDGLite::renderCsi(
  const QString     &addLine,
  const QStringList &csiParts,
  const QString     &pngName,
        Meta        &meta)
{
  int rc;

  /* Create the CSI DAT file */

  QString ldrName = QDir::currentPath() + "/" + Paths::tmpDir + "/csi.ldr";

  rc = rotateParts(addLine, meta.rotStep, csiParts, ldrName);
  if (rc < 0) {
    return rc;
  }

  /* determine camera distance */

  QString cg = "-cg0,0";
  
  QStringList arguments;

  int cd = cameraDistance(meta,meta.LPub.assem.modelScale.value());

  int width = meta.LPub.page.size.valuePixels(0);
  int height = meta.LPub.page.size.valuePixels(1);

  QString v  = QString("-v%1,%2")   .arg(width)
                                    .arg(height);
  QString o  = QString("-o0,-%1")   .arg(height/6);
  QString mf = QString("-mF%1")     .arg(pngName);
  
  int lineThickness = resolution()/150+0.5;
  if (lineThickness == 0) {
    lineThickness = 1;
  }
                                    // ldglite always deals in 72 DPI
  QString w  = QString("-W%1")      .arg(lineThickness);

  cg = QString("-cg0.0,0.0,%1") .arg(cd);

  arguments << "-l3";
  arguments << "-i2";
  arguments << CA;
  arguments << cg;
  arguments << "-J";
  arguments << v;
  arguments << o;
  arguments << w;
  arguments << "-q";

  QStringList list;
  list = meta.LPub.assem.ldgliteParms.value().split("\\s+");
  for (int i = 0; i < list.size(); i++) {
    if (list[i] != "" && list[i] != " ") {
      arguments << list[i];
    }
  }

  arguments << mf;
  arguments << ldrName;
  
  QProcess    ldglite;
  QStringList env = QProcess::systemEnvironment();
  env << "LDRAWDIR=" + Preferences::ldrawPath;
  ldglite.setEnvironment(env);
  ldglite.setWorkingDirectory(QDir::currentPath()+"/"+Paths::tmpDir);
  ldglite.setStandardErrorFile(QDir::currentPath() + "/stderr");
  ldglite.setStandardOutputFile(QDir::currentPath() + "/stdout");
  ldglite.start(Preferences::ldgliteExe,arguments);
  if ( ! ldglite.waitForFinished(5*60*1000)) {
    if (ldglite.exitCode() != 0) {
      QByteArray status = ldglite.readAll();
      QString str;
      str.append(status);
      QMessageBox::warning(NULL,
                           QMessageBox::tr("LPub"),
                           QMessageBox::tr("LDGlite failed\n%1") .arg(str));
      return -1;
    }
  }
  QFile::remove(ldrName);
  return 0;
}

  
int LDGLite::renderPli(
  const QString &ldrName,
  const QString &pngName,
  Meta    &meta,
  bool     bom)
{
  int width  = meta.LPub.page.size.valuePixels(0);
  int height = meta.LPub.page.size.valuePixels(1);
  
  /* determine camera distance */

  PliMeta &pliMeta = bom ? meta.LPub.bom : meta.LPub.pli;

  int cd = cameraDistance(meta,pliMeta.modelScale.value());

  QString cg = QString("-cg%1,%2,%3") .arg(pliMeta.angle.value(0))
                                      .arg(pliMeta.angle.value(1))
                                      .arg(cd);

  QString v  = QString("-v%1,%2")   .arg(width)
                                    .arg(height);
  QString o  = QString("-o0,-%1")   .arg(height/6);
  QString mf = QString("-mF%1")     .arg(pngName);
                                    // ldglite always deals in 72 DPI
  QString w  = QString("-W%1")      .arg(int(resolution()/72.0+0.5));

  QStringList arguments;
  arguments << "-l3";
  arguments << "-i2";
  arguments << CA;
  arguments << cg;
  arguments << "-J";
  arguments << v;
  arguments << o;
  arguments << w;
  arguments << "-q";

  QStringList list;
  list = meta.LPub.pli.ldgliteParms.value().split("\\s+");
  for (int i = 0; i < list.size(); i++) {
	  if (list[i] != "" && list[i] != " ") {
      arguments << list[i];
	  }
  }
  arguments << mf;
  arguments << ldrName;
  
  QProcess    ldglite;
  QStringList env = QProcess::systemEnvironment();
  env << "LDRAWDIR=" + Preferences::ldrawPath;
  ldglite.setEnvironment(env);  
  ldglite.setWorkingDirectory(QDir::currentPath());
  ldglite.setStandardErrorFile(QDir::currentPath() + "/stderr");
  ldglite.setStandardOutputFile(QDir::currentPath() + "/stdout");
  ldglite.start(Preferences::ldgliteExe,arguments);
  if (! ldglite.waitForFinished()) {
    if (ldglite.exitCode()) {
      QByteArray status = ldglite.readAll();
      QString str;
      str.append(status);
      QMessageBox::warning(NULL,
                           QMessageBox::tr("LPub"),
                           QMessageBox::tr("LDGlite failed\n%1") .arg(str));
      return -1;
    }
  }
  return 0;
}


/***************************************************************************
 *
 * LDView renderer
 *                                  6x6                    5990
 *      LDView               LDView    LDGLite       LDView
 * 0.1    8x5     8x6         32x14    40x19  0.25  216x150    276x191  0.28
 * 0.2   14x10   16x10                              430x298    552x381
 * 0.3   20x14   20x15                              644x466    824x571
 * 0.4   28x18   28x19                              859x594   1100x762
 * 0.5   34x22   36x22                             1074x744   1376x949  0.28
 * 0.6   40x27   40x28                             1288x892
 * 0.7   46x31   48x32                            1502x1040
 * 0.8   54x35   56x37                          
 * 0.9   60x40   60x41
 * 1.0   66x44   68x46       310x135  400x175 0.29 
 * 1.1   72x48
 * 1.2   80x53
 * 1.3   86x57
 * 1.4   92x61
 * 1.5   99x66
 * 1.6  106x70
 * 2.0  132x87  132x90       620x270  796x348 0.28
 * 3.0  197x131 200x134      930x404 1169x522
 * 4.0  262x174 268x178     1238x539 1592x697 0.29
 * 5.0  328x217 332x223     1548x673
 * 
 *
 **************************************************************************/

float LDView::cameraDistance(
  Meta &meta,
  float scale)
{
  float onexone;
  float factor;

  // Do the math in pixels

  onexone  = 20*meta.LPub.resolution.ldu(); // size of 1x1 in units
  onexone *= meta.LPub.resolution.value();  // size of 1x1 in pixels
  onexone *= scale;
  factor   = (meta.LPub.page.size.valuePixels(0)*0.775)/onexone; // in pixels;
  
  return factor*LduDistance; 
}

int LDView::renderCsi(
  const QString     &addLine,
  const QStringList &csiParts,
  const QString     &pngName,
        Meta        &meta)
{
  int rc;

  /* Create the CSI DAT file */

  QString ldrName = QDir::currentPath() + "/" + Paths::tmpDir + "/csi.ldr";

  rc = rotateParts(addLine,meta.rotStep, csiParts, ldrName);

  if (rc < 0) {
    return rc;
  }

  /* determine camera distance */
  
  QStringList arguments;

  int cd = cameraDistance(meta,meta.LPub.assem.modelScale.value())*1700/1000;
  int width = meta.LPub.page.size.valuePixels(0);
  int height = meta.LPub.page.size.valuePixels(1);

  QString w  = QString("-SaveWidth=%1") .arg(width);
  QString h  = QString("-SaveHeight=%1") .arg(height);
  QString s  = QString("-SaveSnapShot=%1") .arg(pngName);

  QString cg = QString("-cg0.0,0.0,%1") .arg(cd);

  arguments << CA;
  arguments << cg;
  arguments << "-SaveAlpha=1";
  arguments << "-AutoCrop=1";
  arguments << "-ShowHighlightLines=1";
  arguments << "-ConditionalHighlights=1";
  arguments << "-SaveZoomToFit=0";
  arguments << "-SubduedLighting=1";
  arguments << "-UseSpecular=0";
  arguments << "-LightVector=0,1,1";
  arguments << "-SaveActualSize=0";
  arguments << w;
  arguments << h;
  arguments << s;

  QStringList list;
  list = meta.LPub.assem.ldviewParms.value().split("\\s+");
  for (int i = 0; i < list.size(); i++) {
    if (list[i] != "" && list[i] != " ") {
      arguments << list[i];
    }
  }
  arguments << ldrName;
  
  QProcess    ldview;
  ldview.setEnvironment(QProcess::systemEnvironment());
  ldview.setWorkingDirectory(QDir::currentPath()+"/"+Paths::tmpDir);
  ldview.start(Preferences::ldviewExe,arguments);

  if ( ! ldview.waitForFinished(5*60*1000)) {
    if (ldview.exitCode() != 0 || 1) {
      QByteArray status = ldview.readAll();
      QString str;
      str.append(status);
      QMessageBox::warning(NULL,
                           QMessageBox::tr("LPub"),
                           QMessageBox::tr("LDView failed\n%1") .arg(str));
      return -1;
    }
  }
  //QFile::remove(ldrName);
  return 0;
}

  
int LDView::renderPli(
  const QString &ldrName,
  const QString &pngName,
  Meta    &meta,
  bool     bom)
{
  int width  = meta.LPub.page.size.valuePixels(0);
  int height = meta.LPub.page.size.valuePixels(1);
  
  QFileInfo fileInfo(ldrName);
  
  if ( ! fileInfo.exists()) {
    return -1;
  }

  /* determine camera distance */

  PliMeta &pliMeta = bom ? meta.LPub.bom : meta.LPub.pli;
  
  int cd = cameraDistance(meta,pliMeta.modelScale.value())*1700/1000;

  QString cg = QString("-cg%1,%2,%3") .arg(pliMeta.angle.value(0))
                                      .arg(pliMeta.angle.value(1))
                                      .arg(cd);
  QString w  = QString("-SaveWidth=%1")  .arg(width);
  QString h  = QString("-SaveHeight=%1") .arg(height);
  QString s  = QString("-SaveSnapShot=%1") .arg(pngName);

  QStringList arguments;
  arguments << CA;
  arguments << cg;
  arguments << "-SaveAlpha=1";
  arguments << "-AutoCrop=1";
  arguments << "-ShowHighlightLines=1";
  arguments << "-ConditionalHighlights=1";
  arguments << "-SaveZoomToFit=0";
  arguments << "-SubduedLighting=1";
  arguments << "-UseSpecular=0";
  arguments << "-LightVector=0,1,1";
  arguments << "-SaveActualSize=0";
  arguments << w;
  arguments << h;
  arguments << s;

  QStringList list;
  list = meta.LPub.pli.ldviewParms.value().split("\\s+");
  for (int i = 0; i < list.size(); i++) {
    if (list[i] != "" && list[i] != " ") {
      arguments << list[i];
    }
  }
  arguments << ldrName;

  QProcess    ldview;
  ldview.setEnvironment(QProcess::systemEnvironment());
  ldview.setWorkingDirectory(QDir::currentPath());
  ldview.start(Preferences::ldviewExe,arguments);
  if ( ! ldview.waitForFinished()) {
    if (ldview.exitCode() != 0) {
      QByteArray status = ldview.readAll();
      QString str;
      str.append(status);
      QMessageBox::warning(NULL,
                           QMessageBox::tr("LPub"),
                           QMessageBox::tr("LDView failed\n%1") .arg(str));
      return -1;
    }
  }
  return 0;
}
