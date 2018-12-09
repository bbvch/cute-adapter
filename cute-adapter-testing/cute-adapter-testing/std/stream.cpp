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

std::ostream& operator<<(std::ostream& stream, const QVariant& value)
{
  switch (value.type()) {
    case QVariant::String:
      stream << value.toString();
      break;
    case QVariant::DateTime:
      stream << value.toDateTime();
      break;
    default:
      stream << value.toString().toStdString();
      break;
  }
  return stream;
}
