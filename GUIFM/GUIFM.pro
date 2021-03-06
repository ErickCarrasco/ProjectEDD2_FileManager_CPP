#-------------------------------------------------
#
# Project created by QtCreator 2019-05-25T15:37:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUIFM
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        BinaryTree.cpp \
        BinaryTreeNode.cpp \
        Field.cpp \
        Key.cpp \
        addfield.cpp \
        addrecord.cpp \
        deletefield.cpp \
        deleterecord.cpp \
        displayrecords.cpp \
        file.cpp \
        main.cpp \
        mainwindow.cpp \
        modfield.cpp \
        modrecord.cpp \
        seekrecord.cpp \
        ventanacampos.cpp

HEADERS += \
        BinaryTree.h \
        BinaryTreeNode.h \
        Field.h \
        Key.h \
        addfield.h \
        addrecord.h \
        deletefield.h \
        deleterecord.h \
        displayrecords.h \
        file.h \
        linkedlist.h \
        mainwindow.h \
        modfield.h \
        modrecord.h \
        seekrecord.h \
        ventanacampos.h

FORMS += \
        addfield.ui \
        addrecord.ui \
        deletefield.ui \
        deleterecord.ui \
        displayrecords.ui \
        mainwindow.ui \
        modfield.ui \
        modrecord.ui \
        seekrecord.ui \
        ventanacampos.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
