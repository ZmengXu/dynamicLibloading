#include "combustionModel.H"
#include "IFstream.H"
#include "dictionary.H"
#include "dlLibraryTable.H"

using namespace Foam;

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        printf("usage: %s <modelname>\n", argv[0]);
        exit(1);
    }

    dictionary controlDict(IFstream("controlDict")());
    //- Any loaded dynamic libraries. Make sure to construct before
    //  reading controlDict.
    dlLibraryTable libraries(controlDict, "libs");

    // Get the name of the algorithm from the arguments passed to the
    // application. 
    const word modelName = argv[1];

    // RTS call. 
    combustionModelBase::New(modelName);

    Info<< "\nEnd\n" << endl;

    return 0;
}

// ************************************************************************* //
