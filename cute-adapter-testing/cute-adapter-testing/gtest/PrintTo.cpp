/*
 * (C) Copyright 2018
 * Urs Fässler
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#include "PrintTo.h"

#include "cute-adapter-testing/std/stream.h"


void PrintTo(const QString& value, std::ostream* stream)
{
  *stream << value;
}

void PrintTo(const QDateTime& value, std::ostream* stream)
{
  *stream << value;
}
