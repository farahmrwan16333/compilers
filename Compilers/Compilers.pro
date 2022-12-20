QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Parse.cpp \
    Scanner.cpp \
    Tree.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Parse.h \
    Scan.h \
    Tree.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


#include "gvc.h"
#include "cdt.h"
#include "cgraph.h"
GRAPHVIZ_PATH = "C:/Program Files/Graphviz/"
DEFINES += WIN32_DLL
DEFINES += GVDLL
INCLUDEPATH += $$GRAPHVIZ_PATH/include/graphviz
LIBS += -L$$GRAPHVIZ_PATH/lib -lgvc -lcgraph  -lcdt
LIBS += -L$$GRAPHVIZ_PATH/bin -lgvc -lcgraph  -lcdt

RESOURCES += \
    resource.qrc
