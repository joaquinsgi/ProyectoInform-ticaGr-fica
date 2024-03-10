#ifndef PSUP_H_INCLUDED
#define PSUP_H_INCLUDED

#include "aux.h"
#include "objrevolucion.h"
#include "cabeza.h"
#include "P1.h"
#include "tronco.h"

class PSup : public Malla3D
{
    public:
        PSup();
        void draw(char opcion, float giroHombroDcho, float giroHombroIzdo, float giroPajarita, float alturaCabeza, float giroCabeza, float giroTronco, float torsionTronco);
        Cabeza * cabeza = nullptr;
        P1 * p1 = nullptr;
        Tronco * tronco = nullptr;

};





#endif