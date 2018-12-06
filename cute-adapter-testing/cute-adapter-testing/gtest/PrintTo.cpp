/*
 * (C) Copyright 2018
 * Urs Fässler
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#include "PrintTo.h"

#include <sstream>


void PrintTo(const QString& value, std::ostream* stream)
{
  *stream << "\"" << value.toStdString() << "\"";
}

void PrintTo(const QDateTime& value, std::ostream* stream)
{
  *stream << value.toString(Qt::ISODate).toStdString();
}
