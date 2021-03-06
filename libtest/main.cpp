#include <cstdlib>
#include <iostream>
#define FT_SPACE_NAME MainFile
#include "main.h"
#include "test.h"

FT_DECLARE()
FT_IMPLEMENT()

FT_BEGIN_FUNC(void, foo)
void foo() {
    
    printf("foo!\n");
}
FT_END_FUNC(foo)

/*FT_BEGIN_FUNC(void, foo, int)
void foo(int x) {
    
    printf("foo!\n");
}
FT_END_FUNC(foo)*/

FT_BEGIN_FUNC(void, bar)
void bar() {
    
    printf("bar!\n");
}
FT_END_FUNC(bar)

FT_BEGIN_FUNC(int, main, (int, char *[]))
int main(int argc, char *argv[]) {
    
    try {
        
        test t = FT_CTOR(test);
        FT_INVOKE(t, method, 5);
        
        for(int i = 0; i < 5; ++i) {
            
            FT_CALL(foo);
        }
        
        FT_CALL(bar);
        
        test *p = new FT_CTOR(test);
        FT_INVOKE(*p, method, 5);
        //FT_INVOKE(*p, method, 5, 7);
        
        FT_INVOKE(t, thrower);
    }
    catch(FTException& e) {
        
        printf("Exception thrown in file \"%s\" in \"%s\", line %d\n", e.File(), FT_FUNC_LOOKUP(e.File(), e.Line()), e.Line());
    }
    
    FT_PRINT_STACK(std::cout);
    
    system("pause");
    return 0;
}
FT_END_FUNC(main)
