/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#pragma once

#include <cute-adapter/UuidGenerator.h>

namespace cute_adapter_production
{


class UuidGenerator :
    public cute_adapter::UuidGenerator
{
public:
  QUuid generate() override;

};


}
