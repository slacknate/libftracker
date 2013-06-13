#define FT_SPACE_NAME TestFile
#include "test.h"

FT_DECLARE()
FT_IMPLEMENT()

FT_BEGIN_CTOR(test, ())
test::test() {
    
    
}
FT_END_CTOR(test)

FT_BEGIN_DTOR(test)
test::~test() {
    
    
}
FT_END_DTOR(test)

FT_BEGIN_METHOD(void, test, method, int)
double* test::method(int x) {
    
    printf("method 1! %d\n", x);
    
    return NULL;
}
FT_END_METHOD(test, method)

/*FT_BEGIN_METHOD(void, test, method, (int, int))
double* test::method(int x, int y) {
    
    printf("method 2!\n");
    
    return NULL;
}
FT_END_METHOD(test, method)*/


FT_BEGIN_METHOD(void, test, thrower)
void test::thrower() {
    
    FT_THROW(this);
}
FT_END_METHOD(test, thrower)
