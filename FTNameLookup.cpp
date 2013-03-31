#include "FTNameLookup.h"

/*
List declarations.
*/
FTNameList FTNameLookup::files;
FTFuncList FTNameLookup::look;

/*
Add a set of functions to our list.
Store which file they came from
and how many functions we grabbed.
*/
FTNameLookup::FTNameLookup(const char *fileName, FT_LOOK_NAME_PTR lookFunc) {
    
    files.push_back(fileName);
    look.push_back((void*)lookFunc);
}

/*
Get a function table by file name, and
return the function name based on line
number.
*/
const char *const FTNameLookup::GetFunction(const char *const fileName, const unsigned int line) {
    
    for(int i = 0; i < look.size(); ++i) {
        
        if(!strcmp(files[i], fileName))
            return ((FT_LOOK_NAME_PTR)look[i])(line);
    }
    
    return NULL;
}
