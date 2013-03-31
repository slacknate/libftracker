#ifndef FT_CALL_STACK_H
#define FT_CALL_STACK_H

#include "FTrackerTypes.h"

/*

*/
class FTCallStack {
    
    private:
        
        static FTNameList files; // list of file names
        static FTLineList lines; // list of line numbers
        static FTNameList funcs; // list of function names
        
    public:
        
        FTCallStack() {} // create our stack as empty
        
        void Post(const char *const fileName, unsigned int line, const char *const funcName);
        void Print(FILE *stream);
        void Print(std::ostream& stream);
};

#endif
