// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: piramidehexagonal.h

//
// #############################################################################

#ifndef PIRAMIDE_HEXAGONAL_H_INCLUDED
#define PIRAMIDE_HEXAGONAL_H_INCLUDED

#include "aux.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Pirámide de base hexagonal con base centrada en el origen 

class PiramideHexagonal : public Malla3D
{
   public:
      PiramideHexagonal(float h=1.0,float r=0.5, float r2= 0.25); // 

};




#endif
