#include "PSup.h"

PSup::PSup(){
    p1 = new P1();
    cabeza = new Cabeza();
    tronco = new Tronco();
}
void PSup::draw(char opcion, float giroHombroDcho, float giroHombroIzdo, float giroPajarita, float alturaCabeza, float giroCabeza, float giroTronco, float torsionTronco){
    glPushMatrix();    
        glPushMatrix();
            tronco->draw(opcion);
        glPopMatrix();
        glPushMatrix();
            glRotatef(giroTronco,0,1,0);
            p1->draw(opcion,giroHombroDcho,giroHombroIzdo,giroPajarita, giroCabeza, alturaCabeza);
        glPopMatrix();
    glPopMatrix();
}