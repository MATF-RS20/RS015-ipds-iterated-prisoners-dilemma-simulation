QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += c++14

TEMPLATE = app

include(catch/single_include/catch2/catch.pri)
include(trompeloeil/trompeloeil.pri)

PROJECT_DIR = $$PWD/../app

INCLUDEPATH += $$PROJECT_DIR

SOURCES +=  \
    main.cpp \
    tst_apptest.cpp
