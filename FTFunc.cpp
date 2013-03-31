#include "FTFunc.h"

/*
Store a function pointer
in the provided map.
*/
FTFunc::FTFunc(FTFuncMap& map, const char *const func, void *ptr) {
    
    map[func] = ptr;
}
