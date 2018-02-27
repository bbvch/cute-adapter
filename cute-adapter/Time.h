/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#pragma once

#include <QDateTime>

namespace cute_adapter
{


class Time
{
public:
  virtual ~Time();

  virtual QDateTime now() const = 0;

};


}
