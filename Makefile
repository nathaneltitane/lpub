#############################################################################
# Makefile for building: lpub
# Generated by qmake (2.01a) (Qt 4.8.6) on: Thu May 29 21:41:12 2014
# Project:  lpub.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt4/bin/qmake -o Makefile lpub.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -Imoc -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = objs/

####### Files

SOURCES       = assemglobals.cpp \
		backgrounddialog.cpp \
		backgrounditem.cpp \
		borderdialog.cpp \
		callout.cpp \
		calloutbackgrounditem.cpp \
		calloutglobals.cpp \
		color.cpp \
		commands.cpp \
		commonmenus.cpp \
		csiitem.cpp \
		dependencies.cpp \
		dividerdialog.cpp \
		editwindow.cpp \
		formatpage.cpp \
		highlighter.cpp \
		ldrawfiles.cpp \
		lpub.cpp \
		lpub_preferences.cpp \
		main.cpp \
		meta.cpp \
		metagui.cpp \
		metaitem.cpp \
		multistepglobals.cpp \
		numberitem.cpp \
		openclose.cpp \
		pagebackgrounditem.cpp \
		pageglobals.cpp \
		pairdialog.cpp \
		partslist.cpp \
		paths.cpp \
		placement.cpp \
		placementdialog.cpp \
		pli.cpp \
		pliconstraindialog.cpp \
		pliglobals.cpp \
		pointeritem.cpp \
		preferencesdialog.cpp \
		printpdf.cpp \
		projectglobals.cpp \
		range.cpp \
		range_element.cpp \
		ranges.cpp \
		ranges_element.cpp \
		ranges_item.cpp \
		render.cpp \
		resize.cpp \
		resolution.cpp \
		rotate.cpp \
		scaledialog.cpp \
		step.cpp \
		traverse.cpp \
		undoredo.cpp \
		textitem.cpp moc/moc_backgrounddialog.cpp \
		moc/moc_borderdialog.cpp \
		moc/moc_dividerdialog.cpp \
		moc/moc_editwindow.cpp \
		moc/moc_globals.cpp \
		moc/moc_highlighter.cpp \
		moc/moc_lpub.cpp \
		moc/moc_metagui.cpp \
		moc/moc_pairdialog.cpp \
		moc/moc_placementdialog.cpp \
		moc/moc_pliconstraindialog.cpp \
		moc/moc_preferencesdialog.cpp \
		moc/moc_scaledialog.cpp \
		rcc/qrc_lpub.cpp
OBJECTS       = objs/assemglobals.o \
		objs/backgrounddialog.o \
		objs/backgrounditem.o \
		objs/borderdialog.o \
		objs/callout.o \
		objs/calloutbackgrounditem.o \
		objs/calloutglobals.o \
		objs/color.o \
		objs/commands.o \
		objs/commonmenus.o \
		objs/csiitem.o \
		objs/dependencies.o \
		objs/dividerdialog.o \
		objs/editwindow.o \
		objs/formatpage.o \
		objs/highlighter.o \
		objs/ldrawfiles.o \
		objs/lpub.o \
		objs/lpub_preferences.o \
		objs/main.o \
		objs/meta.o \
		objs/metagui.o \
		objs/metaitem.o \
		objs/multistepglobals.o \
		objs/numberitem.o \
		objs/openclose.o \
		objs/pagebackgrounditem.o \
		objs/pageglobals.o \
		objs/pairdialog.o \
		objs/partslist.o \
		objs/paths.o \
		objs/placement.o \
		objs/placementdialog.o \
		objs/pli.o \
		objs/pliconstraindialog.o \
		objs/pliglobals.o \
		objs/pointeritem.o \
		objs/preferencesdialog.o \
		objs/printpdf.o \
		objs/projectglobals.o \
		objs/range.o \
		objs/range_element.o \
		objs/ranges.o \
		objs/ranges_element.o \
		objs/ranges_item.o \
		objs/render.o \
		objs/resize.o \
		objs/resolution.o \
		objs/rotate.o \
		objs/scaledialog.o \
		objs/step.o \
		objs/traverse.o \
		objs/undoredo.o \
		objs/textitem.o \
		objs/moc_backgrounddialog.o \
		objs/moc_borderdialog.o \
		objs/moc_dividerdialog.o \
		objs/moc_editwindow.o \
		objs/moc_globals.o \
		objs/moc_highlighter.o \
		objs/moc_lpub.o \
		objs/moc_metagui.o \
		objs/moc_pairdialog.o \
		objs/moc_placementdialog.o \
		objs/moc_pliconstraindialog.o \
		objs/moc_preferencesdialog.o \
		objs/moc_scaledialog.o \
		objs/qrc_lpub.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		lpub.pro
QMAKE_TARGET  = lpub
DESTDIR       = 
TARGET        = lpub

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_preferences.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: lpub.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile lpub.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile lpub.pro

dist: 
	@$(CHK_DIR_EXISTS) objs/lpub1.0.0 || $(MKDIR) objs/lpub1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) objs/lpub1.0.0/ && $(COPY_FILE) --parents backgrounddialog.h backgrounditem.h borderdialog.h callout.h calloutbackgrounditem.h color.h commands.h commonmenus.h csiitem.h dependencies.h dividerdialog.h editwindow.h globals.h highlighter.h ldrawfiles.h lpub.h lpub_preferences.h meta.h metagui.h metaitem.h metatypes.h name.h numberitem.h pagebackgrounditem.h pairdialog.h partslist.h paths.h placement.h placementdialog.h pli.h pliconstraindialog.h pointer.h pointeritem.h preferencesdialog.h range.h range_element.h ranges.h ranges_element.h ranges_item.h render.h reserve.h resize.h resolution.h scaledialog.h step.h where.h textitem.h objs/lpub1.0.0/ && $(COPY_FILE) --parents lpub.qrc objs/lpub1.0.0/ && $(COPY_FILE) --parents assemglobals.cpp backgrounddialog.cpp backgrounditem.cpp borderdialog.cpp callout.cpp calloutbackgrounditem.cpp calloutglobals.cpp color.cpp commands.cpp commonmenus.cpp csiitem.cpp dependencies.cpp dividerdialog.cpp editwindow.cpp formatpage.cpp highlighter.cpp ldrawfiles.cpp lpub.cpp lpub_preferences.cpp main.cpp meta.cpp metagui.cpp metaitem.cpp multistepglobals.cpp numberitem.cpp openclose.cpp pagebackgrounditem.cpp pageglobals.cpp pairdialog.cpp partslist.cpp paths.cpp placement.cpp placementdialog.cpp pli.cpp pliconstraindialog.cpp pliglobals.cpp pointeritem.cpp preferencesdialog.cpp printpdf.cpp projectglobals.cpp range.cpp range_element.cpp ranges.cpp ranges_element.cpp ranges_item.cpp render.cpp resize.cpp resolution.cpp rotate.cpp scaledialog.cpp step.cpp traverse.cpp undoredo.cpp textitem.cpp objs/lpub1.0.0/ && $(COPY_FILE) --parents preferences.ui objs/lpub1.0.0/ && (cd `dirname objs/lpub1.0.0` && $(TAR) lpub1.0.0.tar lpub1.0.0 && $(COMPRESS) lpub1.0.0.tar) && $(MOVE) `dirname objs/lpub1.0.0`/lpub1.0.0.tar.gz . && $(DEL_FILE) -r objs/lpub1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc/moc_backgrounddialog.cpp moc/moc_borderdialog.cpp moc/moc_dividerdialog.cpp moc/moc_editwindow.cpp moc/moc_globals.cpp moc/moc_highlighter.cpp moc/moc_lpub.cpp moc/moc_metagui.cpp moc/moc_pairdialog.cpp moc/moc_placementdialog.cpp moc/moc_pliconstraindialog.cpp moc/moc_preferencesdialog.cpp moc/moc_scaledialog.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc/moc_backgrounddialog.cpp moc/moc_borderdialog.cpp moc/moc_dividerdialog.cpp moc/moc_editwindow.cpp moc/moc_globals.cpp moc/moc_highlighter.cpp moc/moc_lpub.cpp moc/moc_metagui.cpp moc/moc_pairdialog.cpp moc/moc_placementdialog.cpp moc/moc_pliconstraindialog.cpp moc/moc_preferencesdialog.cpp moc/moc_scaledialog.cpp
moc/moc_backgrounddialog.cpp: meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		backgrounddialog.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) backgrounddialog.h -o moc/moc_backgrounddialog.cpp

moc/moc_borderdialog.cpp: meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		borderdialog.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) borderdialog.h -o moc/moc_borderdialog.cpp

moc/moc_dividerdialog.cpp: meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		dividerdialog.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) dividerdialog.h -o moc/moc_dividerdialog.cpp

moc/moc_editwindow.cpp: editwindow.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) editwindow.h -o moc/moc_editwindow.cpp

moc/moc_globals.cpp: globals.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) globals.h -o moc/moc_globals.cpp

moc/moc_highlighter.cpp: highlighter.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) highlighter.h -o moc/moc_highlighter.cpp

moc/moc_lpub.cpp: color.h \
		partslist.h \
		ranges.h \
		pli.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		placement.h \
		metaitem.h \
		backgrounditem.h \
		name.h \
		resize.h \
		ldrawfiles.h \
		lpub.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) lpub.h -o moc/moc_lpub.cpp

moc/moc_metagui.cpp: resolution.h \
		metatypes.h \
		metagui.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) metagui.h -o moc/moc_metagui.cpp

moc/moc_pairdialog.cpp: meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		pairdialog.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) pairdialog.h -o moc/moc_pairdialog.cpp

moc/moc_placementdialog.cpp: metatypes.h \
		placementdialog.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) placementdialog.h -o moc/moc_placementdialog.cpp

moc/moc_pliconstraindialog.cpp: meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		pliconstraindialog.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) pliconstraindialog.h -o moc/moc_pliconstraindialog.cpp

moc/moc_preferencesdialog.cpp: ui_preferences.h \
		preferencesdialog.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) preferencesdialog.h -o moc/moc_preferencesdialog.cpp

moc/moc_scaledialog.cpp: meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		scaledialog.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) scaledialog.h -o moc/moc_scaledialog.cpp

compiler_rcc_make_all: rcc/qrc_lpub.cpp
compiler_rcc_clean:
	-$(DEL_FILE) rcc/qrc_lpub.cpp
rcc/qrc_lpub.cpp: lpub.qrc \
		images/editredo.png \
		images/fitVisible.png \
		images/open.png \
		images/editundo.png \
		images/fitPage.png \
		images/prev.png \
		images/redraw.png \
		images/paste.png \
		images/save.png \
		images/next.png \
		images/first.png \
		images/zoomout.png \
		images/pdf_logo.png \
		images/copy.png \
		images/cut.png \
		images/last.png \
		images/fitWidth.png \
		images/actual.png \
		images/zoomin.png
	/usr/lib/x86_64-linux-gnu/qt4/bin/rcc -name lpub lpub.qrc -o rcc/qrc_lpub.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_preferences.h
compiler_uic_clean:
	-$(DEL_FILE) ui_preferences.h
ui_preferences.h: preferences.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic preferences.ui -o ui_preferences.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

objs/assemglobals.o: assemglobals.cpp globals.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		metaitem.h \
		metagui.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/assemglobals.o assemglobals.cpp

objs/backgrounddialog.o: backgrounddialog.cpp backgrounddialog.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		metagui.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/backgrounddialog.o backgrounddialog.cpp

objs/backgrounditem.o: backgrounditem.cpp backgrounditem.h \
		placement.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		metaitem.h \
		color.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/backgrounditem.o backgrounditem.cpp

objs/borderdialog.o: borderdialog.cpp borderdialog.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		metagui.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/borderdialog.o borderdialog.cpp

objs/callout.o: callout.cpp callout.h \
		ranges.h \
		pli.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		placement.h \
		metaitem.h \
		backgrounditem.h \
		name.h \
		resize.h \
		numberitem.h \
		calloutbackgrounditem.h \
		pointer.h \
		pointeritem.h \
		range.h \
		ranges_element.h \
		step.h \
		range_element.h \
		csiitem.h \
		lpub.h \
		color.h \
		partslist.h \
		ldrawfiles.h \
		placementdialog.h \
		commonmenus.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/callout.o callout.cpp

objs/calloutbackgrounditem.o: calloutbackgrounditem.cpp callout.h \
		ranges.h \
		pli.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		placement.h \
		metaitem.h \
		backgrounditem.h \
		name.h \
		resize.h \
		numberitem.h \
		calloutbackgrounditem.h \
		pointer.h \
		pointeritem.h \
		lpub.h \
		color.h \
		partslist.h \
		ldrawfiles.h \
		commonmenus.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/calloutbackgrounditem.o calloutbackgrounditem.cpp

objs/calloutglobals.o: calloutglobals.cpp globals.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		metagui.h \
		metaitem.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/calloutglobals.o calloutglobals.cpp

objs/color.o: color.cpp color.h \
		lpub_preferences.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/color.o color.cpp

objs/commands.o: commands.cpp commands.h \
		where.h \
		ldrawfiles.h \
		lpub.h \
		color.h \
		partslist.h \
		ranges.h \
		pli.h \
		meta.h \
		metatypes.h \
		resolution.h \
		placement.h \
		metaitem.h \
		backgrounditem.h \
		name.h \
		resize.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/commands.o commands.cpp

objs/commonmenus.o: commonmenus.cpp commonmenus.h \
		metatypes.h \
		placement.h \
		meta.h \
		where.h \
		resolution.h \
		metaitem.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/commonmenus.o commonmenus.cpp

objs/csiitem.o: csiitem.cpp lpub.h \
		color.h \
		partslist.h \
		ranges.h \
		pli.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		placement.h \
		metaitem.h \
		backgrounditem.h \
		name.h \
		resize.h \
		ldrawfiles.h \
		step.h \
		range_element.h \
		csiitem.h \
		callout.h \
		numberitem.h \
		ranges_element.h \
		calloutbackgrounditem.h \
		commonmenus.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/csiitem.o csiitem.cpp

objs/dependencies.o: dependencies.cpp dependencies.h \
		lpub.h \
		color.h \
		partslist.h \
		ranges.h \
		pli.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		placement.h \
		metaitem.h \
		backgrounditem.h \
		name.h \
		resize.h \
		ldrawfiles.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/dependencies.o dependencies.cpp

objs/dividerdialog.o: dividerdialog.cpp dividerdialog.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		metagui.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/dividerdialog.o dividerdialog.cpp

objs/editwindow.o: editwindow.cpp editwindow.h \
		highlighter.h \
		ldrawfiles.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/editwindow.o editwindow.cpp

objs/formatpage.o: formatpage.cpp callout.h \
		ranges.h \
		pli.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		placement.h \
		metaitem.h \
		backgrounditem.h \
		name.h \
		resize.h \
		numberitem.h \
		lpub.h \
		color.h \
		partslist.h \
		ldrawfiles.h \
		range.h \
		ranges_element.h \
		step.h \
		range_element.h \
		csiitem.h \
		pagebackgrounditem.h \
		calloutbackgrounditem.h \
		textitem.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/formatpage.o formatpage.cpp

objs/highlighter.o: highlighter.cpp highlighter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/highlighter.o highlighter.cpp

objs/ldrawfiles.o: ldrawfiles.cpp ldrawfiles.h \
		name.h \
		paths.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/ldrawfiles.o ldrawfiles.cpp

objs/lpub.o: lpub.cpp lpub.h \
		color.h \
		partslist.h \
		ranges.h \
		pli.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		placement.h \
		metaitem.h \
		backgrounditem.h \
		name.h \
		resize.h \
		ldrawfiles.h \
		editwindow.h \
		paths.h \
		globals.h \
		lpub_preferences.h \
		render.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/lpub.o lpub.cpp

objs/lpub_preferences.o: lpub_preferences.cpp lpub_preferences.h \
		render.h \
		ui_preferences.h \
		preferencesdialog.h \
		name.h \
		resolution.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/lpub_preferences.o lpub_preferences.cpp

objs/main.o: main.cpp lpub_preferences.h \
		lpub.h \
		color.h \
		partslist.h \
		ranges.h \
		pli.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		placement.h \
		metaitem.h \
		backgrounditem.h \
		name.h \
		resize.h \
		ldrawfiles.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/main.o main.cpp

objs/meta.o: meta.cpp meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		lpub.h \
		color.h \
		partslist.h \
		ranges.h \
		pli.h \
		placement.h \
		metaitem.h \
		backgrounditem.h \
		name.h \
		resize.h \
		ldrawfiles.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/meta.o meta.cpp

objs/metagui.o: metagui.cpp metagui.h \
		resolution.h \
		metatypes.h \
		meta.h \
		where.h \
		metaitem.h \
		color.h \
		lpub.h \
		partslist.h \
		ranges.h \
		pli.h \
		placement.h \
		backgrounditem.h \
		name.h \
		resize.h \
		ldrawfiles.h \
		lpub_preferences.h \
		render.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/metagui.o metagui.cpp

objs/metaitem.o: metaitem.cpp metaitem.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		lpub.h \
		color.h \
		partslist.h \
		ranges.h \
		pli.h \
		placement.h \
		backgrounditem.h \
		name.h \
		resize.h \
		ldrawfiles.h \
		placementdialog.h \
		pliconstraindialog.h \
		pairdialog.h \
		scaledialog.h \
		borderdialog.h \
		backgrounddialog.h \
		dividerdialog.h \
		paths.h \
		render.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/metaitem.o metaitem.cpp

objs/multistepglobals.o: multistepglobals.cpp globals.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		metagui.h \
		metaitem.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/multistepglobals.o multistepglobals.cpp

objs/numberitem.o: numberitem.cpp numberitem.h \
		where.h \
		placement.h \
		meta.h \
		metatypes.h \
		resolution.h \
		metaitem.h \
		color.h \
		name.h \
		placementdialog.h \
		commonmenus.h \
		ranges.h \
		pli.h \
		backgrounditem.h \
		resize.h \
		step.h \
		range_element.h \
		csiitem.h \
		callout.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/numberitem.o numberitem.cpp

objs/openclose.o: openclose.cpp lpub.h \
		color.h \
		partslist.h \
		ranges.h \
		pli.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		placement.h \
		metaitem.h \
		backgrounditem.h \
		name.h \
		resize.h \
		ldrawfiles.h \
		lpub_preferences.h \
		editwindow.h \
		paths.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/openclose.o openclose.cpp

objs/pagebackgrounditem.o: pagebackgrounditem.cpp pagebackgrounditem.h \
		backgrounditem.h \
		placement.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		metaitem.h \
		ranges.h \
		pli.h \
		name.h \
		resize.h \
		commonmenus.h \
		ranges_element.h \
		range.h \
		range_element.h \
		step.h \
		csiitem.h \
		callout.h \
		numberitem.h \
		lpub.h \
		color.h \
		partslist.h \
		ldrawfiles.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/pagebackgrounditem.o pagebackgrounditem.cpp

objs/pageglobals.o: pageglobals.cpp globals.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		metaitem.h \
		metagui.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/pageglobals.o pageglobals.cpp

objs/pairdialog.o: pairdialog.cpp pairdialog.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		backgrounddialog.h \
		metagui.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/pairdialog.o pairdialog.cpp

objs/partslist.o: partslist.cpp partslist.h \
		lpub_preferences.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/partslist.o partslist.cpp

objs/paths.o: paths.cpp paths.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/paths.o paths.cpp

objs/placement.o: placement.cpp placement.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		metaitem.h \
		ranges.h \
		pli.h \
		backgrounditem.h \
		name.h \
		resize.h \
		callout.h \
		numberitem.h \
		range.h \
		ranges_element.h \
		step.h \
		range_element.h \
		csiitem.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/placement.o placement.cpp

objs/placementdialog.o: placementdialog.cpp metatypes.h \
		placementdialog.h \
		meta.h \
		where.h \
		resolution.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/placementdialog.o placementdialog.cpp

objs/pli.o: pli.cpp pli.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		placement.h \
		metaitem.h \
		backgrounditem.h \
		name.h \
		resize.h \
		step.h \
		range_element.h \
		csiitem.h \
		callout.h \
		ranges.h \
		numberitem.h \
		render.h \
		paths.h \
		partslist.h \
		ldrawfiles.h \
		placementdialog.h \
		color.h \
		lpub.h \
		commonmenus.h \
		lpub_preferences.h \
		ranges_element.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/pli.o pli.cpp

objs/pliconstraindialog.o: pliconstraindialog.cpp pliconstraindialog.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		metagui.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/pliconstraindialog.o pliconstraindialog.cpp

objs/pliglobals.o: pliglobals.cpp globals.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		metagui.h \
		metaitem.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/pliglobals.o pliglobals.cpp

objs/pointeritem.o: pointeritem.cpp pointeritem.h \
		pointer.h \
		where.h \
		meta.h \
		metatypes.h \
		resolution.h \
		metaitem.h \
		resize.h \
		placement.h \
		lpub.h \
		color.h \
		partslist.h \
		ranges.h \
		pli.h \
		backgrounditem.h \
		name.h \
		ldrawfiles.h \
		callout.h \
		numberitem.h \
		step.h \
		range_element.h \
		csiitem.h \
		range.h \
		ranges_element.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/pointeritem.o pointeritem.cpp

objs/preferencesdialog.o: preferencesdialog.cpp ui_preferences.h \
		preferencesdialog.h \
		lpub_preferences.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/preferencesdialog.o preferencesdialog.cpp

objs/printpdf.o: printpdf.cpp lpub.h \
		color.h \
		partslist.h \
		ranges.h \
		pli.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		placement.h \
		metaitem.h \
		backgrounditem.h \
		name.h \
		resize.h \
		ldrawfiles.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/printpdf.o printpdf.cpp

objs/projectglobals.o: projectglobals.cpp globals.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		metaitem.h \
		metagui.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/projectglobals.o projectglobals.cpp

objs/range.o: range.cpp range.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		ranges_element.h \
		placement.h \
		metaitem.h \
		step.h \
		range_element.h \
		pli.h \
		backgrounditem.h \
		name.h \
		resize.h \
		csiitem.h \
		callout.h \
		ranges.h \
		numberitem.h \
		reserve.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/range.o range.cpp

objs/range_element.o: range_element.cpp ranges_element.h \
		where.h \
		placement.h \
		meta.h \
		metatypes.h \
		resolution.h \
		metaitem.h \
		range_element.h \
		ranges.h \
		pli.h \
		backgrounditem.h \
		name.h \
		resize.h \
		callout.h \
		numberitem.h \
		lpub.h \
		color.h \
		partslist.h \
		ldrawfiles.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/range_element.o range_element.cpp

objs/ranges.o: ranges.cpp ranges.h \
		pli.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		placement.h \
		metaitem.h \
		backgrounditem.h \
		name.h \
		resize.h \
		ranges_item.h \
		range_element.h \
		range.h \
		ranges_element.h \
		step.h \
		csiitem.h \
		callout.h \
		numberitem.h \
		calloutbackgrounditem.h \
		lpub.h \
		color.h \
		partslist.h \
		ldrawfiles.h \
		dividerdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/ranges.o ranges.cpp

objs/ranges_element.o: ranges_element.cpp range_element.h \
		placement.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		metaitem.h \
		ranges_element.h \
		ranges.h \
		pli.h \
		backgrounditem.h \
		name.h \
		resize.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/ranges_element.o ranges_element.cpp

objs/ranges_item.o: ranges_item.cpp ranges.h \
		pli.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		placement.h \
		metaitem.h \
		backgrounditem.h \
		name.h \
		resize.h \
		ranges_item.h \
		range.h \
		ranges_element.h \
		step.h \
		range_element.h \
		csiitem.h \
		callout.h \
		numberitem.h \
		color.h \
		commonmenus.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/ranges_item.o ranges_item.cpp

objs/render.o: render.cpp render.h \
		resolution.h \
		meta.h \
		where.h \
		metatypes.h \
		lpub.h \
		color.h \
		partslist.h \
		ranges.h \
		pli.h \
		placement.h \
		metaitem.h \
		backgrounditem.h \
		name.h \
		resize.h \
		ldrawfiles.h \
		lpub_preferences.h \
		paths.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/render.o render.cpp

objs/resize.o: resize.cpp resize.h \
		placement.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		metaitem.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/resize.o resize.cpp

objs/resolution.o: resolution.cpp resolution.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/resolution.o resolution.cpp

objs/rotate.o: rotate.cpp render.h \
		ldrawfiles.h \
		lpub.h \
		color.h \
		partslist.h \
		ranges.h \
		pli.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		placement.h \
		metaitem.h \
		backgrounditem.h \
		name.h \
		resize.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/rotate.o rotate.cpp

objs/scaledialog.o: scaledialog.cpp scaledialog.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		metagui.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/scaledialog.o scaledialog.cpp

objs/step.o: step.cpp lpub.h \
		color.h \
		partslist.h \
		ranges.h \
		pli.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		placement.h \
		metaitem.h \
		backgrounditem.h \
		name.h \
		resize.h \
		ldrawfiles.h \
		step.h \
		range_element.h \
		csiitem.h \
		callout.h \
		numberitem.h \
		range.h \
		ranges_element.h \
		render.h \
		calloutbackgrounditem.h \
		pointer.h \
		pointeritem.h \
		dependencies.h \
		paths.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/step.o step.cpp

objs/traverse.o: traverse.cpp lpub.h \
		color.h \
		partslist.h \
		ranges.h \
		pli.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		placement.h \
		metaitem.h \
		backgrounditem.h \
		name.h \
		resize.h \
		ldrawfiles.h \
		callout.h \
		numberitem.h \
		pointer.h \
		range.h \
		ranges_element.h \
		reserve.h \
		range_element.h \
		step.h \
		csiitem.h \
		paths.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/traverse.o traverse.cpp

objs/undoredo.o: undoredo.cpp lpub.h \
		color.h \
		partslist.h \
		ranges.h \
		pli.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		placement.h \
		metaitem.h \
		backgrounditem.h \
		name.h \
		resize.h \
		ldrawfiles.h \
		commands.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/undoredo.o undoredo.cpp

objs/textitem.o: textitem.cpp textitem.h \
		placement.h \
		meta.h \
		where.h \
		metatypes.h \
		resolution.h \
		metaitem.h \
		lpub.h \
		color.h \
		partslist.h \
		ranges.h \
		pli.h \
		backgrounditem.h \
		name.h \
		resize.h \
		ldrawfiles.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/textitem.o textitem.cpp

objs/moc_backgrounddialog.o: moc/moc_backgrounddialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/moc_backgrounddialog.o moc/moc_backgrounddialog.cpp

objs/moc_borderdialog.o: moc/moc_borderdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/moc_borderdialog.o moc/moc_borderdialog.cpp

objs/moc_dividerdialog.o: moc/moc_dividerdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/moc_dividerdialog.o moc/moc_dividerdialog.cpp

objs/moc_editwindow.o: moc/moc_editwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/moc_editwindow.o moc/moc_editwindow.cpp

objs/moc_globals.o: moc/moc_globals.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/moc_globals.o moc/moc_globals.cpp

objs/moc_highlighter.o: moc/moc_highlighter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/moc_highlighter.o moc/moc_highlighter.cpp

objs/moc_lpub.o: moc/moc_lpub.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/moc_lpub.o moc/moc_lpub.cpp

objs/moc_metagui.o: moc/moc_metagui.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/moc_metagui.o moc/moc_metagui.cpp

objs/moc_pairdialog.o: moc/moc_pairdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/moc_pairdialog.o moc/moc_pairdialog.cpp

objs/moc_placementdialog.o: moc/moc_placementdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/moc_placementdialog.o moc/moc_placementdialog.cpp

objs/moc_pliconstraindialog.o: moc/moc_pliconstraindialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/moc_pliconstraindialog.o moc/moc_pliconstraindialog.cpp

objs/moc_preferencesdialog.o: moc/moc_preferencesdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/moc_preferencesdialog.o moc/moc_preferencesdialog.cpp

objs/moc_scaledialog.o: moc/moc_scaledialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/moc_scaledialog.o moc/moc_scaledialog.cpp

objs/qrc_lpub.o: rcc/qrc_lpub.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/qrc_lpub.o rcc/qrc_lpub.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
