/*
 * (C) Copyright 2018
 * Urs Fässler
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#include "parser.h"

#include <gtest/gtest.h>
#include <QString>
#include <QDateTime>


namespace
{


TEST(cucumber_parser, can_parse_QString)
{
  std::istringstream stream{"Hello World"};
  QString testee;

  stream >> testee;

  ASSERT_EQ("Hello World", testee.toStdString());
}


TEST(cucumber_parser, can_parse_QDateTime)
{
  const QDateTime expected{{1990, 6, 13}, {15, 47, 12}, Qt::OffsetFromUTC, 4*60*60};
  std::istringstream stream{"1990-06-13T15:47:12+04:00"};
  QDateTime testee;

  stream >> testee;

  ASSERT_EQ(expected, testee);
}


}
