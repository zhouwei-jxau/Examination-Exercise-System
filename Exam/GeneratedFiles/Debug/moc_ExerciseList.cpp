/****************************************************************************
** Meta object code from reading C++ file 'ExerciseList.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../ExerciseList.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ExerciseList.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ExerciseList_t {
    QByteArrayData data[12];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ExerciseList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ExerciseList_t qt_meta_stringdata_ExerciseList = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ExerciseList"
QT_MOC_LITERAL(1, 13, 27), // "signalAddToErrorBookClicked"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 15), // "slotItemClicked"
QT_MOC_LITERAL(4, 58, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(5, 75, 4), // "item"
QT_MOC_LITERAL(6, 80, 25), // "slotAddToErrorBookClicked"
QT_MOC_LITERAL(7, 106, 16), // "QAbstractButton*"
QT_MOC_LITERAL(8, 123, 6), // "button"
QT_MOC_LITERAL(9, 130, 27), // "slotGetAddtoErrorBookStatus"
QT_MOC_LITERAL(10, 158, 14), // "QNetworkReply*"
QT_MOC_LITERAL(11, 173, 5) // "reply"

    },
    "ExerciseList\0signalAddToErrorBookClicked\0"
    "\0slotItemClicked\0QListWidgetItem*\0"
    "item\0slotAddToErrorBookClicked\0"
    "QAbstractButton*\0button\0"
    "slotGetAddtoErrorBookStatus\0QNetworkReply*\0"
    "reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExerciseList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   35,    2, 0x08 /* Private */,
       6,    1,   38,    2, 0x08 /* Private */,
       9,    1,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void ExerciseList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ExerciseList *_t = static_cast<ExerciseList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalAddToErrorBookClicked(); break;
        case 1: _t->slotItemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->slotAddToErrorBookClicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 3: _t->slotGetAddtoErrorBookStatus((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ExerciseList::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ExerciseList::signalAddToErrorBookClicked)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ExerciseList::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_ExerciseList.data,
      qt_meta_data_ExerciseList,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ExerciseList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExerciseList::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ExerciseList.stringdata0))
        return static_cast<void*>(const_cast< ExerciseList*>(this));
    return QListWidget::qt_metacast(_clname);
}

int ExerciseList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ExerciseList::signalAddToErrorBookClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
