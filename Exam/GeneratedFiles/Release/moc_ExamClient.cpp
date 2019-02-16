/****************************************************************************
** Meta object code from reading C++ file 'ExamClient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../ExamClient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ExamClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ExamClient_t {
    QByteArrayData data[9];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ExamClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ExamClient_t qt_meta_stringdata_ExamClient = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ExamClient"
QT_MOC_LITERAL(1, 11, 16), // "signalUserCommit"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "slotCommit"
QT_MOC_LITERAL(4, 40, 20), // "slotExerciseSelected"
QT_MOC_LITERAL(5, 61, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(6, 78, 4), // "item"
QT_MOC_LITERAL(7, 83, 25), // "slotExerciseDoubleClicked"
QT_MOC_LITERAL(8, 109, 17) // "slotAnswerChanged"

    },
    "ExamClient\0signalUserCommit\0\0slotCommit\0"
    "slotExerciseSelected\0QListWidgetItem*\0"
    "item\0slotExerciseDoubleClicked\0"
    "slotAnswerChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExamClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x08 /* Private */,
       4,    1,   41,    2, 0x08 /* Private */,
       7,    1,   44,    2, 0x08 /* Private */,
       8,    0,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,

       0        // eod
};

void ExamClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ExamClient *_t = static_cast<ExamClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalUserCommit(); break;
        case 1: _t->slotCommit(); break;
        case 2: _t->slotExerciseSelected((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->slotExerciseDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->slotAnswerChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ExamClient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ExamClient::signalUserCommit)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ExamClient::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ExamClient.data,
      qt_meta_data_ExamClient,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ExamClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExamClient::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ExamClient.stringdata0))
        return static_cast<void*>(const_cast< ExamClient*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ExamClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ExamClient::signalUserCommit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
