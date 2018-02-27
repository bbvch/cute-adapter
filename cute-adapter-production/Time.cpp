/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#include "Time.h"

namespace cute_adapter_production
{


QDateTime Time::now() const
{
  return QDateTime::currentDateTime().toUTC();
}


}
