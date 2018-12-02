# (C) Copyright 2018
# Urs Fässler, bbv Software Services, http://bbv.ch
#
# SPDX-License-Identifier:	Apache-2.0

include(../common.pri)

TEMPLATE = lib
CONFIG += staticlib

QT -= gui

INCLUDEPATH += ../cute-adapter/

target.path = $$PREFIX/lib/
INSTALLS += target

header.files = \
    $$TARGET/SimulatedTime.h \
    $$TARGET/SimulatedTimerFactory.h \
    $$TARGET/SimulatedTimer.h \
    $$TARGET/Time.mock.h \
    $$TARGET/TimerFactory.mock.h \
    $$TARGET/Timer.mock.h \
    $$TARGET/UuidRepository.h \

header.path = $$PREFIX/include/$$TARGET/

INSTALLS += header


SOURCES += \
    $$TARGET/SimulatedTime.cpp \
    $$TARGET/SimulatedTimerFactory.cpp \
    $$TARGET/SimulatedTimer.cpp \
    $$TARGET/UuidRepository.cpp \

HEADERS += \
    $$header.files \

LIBS += -lcute-adapter
