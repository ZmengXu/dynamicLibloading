#ifndef WSR_H
#define WSR_H

#include "combustionModel.H"

class WSR
:
    public combustionModelBase
{
    public: 

        // Declare the static variable typeName of the class WSR.
        static const ::Foam::word typeName;
        static int debug;

        // Empty constructor. 
        WSR ()
        {
            Info << "Constructing " << typeName << endl;
        };
};
#endif
