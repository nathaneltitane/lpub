/****************************************************************************
** Meta object code from reading C++ file 'metagui.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../metagui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'metagui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MetaGui[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_MetaGui[] = {
    "MetaGui\0"
};

void MetaGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MetaGui::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MetaGui::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MetaGui,
      qt_meta_data_MetaGui, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MetaGui::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MetaGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MetaGui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MetaGui))
        return static_cast<void*>(const_cast< MetaGui*>(this));
    return QWidget::qt_metacast(_clname);
}

int MetaGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_CheckBoxGui[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   13,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CheckBoxGui[] = {
    "CheckBoxGui\0\0state\0stateChanged(int)\0"
};

void CheckBoxGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CheckBoxGui *_t = static_cast<CheckBoxGui *>(_o);
        switch (_id) {
        case 0: _t->stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CheckBoxGui::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CheckBoxGui::staticMetaObject = {
    { &MetaGui::staticMetaObject, qt_meta_stringdata_CheckBoxGui,
      qt_meta_data_CheckBoxGui, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CheckBoxGui::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CheckBoxGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CheckBoxGui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CheckBoxGui))
        return static_cast<void*>(const_cast< CheckBoxGui*>(this));
    return MetaGui::qt_metacast(_clname);
}

int CheckBoxGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MetaGui::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_BoolRadioGui[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   14,   13,   13, 0x0a,
      40,   14,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BoolRadioGui[] = {
    "BoolRadioGui\0\0clicked\0trueClicked(bool)\0"
    "falseClicked(bool)\0"
};

void BoolRadioGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BoolRadioGui *_t = static_cast<BoolRadioGui *>(_o);
        switch (_id) {
        case 0: _t->trueClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->falseClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BoolRadioGui::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BoolRadioGui::staticMetaObject = {
    { &MetaGui::staticMetaObject, qt_meta_stringdata_BoolRadioGui,
      qt_meta_data_BoolRadioGui, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BoolRadioGui::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BoolRadioGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BoolRadioGui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BoolRadioGui))
        return static_cast<void*>(const_cast< BoolRadioGui*>(this));
    return MetaGui::qt_metacast(_clname);
}

int BoolRadioGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MetaGui::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_UnitsGui[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      32,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_UnitsGui[] = {
    "UnitsGui\0\0value0Change(QString)\0"
    "value1Change(QString)\0"
};

void UnitsGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UnitsGui *_t = static_cast<UnitsGui *>(_o);
        switch (_id) {
        case 0: _t->value0Change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->value1Change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData UnitsGui::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject UnitsGui::staticMetaObject = {
    { &MetaGui::staticMetaObject, qt_meta_stringdata_UnitsGui,
      qt_meta_data_UnitsGui, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UnitsGui::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UnitsGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UnitsGui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UnitsGui))
        return static_cast<void*>(const_cast< UnitsGui*>(this));
    return MetaGui::qt_metacast(_clname);
}

int UnitsGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MetaGui::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_FloatsGui[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      33,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FloatsGui[] = {
    "FloatsGui\0\0value0Change(QString)\0"
    "value1Change(QString)\0"
};

void FloatsGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FloatsGui *_t = static_cast<FloatsGui *>(_o);
        switch (_id) {
        case 0: _t->value0Change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->value1Change((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FloatsGui::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FloatsGui::staticMetaObject = {
    { &MetaGui::staticMetaObject, qt_meta_stringdata_FloatsGui,
      qt_meta_data_FloatsGui, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FloatsGui::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FloatsGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FloatsGui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FloatsGui))
        return static_cast<void*>(const_cast< FloatsGui*>(this));
    return MetaGui::qt_metacast(_clname);
}

int FloatsGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MetaGui::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_NumberGui[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   11,   10,   10, 0x0a,
      36,   11,   10,   10, 0x0a,
      54,   10,   10,   10, 0x0a,
      77,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_NumberGui[] = {
    "NumberGui\0\0clicked\0browseFont(bool)\0"
    "browseColor(bool)\0value0Changed(QString)\0"
    "value1Changed(QString)\0"
};

void NumberGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NumberGui *_t = static_cast<NumberGui *>(_o);
        switch (_id) {
        case 0: _t->browseFont((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->browseColor((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->value0Changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->value1Changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData NumberGui::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NumberGui::staticMetaObject = {
    { &MetaGui::staticMetaObject, qt_meta_stringdata_NumberGui,
      qt_meta_data_NumberGui, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NumberGui::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NumberGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NumberGui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NumberGui))
        return static_cast<void*>(const_cast< NumberGui*>(this));
    return MetaGui::qt_metacast(_clname);
}

int NumberGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MetaGui::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_DoubleSpinGui[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DoubleSpinGui[] = {
    "DoubleSpinGui\0\0valueChanged(double)\0"
};

void DoubleSpinGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DoubleSpinGui *_t = static_cast<DoubleSpinGui *>(_o);
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DoubleSpinGui::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DoubleSpinGui::staticMetaObject = {
    { &MetaGui::staticMetaObject, qt_meta_stringdata_DoubleSpinGui,
      qt_meta_data_DoubleSpinGui, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DoubleSpinGui::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DoubleSpinGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DoubleSpinGui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DoubleSpinGui))
        return static_cast<void*>(const_cast< DoubleSpinGui*>(this));
    return MetaGui::qt_metacast(_clname);
}

int DoubleSpinGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MetaGui::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_BackgroundGui[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      35,   14,   14,   14, 0x0a,
      58,   14,   14,   14, 0x0a,
      78,   14,   14,   14, 0x0a,
      96,   14,   14,   14, 0x0a,
     110,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BackgroundGui[] = {
    "BackgroundGui\0\0typeChange(QString)\0"
    "pictureChange(QString)\0browsePicture(bool)\0"
    "browseColor(bool)\0stretch(bool)\0"
    "tile(bool)\0"
};

void BackgroundGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BackgroundGui *_t = static_cast<BackgroundGui *>(_o);
        switch (_id) {
        case 0: _t->typeChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->pictureChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->browsePicture((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->browseColor((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->stretch((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->tile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BackgroundGui::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BackgroundGui::staticMetaObject = {
    { &MetaGui::staticMetaObject, qt_meta_stringdata_BackgroundGui,
      qt_meta_data_BackgroundGui, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BackgroundGui::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BackgroundGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BackgroundGui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BackgroundGui))
        return static_cast<void*>(const_cast< BackgroundGui*>(this));
    return MetaGui::qt_metacast(_clname);
}

int BackgroundGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MetaGui::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
static const uint qt_meta_data_BorderGui[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      31,   10,   10,   10, 0x0a,
      56,   10,   10,   10, 0x0a,
      74,   10,   10,   10, 0x0a,
      92,   10,   10,   10, 0x0a,
     115,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BorderGui[] = {
    "BorderGui\0\0typeChange(QString)\0"
    "thicknessChange(QString)\0browseColor(bool)\0"
    "radiusChange(int)\0marginXChange(QString)\0"
    "marginYChange(QString)\0"
};

void BorderGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BorderGui *_t = static_cast<BorderGui *>(_o);
        switch (_id) {
        case 0: _t->typeChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->thicknessChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->browseColor((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->radiusChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->marginXChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->marginYChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BorderGui::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BorderGui::staticMetaObject = {
    { &MetaGui::staticMetaObject, qt_meta_stringdata_BorderGui,
      qt_meta_data_BorderGui, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BorderGui::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BorderGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BorderGui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BorderGui))
        return static_cast<void*>(const_cast< BorderGui*>(this));
    return MetaGui::qt_metacast(_clname);
}

int BorderGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MetaGui::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
static const uint qt_meta_data_ConstrainGui[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      34,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ConstrainGui[] = {
    "ConstrainGui\0\0typeChange(QString)\0"
    "valueChange(QString)\0"
};

void ConstrainGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ConstrainGui *_t = static_cast<ConstrainGui *>(_o);
        switch (_id) {
        case 0: _t->typeChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->valueChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ConstrainGui::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ConstrainGui::staticMetaObject = {
    { &MetaGui::staticMetaObject, qt_meta_stringdata_ConstrainGui,
      qt_meta_data_ConstrainGui, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConstrainGui::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConstrainGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConstrainGui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConstrainGui))
        return static_cast<void*>(const_cast< ConstrainGui*>(this));
    return MetaGui::qt_metacast(_clname);
}

int ConstrainGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MetaGui::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_SepGui[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x0a,
      41,   33,    7,    7, 0x0a,
      59,    7,    7,    7, 0x0a,
      82,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SepGui[] = {
    "SepGui\0\0thicknessChange(QString)\0"
    "clicked\0browseColor(bool)\0"
    "marginXChange(QString)\0marginYChange(QString)\0"
};

void SepGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SepGui *_t = static_cast<SepGui *>(_o);
        switch (_id) {
        case 0: _t->thicknessChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->browseColor((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->marginXChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->marginYChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SepGui::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SepGui::staticMetaObject = {
    { &MetaGui::staticMetaObject, qt_meta_stringdata_SepGui,
      qt_meta_data_SepGui, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SepGui::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SepGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SepGui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SepGui))
        return static_cast<void*>(const_cast< SepGui*>(this));
    return MetaGui::qt_metacast(_clname);
}

int SepGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MetaGui::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_ResolutionGui[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      36,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ResolutionGui[] = {
    "ResolutionGui\0\0unitsChange(QString)\0"
    "valueChange(QString)\0"
};

void ResolutionGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ResolutionGui *_t = static_cast<ResolutionGui *>(_o);
        switch (_id) {
        case 0: _t->unitsChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->valueChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ResolutionGui::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ResolutionGui::staticMetaObject = {
    { &MetaGui::staticMetaObject, qt_meta_stringdata_ResolutionGui,
      qt_meta_data_ResolutionGui, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ResolutionGui::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ResolutionGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ResolutionGui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ResolutionGui))
        return static_cast<void*>(const_cast< ResolutionGui*>(this));
    return MetaGui::qt_metacast(_clname);
}

int ResolutionGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MetaGui::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_RendererGui[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RendererGui[] = {
    "RendererGui\0\0typeChange(QString)\0"
};

void RendererGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RendererGui *_t = static_cast<RendererGui *>(_o);
        switch (_id) {
        case 0: _t->typeChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RendererGui::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RendererGui::staticMetaObject = {
    { &MetaGui::staticMetaObject, qt_meta_stringdata_RendererGui,
      qt_meta_data_RendererGui, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RendererGui::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RendererGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RendererGui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RendererGui))
        return static_cast<void*>(const_cast< RendererGui*>(this));
    return MetaGui::qt_metacast(_clname);
}

int RendererGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MetaGui::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
