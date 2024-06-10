QT       += core gui sql
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addbuilds.cpp \
    adminroom.cpp \
    anotherwindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    addbuilds.h \
    adminroom.h \
    anotherwindow.h \
    mainwindow.h

FORMS += \
    addbuilds.ui \
    adminroom.ui \
    anotherwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../build-BD_01-Desktop_Qt_6_6_0_MinGW_64_bit-Debug/debug/rykovod.txt

RESOURCES += \
    resource.qrc
