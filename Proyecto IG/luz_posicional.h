#ifndef LUZ_POSICIONAL_H_INCLUDED
#define LUZ_POSICIONAL_H_INCLUDED

#include "aux.h"
#include "luz.h"
class LuzPosicional : public Luz {
    public :
        LuzPosicional ( const Tupla3f & posicion, const GLenum idLuzOpenGl, const Tupla4f &colorAmbiente,  const Tupla4f &colorEspecular, const Tupla4f &colorDifuso ) ;
        void variarPosicionLuz(int aumentox, int aumentoy, int aumentoz);

};  

#endif