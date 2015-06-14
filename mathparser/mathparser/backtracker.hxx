#ifndef MATHPARSER_BACKTRACKER_HXX
#define MATHPARSER_BACKTRACKER_HXX

namespace mp
{
    template <typename T>
    class backtracker
    {
    public:
        backtracker(T & val)
            : old_val_(val)
            , target_(&val)
        {
        }
        
        ~backtracker()
        {
            if (target_)
                *target_ = old_val_;
        }
        
        T old_value() const
        {
            return old_val_;
        }
        
        void disable()
        {
            target_ = 0;
        }
        
        bool is_disabled() const
        {
            return target_ == 0;
        }
        
    private:
        T old_val_;
        T * target_;
    };
}

#endif // MATHPARSER_BACKTRACKER_HXX
