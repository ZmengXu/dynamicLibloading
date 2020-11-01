#include "combustionModel.H"

// static Factory Method (selector)
void combustionModelBase::New (const word& modelName)
{

    Info<< "\nWe are now in combustionModelBase::New fucntion "
        << "\nlooking for the "
        << modelName
        << " in the WordConstructorTable\n"
        << WordConstructorTablePtr_->sortedToc()
        << endl;

    // Find the class typeName pointer in the RTS Table 
    // (HashTable<word, autoPtr<combustionModelBase>(*)(word))
    WordConstructorTable::iterator cstrIter =
        WordConstructorTablePtr_->find(modelName);

    // If the Factory Method was not found. 
    if (cstrIter == WordConstructorTablePtr_->end())
    {
        FatalErrorIn
        (
            "combustionModelBase::New(const word&)"
        )   << "Unknown combustionModelBase type "
            << modelName << nl << nl
            << "Valid combustionModelBase types are :" << endl
            << WordConstructorTablePtr_->sortedToc()
            << exit(FatalError);
    }

    Info<< "\nWe found the modelName "
        << modelName
        << "\nThe debug value for it is "
        << (*WordConstructorTablePtr_)[modelName] << endl;

}