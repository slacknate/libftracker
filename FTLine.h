#ifndef FT_LINE_H
#define FT_LINE_H

#include "FTrackerTypes.h"

/*
Stores a line number in a map.
*/
class FTLine {
    
    public:
        
        FTLine(FTLineMap& map, const char *const func, int line);
};

#endif
