/****************************************************************************
** Meta object code from reading C++ file 'entrylistview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GUI/entry/view/entrylistview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'entrylistview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EntryListView_t {
    QByteArrayData data[19];
    char stringdata[294];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_EntryListView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_EntryListView_t qt_meta_stringdata_EntryListView = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 20),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 16),
QT_MOC_LITERAL(4, 53, 10),
QT_MOC_LITERAL(5, 64, 14),
QT_MOC_LITERAL(6, 79, 16),
QT_MOC_LITERAL(7, 96, 18),
QT_MOC_LITERAL(8, 115, 16),
QT_MOC_LITERAL(9, 132, 15),
QT_MOC_LITERAL(10, 148, 18),
QT_MOC_LITERAL(11, 167, 12),
QT_MOC_LITERAL(12, 180, 27),
QT_MOC_LITERAL(13, 208, 12),
QT_MOC_LITERAL(14, 221, 12),
QT_MOC_LITERAL(15, 234, 14),
QT_MOC_LITERAL(16, 249, 11),
QT_MOC_LITERAL(17, 261, 18),
QT_MOC_LITERAL(18, 280, 12)
    },
    "EntryListView\0context_menu_emitted\0\0"
    "sig_rows_removed\0QList<int>\0sig_rows_moved\0"
    "sig_info_clicked\0sig_remove_clicked\0"
    "sig_edit_clicked\0sig_sel_changed\0"
    "sig_double_clicked\0sig_no_focus\0"
    "forbid_mimedata_destroyable\0edit_clicked\0"
    "info_clicked\0remove_clicked\0row_pressed\0"
    "row_double_clicked\0row_released\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EntryListView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06,
       3,    2,   97,    2, 0x06,
       5,    2,  102,    2, 0x06,
       6,    0,  107,    2, 0x06,
       7,    0,  108,    2, 0x06,
       8,    0,  109,    2, 0x06,
       9,    1,  110,    2, 0x06,
      10,    1,  113,    2, 0x06,
      11,    0,  116,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
      12,    0,  117,    2, 0x08,
      13,    0,  118,    2, 0x08,
      14,    0,  119,    2, 0x08,
      15,    0,  120,    2, 0x08,
      16,    1,  121,    2, 0x08,
      17,    1,  124,    2, 0x08,
      18,    1,  127,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Bool,    2,    2,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void, QMetaType::QModelIndex,    2,

       0        // eod
};

void EntryListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EntryListView *_t = static_cast<EntryListView *>(_o);
        switch (_id) {
        case 0: _t->context_menu_emitted((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 1: _t->sig_rows_removed((*reinterpret_cast< const QList<int>(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->sig_rows_moved((*reinterpret_cast< const QList<int>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->sig_info_clicked(); break;
        case 4: _t->sig_remove_clicked(); break;
        case 5: _t->sig_edit_clicked(); break;
        case 6: _t->sig_sel_changed((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->sig_double_clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->sig_no_focus(); break;
        case 9: _t->forbid_mimedata_destroyable(); break;
        case 10: _t->edit_clicked(); break;
        case 11: _t->info_clicked(); break;
        case 12: _t->remove_clicked(); break;
        case 13: _t->row_pressed((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 14: _t->row_double_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 15: _t->row_released((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EntryListView::*_t)(const QPoint & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EntryListView::context_menu_emitted)) {
                *result = 0;
            }
        }
        {
            typedef void (EntryListView::*_t)(const QList<int> & , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EntryListView::sig_rows_removed)) {
                *result = 1;
            }
        }
        {
            typedef void (EntryListView::*_t)(const QList<int> & , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EntryListView::sig_rows_moved)) {
                *result = 2;
            }
        }
        {
            typedef void (EntryListView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EntryListView::sig_info_clicked)) {
                *result = 3;
            }
        }
        {
            typedef void (EntryListView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EntryListView::sig_remove_clicked)) {
                *result = 4;
            }
        }
        {
            typedef void (EntryListView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EntryListView::sig_edit_clicked)) {
                *result = 5;
            }
        }
        {
            typedef void (EntryListView::*_t)(const QModelIndex & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EntryListView::sig_sel_changed)) {
                *result = 6;
            }
        }
        {
            typedef void (EntryListView::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EntryListView::sig_double_clicked)) {
                *result = 7;
            }
        }
        {
            typedef void (EntryListView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EntryListView::sig_no_focus)) {
                *result = 8;
            }
        }
    }
}

const QMetaObject EntryListView::staticMetaObject = {
    { &QListView::staticMetaObject, qt_meta_stringdata_EntryListView.data,
      qt_meta_data_EntryListView,  qt_static_metacall, 0, 0}
};


const QMetaObject *EntryListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EntryListView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EntryListView.stringdata))
        return static_cast<void*>(const_cast< EntryListView*>(this));
    return QListView::qt_metacast(_clname);
}

int EntryListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void EntryListView::context_menu_emitted(const QPoint & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EntryListView::sig_rows_removed(const QList<int> & _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void EntryListView::sig_rows_moved(const QList<int> & _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void EntryListView::sig_info_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void EntryListView::sig_remove_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void EntryListView::sig_edit_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void EntryListView::sig_sel_changed(const QModelIndex & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void EntryListView::sig_double_clicked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void EntryListView::sig_no_focus()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}
QT_END_MOC_NAMESPACE
