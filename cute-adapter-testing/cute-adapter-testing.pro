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

HEADERS += $$header.files


header_gtest.files = \
    $$TARGET/gtest/PrintTo.h \

header_gtest.path = $$PREFIX/include/$$TARGET/gtest/

INSTALLS += header_gtest

HEADERS += $$header_gtest.files


header_cucumber.files = \
    $$TARGET/cucumber/parser.h \

header_cucumber.path = $$PREFIX/include/$$TARGET/cucumber/

INSTALLS += header_cucumber

HEADERS += $$header_cucumber.files


header_std.files = \
    $$TARGET/std/stream.h \

header_std.path = $$PREFIX/include/$$TARGET/std/

INSTALLS += header_std

HEADERS += $$header_std.files


SOURCES += \
    $$TARGET/SimulatedTime.cpp \
    $$TARGET/SimulatedTimerFactory.cpp \
    $$TARGET/SimulatedTimer.cpp \
    $$TARGET/UuidRepository.cpp \
    $$TARGET/gtest/PrintTo.cpp \
    $$TARGET/cucumber/parser.cpp \
    $$TARGET/std/stream.cpp \

LIBS += -lcute-adapter
