/****************************************************************************
** Meta object code from reading C++ file 'Regist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../Regist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Regist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Regist_t {
    QByteArrayData data[7];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Regist_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Regist_t qt_meta_stringdata_Regist = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Regist"
QT_MOC_LITERAL(1, 7, 15), // "slotBackToLogin"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 10), // "slotRegist"
QT_MOC_LITERAL(4, 35, 15), // "requestFinished"
QT_MOC_LITERAL(5, 51, 14), // "QNetworkReply*"
QT_MOC_LITERAL(6, 66, 5) // "reply"

    },
    "Regist\0slotBackToLogin\0\0slotRegist\0"
    "requestFinished\0QNetworkReply*\0reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Regist[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    1,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void Regist::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Regist *_t = static_cast<Regist *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotBackToLogin(); break;
        case 1: _t->slotRegist(); break;
        case 2: _t->requestFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Regist::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Regist.data,
      qt_meta_data_Regist,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Regist::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Regist::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Regist.stringdata0))
        return static_cast<void*>(const_cast< Regist*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Regist::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE