/*
 * (C) Copyright 2018
 * Urs Fässler
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#include "stream.h"

#include <gtest/gtest.h>
#include <QString>
#include <QDateTime>


namespace
{


TEST(std_stream, can_pretty_print_QString)
{
  std::stringstream stream{};
  const QString testee{"Hello World"};

  stream << testee;

  ASSERT_EQ("\"Hello World\"", stream.str());
}

TEST(std_stream, can_pretty_print_QDateTime)
{
  std::stringstream stream{};
  const QDateTime testee{{1990, 6, 13}, {15, 47, 12}, Qt::OffsetFromUTC, 4*60*60};

  stream << testee;

  ASSERT_EQ("1990-06-13T15:47:12+04:00", stream.str());
}


}
