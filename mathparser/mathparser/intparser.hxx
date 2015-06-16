/*************************************************************
 * Copyright © 2015, Felix Bytow <felix.bytow@googlemail.com *
 *                                                           *
 * See the file COPYING for copying permissions.             *
 *************************************************************/

#ifndef MATHPARSER_INTPARSER_HXX
#define MATHPARSER_INTPARSER_HXX

#include "backtracker.hxx"
#include "exception.hxx"
#include "optional.hxx"

#include <cctype>

namespace mp
{
    class intparser
    {
    public:
        template <typename Iterator>
        static optional<int> parse(Iterator & it, Iterator end)
        {
            backtracker<Iterator> bt(it);

            if (!std::isdigit(*it))
                return {};

            int n = *it++ - '0';
            while (std::isdigit(*it))
            {
                n *= 10;
                n += *it++ - '0';
                if (n < 0)
                    throw exception("literal too big");
            }

            bt.disable();
            return n;
        }
    };
}

#endif // MATHPARSER_INTPARSER_HXX
