#include "combustionModel.H"
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
using namespace Foam;

//typedef int (*funcType)(int);
int main(int argc, char *argv[])
{
    if(argc<2)
    {
        printf("usage: %s <modelname> <library>\n", argv[0]);
        exit(1);
    }

    if(argc==2)
    {
        const word modelName = argv[1];
        // RTS call. 
        combustionModelBase::New(modelName);
    }
    else
    {
        char *librarypath = argv[2];

        void *libhandle = dlopen(librarypath, RTLD_LAZY);

        if(libhandle == NULL)
        {
            perror("dlopen");
        }

        // Get the name of the algorithm from the arguments passed to the
        // application. 
        const word modelName = argv[1];

        // RTS call. 
        combustionModelBase::New(modelName);

        //funcType opfunc = dlsym(libhandle, "do_operation");

        dlclose(libhandle);
    }

    Info<< "\nEnd\n" << endl;

    return 0;
}

// ************************************************************************* //
