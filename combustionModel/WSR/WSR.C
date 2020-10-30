#include "WSR.H"

const ::Foam::word WSR::typeName("WSR");
int WSR::debug(1);
WSR::addWordConstructorToTable< WSR > addWSRWordConstructorTocombustionModelBaseTable_;