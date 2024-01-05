/****************************************************************************
** Meta object code from reading C++ file 'game_screen.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../client/game_screen.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game_screen.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSGame_ScreenENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSGame_ScreenENDCLASS = QtMocHelpers::stringData(
    "Game_Screen",
    "itemClicked",
    "",
    "handleServerResponse",
    "responseData",
    "handleRoomIn4Changed",
    "room",
    "newRoom",
    "on_readyButton_clicked",
    "on_exit_clicked",
    "on_yes_clicked",
    "on_no_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSGame_ScreenENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[12];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[13];
    char stringdata5[21];
    char stringdata6[5];
    char stringdata7[8];
    char stringdata8[23];
    char stringdata9[16];
    char stringdata10[15];
    char stringdata11[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSGame_ScreenENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSGame_ScreenENDCLASS_t qt_meta_stringdata_CLASSGame_ScreenENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "Game_Screen"
        QT_MOC_LITERAL(12, 11),  // "itemClicked"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 20),  // "handleServerResponse"
        QT_MOC_LITERAL(46, 12),  // "responseData"
        QT_MOC_LITERAL(59, 20),  // "handleRoomIn4Changed"
        QT_MOC_LITERAL(80, 4),  // "room"
        QT_MOC_LITERAL(85, 7),  // "newRoom"
        QT_MOC_LITERAL(93, 22),  // "on_readyButton_clicked"
        QT_MOC_LITERAL(116, 15),  // "on_exit_clicked"
        QT_MOC_LITERAL(132, 14),  // "on_yes_clicked"
        QT_MOC_LITERAL(147, 13)   // "on_no_clicked"
    },
    "Game_Screen",
    "itemClicked",
    "",
    "handleServerResponse",
    "responseData",
    "handleRoomIn4Changed",
    "room",
    "newRoom",
    "on_readyButton_clicked",
    "on_exit_clicked",
    "on_yes_clicked",
    "on_no_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGame_ScreenENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x0a,    1 /* Public */,
       3,    1,   57,    2, 0x0a,    2 /* Public */,
       5,    1,   60,    2, 0x0a,    4 /* Public */,
       8,    0,   63,    2, 0x08,    6 /* Private */,
       9,    0,   64,    2, 0x08,    7 /* Private */,
      10,    0,   65,    2, 0x08,    8 /* Private */,
      11,    0,   66,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Game_Screen::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSGame_ScreenENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGame_ScreenENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGame_ScreenENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Game_Screen, std::true_type>,
        // method 'itemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleServerResponse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'handleRoomIn4Changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const room &, std::false_type>,
        // method 'on_readyButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_exit_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_yes_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_no_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Game_Screen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Game_Screen *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->itemClicked(); break;
        case 1: _t->handleServerResponse((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 2: _t->handleRoomIn4Changed((*reinterpret_cast< std::add_pointer_t<room>>(_a[1]))); break;
        case 3: _t->on_readyButton_clicked(); break;
        case 4: _t->on_exit_clicked(); break;
        case 5: _t->on_yes_clicked(); break;
        case 6: _t->on_no_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *Game_Screen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Game_Screen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGame_ScreenENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Game_Screen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
