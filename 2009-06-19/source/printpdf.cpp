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
#include <QPainter>
#include <QPrinter>
#include <QFileInfo>
#include <QFileDialog>
#include <QDir>
#include <QString>
#include <QMessageBox>

#include "lpub.h"

struct paperSizes {
  QPrinter::PaperSize paperSize;
  float              width;
  float              height;
} paperSizes[] = {
  { QPrinter::A0,         841, 1189 },
  { QPrinter::A1,         594,  841 },
  { QPrinter::A2,         420,  594 },
  { QPrinter::A3,         297,  420 },
  { QPrinter::A4,         210,  297 },
  { QPrinter::A5,         148,  210 },
  { QPrinter::A6,         105,  148 },
  { QPrinter::A7,          74,  105 },
  { QPrinter::A8,          52,   74 },
  { QPrinter::A9,          37,   52 },
  { QPrinter::B0,        1030, 1456 },
  { QPrinter::B1,         728, 1030 },
  { QPrinter::B10,         32,   45 },
  { QPrinter::B2,         515,  728 },
  { QPrinter::B3,         364,  515 },
  { QPrinter::B4,         257,  364 },
  { QPrinter::B5,         182,  257 },
  { QPrinter::B6,         128,  182 },
  { QPrinter::B7,          91,  128 },
  { QPrinter::B8,          64,   91 },
  { QPrinter::B9,          45,   64 },
  { QPrinter::C5E,        163,  229 },
  { QPrinter::Comm10E,    105,  241 },
  { QPrinter::DLE,        110,  220 },
  { QPrinter::Executive,  191,  254 },
  { QPrinter::Folio,      210,  330 },
  { QPrinter::Legal,      216,  356 },
  { QPrinter::Letter,     216,  279 },
  { QPrinter::Tabloid,    279,  432 },
};

int Gui::bestPaperSizeOrientation(
  float widthMm,
  float heightMm,
  QPrinter::PaperSize &paperSize,
  QPrinter::Orientation &orient)
{
  int   numPaperSizes = sizeof(paperSizes)/sizeof(paperSizes[0]);
  float diffWidth = 1000;
  float diffHeight = 1000;
  int     bestSize = 0;
  
  for (int i = 0; i < numPaperSizes; i++) {
 
    float widthDiff = paperSizes[i].width - widthMm;
    float heightDiff = paperSizes[i].height - heightMm;

    if (widthDiff >= 0  && heightDiff >= 0) {
     if (widthDiff <= diffWidth && heightDiff <= diffHeight) {
       bestSize = i;
       paperSize = paperSizes[i].paperSize;
       orient = QPrinter::Portrait;
       diffWidth = widthDiff;
       diffHeight = heightDiff;
     }
   }
 
   widthDiff = paperSizes[i].height - widthMm;
   heightDiff  = paperSizes[i].width - heightMm;
	
   if (widthDiff >= 0  && heightDiff >= 0) {
     if (widthDiff <= diffWidth && heightDiff <= diffHeight) {
       bestSize = i;
       paperSize = paperSizes[i].paperSize;
       orient = QPrinter::Landscape;
       diffWidth = widthDiff;
       diffHeight = heightDiff;
	    }
	  }
  }
  return bestSize;
}

void Gui::printToFile()
{
  float pageWidth = page.meta.LPub.page.size.value(0);
  float pageHeight = page.meta.LPub.page.size.value(1);

  if (page.meta.LPub.resolution.type() == DPI) {
    // convert to MM
    pageWidth = int(inches2centimeters(pageWidth));
    pageHeight = int(inches2centimeters(pageHeight));
  }
  pageWidth  *= 10;  // convert to mm
  pageHeight *= 10;

  QPrinter::PaperSize paperSize = QPrinter::PaperSize();
  QPrinter::Orientation orientation = QPrinter::Orientation();
  int bestSize;
  bestSize = bestPaperSizeOrientation(pageWidth,pageHeight,paperSize,orientation);

  // Convert closest page size to pixels for bounding rect

  if (orientation == QPrinter::Portrait) {
    pageWidth = paperSizes[bestSize].width/10.0;  // in centimeters
    pageHeight = paperSizes[bestSize].height/10.0; // in centimeters
  } else {
    pageWidth = paperSizes[bestSize].height/10.0;  // in centimeters
    pageHeight = paperSizes[bestSize].width/10.0; // in centimeters
  }

  if (resolutionType() == DPI) {
    pageWidth = centimeters2inches(pageWidth);
    pageHeight = centimeters2inches(pageHeight);
  }

  pageWidth *= resolution();
  pageHeight *= resolution();

  if (resolutionType() == DPCM) {
    pageWidth = centimeters2inches(pageWidth);
    pageHeight = centimeters2inches(pageHeight);
  }

  QFileInfo fileInfo(curFile);
  QString   baseName = fileInfo.baseName();

  QString fileName = QFileDialog::getSaveFileName(
    this,
	  tr("Print File Name"),
	  QDir::currentPath() + "/" + baseName,
	  tr("PDF (*.pdf)\nPDF (*.PDF)"));

  if (fileName == "") {
    return;
  }

  fileInfo.setFile(fileName);

  QString suffix = fileInfo.suffix();
  if (suffix == "") {
    fileName += ".pdf";
  } else if (suffix != ".pdf" && suffix != ".PDF") {
    fileName = fileInfo.path() + "/" + fileInfo.completeBaseName() + ".pdf";
  }

  QPrinter printer(QPrinter::ScreenResolution);
  printer.setOutputFileName(fileName);
  printer.setOrientation(orientation);
  printer.setPaperSize(paperSize);
  printer.setPageMargins(0,0,0,0,QPrinter::Inch);
  printer.setFullPage(true);

  QPainter painter;
  painter.begin(&printer);

  int savePageNumber = displayPageNum;

  QGraphicsScene scene;
  LGraphicsView  view(&scene);

  QRectF boundingRect(0.0,0.0,pageWidth,pageHeight);
  QRect  bounding(0,0,pageWidth,pageHeight);
  view.setMinimumSize(pageWidth,pageHeight);
  view.setMaximumSize(pageWidth,pageHeight);
  view.setGeometry(bounding);
  view.setSceneRect(boundingRect);
  view.setRenderHints(QPainter::Antialiasing | 
					  QPainter::TextAntialiasing |
					  QPainter::SmoothPixmapTransform);

  view.scale(1.0,1.0);
  view.centerOn(boundingRect.center());
  clearPage(&view,&scene);
  
  for (displayPageNum = 1; displayPageNum <= maxPages; displayPageNum++) {

    qApp->processEvents();
	
    drawPage(&view,&scene,true);
    view.render(&painter);
    clearPage(&view,&scene);

    if (maxPages - displayPageNum > 0) {
      printer.newPage();
    }
  }
  painter.end();
  displayPageNum = savePageNumber;
  drawPage(KpageView,KpageScene,false);
}

void Gui::exportAsPng()
{
  QString suffix(".png");
  exportAs(suffix);
}

void Gui::exportAsJpg()
{
  QString suffix(".jpg");
  exportAs(suffix);
}

void Gui::exportAsBmp()
{
  QString suffix(".bmp");
  exportAs(suffix);
}

void Gui::exportAs(QString &suffix)
{
  float pageWidth = page.meta.LPub.page.size.value(0);
  float pageHeight = page.meta.LPub.page.size.value(1);
  if (page.meta.LPub.resolution.type() == DPI) {
    // convert to MM
    pageWidth = int(inches2centimeters(pageWidth)*10);
    pageHeight = int(inches2centimeters(pageHeight)*10);
  }

  QPrinter::PaperSize paperSize = QPrinter::PaperSize();
  QPrinter::Orientation orientation = QPrinter::Orientation();
  int bestSize;
  bestSize = bestPaperSizeOrientation(pageWidth,pageHeight,paperSize,orientation);

  // Convert closest page size to pixels for bounding rect

  if (orientation == QPrinter::Portrait) {
    pageWidth = paperSizes[bestSize].width/10.0;  // in centimeters
    pageHeight = paperSizes[bestSize].height/10.0; // in centimeters
  } else {
    pageWidth = paperSizes[bestSize].height/10.0;  // in centimeters
    pageHeight = paperSizes[bestSize].width/10.0; // in centimeters
  }

  if (resolutionType() == DPI) {
    pageWidth = centimeters2inches(pageWidth);
    pageHeight = centimeters2inches(pageHeight);
  }
  pageWidth *= resolution();
  pageHeight *= resolution();
  if (resolutionType() == DPCM) {
    pageWidth = centimeters2inches(pageWidth);
    pageHeight = centimeters2inches(pageHeight);
  }

  QGraphicsScene scene;
  LGraphicsView  view(&scene);

  int savePageNumber = displayPageNum;

  QFileInfo fileInfo(curFile);
  QString   baseName = fileInfo.baseName();

  //clearPage(KpageView,KpageScene);

  // Strangeness needing to warm up the process?

  QImage image(pageWidth,pageHeight,QImage::Format_ARGB32);

  for (displayPageNum = 1;
       displayPageNum <= maxPages && displayPageNum < 6;
       displayPageNum++) {

    qApp->processEvents();

    QRect  bounding(0,0,pageWidth,pageHeight);
    view.setGeometry(bounding);
    view.setRenderHints(QPainter::Antialiasing |
              QPainter::TextAntialiasing |
              QPainter::SmoothPixmapTransform);
    view.scale(1.0,1.0);
    QRectF boundingRect(0.0,0.0,pageWidth,pageHeight);
    view.centerOn(boundingRect.center());
    drawPage(&view,&scene,true);

    QPainter painter;
    painter.begin(&image);
    view.render(&painter);
    QString pn = QString("%1") .arg(displayPageNum);
    image.save(baseName + "_page_" +pn + suffix);
    painter.end();

    clearPage(&view,&scene);
  }

  for (displayPageNum = 1; displayPageNum <= maxPages; displayPageNum++) {

    qApp->processEvents();

    QRect  bounding(0,0,pageWidth,pageHeight);
    view.setGeometry(bounding);
    view.setRenderHints(QPainter::Antialiasing |
              QPainter::TextAntialiasing |
              QPainter::SmoothPixmapTransform);
    view.scale(1.0,1.0);
    QRectF boundingRect(0.0,0.0,pageWidth,pageHeight);
    view.centerOn(boundingRect.center());
    drawPage(&view,&scene,true);

    QPainter painter;
    painter.begin(&image);
    view.render(&painter);
    QString pn = QString("%1") .arg(displayPageNum);
    image.save(baseName + "_page_" +pn + suffix);
    painter.end();

    clearPage(&view,&scene);
  }
  displayPageNum = savePageNumber;
  drawPage(KpageView,KpageScene,false);
}
