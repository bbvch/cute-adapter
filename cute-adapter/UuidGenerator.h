/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#pragma once

#include <QUuid>

namespace cute_adapter
{


class UuidGenerator
{
public:
  virtual ~UuidGenerator();

  virtual QUuid generate() = 0;

};


}
