#ifndef combustionModel_H
#define combustionModel_H

#include "word.H"
#include "HashTable.H"

using namespace Foam;

class combustionModelBase
{
    public: 

        // Declare the static variable typeName of the class combustionModelBase.
        static const ::Foam::word typeName;
        static int debug;

        // Empty constructor. 
        combustionModelBase () {};

        // Destructor: needs to be declared virtual since 
        virtual ~combustionModelBase() {};

        typedef HashTable< label, word > WordConstructorTable;
        static WordConstructorTable* WordConstructorTablePtr_;
        static void constructWordConstructorTables();
        static void destroyWordConstructorTables();
        template< class Type >
        class addWordConstructorToTable
        {
            public:
            addWordConstructorToTable( const word& lookup = Type::typeName )
            {
                constructWordConstructorTables();
                std::cout << "Try to insert " << lookup 
                << " into the WordConstructorTablePtr_"
                << std::endl;
                if (!WordConstructorTablePtr_->insert(lookup, Type::debug))
                {
                    std::cerr<< "Duplicate entry "
                        << lookup << " in runtime selection table "
                        << "combustionModelBase" << std::endl;
                    error::safePrintStack(std::cerr);
                }
            }
            
            ~addWordConstructorToTable()
            {
                destroyWordConstructorTables();
            }
        };

        // static Factory Method (selector)
        static void New (const word& modelName);

};

#endif

// ************************************************************************* //
