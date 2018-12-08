/*
 * (C) Copyright 2018
 * Urs Fässler
 *
 * SPDX-License-Identifier:	Apache-2.0
 */

#include "PrintTo.h"

#include <gtest/gtest.h>
#include <QString>
#include <QDateTime>
#include <QVariant>


namespace
{


TEST(gtest_PrintTo, can_pretty_print_QString)
{
  std::stringstream stream{};
  const QString testee{"Hello World"};

  PrintTo(testee, &stream);

  ASSERT_EQ("\"Hello World\"", stream.str());
}

TEST(gtest_PrintTo, can_pretty_print_QVariant_QString)
{
  std::stringstream stream{};
  const QVariant testee{QString{"Hello World"}};

  PrintTo(testee, &stream);

  ASSERT_EQ("\"Hello World\"", stream.str());
}

TEST(gtest_PrintTo, can_pretty_print_QDateTime)
{
  std::stringstream stream{};
  const QDateTime testee{{1990, 6, 13}, {15, 47, 12}, Qt::OffsetFromUTC, 4*60*60};

  PrintTo(testee, &stream);

  ASSERT_EQ("1990-06-13T15:47:12+04:00", stream.str());
}

TEST(gtest_PrintTo, can_pretty_print_QVariant_QDateTime)
{
  std::stringstream stream{};
  const QVariant testee{QDateTime{{1990, 6, 13}, {15, 47, 12}, Qt::OffsetFromUTC, 4*60*60}};

  PrintTo(testee, &stream);

  ASSERT_EQ("1990-06-13T15:47:12+04:00", stream.str());
}


}
