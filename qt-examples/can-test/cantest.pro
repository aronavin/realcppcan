QT       += core gui concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

QMAKE_CXXFLAGS += "-std=c++11"
#QMAKE_CXXFLAGS += "pthread"

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp\

HEADERS += \
    mainwindow.h\

FORMS += \
    mainwindow.ui

INCLUDEPATH += $$PWD/ComModules

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


unix:!macx: LIBS += -L$$PWD/../../build/ -lvisorcan

INCLUDEPATH += $$PWD/../../build
DEPENDPATH += $$PWD/../../build

unix:!macx: PRE_TARGETDEPS += $$PWD/../../build/libvisorcan.a
