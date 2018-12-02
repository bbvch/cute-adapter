# (C) Copyright 2018
# Urs Fässler, bbv Software Services, http://bbv.ch
#
# SPDX-License-Identifier:	Apache-2.0

include(../common.pri)

TEMPLATE = lib
CONFIG += staticlib

QT -= gui

target.path = $$PREFIX/lib/

baseHeader.files = \
    $$TARGET/Time.h \
    $$TARGET/TimerFactory.h \
    $$TARGET/Timer.h \
    $$TARGET/UuidGenerator.h \

baseHeader.path = $$PREFIX/include/$$TARGET/

linuxHeader.files = \
    $$TARGET/linux/SignalHandler.h \

linuxHeader.path = $$PREFIX/include/$$TARGET/linux/

HEADERS = \
    $$baseHeader.files \
    $$linuxHeader.files \

SOURCES = \
    $$TARGET/Time.cpp \
    $$TARGET/TimerFactory.cpp \
    $$TARGET/Timer.cpp \
    $$TARGET/UuidGenerator.cpp \
    $$TARGET/linux/SignalHandler.cpp \

INSTALLS += \
    target \
    baseHeader \
    linuxHeader
