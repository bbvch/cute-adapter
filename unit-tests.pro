# (C) Copyright 2018
# Urs Fässler, bbv Software Services, http://bbv.ch
#
# SPDX-License-Identifier:	Apache-2.0

include(common.pri)

TEMPLATE = app

CONFIG += console

QT -= gui
QT += testlib

SOURCES += \
    cute-adapter-testing/SimulatedTimerFactory.test.cpp \
    cute-adapter-testing/SimulatedTimerFactory.cpp \
    cute-adapter-testing/SimulatedTimer.cpp \
    cute-adapter-testing/SimulatedTime.cpp \
    cute-adapter-testing/Time.dummy.cpp \
    cute-adapter-testing/TimerSink.testsupport.cpp \
    cute-adapter-testing/SignalReceiver.testsupport.cpp

HEADERS += \
    cute-adapter-testing/SimulatedTimerFactory.h \
    cute-adapter-testing/SimulatedTimer.h \
    cute-adapter-testing/SimulatedTime.h \
    cute-adapter-testing/Time.dummy.h \
    cute-adapter-testing/TimerSink.testsupport.h \
    cute-adapter-testing/SignalReceiver.testsupport.h

LIBS += -lgtest -lgmock_main -lgmock
