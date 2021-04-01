/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[291];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 18), // "on_ajouter_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 18), // "on_pb_supp_clicked"
QT_MOC_LITERAL(4, 50, 22), // "on_tableView_activated"
QT_MOC_LITERAL(5, 73, 11), // "QModelIndex"
QT_MOC_LITERAL(6, 85, 5), // "index"
QT_MOC_LITERAL(7, 91, 20), // "on_tableView_clicked"
QT_MOC_LITERAL(8, 112, 20), // "on_ajouter_2_clicked"
QT_MOC_LITERAL(9, 133, 20), // "on_ajouter_3_clicked"
QT_MOC_LITERAL(10, 154, 24), // "on_tableView_2_activated"
QT_MOC_LITERAL(11, 179, 22), // "on_tableView_2_clicked"
QT_MOC_LITERAL(12, 202, 20), // "on_pb_supp_2_clicked"
QT_MOC_LITERAL(13, 223, 20), // "on_ajouter_4_clicked"
QT_MOC_LITERAL(14, 244, 15), // "on_trie_clicked"
QT_MOC_LITERAL(15, 260, 25), // "on_lineEdit_8_textChanged"
QT_MOC_LITERAL(16, 286, 4) // "arg1"

    },
    "MainWindow\0on_ajouter_clicked\0\0"
    "on_pb_supp_clicked\0on_tableView_activated\0"
    "QModelIndex\0index\0on_tableView_clicked\0"
    "on_ajouter_2_clicked\0on_ajouter_3_clicked\0"
    "on_tableView_2_activated\0"
    "on_tableView_2_clicked\0on_pb_supp_2_clicked\0"
    "on_ajouter_4_clicked\0on_trie_clicked\0"
    "on_lineEdit_8_textChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    1,   76,    2, 0x08 /* Private */,
       7,    1,   79,    2, 0x08 /* Private */,
       8,    0,   82,    2, 0x08 /* Private */,
       9,    0,   83,    2, 0x08 /* Private */,
      10,    1,   84,    2, 0x08 /* Private */,
      11,    1,   87,    2, 0x08 /* Private */,
      12,    0,   90,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    1,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ajouter_clicked(); break;
        case 1: _t->on_pb_supp_clicked(); break;
        case 2: _t->on_tableView_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_tableView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->on_ajouter_2_clicked(); break;
        case 5: _t->on_ajouter_3_clicked(); break;
        case 6: _t->on_tableView_2_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->on_tableView_2_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_pb_supp_2_clicked(); break;
        case 9: _t->on_ajouter_4_clicked(); break;
        case 10: _t->on_trie_clicked(); break;
        case 11: _t->on_lineEdit_8_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
