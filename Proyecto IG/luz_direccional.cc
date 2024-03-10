#include "luz_direccional.h"

LuzDireccional::LuzDireccional ( const Tupla2f & orientacion, const GLenum idLuzOpenGl, const Tupla4f &_colorAmbiente,  const Tupla4f &_colorEspecular, const Tupla4f &_colorDifuso ) {
        id = idLuzOpenGl;
        colorAmbiente = _colorAmbiente;
        colorDifuso = _colorDifuso;
        colorEspecular = _colorEspecular;
        alpha = orientacion[0];
        beta = orientacion[1];
        posicion[0] = sin(alpha * M_PI/180) * cos(beta *M_PI/180);
        posicion[1] = sin(beta *M_PI/180) * sin(alpha * M_PI/180);
        posicion[2] = cos(alpha *M_PI/180);
        posicion[3] = 0.0;
}
       
void LuzDireccional::variarAnguloAlpha ( float incremento ) {
        alpha += incremento;
        posicion[0] = sin(alpha * M_PI/180) * cos(beta *M_PI/180);
        posicion[1] = sin(beta *M_PI/180) * sin(alpha * M_PI/180);
        posicion[2] = cos(alpha *M_PI/180);
        posicion[3] = 0.0;
}

void LuzDireccional::variarAnguloBeta ( float incremento ) {
        beta += incremento;;
        posicion[0] = sin(alpha * M_PI/180) * cos(beta *M_PI/180);
        posicion[1] = sin(beta * M_PI/180) * sin(alpha * M_PI/180);
        posicion[2] = cos(alpha * M_PI/180);
        posicion[3] = 0.0;
}

void LuzDireccional::CambiarLuz(){
        std::vector<Tupla4f> colores = {{1.0f, 0.588f, 0.588f,1.0}, {0.588f, 1.0f, 0.588f,1.0},{0.588f, 0.706f, 1.0f,1.0}};
        int color = std::rand()%3;
        int color2 = std::rand()%3;
        int color3 = std::rand()%3;
        colorDifuso = colores[color];
        colorAmbiente = colores[color2];
        colorEspecular = colores[color3];
}