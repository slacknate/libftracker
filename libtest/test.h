#ifndef TEST_H
#define TEST_H

#include "FTracker.h"

class test {
    
    public:
        
        test();
        ~test();
        
        FT_DECL_METHOD(double*, test, method, int);
        //FT_DECL_METHOD(double*, test, method, (int, int));
        FT_DECL_METHOD(void, test, thrower);
};

class test2 {
    
    public:
        
        test2();
        ~test2();
};

#endif
