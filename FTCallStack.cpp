#include "FTCallStack.h"

/*
List declarations.
*/
FTNameList FTCallStack::files;
FTLineList FTCallStack::lines;
FTNameList FTCallStack::funcs;

/*

*/
void FTCallStack::Post(const char *const fileName, unsigned int line, const char *const funcName) {
    
    files.push_back(fileName);
    lines.push_back(line);
    funcs.push_back(funcName);
}

/*
Print out the call stack to the given C style stream.
*/
void FTCallStack::Print(FILE *stream) {
    
    if(stream != NULL) {

        for(int i = 0; i < files.size(); ++i)
            fprintf(stream, "%s, %s, %d\n", files[i], funcs[i], lines[i]);
    }
}

/*
Print out the call stack to the given C++ style output stream.
*/
void FTCallStack::Print(std::ostream& stream) {
    
    for(int i = 0; i < files.size(); ++i)
        stream << files[i] << ", " << funcs[i] << ", " << lines[i] << std::endl;
}
