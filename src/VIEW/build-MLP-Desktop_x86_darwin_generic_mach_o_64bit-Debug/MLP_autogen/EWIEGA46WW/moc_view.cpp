/****************************************************************************
** Meta object code from reading C++ file 'view.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MLP/view.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_View_t {
    const uint offsetsAndSize[34];
    char stringdata0[404];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_View_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_View_t qt_meta_stringdata_View = {
    {
QT_MOC_LITERAL(0, 4), // "View"
QT_MOC_LITERAL(5, 19), // "on_pushLoad_clicked"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 20), // "on_pushClear_clicked"
QT_MOC_LITERAL(47, 22), // "on_pushPredict_clicked"
QT_MOC_LITERAL(70, 29), // "on_push_training_data_clicked"
QT_MOC_LITERAL(100, 28), // "on_push_testing_data_clicked"
QT_MOC_LITERAL(129, 21), // "on_push_train_clicked"
QT_MOC_LITERAL(151, 34), // "on_push_check_testing_data_cl..."
QT_MOC_LITERAL(186, 32), // "on_epochs_count_box_valueChanged"
QT_MOC_LITERAL(219, 4), // "arg1"
QT_MOC_LITERAL(224, 31), // "on_count_3_hidden_layer_clicked"
QT_MOC_LITERAL(256, 31), // "on_count_4_hidden_layer_clicked"
QT_MOC_LITERAL(288, 31), // "on_count_5_hidden_layer_clicked"
QT_MOC_LITERAL(320, 28), // "on_push_load_weights_clicked"
QT_MOC_LITERAL(349, 28), // "on_push_save_weights_clicked"
QT_MOC_LITERAL(378, 25) // "on_shape_box_valueChanged"

    },
    "View\0on_pushLoad_clicked\0\0"
    "on_pushClear_clicked\0on_pushPredict_clicked\0"
    "on_push_training_data_clicked\0"
    "on_push_testing_data_clicked\0"
    "on_push_train_clicked\0"
    "on_push_check_testing_data_clicked\0"
    "on_epochs_count_box_valueChanged\0arg1\0"
    "on_count_3_hidden_layer_clicked\0"
    "on_count_4_hidden_layer_clicked\0"
    "on_count_5_hidden_layer_clicked\0"
    "on_push_load_weights_clicked\0"
    "on_push_save_weights_clicked\0"
    "on_shape_box_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_View[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x08,    1 /* Private */,
       3,    0,   99,    2, 0x08,    2 /* Private */,
       4,    0,  100,    2, 0x08,    3 /* Private */,
       5,    0,  101,    2, 0x08,    4 /* Private */,
       6,    0,  102,    2, 0x08,    5 /* Private */,
       7,    0,  103,    2, 0x08,    6 /* Private */,
       8,    0,  104,    2, 0x08,    7 /* Private */,
       9,    1,  105,    2, 0x08,    8 /* Private */,
      11,    0,  108,    2, 0x08,   10 /* Private */,
      12,    0,  109,    2, 0x08,   11 /* Private */,
      13,    0,  110,    2, 0x08,   12 /* Private */,
      14,    0,  111,    2, 0x08,   13 /* Private */,
      15,    0,  112,    2, 0x08,   14 /* Private */,
      16,    1,  113,    2, 0x08,   15 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   10,

       0        // eod
};

void View::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<View *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushLoad_clicked(); break;
        case 1: _t->on_pushClear_clicked(); break;
        case 2: _t->on_pushPredict_clicked(); break;
        case 3: _t->on_push_training_data_clicked(); break;
        case 4: _t->on_push_testing_data_clicked(); break;
        case 5: _t->on_push_train_clicked(); break;
        case 6: _t->on_push_check_testing_data_clicked(); break;
        case 7: _t->on_epochs_count_box_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_count_3_hidden_layer_clicked(); break;
        case 9: _t->on_count_4_hidden_layer_clicked(); break;
        case 10: _t->on_count_5_hidden_layer_clicked(); break;
        case 11: _t->on_push_load_weights_clicked(); break;
        case 12: _t->on_push_save_weights_clicked(); break;
        case 13: _t->on_shape_box_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject View::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_View.offsetsAndSize,
    qt_meta_data_View,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_View_t
, QtPrivate::TypeAndForceComplete<View, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>


>,
    nullptr
} };


const QMetaObject *View::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *View::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_View.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int View::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
