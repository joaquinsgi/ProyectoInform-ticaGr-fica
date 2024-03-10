#ifndef TRONCO_H_INCLUDED
#define TRONCO_H_INCLUDED

#include "aux.h"
#include "objrevolucion.h"
#include "esfera.h"
#include "cubo.h"
#include "cilindro.h"

class Tronco : public ObjRevolucion
{
   public:
   Tronco();
   void draw(char opcion);
   Cubo * cubo = nullptr;
   Cilindro * cuello = nullptr;


};





#endif