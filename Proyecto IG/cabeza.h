#ifndef CABEZA_H_INCLUDED
#define CABEZA_H_INCLUDED

#include "aux.h"
#include "objrevolucion.h"
#include "cilindro.h"
#include "cubo.h"
#include "esfera.h"
#include "sombrero.h"

class Cabeza : public Malla3D
{
   public:
   Cabeza();
   void draw(char opcion);
   Cilindro * orejaIzda = nullptr;
   Cilindro * orejaDcha = nullptr;
   Cubo * cabeza = nullptr;
   Esfera * boca = nullptr;
   Sombrero * sombrero = nullptr;
   Esfera * ojoIzdo = nullptr;
   Esfera * pupiIzda = nullptr;
   Esfera * ojoDcho = nullptr;
   Esfera * pupiDcha = nullptr;
   Esfera * nariz = nullptr;

};







#endif