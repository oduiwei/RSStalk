/****************************************************************************
** Meta object code from reading C++ file 'filedownloader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RSStalk/filedownloader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filedownloader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FileDownloader_t {
    QByteArrayData data[6];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileDownloader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileDownloader_t qt_meta_stringdata_FileDownloader = {
    {
QT_MOC_LITERAL(0, 0, 14), // "FileDownloader"
QT_MOC_LITERAL(1, 15, 16), // "downloadOverTime"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 15), // "downloadSuccess"
QT_MOC_LITERAL(4, 49, 16), // "downloadFinished"
QT_MOC_LITERAL(5, 66, 14) // "QNetworkReply*"

    },
    "FileDownloader\0downloadOverTime\0\0"
    "downloadSuccess\0downloadFinished\0"
    "QNetworkReply*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileDownloader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       3,    0,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QUrl,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    2,

       0        // eod
};

void FileDownloader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FileDownloader *_t = static_cast<FileDownloader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->downloadOverTime((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 1: _t->downloadSuccess(); break;
        case 2: _t->downloadFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FileDownloader::*_t)(QUrl );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FileDownloader::downloadOverTime)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FileDownloader::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FileDownloader::downloadSuccess)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject FileDownloader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FileDownloader.data,
      qt_meta_data_FileDownloader,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FileDownloader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileDownloader::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FileDownloader.stringdata0))
        return static_cast<void*>(const_cast< FileDownloader*>(this));
    return QObject::qt_metacast(_clname);
}

int FileDownloader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void FileDownloader::downloadOverTime(QUrl _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileDownloader::downloadSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
struct qt_meta_stringdata_InfoXMLParser_t {
    QByteArrayData data[1];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InfoXMLParser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InfoXMLParser_t qt_meta_stringdata_InfoXMLParser = {
    {
QT_MOC_LITERAL(0, 0, 13) // "InfoXMLParser"

    },
    "InfoXMLParser"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InfoXMLParser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void InfoXMLParser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject InfoXMLParser::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_InfoXMLParser.data,
      qt_meta_data_InfoXMLParser,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *InfoXMLParser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InfoXMLParser::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_InfoXMLParser.stringdata0))
        return static_cast<void*>(const_cast< InfoXMLParser*>(this));
    if (!strcmp(_clname, "QXmlStreamReader"))
        return static_cast< QXmlStreamReader*>(const_cast< InfoXMLParser*>(this));
    return QObject::qt_metacast(_clname);
}

int InfoXMLParser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
