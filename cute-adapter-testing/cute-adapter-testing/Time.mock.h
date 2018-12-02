/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#pragma once

#include <cute-adapter/Time.h>

#include <gmock/gmock.h>

namespace infrastructure
{


class TimeMock :
    public cute_adapter::Time
{
public:
  MOCK_CONST_METHOD0(now, QDateTime());

};


}
