#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "word.H"
#include "IOstreams.H"
using namespace Foam;

// define a function pointer type
typedef void (*funcType)(void);

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        Info << "usage: <library>\n" << endl;
        return 0;
    }

    char* librarypath = argv[1];

    // RTLD_LAZY means "there may be symbols that can't be resolved;
    // don't try to resolve them until they're used." 
    auto libhandle = dlopen(librarypath, RTLD_LAZY | RTLD_GLOBAL);

    if(libhandle != NULL)
    {
        Info << librarypath << " is found." << endl;

        auto voidPtr = dlsym(libhandle, "_Z16get_library_namev");

        funcType funcPtr = (funcType)voidPtr;

        funcPtr();

        dlclose(libhandle);
    }
    else
    {
        Info << librarypath << " is not found." << endl;
    }

    return 0;
}