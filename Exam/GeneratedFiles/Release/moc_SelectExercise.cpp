/****************************************************************************
** Meta object code from reading C++ file 'SelectExercise.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../SelectExercise.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SelectExercise.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SelectExercise_t {
    QByteArrayData data[7];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SelectExercise_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SelectExercise_t qt_meta_stringdata_SelectExercise = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SelectExercise"
QT_MOC_LITERAL(1, 15, 19), // "slotRequestFinished"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 14), // "QNetworkReply*"
QT_MOC_LITERAL(4, 51, 5), // "reply"
QT_MOC_LITERAL(5, 57, 23), // "slotSelectedExerciseSet"
QT_MOC_LITERAL(6, 81, 15) // "slotBackToLogin"

    },
    "SelectExercise\0slotRequestFinished\0\0"
    "QNetworkReply*\0reply\0slotSelectedExerciseSet\0"
    "slotBackToLogin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SelectExercise[] = {

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
       1,    1,   29,    2, 0x08 /* Private */,
       5,    0,   32,    2, 0x08 /* Private */,
       6,    0,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SelectExercise::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SelectExercise *_t = static_cast<SelectExercise *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotRequestFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 1: _t->slotSelectedExerciseSet(); break;
        case 2: _t->slotBackToLogin(); break;
        default: ;
        }
    }
}

const QMetaObject SelectExercise::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SelectExercise.data,
      qt_meta_data_SelectExercise,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SelectExercise::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SelectExercise::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SelectExercise.stringdata0))
        return static_cast<void*>(const_cast< SelectExercise*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SelectExercise::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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