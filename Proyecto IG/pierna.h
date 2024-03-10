#ifndef PIERNA_H_INCLUDED
#define PIERNA_H_INCLUDED

#include "aux.h"
#include "objrevolucion.h"
#include "cilindro.h"
#include "cubo.h"
//AntePierna Cilindro Pierna Cilindro Pie Esfera(Transformada) + Cilindros y Esferas


class Pierna : public ObjRevolucion
{
   public:
   Pierna();
   void draw(char opcion);
   Cilindro * cilindro1 = nullptr;
   Cilindro * tobillo = nullptr;
   Cubo * pie = nullptr;


};





#endif