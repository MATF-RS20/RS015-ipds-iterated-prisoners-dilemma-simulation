QT       += core gui printsupport testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += staticlib c++17

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# LIBS += -lgtest

include(catch/single_include/catch2/catch.pri)
include(trompeloeil/trompeloeil.pri)
#include($$PWD/../IPDS_QT_Project/RS015-ipds-iterated-prisoners-dilemma-simulation.pri)

PROJECT_DIR = $$PWD/../IPDS_QT_Project

INCLUDEPATH += $$PROJECT_DIR

SOURCES +=  \
#    $$PROJECT_SOURCES \
    $$PROJECT_DIR/food.cpp \
    $$PROJECT_DIR/graphicSim.cpp \
    $$PROJECT_DIR/mainwindow.cpp \
    $$PROJECT_DIR/qcustomplot.cpp \
    $$PROJECT_DIR/simulation.cpp \
    $$PROJECT_DIR/specimen.cpp \
    $$PROJECT_DIR/statehistory.cpp \
    $$files(*.cpp) \
    $$files($$PROJECT_DIR/strategies/*.cpp)


HEADERS += \
#    $$PROJECT_HEADERS
    $$files(*.h) \
    $$files(strategies/*.h) \
    $$files(*.hpp) \
    $$files($$PROJECT_DIR/*.h) \
    $$files($$PROJECT_DIR/strategies/*.h) \
    $$files($$PROJECT_DIR/*.hpp) \
    $$files(catch/single_include/catch2/*.hpp) \
    $$files(trompeloeil/*.hpp)


RESOURCES += \
    $$PROJECT_DIR/resources.qrc

FORMS += \
    $$PROJECT_DIR/mainwindow.ui


#PROJECT_SOURCES = \
#    $$PROJECT_DIR/food.cpp \
#    $$PROJECT_DIR/graphicSim.cpp \
#    $$PROJECT_DIR/mainwindow.cpp \
#    $$PROJECT_DIR/qcustomplot.cpp \
#    $$PROJECT_DIR/simulation.cpp \
#    $$PROJECT_DIR/specimen.cpp \
#    $$PROJECT_DIR/statehistory.cpp \
#    $$PROJECT_DIR/strategy/dove.cpp \
#    $$PROJECT_DIR/strategy/hawk.cpp \
#    $$PROJECT_DIR/strategy/random.cpp \
#    $$PROJECT_DIR/strategy/titfortat.cpp \
#    $$PROJECT_DIR/strategy/titfortwotats.cpp \
#    $$PROJECT_DIR/strategy/twotitsfortat.cpp \
#    $$PROJECT_DIR/strategy/pavlov.cpp

#PROJECT_HEADERS = \
#    $$PROJECT_DIR/eoutcome.h \
#    $$PROJECT_DIR/estrategy.h \
#    $$PROJECT_DIR/food.h \
#    $$PROJECT_DIR/graphicSim.h \
#    $$PROJECT_DIR/mainwindow.h \
#    $$PROJECT_DIR/qcustomplot.h \
#    $$PROJECT_DIR/simulation.h \
#    $$PROJECT_DIR/specimen.h \
#    $$PROJECT_DIR/statehistory.h \
#    $$PROJECT_DIR/strategy/dove.h \
#    $$PROJECT_DIR/strategy/hawk.h \
#    $$PROJECT_DIR/strategy/random.h \
#    $$PROJECT_DIR/strategy/titfortat.h \
#    $$PROJECT_DIR/strategy/titfortwotats.h \
#    $$PROJECT_DIR/strategy/twotitsfortat.h \
#    $$PROJECT_DIR/strategy/pavlov.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
