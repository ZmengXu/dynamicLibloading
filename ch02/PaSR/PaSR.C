#include "PaSR.H"

const ::Foam::word PaSR::typeName("PaSR");
int PaSR::debug(2);
PaSR::addWordConstructorToTable< PaSR > addPaSRWordConstructorTocombustionModelBaseTable_;