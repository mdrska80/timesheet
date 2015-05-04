/****************************************************************************
** Meta object code from reading C++ file 'GUI_LevelPainter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GUI/GUI_LevelPainter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUI_LevelPainter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GUI_LevelPainter_t {
    QByteArrayData data[9];
    char stringdata[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GUI_LevelPainter_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GUI_LevelPainter_t qt_meta_stringdata_GUI_LevelPainter = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 8),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 17),
QT_MOC_LITERAL(4, 45, 9),
QT_MOC_LITERAL(5, 55, 8),
QT_MOC_LITERAL(6, 64, 16),
QT_MOC_LITERAL(7, 81, 5),
QT_MOC_LITERAL(8, 87, 9)
    },
    "GUI_LevelPainter\0sig_show\0\0sig_right_clicked\0"
    "set_level\0psl_stop\0psl_style_update\0"
    "inner\0timed_out\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUI_LevelPainter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06,
       3,    1,   52,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    2,   55,    2, 0x0a,
       5,    0,   60,    2, 0x0a,
       6,    1,   61,    2, 0x0a,
       6,    0,   64,    2, 0x2a,
       8,    0,   65,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Float, QMetaType::Float,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GUI_LevelPainter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GUI_LevelPainter *_t = static_cast<GUI_LevelPainter *>(_o);
        switch (_id) {
        case 0: _t->sig_show((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->sig_right_clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->set_level((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 3: _t->psl_stop(); break;
        case 4: _t->psl_style_update((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->psl_style_update(); break;
        case 6: _t->timed_out(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GUI_LevelPainter::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GUI_LevelPainter::sig_show)) {
                *result = 0;
            }
        }
        {
            typedef void (GUI_LevelPainter::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GUI_LevelPainter::sig_right_clicked)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject GUI_LevelPainter::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GUI_LevelPainter.data,
      qt_meta_data_GUI_LevelPainter,  qt_static_metacall, 0, 0}
};


const QMetaObject *GUI_LevelPainter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUI_LevelPainter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GUI_LevelPainter.stringdata))
        return static_cast<void*>(const_cast< GUI_LevelPainter*>(this));
    return QWidget::qt_metacast(_clname);
}

int GUI_LevelPainter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void GUI_LevelPainter::sig_show(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GUI_LevelPainter::sig_right_clicked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
