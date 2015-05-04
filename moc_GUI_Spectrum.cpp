/****************************************************************************
** Meta object code from reading C++ file 'GUI_Spectrum.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GUI/GUI_Spectrum.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUI_Spectrum.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GUI_Spectrum_t {
    QByteArrayData data[10];
    char stringdata[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GUI_Spectrum_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GUI_Spectrum_t qt_meta_stringdata_GUI_Spectrum = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 8),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 10),
QT_MOC_LITERAL(4, 34, 17),
QT_MOC_LITERAL(5, 52, 12),
QT_MOC_LITERAL(6, 65, 13),
QT_MOC_LITERAL(7, 79, 8),
QT_MOC_LITERAL(8, 88, 16),
QT_MOC_LITERAL(9, 105, 9)
    },
    "GUI_Spectrum\0sig_show\0\0closeEvent\0"
    "sig_right_clicked\0set_spectrum\0"
    "QList<float>&\0psl_stop\0psl_style_update\0"
    "timed_out\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUI_Spectrum[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06,
       3,    0,   52,    2, 0x06,
       4,    1,   53,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    1,   56,    2, 0x0a,
       7,    0,   59,    2, 0x0a,
       8,    0,   60,    2, 0x0a,
       9,    0,   61,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GUI_Spectrum::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GUI_Spectrum *_t = static_cast<GUI_Spectrum *>(_o);
        switch (_id) {
        case 0: _t->sig_show((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->closeEvent(); break;
        case 2: _t->sig_right_clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->set_spectrum((*reinterpret_cast< QList<float>(*)>(_a[1]))); break;
        case 4: _t->psl_stop(); break;
        case 5: _t->psl_style_update(); break;
        case 6: _t->timed_out(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GUI_Spectrum::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GUI_Spectrum::sig_show)) {
                *result = 0;
            }
        }
        {
            typedef void (GUI_Spectrum::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GUI_Spectrum::closeEvent)) {
                *result = 1;
            }
        }
        {
            typedef void (GUI_Spectrum::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GUI_Spectrum::sig_right_clicked)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject GUI_Spectrum::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GUI_Spectrum.data,
      qt_meta_data_GUI_Spectrum,  qt_static_metacall, 0, 0}
};


const QMetaObject *GUI_Spectrum::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUI_Spectrum::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GUI_Spectrum.stringdata))
        return static_cast<void*>(const_cast< GUI_Spectrum*>(this));
    return QWidget::qt_metacast(_clname);
}

int GUI_Spectrum::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void GUI_Spectrum::sig_show(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GUI_Spectrum::closeEvent()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void GUI_Spectrum::sig_right_clicked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
