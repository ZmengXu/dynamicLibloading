#include "combustionModel.H"

combustionModelBase::WordConstructorTable* combustionModelBase::WordConstructorTablePtr_ = __null;
void combustionModelBase::constructWordConstructorTables()
{
    static bool constructed = false;
    if (!constructed)
    {
        constructed = true;
        combustionModelBase::WordConstructorTablePtr_ = new combustionModelBase::WordConstructorTable;
    }
};
    
void combustionModelBase::destroyWordConstructorTables()
{
    if (combustionModelBase::WordConstructorTablePtr_)
    {
        delete combustionModelBase::WordConstructorTablePtr_;
        combustionModelBase::WordConstructorTablePtr_ = __null;
    }
};

const ::Foam::word combustionModelBase::typeName("base");
int combustionModelBase::debug(0);
//combustionModelBase::addWordConstructorToTable< combustionModelBase > addcombustionModelBaseWordConstructorTocombustionModelBaseTable_;
