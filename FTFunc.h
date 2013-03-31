#ifndef FT_FUNC_H
#define FT_FUNC_H

#include "FTrackerTypes.h"

/*
Stores a function pointer in a map.
*/
class FTFunc {
    
    public:
        
        FTFunc(FTFuncMap& map, const char *const func, void *ptr);
};

#endif
