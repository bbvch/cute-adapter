QT += core
QT -= gui

CONFIG += c++11

TARGET = HelloWorld
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp \
    HelloWorld.cpp \

HEADERS += \
    HelloWorld.h \

LIBS += -lcute-adapter-production -lcute-adapter
