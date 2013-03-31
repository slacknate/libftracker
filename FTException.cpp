#include "FTException.h"
#include "FTracker.h"
#include "FTrackerDefs.h"

/*
Initialize ou exception. Store all data.
*/
FTException::FTException(const char *f, unsigned int l, void *d) {
    
    fileName = f;
    line = l;
    data = d;
}

/*
Return the file name.
*/
const char *const FTException::File() {
    
    return fileName;
}

/*
Return the line number.
*/
unsigned int FTException::Line() {
    
    return line;
}

/*
Return user data pointer.
*/
void* FTException::Data() {
    
    return data;
}
