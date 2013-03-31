#ifndef FT_EXCEPTION_H
#define FT_EXCEPTION_H

/*
Exception class which retains the file
and line from which it was thrown.
*/
class FTException { 
    
    protected:
        
        const char *fileName; // file name
        unsigned int line; // line number
        void *data; // user data
    
    public:
        
        FTException(const char *f, unsigned int l, void *d);
        
        const char *const File();
        unsigned int Line();
        void* Data();
};

#endif
