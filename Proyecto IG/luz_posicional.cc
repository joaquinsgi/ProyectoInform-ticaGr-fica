#include "luz_posicional.h"

LuzPosicional::LuzPosicional( const Tupla3f & _posicion, const GLenum idLuzOpenGl, const Tupla4f &_colorAmbiente,  const Tupla4f &_colorEspecular, const Tupla4f &_colorDifuso ) {
    posicion[0] = _posicion[0];
    posicion[1] = _posicion[1];
    posicion[2] = _posicion[2];
    posicion[3] = 1.0;
    id = idLuzOpenGl;
    colorAmbiente = _colorAmbiente;
    colorDifuso = _colorDifuso;
    colorEspecular = _colorEspecular;
}

void LuzPosicional::variarPosicionLuz(int aumentox, int aumentoy, int aumentoz){
    float posicionx = posicion[0]+aumentox;
    float posiciony = posicion[1]+aumentoy;
    float posicionz = posicion[2]+aumentoz;
        posicion[0]+= aumentox;
        posicion[1]+= aumentoy;
        posicion[2]+= aumentoz;
    
   
}


