#include "tronco.h"
Tronco::Tronco(){
    cubo = new Cubo(1);
    cuello = new Cilindro(20,100,1,1);
    cubo -> setMaterial(new Material({0.7f, 0.3f, 0.0f, 1.0f},{0.5f, 0.5f, 0.5f, 1.0f}, {0.5f, 0.2f, 0.0f, 1.0f}, 100.0));
    cuello->setMaterial(new Material({0.2f, 0.2f, 0.2f, 1.0f}, {0.2f, 0.2f, 0.2f, 1.0f}, {0.2f, 0.2f, 0.2f, 1.0f}, 100.0));

}
void Tronco::draw(char opcion){
    glPushMatrix();
        glScalef(50,60,20);
        cubo->draw(opcion);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,60,0);
        glScalef(5,20,5);
        cuello->draw(opcion);
    glPopMatrix();
}