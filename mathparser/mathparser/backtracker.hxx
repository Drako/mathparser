/*************************************************************
 * Copyright © 2015, Felix Bytow <felix.bytow@googlemail.com *
 *                                                           *
 * See the file COPYING for copying permissions.             *
 *************************************************************/

#ifndef MATHPARSER_BACKTRACKER_HXX
#define MATHPARSER_BACKTRACKER_HXX

#include <utility>

namespace mp
{
    /**
     * @brief Back tracker used for restoring old parser state.
     * 
     * The main purpose of this class is to store the old position
     * of the Iterators used by the parser. It restores their old
     * values if the input could not be parsed correctly.
     * 
     * \tparam T The data type of the object being backtracked. 
     */
    template <typename T>
    class backtracker
    {
    public:
        /**
         * @brief Constructor
         * 
         * The constructor stores the current value of \p val for later restoration.
         * 
         * \param[in,out] val A reference to an object, that shall be backtracked.
         */
        backtracker(T & val)
            : old_val_(val)
            , target_(std::addressof(val))
        {
        }
        
        /**
         * @brief Destructor
         * 
         * The destructor restores the old value of the object being backtracked.
         * This is only done if the backtracker itself has not been disabled.
         */
        ~backtracker()
        {
            if (!is_disabled())
                *target_ = old_val_;
        }
        
        /**
         * \brief Query the old value of the object being backtracked.
         * 
         * \return The old value of the object being backtracked.
         */
        T old_value() const
        {
            return old_val_;
        }
        
        /**
         * \brief Disabled the backtracking mechanism.
         * 
         * This function disables the backtracker.
         * This way the object being backtracked will keep its value
         * after the backtracker is destroyed.
         * 
         * \attention Disabling the backtracker cannot be undone.
         */
        void disable()
        {
            target_ = nullptr;
        }
        
        /**
         * \brief Check if the backtracker has been disabled.
         * 
         * \return \p true if the backtracker is disabled, \p false otherwise.
         */
        bool is_disabled() const
        {
            return !target_;
        }
        
    private:
        T old_val_;
        T * target_;
    };
}

#endif // MATHPARSER_BACKTRACKER_HXX
