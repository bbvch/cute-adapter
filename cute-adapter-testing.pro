# (C) Copyright 2018
# Urs Fässler, bbv Software Services, http://bbv.ch
#
# SPDX-License-Identifier:	Apache-2.0

TEMPLATE = lib
CONFIG += staticlib

QT -= gui

target.path = /usr/lib/
INSTALLS += target

header.files = \
    $$TARGET/SimulatedTime.h \
    $$TARGET/SimulatedTimerFactory.h \
    $$TARGET/SimulatedTimer.h \
    $$TARGET/Time.mock.h \
    $$TARGET/TimerFactory.mock.h \
    $$TARGET/Timer.mock.h \

header.path = /usr/include/$$TARGET/

INSTALLS += header


SOURCES += \
    $$TARGET/SimulatedTime.cpp \
    $$TARGET/SimulatedTimerFactory.cpp \
    $$TARGET/SimulatedTimer.cpp \

HEADERS += \
    $$header.files \

LIBS += -lcute-adapter

include(common.pri)
