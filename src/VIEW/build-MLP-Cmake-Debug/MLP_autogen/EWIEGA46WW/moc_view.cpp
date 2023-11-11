/****************************************************************************
** Meta object code from reading C++ file 'view.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../MLP/view.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSViewENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSViewENDCLASS = QtMocHelpers::stringData(
    "View",
    "on_pushLoad_clicked",
    "",
    "on_pushClear_clicked",
    "on_pushPredict_clicked",
    "on_push_training_data_clicked",
    "on_push_testing_data_clicked",
    "on_push_train_clicked",
    "on_push_check_testing_data_clicked",
    "on_epochs_count_box_valueChanged",
    "arg1",
    "on_count_3_hidden_layer_clicked",
    "on_count_4_hidden_layer_clicked",
    "on_count_5_hidden_layer_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSViewENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[5];
    char stringdata1[20];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[23];
    char stringdata5[30];
    char stringdata6[29];
    char stringdata7[22];
    char stringdata8[35];
    char stringdata9[33];
    char stringdata10[5];
    char stringdata11[32];
    char stringdata12[32];
    char stringdata13[32];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSViewENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSViewENDCLASS_t qt_meta_stringdata_CLASSViewENDCLASS = {
    {
        QT_MOC_LITERAL(0, 4),  // "View"
        QT_MOC_LITERAL(5, 19),  // "on_pushLoad_clicked"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 20),  // "on_pushClear_clicked"
        QT_MOC_LITERAL(47, 22),  // "on_pushPredict_clicked"
        QT_MOC_LITERAL(70, 29),  // "on_push_training_data_clicked"
        QT_MOC_LITERAL(100, 28),  // "on_push_testing_data_clicked"
        QT_MOC_LITERAL(129, 21),  // "on_push_train_clicked"
        QT_MOC_LITERAL(151, 34),  // "on_push_check_testing_data_cl..."
        QT_MOC_LITERAL(186, 32),  // "on_epochs_count_box_valueChanged"
        QT_MOC_LITERAL(219, 4),  // "arg1"
        QT_MOC_LITERAL(224, 31),  // "on_count_3_hidden_layer_clicked"
        QT_MOC_LITERAL(256, 31),  // "on_count_4_hidden_layer_clicked"
        QT_MOC_LITERAL(288, 31)   // "on_count_5_hidden_layer_clicked"
    },
    "View",
    "on_pushLoad_clicked",
    "",
    "on_pushClear_clicked",
    "on_pushPredict_clicked",
    "on_push_training_data_clicked",
    "on_push_testing_data_clicked",
    "on_push_train_clicked",
    "on_push_check_testing_data_clicked",
    "on_epochs_count_box_valueChanged",
    "arg1",
    "on_count_3_hidden_layer_clicked",
    "on_count_4_hidden_layer_clicked",
    "on_count_5_hidden_layer_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSViewENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x08,    1 /* Private */,
       3,    0,   81,    2, 0x08,    2 /* Private */,
       4,    0,   82,    2, 0x08,    3 /* Private */,
       5,    0,   83,    2, 0x08,    4 /* Private */,
       6,    0,   84,    2, 0x08,    5 /* Private */,
       7,    0,   85,    2, 0x08,    6 /* Private */,
       8,    0,   86,    2, 0x08,    7 /* Private */,
       9,    1,   87,    2, 0x08,    8 /* Private */,
      11,    0,   90,    2, 0x08,   10 /* Private */,
      12,    0,   91,    2, 0x08,   11 /* Private */,
      13,    0,   92,    2, 0x08,   12 /* Private */,

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

       0        // eod
};

Q_CONSTINIT const QMetaObject View::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSViewENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSViewENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSViewENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<View, std::true_type>,
        // method 'on_pushLoad_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushClear_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushPredict_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_push_training_data_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_push_testing_data_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_push_train_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_push_check_testing_data_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_epochs_count_box_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_count_3_hidden_layer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_count_4_hidden_layer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_count_5_hidden_layer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

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
        case 7: _t->on_epochs_count_box_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->on_count_3_hidden_layer_clicked(); break;
        case 9: _t->on_count_4_hidden_layer_clicked(); break;
        case 10: _t->on_count_5_hidden_layer_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *View::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *View::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSViewENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int View::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
