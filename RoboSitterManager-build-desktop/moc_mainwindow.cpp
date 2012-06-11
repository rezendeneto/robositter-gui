/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon Jun 11 01:36:59 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../RoboSitterManager/GUI/src/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      44,   11,   11,   11, 0x08,
      70,   11,   11,   11, 0x08,
     103,   11,   11,   11, 0x08,
     115,   11,   11,   11, 0x08,
     127,   11,   11,   11, 0x08,
     137,   11,   11,   11, 0x08,
     147,   11,   11,   11, 0x08,
     159,   11,   11,   11, 0x08,
     171,   11,   11,   11, 0x08,
     181,   11,   11,   11, 0x08,
     191,   11,   11,   11, 0x08,
     203,   11,   11,   11, 0x08,
     215,   11,   11,   11, 0x08,
     225,   11,   11,   11, 0x08,
     235,   11,   11,   11, 0x08,
     248,   11,   11,   11, 0x08,
     259,   11,   11,   11, 0x08,
     268,   11,   11,   11, 0x08,
     277,   11,   11,   11, 0x08,
     286,   11,   11,   11, 0x08,
     295,   11,   11,   11, 0x08,
     303,   11,   11,   11, 0x08,
     311,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_actionChangeMode_triggered()\0"
    "on_actionSair_triggered()\0"
    "on_actionConfigura_o_triggered()\0"
    "mInitialH()\0pInitialH()\0mFinalH()\0"
    "pFinalH()\0mInitialS()\0pInitialS()\0"
    "mFinalS()\0pFinalS()\0mInitialV()\0"
    "pInitialV()\0mFinalV()\0pFinalV()\0"
    "resetColor()\0setStart()\0bMoveF()\0"
    "bMoveB()\0bMoveL()\0bMoveR()\0bRotL()\0"
    "bRotR()\0bStop()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_actionChangeMode_triggered(); break;
        case 1: on_actionSair_triggered(); break;
        case 2: on_actionConfigura_o_triggered(); break;
        case 3: mInitialH(); break;
        case 4: pInitialH(); break;
        case 5: mFinalH(); break;
        case 6: pFinalH(); break;
        case 7: mInitialS(); break;
        case 8: pInitialS(); break;
        case 9: mFinalS(); break;
        case 10: pFinalS(); break;
        case 11: mInitialV(); break;
        case 12: pInitialV(); break;
        case 13: mFinalV(); break;
        case 14: pFinalV(); break;
        case 15: resetColor(); break;
        case 16: setStart(); break;
        case 17: bMoveF(); break;
        case 18: bMoveB(); break;
        case 19: bMoveL(); break;
        case 20: bMoveR(); break;
        case 21: bRotL(); break;
        case 22: bRotR(); break;
        case 23: bStop(); break;
        default: ;
        }
        _id -= 24;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
