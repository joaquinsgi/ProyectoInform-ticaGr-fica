#include "brazo.h"
Brazo::Brazo(){
    cilindro1 = new Cilindro(20,100,1,1);
    cilindro2 = new Cilindro(20,100,1,1);
    mano = new Mano();
    codo = new Esfera(50,100,1);
    cilindro1->setMaterial(new Material({0.7f, 0.3f, 0.0f, 1.0f},{0.5f, 0.5f, 0.5f, 1.0f}, {0.5f, 0.2f, 0.0f, 1.0f}, 100.0));
    cilindro2->setMaterial(new Material({0.7f, 0.3f, 0.0f, 1.0f},{0.5f, 0.5f, 0.5f, 1.0f}, {0.5f, 0.2f, 0.0f, 1.0f}, 100.0));
    codo->setMaterial(new Material({0.2f, 0.2f, 0.2f, 1.0f}, {0.2f, 0.2f, 0.2f, 1.0f}, {0.2f, 0.2f, 0.2f, 1.0f}, 100.0));
    mano->setMaterial(new Material({0.2f, 0.2f, 0.2f, 1.0f}, {0.2f, 0.2f, 0.2f, 1.0f}, {0.2f, 0.2f, 0.2f, 1.0f}, 100.0));

}

void Brazo::draw(char opcion){
    glPushMatrix();
        glTranslatef(0,-50,0);
        glScalef(7.5,50,7.5);
        cilindro1->draw(opcion);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,-50,0);
        glScalef(10,10,10);
        codo->draw(opcion);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,-50,0);
        glRotatef(90,1,0,0);
        glScalef(7.5,40,7.5);
        cilindro2->draw(opcion);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,-50,40);
        glRotatef(-80,1,0,0);
        mano->draw(opcion);
    glPopMatrix();
}
