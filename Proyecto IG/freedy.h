#ifndef FREEDY_H_INCLUDED
#define FREEDY_H_INCLUDED

#include "aux.h"
#include "objrevolucion.h"
#include "piernaizda.h"
#include "pierna.h"
#include "tronco.h"
#include "brazo.h"
#include "cabeza.h"
#include "objply.h"
#include "PSup.h"
class Freedy : public Malla3D
{
    private: 
        float giroTronco;
        float giroHombroDcho, giroHombroIzdo ;
        float alturaCabeza;
        float giroPajarita;
        float giroPiernaIzda, giroPiernaDcha;
        float giroCabeza;
        float torsionTronco;
    public:
        Freedy();
        void draw(char opcion);
        void modificaGiroTronco(float valor);
        void modificaGiroTroncoAuto(float valor);
        void modificaAlturaCabeza(float valor);

        void modificaGiroCabeza(float valor);
        void modificaGiroPierna(float valor);
        void modificaGiroHombro(float valor);
        void modificaGiroHombroAuto(float valor);

        void modificaGiroPajarita(float valor);
        void modificaTorsionTronco(float valor);
        void modificaTorsionTroncoAuto(float valor);

        void modificaGiroCabezaAuto(float valor);
        void modificaAlturaCabezaAuto(float valor);        
        float getAlturaCabeza();
        float getGiroHombroDcho();
        float getGiroHombroIzdo();
        float getGiroCabeza();
        float getTorsionTronco();
        float getGiroTronco();


        Brazo * brazoDcho = nullptr;
        Brazo * brazoIzdo = nullptr;
        Tronco * tronco = nullptr;
        Pierna * piernaDcha = nullptr;
        Pierna * piernaIzda = nullptr;
        Cabeza * cabeza = nullptr;
        ObjPLY * pajarita = nullptr;
        PSup * psup = nullptr;
} ;




#endif