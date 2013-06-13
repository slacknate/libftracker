#ifndef TEST_H
#define TEST_H

#include "FTracker.h"

class test {
    
    public:
        
        test();
        ~test();
        
        FT_DECL_METHOD(double*, test, method, (int));
        //FT_DECL_METHOD(double*, test, method, (int, int));
        FT_DECL_METHOD(void, test, thrower, ());
};

#endif
