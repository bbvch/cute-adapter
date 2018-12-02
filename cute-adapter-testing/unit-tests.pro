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

LIBS += -lgtest -lgmock_main -lgmock
