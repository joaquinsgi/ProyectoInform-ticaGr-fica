#ifndef BRAZO_H_INCLUDED
#define BRAZO_H_INCLUDED

#include "aux.h"
#include "objrevolucion.h"
#include "cilindro.h"
#include "esfera.h"
#include "mano.h"
// Antebrazo-Cilindro Brazo-Cilindro Mano-Esfera(Transformada)y cilindros+esfera

class Brazo : public ObjRevolucion
{
   public:
   Brazo();
   void draw(char opcion);

   Cilindro * cilindro1 = nullptr;
   Cilindro * cilindro2 = nullptr;
   Esfera * codo = nullptr;
   Mano * mano = nullptr;
};





#endif