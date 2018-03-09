# (C) Copyright 2018
# Urs Fässler, bbv Software Services, http://bbv.ch
#
# SPDX-License-Identifier:	Apache-2.0

TEMPLATE = lib
CONFIG += staticlib

QT -= gui

target.path = /usr/local/lib/

baseHeader.files = \
    $$TARGET/Time.h \
    $$TARGET/Timer.h \
    $$TARGET/TimerFactory.h \

baseHeader.path = /usr/local/include/$$TARGET/

linuxHeader.files = \
    $$TARGET/linux/SignalHandler.h \

linuxHeader.path = /usr/local/include/$$TARGET/linux/

SOURCES += \
    $$TARGET/Time.cpp \
    $$TARGET/Timer.cpp \
    $$TARGET/TimerFactory.cpp \
    $$TARGET/linux/SignalHandler.cpp \

HEADERS += \
    $$baseHeader.files \
    $$linuxHeader.files \

INSTALLS += \
    target \
    baseHeader \
    linuxHeader \

include(common.pri)
