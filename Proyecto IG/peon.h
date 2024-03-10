#ifndef PEON_H_INCLUDED
#define PEON_H_INCLUDED

#include "aux.h"
#include "objrevolucion.h"

class Peon : public ObjRevolucion
{
    public :
    Peon (const int num_vert_perfil , const int num_instancias_perf , const float radio_cubo, const float altura);
} ;




#endif