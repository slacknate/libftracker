#ifndef FT_NAME_LOOKUP_H
#define FT_NAME_LOOKUP_H

#include "FTrackerTypes.h"

/*
Tracks the location of all specified
functions and class methods.
*/
class FTNameLookup {
    
    private:
        
        static FTNameList files; // list of file names
        static FTFuncList look; // list of function pointers
        
    public:
        
        FTNameLookup() {} // used for global tracker initialization
        FTNameLookup(const char *fileName, FT_LOOK_NAME_PTR lookFunc);
        
        const char *const GetFunction(const char *const fileName, const unsigned int line);
};

#endif
