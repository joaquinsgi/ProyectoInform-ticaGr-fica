#include "mano.h"

Mano::Mano(){
    palma = new Esfera(50,100,1);
    dedo1 = new Cilindro(20,100,1,1);
    dedo2 = new Cilindro(20,100,1,1);
    dedo3 = new Cilindro(20,100,1,1);
    dedo4 = new Cilindro(20,100,1,1);
    dedo5 = new Cilindro(20,100,1,1);
    palma->setMaterial(new Material({0.7f, 0.3f, 0.0f, 1.0f},{0.5f, 0.5f, 0.5f, 1.0f}, {0.5f, 0.2f, 0.0f, 1.0f}, 100.0));
    dedo1->setMaterial(new Material({0.7f, 0.3f, 0.0f, 1.0f},{0.5f, 0.5f, 0.5f, 1.0f}, {0.5f, 0.2f, 0.0f, 1.0f}, 100.0));
    dedo2->setMaterial(new Material({0.7f, 0.3f, 0.0f, 1.0f},{0.5f, 0.5f, 0.5f, 1.0f}, {0.5f, 0.2f, 0.0f, 1.0f}, 100.0));
    dedo3->setMaterial(new Material({0.7f, 0.3f, 0.0f, 1.0f},{0.5f, 0.5f, 0.5f, 1.0f}, {0.5f, 0.2f, 0.0f, 1.0f}, 100.0));
    dedo4->setMaterial(new Material({0.7f, 0.3f, 0.0f, 1.0f},{0.5f, 0.5f, 0.5f, 1.0f}, {0.5f, 0.2f, 0.0f, 1.0f}, 100.0));
    dedo5->setMaterial(new Material({0.7f, 0.3f, 0.0f, 1.0f},{0.5f, 0.5f, 0.5f, 1.0f}, {0.5f, 0.2f, 0.0f, 1.0f}, 100.0));

}

void Mano::draw(char opcion){
    glPushMatrix();
        glScalef(10,12,13);
        palma->draw(opcion);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,-24,-8);
        glScalef(2,30,2);
        dedo1->draw(opcion);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,-28,-3);
        glScalef(2,30,2);
        dedo2->draw(opcion);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,-28,2);
        glScalef(2,30,2);
        dedo3->draw(opcion);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,-24,7);
        glScalef(2,30,2);
        dedo4->draw(opcion);
    glPopMatrix();
    glPushMatrix();
    //glTranslatef(0,-22,12);
        glRotatef(90,1,0,0);
        glTranslatef(0,10,4);
        glScalef(2,15,2);
        dedo5->draw(opcion);
    glPopMatrix();
}
