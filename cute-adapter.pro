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
    $$TARGET/TimerFactory.h \
    $$TARGET/Timer.h \

baseHeader.path = /usr/local/include/$$TARGET/

linuxHeader.files = \
    $$TARGET/linux/SignalHandler.h \

linuxHeader.path = /usr/local/include/$$TARGET/linux/

HEADERS = \
    $$baseHeader.files \
    $$linuxHeader.files \

SOURCES = \
    $$TARGET/Time.cpp \
    $$TARGET/TimerFactory.cpp \
    $$TARGET/Timer.cpp \
    $$TARGET/linux/SignalHandler.cpp \

INSTALLS += \
    target \
    baseHeader \
    linuxHeader

include(common.pri)
