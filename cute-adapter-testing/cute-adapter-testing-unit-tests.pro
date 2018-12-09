# (C) Copyright 2018
# Urs Fässler, bbv Software Services, http://bbv.ch
#
# SPDX-License-Identifier:	Apache-2.0

include(../common.pri)

TEMPLATE = app

CONFIG += console

QT -= gui
QT += testlib

CUTE_ADAPTER_DIR = ../cute-adapter/

INCLUDEPATH += $$CUTE_ADAPTER_DIR

SOURCES += \
    cute-adapter-testing/SimulatedTimerFactory.test.cpp \
    cute-adapter-testing/SimulatedTimerFactory.cpp \
    cute-adapter-testing/SimulatedTimer.cpp \
    cute-adapter-testing/SimulatedTime.cpp \
    cute-adapter-testing/Time.dummy.cpp \
    cute-adapter-testing/TimerSink.testsupport.cpp \
    cute-adapter-testing/SignalReceiver.testsupport.cpp \
    $$CUTE_ADAPTER_DIR/cute-adapter/Timer.cpp \
    $$CUTE_ADAPTER_DIR/cute-adapter/Time.cpp \
    $$CUTE_ADAPTER_DIR/cute-adapter/TimerFactory.cpp \
    cute-adapter-testing/gtest/PrintTo.cpp \
    cute-adapter-testing/gtest/PrintTo.test.cpp \
    cute-adapter-testing/cucumber/parser.cpp \
    cute-adapter-testing/cucumber/parser.test.cpp \
    cute-adapter-testing/std/stream.cpp \
    cute-adapter-testing/std/stream.test.cpp \

HEADERS += \
    cute-adapter-testing/SimulatedTimerFactory.h \
    cute-adapter-testing/SimulatedTimer.h \
    cute-adapter-testing/SimulatedTime.h \
    cute-adapter-testing/Time.dummy.h \
    cute-adapter-testing/TimerSink.testsupport.h \
    cute-adapter-testing/SignalReceiver.testsupport.h \
    $$CUTE_ADAPTER_DIR/cute-adapter/Timer.h \
    $$CUTE_ADAPTER_DIR/cute-adapter/Time.h \
    $$CUTE_ADAPTER_DIR/cute-adapter/TimerFactory.h \
    cute-adapter-testing/gtest/PrintTo.h \
    cute-adapter-testing/cucumber/parser.h \
    cute-adapter-testing/std/stream.h \

LIBS += -lgtest -lgmock_main -lgmock
