#include "cabeza.h"
Cabeza::Cabeza(){
    orejaIzda = new Cilindro(20,100,1,1);
    orejaDcha = new Cilindro(20,100,1,1);
    cabeza = new Cubo(1);
    boca = new Esfera(20,20,1);
    ojoIzdo = new Esfera(20,20,1);
    ojoDcho = new Esfera(20,20,1);
    pupiDcha = new Esfera(20,20,1);
    pupiIzda = new Esfera(20,20,1);
    sombrero = new Sombrero(20);
    nariz = new Esfera(20,20,1);
    

    orejaIzda->setMaterial(new Material({0.7f, 0.3f, 0.0f, 1.0f},{0.5f, 0.5f, 0.5f, 1.0f}, {0.5f, 0.2f, 0.0f, 1.0f}, 100.0));
    orejaDcha->setMaterial(new Material({0.7f, 0.3f, 0.0f, 1.0f},{0.5f, 0.5f, 0.5f, 1.0f}, {0.5f, 0.2f, 0.0f, 1.0f}, 100.0));
    cabeza->setMaterial(new Material({0.7f, 0.3f, 0.0f, 1.0f},{0.5f, 0.5f, 0.5f, 1.0f}, {0.5f, 0.2f, 0.0f, 1.0f}, 100.0));
    boca->setMaterial(new Material({0.8f, 0.5f, 0.2f, 1.0f},{0.5f, 0.5f, 0.5f, 1.0f}, {0.7f, 0.4f, 0.1f, 1.0f},100.0));
    ojoDcho->setMaterial(new Material({0.7f, 0.7f, 0.8f, 1.0f},{0.8f, 0.8f, 0.9f, 1.0f}, {0.7f, 0.7f, 0.8f, 1.0f},100.0));
    ojoIzdo->setMaterial(new Material({0.7f, 0.7f, 0.8f, 1.0f},{0.8f, 0.8f, 0.9f, 1.0f}, {0.7f, 0.7f, 0.8f, 1.0f},100.0));
    pupiDcha->setMaterial(new Material({0.0f, 0.9f, 0.9f, 1.0f},{0.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.8f, 0.8f, 1.0f},100.0));
    pupiIzda->setMaterial(new Material({0.0f, 0.9f, 0.9f, 1.0f},{0.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.8f, 0.8f, 1.0f},100.0));
    sombrero->setMaterial(new Material({0.0f, 0.0f, 0.0f, 1.0f},{0.0f, 0.0f, 0.0f, 0.0f},{0.0f, 0.0f, 0.0f, 0.0f},0.0));
    nariz->setMaterial(new Material({0.0f, 0.0f, 0.0f, 1.0f},{0.0f, 0.0f, 0.0f, 1.0f},{0.0f, 0.0f, 0.0f, 1.0f},100.0));
    
}
void Cabeza::draw(char opcion){
    glPushMatrix();
        glTranslatef(12.5,20,-2.5);
        glRotatef(90,1,0,0);
        glScalef(5,5,5);
        orejaIzda->draw(opcion);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-12.5,20,-2.5);
        glRotatef(90,1,0,0);
        glScalef(5,5,5);
        orejaDcha->draw(opcion);
    glPopMatrix();
    glPushMatrix();
        glScalef(20,20,15);
        cabeza->draw(opcion);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,5,5);
        glScalef(10,7,8);
        boca->draw(opcion);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(5,15,5);
        glScalef(3,4,5);
        ojoIzdo->draw(opcion);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-5,15,5);
        glScalef(3,4,5);
        ojoDcho->draw(opcion);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(4.5,15,10);
        pupiIzda->draw(opcion);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-4.5,15,10);
        pupiDcha->draw(opcion);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,20,0);
        glScalef(2,2,2);
        sombrero->draw(opcion);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,8,12);
        glScalef(2,2,2);
        nariz->draw(opcion);
    glPopMatrix();
}