#ifndef FTRACKER_TYPES_H
#define FTRACKER_TYPES_H

#include <map>
#include <vector>
#include <ostream>

typedef const char *const (*FT_LOOK_NAME_PTR)(int);
typedef void* (*FT_LOOK_FUNC_PTR)(const char *const);
typedef std::vector<void*> FTFuncList;
typedef std::map<const char *const, void*> FTFuncMap;
typedef std::map<const char *const, unsigned int> FTLineMap;
typedef std::vector<unsigned int> FTLineList;
typedef std::vector<const char *> FTNameList;

#endif
