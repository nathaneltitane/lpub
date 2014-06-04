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
  { QPrinter::A0,         841,   1189 },
  { QPrinter::A1,         594,    841 },
  { QPrinter::A2,         420,    594 },
  { QPrinter::A3,         297,    420 },
  { QPrinter::A4,         210,    297 },
  { QPrinter::A5,         148,    210 },
  { QPrinter::A6,         105,    148 },
  { QPrinter::A7,          74,    105 },
  { QPrinter::A8,          52,     74 },
  { QPrinter::A9,          37,     52 },
  { QPrinter::B0,        1030,   1456 },
  { QPrinter::B1,         728,   1030 },
  { QPrinter::B10,         32,     45 },
  { QPrinter::B2,         515,    728 },
  { QPrinter::B3,         364,    515 },
  { QPrinter::B4,         257,    364 },
  { QPrinter::B5,         182,    257 },
  { QPrinter::B6,         128,    182 },
  { QPrinter::B7,          91,    128 },
  { QPrinter::B8,          64,     91 },
  { QPrinter::B9,          45,     64 },
  { QPrinter::B10,         31,     44 },
  { QPrinter::C5E,        163,    229 },
  { QPrinter::Comm10E,    105,    241 },
  { QPrinter::DLE,        110,    220 },
  { QPrinter::Executive,  190.5,  254 },
  { QPrinter::Folio,      210,    330 },
  { QPrinter::Ledger,     431.8,  279.4 },
  { QPrinter::Legal,      215.9,  355.6 },
  { QPrinter::Letter,     215.9,  279.4 },
  { QPrinter::Tabloid,    279.4,  431.8 },
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

void Gui::GetPixelDimensions(float &pixelWidth, float &pixelHeight)
{
	float pageWidthIn, pageHeightIn;

	// only concerned with inches because resolution() reports DPI	
	if (page.meta.LPub.resolution.type() == DPI) {
		pageWidthIn = page.meta.LPub.page.size.value(0);
		pageHeightIn = page.meta.LPub.page.size.value(1);
	} else {
		pageWidthIn = centimeters2inches(page.meta.LPub.page.size.value(0));
		pageHeightIn = centimeters2inches(page.meta.LPub.page.size.value(1));
	}
		
	// pixel dimension are inches * pixels per inch
	pixelWidth = int((pageWidthIn * resolution()) + 0.5);
	pixelHeight = int((pageHeightIn * resolution()) + 0.5);
}


void Gui::GetPagePixelDimensions(float &pagePixelWidth, float &pagePixelHeight, QPrinter::PaperSize &paperSize, QPrinter::Orientation &orientation)
{
	float pageWidthMm, pageHeightMm;
	float pageWidthCm, pageHeightCm;
	float pageWidthIn, pageHeightIn;
	
	if (page.meta.LPub.resolution.type() == DPI) {
		pageWidthIn = page.meta.LPub.page.size.value(0);
		pageHeightIn = page.meta.LPub.page.size.value(1);
		pageWidthCm = inches2centimeters(pageWidthIn);
		pageHeightCm = inches2centimeters(pageHeightIn);
	} else {
		pageWidthCm = page.meta.LPub.page.size.value(0);
		pageHeightCm = page.meta.LPub.page.size.value(1);
		pageWidthIn = centimeters2inches(pageWidthCm);
		pageHeightIn = centimeters2inches(pageHeightCm);
	}
	
  pageWidthMm = pageWidthCm * 10.0;
  pageHeightMm = pageHeightCm * 10.0;
	
	int sizeIndex = bestPaperSizeOrientation(pageWidthMm, pageHeightMm, paperSize, orientation);

	if (orientation == QPrinter::Portrait) {
		pageWidthCm = paperSizes[sizeIndex].width / 10.0;
		pageHeightCm = paperSizes[sizeIndex].height / 10.0;
	} else {
		pageWidthCm = paperSizes[sizeIndex].height / 10.0;
		pageHeightCm = paperSizes[sizeIndex].width / 10.0;
	}
	
	pageWidthIn = centimeters2inches(pageWidthCm);
	pageHeightIn = centimeters2inches(pageHeightCm);
	
	// important: note that pixel dimensions converted back from mm paper sizes may
	// not match GetPixelDimensions. For example, Letter mm dimensions do not *exactly* equal 8.5 x 11
	
	pagePixelWidth = int((pageWidthIn * resolution()) + 0.5);
	pagePixelHeight = int((pageHeightIn * resolution()) + 0.5);	
}

void Gui::printToFile()
{
  // determine location for output file
  QFileInfo fileInfo(curFile);
  QString baseName = fileInfo.baseName();
  QString fileName = QFileDialog::getSaveFileName(
      this,
      tr("Print File Name"),
      QDir::currentPath() + "/" + baseName,
      tr("PDF (*.pdf)\nPDF (*.PDF)"));
  if (fileName == "") {
    return;
  }
  
  // want info about output file now, not model file
  fileInfo.setFile(fileName);
  
  // append proper PDF file extension if needed
  QString suffix = fileInfo.suffix();
  if (suffix == "") {
    fileName += ".pdf";
  } else if (suffix != ".pdf" && suffix != ".PDF") {
    fileName = fileInfo.path() + "/" + fileInfo.completeBaseName() + ".pdf";
  }

  // determine size of output pages, in pixels
  QPrinter::PaperSize paperSize = QPrinter::PaperSize();
  QPrinter::Orientation orientation = QPrinter::Orientation();
  float pageWidthPx, pageHeightPx;
  GetPagePixelDimensions(pageWidthPx, pageHeightPx, paperSize, orientation);

  // create a PDF printer
  QPrinter printer(QPrinter::ScreenResolution);
  //printer.setResolution(resolution());
  printer.setOutputFileName(fileName);
  printer.setOrientation(orientation);
  printer.setPaperSize(paperSize);
  printer.setPageMargins(0,0,0,0,QPrinter::Inch);
  printer.setFullPage(true);
  
  // paint to the printer the scene we view
  QPainter painter;
  painter.begin(&printer);
  QGraphicsScene scene;
  LGraphicsView view(&scene);
  
  // set up the view
  QRectF boundingRect(0.0, 0.0, pageWidthPx, pageHeightPx);
  QRect bounding(0, 0, pageWidthPx, pageHeightPx);
  view.scale(1.0,1.0);
  view.setMinimumSize(pageWidthPx,pageHeightPx);
  view.setMaximumSize(pageWidthPx,pageHeightPx);
  view.setGeometry(bounding);
  view.setSceneRect(boundingRect);
  view.setRenderHints(
      QPainter::Antialiasing | 
      QPainter::TextAntialiasing |
      QPainter::SmoothPixmapTransform);
  view.centerOn(boundingRect.center());
  clearPage(&view,&scene);
  
  int savePageNumber = displayPageNum;
  for (displayPageNum = 1; displayPageNum <= maxPages; displayPageNum++) {

    //qApp->processEvents();

    // render this page
    drawPage(&view,&scene,true);
    scene.setSceneRect(0.0,0.0,pageWidthPx,pageHeightPx);
    scene.render(&painter);
    clearPage(&view,&scene);
    
    // prepare to print another page
    if(displayPageNum < maxPages) {
      printer.newPage();
    }
  }
  
  painter.end();
  
  // return to whatever page we were viewing before output
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
  // determine location to output images
  QFileInfo fileInfo(curFile);
  //QDir initialDirectory = fileInfo.dir();
  QString baseName = fileInfo.baseName();
  QString directoryName = QFileDialog::getExistingDirectory(
      this,
      tr("Save images to folder"), // needs translation! also, include suffix in here
      QDir::currentPath(),
      QFileDialog::ShowDirsOnly);
  if (directoryName == "") {
    return;
  }
  
  // determine size of output image, in pixels
  float pageWidthPx, pageHeightPx;
  GetPixelDimensions(pageWidthPx, pageHeightPx);
  
  // paint to the image the scene we view
  QImage image(pageWidthPx, pageHeightPx, QImage::Format_ARGB32);
  QPainter painter;
  painter.begin(&image);
  QGraphicsScene scene;
  LGraphicsView view(&scene);

  // set up the view  
  QRectF boundingRect(0.0,0.0,pageWidthPx,pageHeightPx);
  QRect  bounding(0,0,pageWidthPx,pageHeightPx);
  view.scale(1.0,1.0);
  view.setMinimumSize(pageWidthPx, pageHeightPx);
  view.setMaximumSize(pageWidthPx, pageHeightPx);
  view.setGeometry(bounding);
  view.setSceneRect(boundingRect);
  view.setRenderHints(
      QPainter::Antialiasing |
      QPainter::TextAntialiasing |
      QPainter::SmoothPixmapTransform);
  view.centerOn(boundingRect.center());
// view.fitInView(boundingRect);
  clearPage(&view, &scene);
    
  // Support transparency for formats that can handle it, but use white for those that can't.
  QColor fill = (suffix.compare(".png", Qt::CaseInsensitive) == 0) ? Qt::transparent :  Qt::white;
  
  int savePageNumber = displayPageNum;  
  for (displayPageNum = 1; displayPageNum <= maxPages; displayPageNum++) {
    
    //qApp->processEvents();
    
    // clear the pixels of the image, just in case the background is
    // transparent or uses a PNG image with transparency. This will
    // prevent rendered pixels from each page layering on top of each
    // other.
    image.fill(fill.Rgb);

    // render this page

    // scene.render instead of view.render resolves "warm up" issue
    drawPage(&view,&scene,false);
    scene.setSceneRect(0.0,0.0,pageWidthPx,pageHeightPx);
    scene.render(&painter);
    clearPage(&view, &scene);    

    // save the image to the selected directory
    // internationalization of "_page_"?
    QString pn = QString("%1") .arg(displayPageNum);
    image.save(directoryName + "/" + baseName + "_page_" + pn + suffix);
  }
  
  painter.end();
  
  // return to whatever page we were viewing before output
  displayPageNum = savePageNumber;
  drawPage(KpageView,KpageScene,false);
}
