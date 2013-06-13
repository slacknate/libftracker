#ifndef FTRACKER_DEFS_H
#define FTRACKER_DEFS_H

#include "FTLine.h"
#include "FTFunc.h"
#include "FTNameLookup.h"
#include "FTCallStack.h"
#include "FTException.h"

/*
Function table handling macros.
*/
#define FT_DECLARE()                            namespace FT_SPACE_NAME { FTFuncMap FuncMap; FTLineMap StartTable; FTLineMap EndTable; }

#define FT_IMPLEMENT()                          namespace FT_SPACE_NAME { \
                                                const char *const NameLookupFunc(int line) { \
                                                FTLineMap::iterator i; \
                                                FTLineMap::iterator k; k = EndTable.begin(); \
                                                for(i = StartTable.begin(); i != StartTable.end(); ++i, ++k) { \
                                                const char *const funcName = i->first; \
                                                unsigned int start = i->second; unsigned int end = k->second; \
                                                if(line > start && line < end) return funcName; } return NULL; } \
                                                FTNameLookup FT_SPACE_NAME ## NameLookup(__FILE__, &NameLookupFunc); \
                                                void* FuncLookupFunc(const char *name) { \
                                                if(name != NULL) return FuncMap[name]; else return NULL; } } 

/*
Function tracking macros.
*/
#define FT_DECL_FUNC(type, funcName, argList)   namespace FT_SPACE_NAME { namespace funcName ## Space { \
                                                extern const char *const func; } \
                                                typedef type (*funcName ## ptr)argList; } type funcName argList

#define FT_BEGIN_FUNC(type, funcName, argList)  namespace FT_SPACE_NAME { namespace funcName ## Space { const char *const func = #type " " #funcName #argList; \
                                                FTLine start(StartTable, func, __LINE__); } }

#define FT_END_FUNC(funcName)                   namespace FT_SPACE_NAME { namespace funcName ## Space { FTLine end(EndTable, func, __LINE__); } }                                        

/*
Class method tracking macros.
*/
#define FT_DECL_METHOD(type, className, funcName, argList) \
                                                class funcName ## Space { public: \
                                                typedef type (className::*funcName ## ptr) argList; \
                                                static const char *const method; }; \
                                                type funcName argList;

#define FT_BEGIN_CTOR(className, argList)       namespace FT_SPACE_NAME { namespace className ## CtorSpace { const char *const ctor = #className "::" #className #argList; \
                                                FTLine start(StartTable, ctor, __LINE__); } }

#define FT_END_CTOR(className)                  namespace FT_SPACE_NAME { namespace className ## CtorSpace { \
                                                FTLine end(EndTable, ctor, __LINE__); } }
                                
#define FT_BEGIN_DTOR(className)                namespace FT_SPACE_NAME { namespace className ## DtorSpace { const char *const dtor = #className "::~" #className "()"; \
                                                FTLine start(StartTable, dtor, __LINE__); } }

#define FT_END_DTOR(className)                  namespace FT_SPACE_NAME { namespace className ## DtorSpace { \
                                                FTLine end(EndTable, dtor, __LINE__); } }                                         
                                            
#define FT_BEGIN_METHOD(type, className, funcName, argList) \
                                                const char *const className::funcName ## Space::method = #type " " #className "::" #funcName #argList; \
                                                namespace FT_SPACE_NAME { namespace className ## funcName ## Space { ; \
                                                FTLine start(StartTable, className::funcName ## Space::method, __LINE__); } }

#define FT_END_METHOD(className, funcName)      namespace FT_SPACE_NAME { namespace className ## funcName ## Space { \
                                                FTLine end(EndTable, className::funcName ## Space::method, __LINE__); } }

/*
Function calling.
*/
#define FT_CALL(funcName, argList)              funcName argList; CallStack.Post(__FILE__, __LINE__, FT_SPACE_NAME::funcName ## Space::func)

#define FT_CTOR(className, argList)             className argList; CallStack.Post(__FILE__, __LINE__, #className "::" #className #argList)

#define FT_INVOKE(className, object, funcName, argList) \
                                                (object).funcName argList; CallStack.Post(__FILE__, __LINE__, className::funcName ## Space::method)

/*
Utility macros.
*/                                           
#define FT_THROW(data)                          throw FTException(__FILE__, __LINE__, data)
    
#define FT_PRINT_STACK(stream)                  CallStack.Print(stream)

#define FT_FUNC_LOOKUP(fileName, lineNumber)    NameLookup.GetFunction(fileName, lineNumber)

#endif
