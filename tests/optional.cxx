/*************************************************************
 * Copyright © 2015, Felix Bytow <felix.bytow@googlemail.com *
 *                                                           *
 * See the file COPYING for copying permissions.             *
 *************************************************************/

#include <mathparser/optional.hxx>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(Optional, IsInvalidByDefault)
{
    using ::testing::Eq;

    mp::optional<int> oi;
    ASSERT_THAT(!oi, Eq(true));
}

TEST(Optional, IsValidWhenSet)
{
    using ::testing::Eq;

    mp::optional<int> oi(42);
    ASSERT_THAT(!oi, Eq(false));
}

TEST(Optional, BooleanValueMatchesValidity)
{
    using ::testing::Eq;

    mp::optional<int> invalid;
    ASSERT_THAT(static_cast<bool>(invalid), Eq(false));

    mp::optional<int> valid(42);
    ASSERT_THAT(static_cast<bool>(valid), Eq(true));
}

TEST(Optional, ThrowsWhenDereferencingInvalid)
{
    mp::optional<int> invalid;
    ASSERT_THROW(*invalid, std::runtime_error);
}

TEST(Optional, ReturnsValueWhenDereferenced)
{
    using ::testing::Eq;

    mp::optional<int> oi(42);
    ASSERT_THAT(*oi, Eq(42));
}
