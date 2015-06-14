/*************************************************************
 * Copyright © 2015, Felix Bytow <felix.bytow@googlemail.com *
 *                                                           *
 * See the file COPYING for copying permissions.             *
 *************************************************************/

#include <mathparser/backtracker.hxx>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(BackTracker, StoresInitialState)
{
    using ::testing::Eq;
    
    int i = 42;
    mp::backtracker<int> bti(i);
    ASSERT_THAT(bti.old_value(), Eq(42));
}

TEST(BackTracker, RestoresInitialState)
{
    using ::testing::Eq;
    
    int i = 42;
    {
        mp::backtracker<int> bti(i);
        i = 23;
        ASSERT_THAT(i, Eq(23));
    }
    ASSERT_THAT(i, Eq(42));
}

TEST(BackTracker, IsEnabledByDefault)
{
    using ::testing::Eq;
    
    int i = 42;
    mp::backtracker<int> bti(i);
    ASSERT_THAT(bti.is_disabled(), Eq(false));
}

TEST(BackTracker, CanBeDisabled)
{
    using ::testing::Eq;
    
    int i = 42;
    mp::backtracker<int> bti(i);
    bti.disable();
    ASSERT_THAT(bti.is_disabled(), Eq(true));
}

TEST(BackTracker, DoesNotRestoreWhenDisabled)
{
    using ::testing::Eq;
    
    int i = 42;
    {
        mp::backtracker<int> bti(i);
        i = 23;
        ASSERT_THAT(i, Eq(23));
        bti.disable();
    }
    ASSERT_THAT(i, Eq(23));
}
