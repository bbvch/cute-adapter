/*
 * (C) Copyright 2018
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#include "Time.dummy.h"

namespace infrastructure
{


QDateTime TimeDummy::now() const
{
  return _now;
}


}
