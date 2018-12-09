/*
 * (C) Copyright 2018
 * Urs Fässler
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#include "parser.h"

#include <sstream>


void operator>>(std::istringstream& stream, QString& value)
{
  const std::string stdstr = stream.str();
  value = QString::fromStdString(stdstr);
}

void operator>>(std::istringstream& stream, QDateTime& value)
{
  const std::string stdstr = stream.str();
  const auto qstr = QString::fromStdString(stdstr);
  value = QDateTime::fromString(qstr, Qt::ISODate);
}
