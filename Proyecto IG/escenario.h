#ifndef ESCENARIO_H_INCLUDED
#define ESCENARIO_H_INCLUDED

#include "aux.h"
#include "objrevolucion.h"
#include "cubo.h"
#include "cilindro.h"
#include "objply.h"
#include "textura.h"
class Escenario : public Malla3D
{
    private: 
        
        
    public:
        Escenario();
        void draw(char opcion);
        Cubo * suelo = nullptr;
        Cubo * pared1 = nullptr;
        Cubo * pared2 = nullptr;
        Cubo * pared3 = nullptr;
        Cubo * techo = nullptr;
        Cubo * cuadro = nullptr;
        Cubo * cartel = nullptr;


        Cilindro * plataforma = nullptr;
        ObjPLY * cortinas = nullptr;
        ObjPLY * microfono = nullptr;
} ;




#endif