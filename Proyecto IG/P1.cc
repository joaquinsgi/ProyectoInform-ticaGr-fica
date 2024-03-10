#include "P1.h"

P1::P1(){
brazoDcho = new Brazo();
    brazoIzdo = new Brazo();
    tronco = new Tronco();
    pajarita = new ObjPLY("./plys/pajarita.ply");
    cabeza = new Cabeza();
    pajarita->setMaterial(new Material({0.0f, 0.0f, 0.0f, 1.0f},{0.0f, 0.0f, 0.0f, 1.0f},{0.0f, 0.0f, 0.0f, 1.0f},100.0));

}
void P1::draw(char opcion, float giroHombroDcho, float giroHombroIzdo, float giroPajarita, float giroCabeza, float alturaCabeza){
    glPushMatrix();
        glTranslatef(-30,50,0);
        glRotatef(giroHombroDcho,1,0,0);
        brazoDcho->draw(opcion);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,alturaCabeza,0); 
            glRotatef(giroCabeza,0,1,0);
            glScalef(2,2,2);
            cabeza->draw(opcion);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(30,50,0);
        glRotatef(-giroHombroIzdo,1,0,0);
        brazoIzdo->draw(opcion);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,50,10); 
        glRotatef(-giroPajarita,0,0,1);
        glScalef(10,5,1);
        pajarita->draw(opcion);
    glPopMatrix();
}