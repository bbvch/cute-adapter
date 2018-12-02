/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#pragma once

#include <cute-adapter/UuidGenerator.h>
#include <QList>

namespace cute_adapter_testing
{


class UuidRepository :
    public cute_adapter::UuidGenerator
{
public:
  QUuid generate() override;

  void clear();
  void append(const QUuid&);

private:
  QList<QUuid> uuids{};

};


}
