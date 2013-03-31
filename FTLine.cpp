#include "FTLine.h"

/*
Store a line number for a given function
in the provided map.
*/
FTLine::FTLine(FTLineMap& map, const char *const func, int line) {
    
    map[func] = line;
}
