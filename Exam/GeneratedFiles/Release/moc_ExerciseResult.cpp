/****************************************************************************
** Meta object code from reading C++ file 'ExerciseResult.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../ExerciseResult.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ExerciseResult.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ExerciseResult_t {
    QByteArrayData data[6];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ExerciseResult_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ExerciseResult_t qt_meta_stringdata_ExerciseResult = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ExerciseResult"
QT_MOC_LITERAL(1, 15, 20), // "slotExerciseSelected"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(4, 54, 4), // "item"
QT_MOC_LITERAL(5, 59, 24) // "slotBackToExerciseSelect"

    },
    "ExerciseResult\0slotExerciseSelected\0"
    "\0QListWidgetItem*\0item\0slotBackToExerciseSelect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExerciseResult[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       5,    0,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void ExerciseResult::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ExerciseResult *_t = static_cast<ExerciseResult *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotExerciseSelected((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->slotBackToExerciseSelect(); break;
        default: ;
        }
    }
}

const QMetaObject ExerciseResult::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ExerciseResult.data,
      qt_meta_data_ExerciseResult,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ExerciseResult::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExerciseResult::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ExerciseResult.stringdata0))
        return static_cast<void*>(const_cast< ExerciseResult*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ExerciseResult::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
