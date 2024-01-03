/****************************************************************************
** Meta object code from reading C++ file 'register_form.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../client/register_form.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'register_form.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
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
struct qt_meta_stringdata_CLASSregisterformENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSregisterformENDCLASS = QtMocHelpers::stringData(
    "registerform",
    "backButtonClicked",
    "",
    "loginButtonClicked",
    "on_show_password_clicked",
    "on_register_btn_clicked",
    "on_Login_clicked",
    "on_show_confirm_password_clicked",
    "on_Back_btn_clicked",
    "handleServerResponse",
    "responseData"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSregisterformENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[13];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[25];
    char stringdata5[24];
    char stringdata6[17];
    char stringdata7[33];
    char stringdata8[20];
    char stringdata9[21];
    char stringdata10[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSregisterformENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSregisterformENDCLASS_t qt_meta_stringdata_CLASSregisterformENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "registerform"
        QT_MOC_LITERAL(13, 17),  // "backButtonClicked"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 18),  // "loginButtonClicked"
        QT_MOC_LITERAL(51, 24),  // "on_show_password_clicked"
        QT_MOC_LITERAL(76, 23),  // "on_register_btn_clicked"
        QT_MOC_LITERAL(100, 16),  // "on_Login_clicked"
        QT_MOC_LITERAL(117, 32),  // "on_show_confirm_password_clicked"
        QT_MOC_LITERAL(150, 19),  // "on_Back_btn_clicked"
        QT_MOC_LITERAL(170, 20),  // "handleServerResponse"
        QT_MOC_LITERAL(191, 12)   // "responseData"
    },
    "registerform",
    "backButtonClicked",
    "",
    "loginButtonClicked",
    "on_show_password_clicked",
    "on_register_btn_clicked",
    "on_Login_clicked",
    "on_show_confirm_password_clicked",
    "on_Back_btn_clicked",
    "handleServerResponse",
    "responseData"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSregisterformENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    1 /* Public */,
       3,    0,   63,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    0,   67,    2, 0x08,    6 /* Private */,
       8,    0,   68,    2, 0x08,    7 /* Private */,
       9,    1,   69,    2, 0x08,    8 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   10,

       0        // eod
};

Q_CONSTINIT const QMetaObject registerform::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSregisterformENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSregisterformENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSregisterformENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<registerform, std::true_type>,
        // method 'backButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loginButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_show_password_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_register_btn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Login_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_show_confirm_password_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Back_btn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleServerResponse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>
    >,
    nullptr
} };

void registerform::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<registerform *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->backButtonClicked(); break;
        case 1: _t->loginButtonClicked(); break;
        case 2: _t->on_show_password_clicked(); break;
        case 3: _t->on_register_btn_clicked(); break;
        case 4: _t->on_Login_clicked(); break;
        case 5: _t->on_show_confirm_password_clicked(); break;
        case 6: _t->on_Back_btn_clicked(); break;
        case 7: _t->handleServerResponse((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (registerform::*)();
            if (_t _q_method = &registerform::backButtonClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (registerform::*)();
            if (_t _q_method = &registerform::loginButtonClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *registerform::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *registerform::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSregisterformENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int registerform::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void registerform::backButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void registerform::loginButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
