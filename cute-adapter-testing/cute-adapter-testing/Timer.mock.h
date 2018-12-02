/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#pragma once

#include <cute-adapter/Timer.h>

#include <gmock/gmock.h>

namespace infrastructure
{


class TimerMock :
    public cute_adapter::Timer
{
public:
  MOCK_CONST_METHOD0(isActive, bool());
  MOCK_METHOD1(setInterval, void(int));
  MOCK_CONST_METHOD0(interval, int());
  MOCK_METHOD1(setSingleShot, void(bool));

  MOCK_METHOD0(start, void());
  MOCK_METHOD0(stop, void());
};


}
