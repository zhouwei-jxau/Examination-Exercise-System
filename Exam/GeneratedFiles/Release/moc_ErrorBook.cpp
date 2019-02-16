/****************************************************************************
** Meta object code from reading C++ file 'ErrorBook.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../ErrorBook.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ErrorBook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ErrorBook_t {
    QByteArrayData data[12];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ErrorBook_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ErrorBook_t qt_meta_stringdata_ErrorBook = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ErrorBook"
QT_MOC_LITERAL(1, 10, 16), // "signalUserCommit"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 20), // "slotExerciseSelected"
QT_MOC_LITERAL(4, 49, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(5, 66, 4), // "item"
QT_MOC_LITERAL(6, 71, 25), // "slotExerciseDoubleClicked"
QT_MOC_LITERAL(7, 97, 17), // "slotAnswerChanged"
QT_MOC_LITERAL(8, 115, 20), // "slotGetErrorExercise"
QT_MOC_LITERAL(9, 136, 14), // "QNetworkReply*"
QT_MOC_LITERAL(10, 151, 5), // "reply"
QT_MOC_LITERAL(11, 157, 12) // "slotGenerate"

    },
    "ErrorBook\0signalUserCommit\0\0"
    "slotExerciseSelected\0QListWidgetItem*\0"
    "item\0slotExerciseDoubleClicked\0"
    "slotAnswerChanged\0slotGetErrorExercise\0"
    "QNetworkReply*\0reply\0slotGenerate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ErrorBook[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   45,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       7,    0,   51,    2, 0x08 /* Private */,
       8,    1,   52,    2, 0x08 /* Private */,
      11,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,

       0        // eod
};

void ErrorBook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ErrorBook *_t = static_cast<ErrorBook *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalUserCommit(); break;
        case 1: _t->slotExerciseSelected((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->slotExerciseDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->slotAnswerChanged(); break;
        case 4: _t->slotGetErrorExercise((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: _t->slotGenerate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ErrorBook::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ErrorBook::signalUserCommit)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ErrorBook::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ErrorBook.data,
      qt_meta_data_ErrorBook,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ErrorBook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ErrorBook::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ErrorBook.stringdata0))
        return static_cast<void*>(const_cast< ErrorBook*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ErrorBook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ErrorBook::signalUserCommit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
