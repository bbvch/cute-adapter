# (C) Copyright 2018
# Urs Fässler, bbv Software Services, http://bbv.ch
#
# SPDX-License-Identifier:	Apache-2.0

TEMPLATE = lib
CONFIG += staticlib

QT -= gui

target.path = /usr/local/lib/
INSTALLS += target

header.files = \
    $$TARGET/Time.h \
    $$TARGET/Timer.h \
    $$TARGET/TimerFactory.h \

header.path = /usr/local/include/$$TARGET/

INSTALLS += header

SOURCES += \
    $$TARGET/Time.cpp \
    $$TARGET/Timer.cpp \
    $$TARGET/TimerFactory.cpp \

HEADERS += \
    $$header.files \

include(common.pri)
