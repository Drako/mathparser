/*************************************************************
 * Copyright © 2015, Felix Bytow <felix.bytow@googlemail.com *
 *                                                           *
 * See the file COPYING for copying permissions.             *
 *************************************************************/

#include <mathparser/intparser.hxx>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <string>

TEST(IntParser, ReturnsInvalidWhenNotStartingWithDigit)
{
    using ::testing::Eq;

    std::string not_a_number("a");
    auto it = not_a_number.begin();

    auto result = mp::intparser::parse(it, not_a_number.end());
    EXPECT_THAT(!result, Eq(true));
}

TEST(IntParser, StopsOnInvalidCharacter)
{
    using ::testing::Eq;
    using ::testing::Ne;

    std::string partial_number("23alpha");
    auto it = partial_number.begin();

    auto result = mp::intparser::parse(it, partial_number.end());
    EXPECT_THAT(*result, Eq(23));
    EXPECT_THAT(it, Ne(partial_number.end()));
}

TEST(IntParser, ThrowsOnTooLargeLiteral)
{
    std::string big_number("762395876395876234978623984763498527985702397503428975");
    auto it = big_number.begin();

    EXPECT_THROW(mp::intparser::parse(it, big_number.end()), mp::exception);
}

TEST(IntParser, ParsesCompleteNumber)
{
    using ::testing::Eq;

    std::string number("42");
    auto it = number.begin();

    auto result = mp::intparser::parse(it, number.end());
    EXPECT_THAT(*result, Eq(42));
    EXPECT_THAT(it, Eq(number.end()));
}
