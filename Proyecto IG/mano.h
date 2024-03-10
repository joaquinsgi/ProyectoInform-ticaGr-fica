#ifndef MANO_H_INCLUDED
#define MANO_H_INCLUDED

#include "aux.h"
#include "objrevolucion.h"
#include "cilindro.h"
#include "esfera.h"
// Antebrazo-Cilindro Brazo-Cilindro Mano-Esfera(Transformada)y cilindros+esfera

class Mano : public Malla3D
{

   public:
   Mano();
   void draw(char opcion);

   Cilindro * dedo1 = nullptr;
   Cilindro * dedo2 = nullptr;
   Cilindro * dedo3 = nullptr;
   Cilindro * dedo4 = nullptr;
   Cilindro * dedo5 = nullptr;

   Esfera * palma = nullptr;

};





#endif