/****************************************************************************
** Meta object code from reading C++ file 'AnswerFillInTheBlanks.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../AnswerFillInTheBlanks.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AnswerFillInTheBlanks.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AnswerFillInTheBlanks_t {
    QByteArrayData data[3];
    char stringdata0[39];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AnswerFillInTheBlanks_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AnswerFillInTheBlanks_t qt_meta_stringdata_AnswerFillInTheBlanks = {
    {
QT_MOC_LITERAL(0, 0, 21), // "AnswerFillInTheBlanks"
QT_MOC_LITERAL(1, 22, 15), // "slotTextChanged"
QT_MOC_LITERAL(2, 38, 0) // ""

    },
    "AnswerFillInTheBlanks\0slotTextChanged\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AnswerFillInTheBlanks[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void AnswerFillInTheBlanks::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AnswerFillInTheBlanks *_t = static_cast<AnswerFillInTheBlanks *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotTextChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject AnswerFillInTheBlanks::staticMetaObject = {
    { &Answer::staticMetaObject, qt_meta_stringdata_AnswerFillInTheBlanks.data,
      qt_meta_data_AnswerFillInTheBlanks,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AnswerFillInTheBlanks::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnswerFillInTheBlanks::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AnswerFillInTheBlanks.stringdata0))
        return static_cast<void*>(const_cast< AnswerFillInTheBlanks*>(this));
    return Answer::qt_metacast(_clname);
}

int AnswerFillInTheBlanks::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Answer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
