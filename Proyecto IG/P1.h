#ifndef P1_H_INCLUDED
#define P1_H_INCLUDED

#include "aux.h"
#include "objrevolucion.h"
#include "objply.h"
#include "tronco.h"
#include "brazo.h"
#include "cabeza.h"
class P1 : public Malla3D
{
    public:
        P1();
        void draw(char opcion, float giroHombroDcho, float giroHombroIzdo, float giroPajarita, float giroCabeza, float alturaCabeza);
        Tronco * tronco = nullptr;
        ObjPLY * pajarita = nullptr;
        Brazo * brazoIzdo = nullptr;
        Brazo * brazoDcho = nullptr;
        Cabeza * cabeza = nullptr;
};





#endif