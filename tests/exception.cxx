/*************************************************************
 * Copyright © 2015, Felix Bytow <felix.bytow@googlemail.com *
 *                                                           *
 * See the file COPYING for copying permissions.             *
 *************************************************************/

#include <mathparser/exception.hxx>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(Exception, CarriesMessage)
{
    using ::testing::StrEq;
    
    try
    {
        throw mp::exception("foo");
    }
    catch (mp::exception const & ex)
    {
        EXPECT_THAT(ex.what(), StrEq("foo"));
    }
    
    try
    {
        std::string msg("bar");
        throw mp::exception(msg);
    }
    catch (mp::exception const & ex)
    {
        EXPECT_THAT(ex.what(), StrEq("bar"));
    }
}

TEST(Exception, IsARuntimeError)
{
    EXPECT_THROW(throw mp::exception(""), std::runtime_error);
}
