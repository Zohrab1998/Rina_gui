######################################################################
# Automatically generated by qmake (3.0) ??? ??? 19 15:51:06 2021
######################################################################

TEMPLATE = app
TARGET = rina_gui
INCLUDEPATH += .

QT += core gui widgets


# Input
HEADERS += add.h \
           configure.h \
           flowshow.h \
           interfacer.h \
           mainwindow.h \
           monitoring.h \
           network/ipcptable.hpp \
           tablemodel.h \
           network/flowstat.hpp \
           network/ipcpstat.hpp \
           network/netconf.hpp \
           network/netstat.hpp \
           network/network.h \
           network/rlite-ctl.h \
           
FORMS += add.ui flowshow.ui mainwindow.ui \
    configure.ui \
    monitoring.ui
SOURCES += add.cpp \
           configure.cpp \
           flowshow.cpp \
           interfacer.cpp \
           main.cpp \
           mainwindow.cpp \
           monitoring.cpp \
           network/ipcptable.cpp \
           tablemodel.cpp \
           network/flowstat.cpp \
           network/ipcpstat.cpp \
           network/netconf.cpp \
           network/network.c \
           network/rlite-ctl.c

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/lib/release/ -lrina-api
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/lib/debug/ -lrina-api
else:unix: LIBS += -L$$PWD/../../../../usr/lib/ -lrina-api

INCLUDEPATH += $$PWD/''
DEPENDPATH += $$PWD/''

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/lib/release/ -lrlite-conf
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/lib/debug/ -lrlite-conf
else:unix: LIBS += -L$$PWD/../../../../usr/lib/ -lrlite-conf

INCLUDEPATH += $$PWD/../../../../usr/include
DEPENDPATH += $$PWD/../../../../usr/include
