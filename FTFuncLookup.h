#ifndef FT_FUNC_LOOKUP_H
#define FT_FUNC_LOOKUP_H

#include "FTrackerTypes.h"

/*
Tracks the location of all specified
functions and class methods.
*/
class FTFuncLookup {
    
    private:
        
        static FTNameList files; // list of file names
        static FTFuncList look; // list of function pointers
        
    public:
        
        FTFuncLookup() {} // used for global tracker initialization
        FTFuncLookup(const char *fileName, FT_LOOK_FUNC_PTR lookFunc);
        
        void* GetFunction(const char *fileName, const char *funcName);
};

#endif
