/*************************************************************
 * Copyright © 2015, Felix Bytow <felix.bytow@googlemail.com *
 *                                                           *
 * See the file COPYING for copying permissions.             *
 *************************************************************/

#ifndef MATHPARSER_OPTIONAL_HXX
#define MATHPARSER_OPTIONAL_HXX

#include <memory>
#include <utility>

#include "exception.hxx"

namespace mp
{
    template <typename T>
    class optional
    {
    public:
        optional()
            : value_(nullptr)
        {
        }

        optional(T const & value)
            : value_(new T(value))
        {
        }

        optional(optional const & src)
            : value_(new T(*(src.value_)))
        {
        }

        optional(optional && src)
            : value_(std::move(src.value_))
        {
        }

        optional & operator = (optional const & rhs)
        {
            value_.reset(new T(*(rhs.value_)));
            return *this;
        }

        optional & operator = (optional && rhs)
        {
            value_ = std::move(rhs.value_);
            return *this;
        }

        explicit operator bool () const
        {
            return value_ != nullptr;
        }

        bool operator ! () const
        {
            return value_ == nullptr;
        }

        T & operator * () const
        {
            if (value_ == nullptr)
                throw exception("dereferencing empty optional");
            return *value_;
        }

        T * operator -> () const
        {
            return value_;
        }

    private:
        std::unique_ptr<T> value_;
    };
}

#endif // MATHPARSER_OPTIONAL_HXX
