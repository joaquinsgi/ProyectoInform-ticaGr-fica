#include "pierna.h"
Pierna::Pierna(){
    cilindro1 = new Cilindro(20,100,1,1);
    pie = new Cubo(1);
    tobillo = new Cilindro(20,100,1,1);
    cilindro1->setMaterial(new Material({0.7f, 0.3f, 0.0f, 0.0f},{0.5f, 0.5f, 0.5f, 0.0f}, {0.5f, 0.2f, 0.0f, 0.0f}, 100.0));
    tobillo->setMaterial(new Material({0.2f, 0.2f, 0.2f, 1.0f}, {0.2f, 0.2f, 0.2f, 1.0f}, {0.2f, 0.2f, 0.2f, 1.0f}, 100.0));
    pie->setMaterial(new Material({0.7f, 0.3f, 0.0f, 0.0f},{0.5f, 0.5f, 0.5f, 0.0f}, {0.5f, 0.2f, 0.0f, 0.0f}, 100.0));

}

void Pierna::draw(char opcion){
    glPushMatrix();
        glTranslatef(0,-65,0);
        glScalef(8,65,8);
        cilindro1->draw(opcion);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,-85,0);
        glScalef(4,20,4);
        tobillo->draw(opcion);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,-95,5);
        glScalef(20,10,40);
        pie->draw(opcion);
    glPopMatrix();
}