#ifndef PaSR_H
#define PaSR_H

#include "WSR.H"

using namespace Foam;

class PaSR
:
    public WSR 
{
    public: 

        // Declare the static variable typeName of the class PaSR.
        static const ::Foam::word typeName;
        static int debug;

        // Empty constructor. 
        PaSR ()
        {
            Info << "Constructing " << typeName << endl;
        };
};

#endif

// ************************************************************************* //
