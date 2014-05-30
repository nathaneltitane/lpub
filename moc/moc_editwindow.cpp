/****************************************************************************
** Meta object code from reading C++ file 'editwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EditWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      46,   12,   11,   11, 0x05,
      86,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     131,   98,   11,   11, 0x08,
     159,   11,   11,   11, 0x08,
     178,  168,   11,   11, 0x0a,
     210,   11,   11,   11, 0x0a,
     236,  224,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_EditWindow[] = {
    "EditWindow\0\0,position,charsRemoved,charsAdded\0"
    "contentsChange(QString,int,int,QString)\0"
    "redrawSig()\0position,charsRemoved,charsAdded\0"
    "contentsChange(int,int,int)\0redraw()\0"
    ",fileName\0displayFile(LDrawFile*,QString)\0"
    "showLine(int)\0op,moveMode\0"
    "pageUpDown(QTextCursor::MoveOperation,QTextCursor::MoveMode)\0"
};

void EditWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EditWindow *_t = static_cast<EditWindow *>(_o);
        switch (_id) {
        case 0: _t->contentsChange((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 1: _t->redrawSig(); break;
        case 2: _t->contentsChange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->redraw(); break;
        case 4: _t->displayFile((*reinterpret_cast< LDrawFile*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->showLine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->pageUpDown((*reinterpret_cast< QTextCursor::MoveOperation(*)>(_a[1])),(*reinterpret_cast< QTextCursor::MoveMode(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EditWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EditWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_EditWindow,
      qt_meta_data_EditWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EditWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EditWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EditWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EditWindow))
        return static_cast<void*>(const_cast< EditWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int EditWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void EditWindow::contentsChange(const QString & _t1, int _t2, int _t3, const QString & _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EditWindow::redrawSig()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
