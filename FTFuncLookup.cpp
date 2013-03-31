#include "FTFuncLookup.h"

/*
List declarations.
*/
FTNameList FTFuncLookup::files;
FTFuncList FTFuncLookup::look;

/*
Add a set of functions to our list.
Store which file they came from
and how many functions we grabbed.
*/
FTFuncLookup::FTFuncLookup(const char *fileName, FT_LOOK_FUNC_PTR lookFunc) {
    
    files.push_back(fileName);
    look.push_back((void*)lookFunc);
}

/*
Get a function table by file name, and
return the function name based on line
number.
*/
void* FTFuncLookup::GetFunction(const char *fileName, const char *funcName) {
    
    for(int i = 0; i < look.size(); ++i) {
        
        if(!strcmp(files[i], fileName))
            return ((FT_LOOK_FUNC_PTR)look[i])(funcName);
    }
    
    return NULL;
}

