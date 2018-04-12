/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#include "UuidRepository.h"

namespace cute_adapter_testing
{


QUuid UuidRepository::generate()
{
  if (uuids.isEmpty()) {
    throw std::runtime_error("no more uuids available");
  }

  const auto uuid = uuids.front();
  uuids.pop_front();
  return uuid;
}

void UuidRepository::clear()
{
  uuids.clear();
}

void UuidRepository::append(const QUuid &value)
{
  uuids.append(value);
}


}
