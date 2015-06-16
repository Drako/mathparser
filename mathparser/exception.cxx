/*************************************************************
 * Copyright © 2015, Felix Bytow <felix.bytow@googlemail.com *
 *                                                           *
 * See the file COPYING for copying permissions.             *
 *************************************************************/

#include <mathparser/exception.hxx>

namespace mp
{
    exception::exception(std::string const & message)
        : std::runtime_error(message)
    {
    }
    
    exception::exception(char const * message)
        : std::runtime_error(message)
    {
    }
}
