# (C) Copyright 2018
# Urs Fässler, bbv Software Services, http://bbv.ch
#
# SPDX-License-Identifier:	Apache-2.0

VERSION = 0.0.2

OBJECTS_DIR = ./$$TARGET-obj/  # workaround for: https://bugreports.qt.io/browse/QTBUG-50803

CONFIG += warn_on
CONFIG += object_parallel_to_source
CONFIG += c++11

QMAKE_CXXFLAGS += -Wall -Wextra -pedantic

isEmpty(PREFIX) {
    PREFIX = /usr/
}
