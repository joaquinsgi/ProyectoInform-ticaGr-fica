#ifndef LUZ_DIRECCIONAL_H_INCLUDED
#define LUZ_DIRECCIONAL_H_INCLUDED

#include "aux.h"
#include "luz.h"
class LuzDireccional : public Luz
{
    protected :
        float alpha ;
        float beta ;
    public :
        // inicializar la fuente de luz
        LuzDireccional ( const Tupla2f & orientacion, const GLenum idLuzOpenGl, const Tupla4f &colorAmbiente,  const Tupla4f &colorEspecular,
                 const Tupla4f &colorDifuso  ) ;
        // Cambiar ángulo:
        void variarAnguloAlpha ( float incremento ) ;
        void variarAnguloBeta ( float incremento ) ;
        void CambiarLuz();

};

#endif