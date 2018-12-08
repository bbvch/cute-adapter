QT += testlib
QT -= gui

CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    HelloWorld.test.cpp \
    HelloWorld.cpp \

HEADERS += \
    HelloWorld.h \

LIBS += -lgtest -lgtest_main -lpthread
LIBS += -lcute-adapter-testing -lcute-adapter
