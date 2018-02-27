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
    $$TARGET/TimerFactory.h \
    $$TARGET/Timer.h \

header.path = /usr/local/include/$$TARGET/

INSTALLS += header

HEADERS = \
    $$header.files \

SOURCES = \
    $$TARGET/Time.cpp \
    $$TARGET/TimerFactory.cpp \
    $$TARGET/Timer.cpp \


include(common.pri)
