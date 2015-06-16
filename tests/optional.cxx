/*************************************************************
 * Copyright © 2015, Felix Bytow <felix.bytow@googlemail.com *
 *                                                           *
 * See the file COPYING for copying permissions.             *
 *************************************************************/

#include <mathparser/optional.hxx>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

class Optional
    : public ::testing::Test
{
protected:
    mp::optional<int> invalid_;
    mp::optional<int> valid_;

public:
    Optional()
        : valid_(42)
    {
    }
};

TEST_F(Optional, IsInvalidByDefault)
{
    using ::testing::Eq;

    EXPECT_THAT(!invalid_, Eq(true));
}

TEST_F(Optional, IsValidWhenSet)
{
    using ::testing::Eq;

    EXPECT_THAT(!valid_, Eq(false));
}

TEST_F(Optional, BooleanValueMatchesValidity)
{
    using ::testing::Eq;

    EXPECT_THAT(static_cast<bool>(invalid_), Eq(false));
    EXPECT_THAT(static_cast<bool>(valid_), Eq(true));
}

TEST_F(Optional, ThrowsWhenDereferencingInvalid)
{
    EXPECT_THROW(*invalid_, mp::exception);
}

TEST_F(Optional, ReturnsValueWhenDereferenced)
{
    using ::testing::Eq;

    EXPECT_THAT(*valid_, Eq(42));
}
