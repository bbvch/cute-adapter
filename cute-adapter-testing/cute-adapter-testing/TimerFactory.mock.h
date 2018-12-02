/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#pragma once

#include <cute-adapter/TimerFactory.h>

#include <gmock/gmock.h>

namespace infrastructure
{


class TimerFactoryMock :
    public cute_adapter::TimerFactory
{
public:
  MOCK_METHOD3(singleShot, void(int msec, const QObject *receiver, const char *member));
  MOCK_METHOD0(timer, infrastructure::ITimer*());
};


}
