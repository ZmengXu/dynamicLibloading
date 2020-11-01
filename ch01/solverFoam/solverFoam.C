#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <link.h> 
#include "word.H"
#include "IOstreams.H"
#include "SHA1Digest.H"
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
/*
    // RTLD_LAZY means "there may be symbols that can't be resolved;
    // don't try to resolve them until they're used." 
    void *libhandle = dlopen(librarypath, RTLD_LAZY);

    if(libhandle != NULL)
    {
        Info << librarypath << " is found." << endl;

        funcType funcPtr = (void (*)())dlsym(libhandle, "get_library_name");

        //funcType funcPtr = (funcType)voidPtr;

        funcPtr();

        dlclose(libhandle);
    }
    else
    {
        Info << librarypath << " is not found." << endl;
        //perror("dlopen");
    }
*/
    auto libhandle = dlopen(librarypath, RTLD_LAZY | RTLD_GLOBAL);
    struct link_map * map = nullptr;
    dlinfo(libhandle, RTLD_DI_LINKMAP, &map);

    Elf64_Sym * symtab = nullptr;
    char * strtab = nullptr;
    int symentries = 0;
    for (auto section = map->l_ld; section->d_tag != DT_NULL; ++section)
    {
        if (section->d_tag == DT_SYMTAB)
        {
            symtab = (Elf64_Sym *)section->d_un.d_ptr;
        }
        if (section->d_tag == DT_STRTAB)
        {
            strtab = (char*)section->d_un.d_ptr;
        }
        if (section->d_tag == DT_SYMENT)
        {
            symentries = section->d_un.d_val;
        }
    }
    int size = strtab - (char *)symtab;
    for (int k = 0; k < size / symentries; ++k)
    {
        auto sym = &symtab[k];
        // If sym is function
        if (ELF64_ST_TYPE(symtab[k].st_info) == STT_FUNC)
        {
            //str is name of each symbol
            auto str = &strtab[sym->st_name];
            printf("%s\n", str);
        }
    }
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
        //perror("dlopen");
    }

    return 0;
}