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

    mp::intparser parser;
    auto result = parser.parse(it, not_a_number.end());
    ASSERT_THAT(!result, Eq(true));
}

TEST(IntParser, StopsOnInvalidCharacter)
{
    using ::testing::Eq;
    using ::testing::Ne;

    std::string partial_number("23alpha");
    auto it = partial_number.begin();

    mp::intparser parser;
    auto result = parser.parse(it, partial_number.end());
    ASSERT_THAT(*result, Eq(23));
    ASSERT_THAT(it, Ne(partial_number.end()));
}

TEST(IntParser, ThrowsOnTooLargeLiteral)
{
    std::string big_number("762395876395876234978623984763498527985702397503428975");
    auto it = big_number.begin();

    mp::intparser parser;
    ASSERT_THROW(parser.parse(it, big_number.end()), std::runtime_error);
}

TEST(IntParser, ParsesCompleteNumber)
{
    using ::testing::Eq;

    std::string number("42");
    auto it = number.begin();

    mp::intparser parser;
    auto result = parser.parse(it, number.end());
    ASSERT_THAT(*result, Eq(42));
    ASSERT_THAT(it, Eq(number.end()));
}
