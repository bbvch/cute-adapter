/*
 * (C) Copyright 2018
 * Urs Fässler
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#include "stream.h"


std::ostream& operator<<(std::ostream& stream, const QString& value)
{
  stream << "\"" << value.toStdString() << "\"";
  return stream;
}

std::ostream& operator<<(std::ostream& stream, const QDateTime& value)
{
  stream << value.toString(Qt::ISODate).toStdString();
  return stream;
}
