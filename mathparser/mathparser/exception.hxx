/*************************************************************
 * Copyright © 2015, Felix Bytow <felix.bytow@googlemail.com *
 *                                                           *
 * See the file COPYING for copying permissions.             *
 *************************************************************/

#ifndef MATHPARSER_EXCEPTION_HXX
#define MATHPARSER_EXCEPTION_HXX

#include <stdexcept>

namespace mp
{
    class exception
        : public std::runtime_error
    {
    public:
        exception(std::string const & message);
        exception(char const * message);
    };
}

#endif // MATHPARSER_EXCEPTION_HXX
