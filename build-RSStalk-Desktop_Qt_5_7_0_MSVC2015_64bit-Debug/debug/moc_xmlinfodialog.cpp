/****************************************************************************
** Meta object code from reading C++ file 'xmlinfodialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RSStalk/xmlinfodialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xmlinfodialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_XMLInfoDialog_t {
    QByteArrayData data[7];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_XMLInfoDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_XMLInfoDialog_t qt_meta_stringdata_XMLInfoDialog = {
    {
QT_MOC_LITERAL(0, 0, 13), // "XMLInfoDialog"
QT_MOC_LITERAL(1, 14, 15), // "treeItemChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(4, 48, 4), // "item"
QT_MOC_LITERAL(5, 53, 6), // "column"
QT_MOC_LITERAL(6, 60, 28) // "subscriptionSelectedFinished"

    },
    "XMLInfoDialog\0treeItemChanged\0\0"
    "QTreeWidgetItem*\0item\0column\0"
    "subscriptionSelectedFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XMLInfoDialog[] = {

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
       1,    2,   24,    2, 0x08 /* Private */,
       6,    0,   29,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void,

       0        // eod
};

void XMLInfoDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XMLInfoDialog *_t = static_cast<XMLInfoDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->treeItemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->subscriptionSelectedFinished(); break;
        default: ;
        }
    }
}

const QMetaObject XMLInfoDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_XMLInfoDialog.data,
      qt_meta_data_XMLInfoDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *XMLInfoDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XMLInfoDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_XMLInfoDialog.stringdata0))
        return static_cast<void*>(const_cast< XMLInfoDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int XMLInfoDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
