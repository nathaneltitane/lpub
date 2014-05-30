/****************************************************************************
** Meta object code from reading C++ file 'placementdialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../placementdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'placementdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PlacementDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      28,   16,   16,   16, 0x08,
      38,   16,   16,   16, 0x08,
      50,   16,   16,   16, 0x08,
      61,   16,   16,   16, 0x08,
      73,   16,   16,   16, 0x08,
      83,   16,   16,   16, 0x08,
      94,   16,   16,   16, 0x08,
     100,   16,   16,   16, 0x08,
     112,   16,   16,   16, 0x08,
     123,   16,   16,   16, 0x08,
     136,   16,   16,   16, 0x08,
     143,   16,   16,   16, 0x08,
     152,   16,   16,   16, 0x08,
     160,   16,   16,   16, 0x08,
     174,   16,   16,   16, 0x08,
     187,   16,   16,   16, 0x08,
     201,   16,   16,   16, 0x08,
     210,   16,   16,   16, 0x08,
     225,   16,   16,   16, 0x08,
     239,   16,   16,   16, 0x08,
     253,   16,   16,   16, 0x08,
     266,   16,   16,   16, 0x08,
     281,   16,   16,   16, 0x08,
     295,   16,   16,   16, 0x08,
     310,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PlacementDialog[] = {
    "PlacementDialog\0\0topLeftO()\0topleft()\0"
    "topcenter()\0topright()\0topRightO()\0"
    "lefttop()\0topLeftI()\0top()\0topRightI()\0"
    "righttop()\0leftcenter()\0left()\0center()\0"
    "right()\0rightcenter()\0leftbottom()\0"
    "bottomLeftI()\0bottom()\0bottomRightI()\0"
    "rightbottom()\0bottomLeftO()\0bottomleft()\0"
    "bottomcenter()\0bottomright()\0"
    "bottomRightO()\0relativeToChanged(int)\0"
};

void PlacementDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PlacementDialog *_t = static_cast<PlacementDialog *>(_o);
        switch (_id) {
        case 0: _t->topLeftO(); break;
        case 1: _t->topleft(); break;
        case 2: _t->topcenter(); break;
        case 3: _t->topright(); break;
        case 4: _t->topRightO(); break;
        case 5: _t->lefttop(); break;
        case 6: _t->topLeftI(); break;
        case 7: _t->top(); break;
        case 8: _t->topRightI(); break;
        case 9: _t->righttop(); break;
        case 10: _t->leftcenter(); break;
        case 11: _t->left(); break;
        case 12: _t->center(); break;
        case 13: _t->right(); break;
        case 14: _t->rightcenter(); break;
        case 15: _t->leftbottom(); break;
        case 16: _t->bottomLeftI(); break;
        case 17: _t->bottom(); break;
        case 18: _t->bottomRightI(); break;
        case 19: _t->rightbottom(); break;
        case 20: _t->bottomLeftO(); break;
        case 21: _t->bottomleft(); break;
        case 22: _t->bottomcenter(); break;
        case 23: _t->bottomright(); break;
        case 24: _t->bottomRightO(); break;
        case 25: _t->relativeToChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PlacementDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PlacementDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PlacementDialog,
      qt_meta_data_PlacementDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PlacementDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PlacementDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PlacementDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PlacementDialog))
        return static_cast<void*>(const_cast< PlacementDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int PlacementDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
