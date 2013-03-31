#ifndef TEST_H
#define TEST_H

#include "FTracker.h"

class test {
    
    public:
        
        test();
        ~test();
        
        double* method(int x);
        double* method(int x, int y);
        
        void thrower();
};

FT_DECL_METHOD(double*, test, method, (int));
//FT_DECL_METHOD(double*, test, method, (int, int));
FT_DECL_METHOD(void, test, thrower, ());

#endif
