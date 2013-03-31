#include <new>
#include <cstring>
#include "FTrackerUtil.h"

char* CreateFunctionName(const char *typeName, const char *funcName, const char *argList) {
    
    int length = strlen(typeName) + strlen(funcName) + strlen(argList) + 1;
    
    char *fullName = new (std::nothrow) char [length];
    if(fullName != NULL) {
        
        memset(fullName, 0, length);
        
        int numCharacters = 0;
        int typeLength = strlen(typeName);
        for(int i = 0; i < typeLength && numCharacters == 0; ++i) {
            
            if(typeName[i] == ' ')
                numCharacters = i + 1;
        }
        
        strncpy(fullName, typeName, numCharacters);
        strcat(fullName, funcName);
        strcat(fullName, argList);
    }
    
    return fullName;
}

char* CreateMethodName(const char *typeName, const char *className, const char *methodName, const char *argList) {
    
    int length = strlen(typeName) + strlen(className) + strlen(methodName) + strlen(argList) + 3;
    
    char *fullName = new (std::nothrow) char [length];
    if(fullName != NULL) {
        
        memset(fullName, 0, length);
        
        int numCharacters = 0;
        int typeLength = strlen(typeName);
        for(int i = 0; i < typeLength && numCharacters == 0; ++i) {
            
            if(typeName[i] == ' ')
                numCharacters = i + 1;
        }
        
        strncpy(fullName, typeName, numCharacters);
        
        strcat(fullName, className);
        strcat(fullName, "::");
        strcat(fullName, methodName);
        strcat(fullName, argList);
    }
    
    return fullName;
}
