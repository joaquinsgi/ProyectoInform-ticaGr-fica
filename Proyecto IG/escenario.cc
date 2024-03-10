#include "escenario.h"


Escenario::Escenario(){
    suelo = new Cubo(1);
    pared1 = new Cubo(1);
    pared2 = new Cubo(1);
    pared3 = new Cubo(1);
    pared3 = new Cubo(1);
    techo = new Cubo(1);
    cuadro = new Cubo(1);
    cartel = new Cubo(1);
    plataforma = new Cilindro(200,100,1,1);
    cortinas = new ObjPLY("./plys/cortinas.ply");
    microfono = new ObjPLY("./plys/microfono.ply");

    pared1->setMaterial(new Material({0.5f, 0.5f, 0.5f, 1.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.2f, 0.2f, 0.2f, 1.0f},100.0));
    pared2->setMaterial(new Material({0.5f, 0.5f, 0.5f, 1.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.2f, 0.2f, 0.2f, 1.0f},100.0));
    pared3->setMaterial(new Material({1.0f, 1.0f, 1.0f, 1.0f},{1.0f, 1.0f, 1.0f, 1.0f},{1.0f, 1.0f, 1.0f, 1.0f},100.0));
    techo->setMaterial(new Material({0.8f, 0.8f, 0.8f, 1.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.6f, 0.6f, 0.6f, 1.0f},100.0));
    microfono->setMaterial(new Material({0.0f, 0.0f, 0.0f, 1.0f},{0.0f, 0.0f, 0.0f, 1.0f},{0.0f, 0.0f, 0.0f, 1.0f},100.0));
    plataforma->setMaterial(new Material({0.0f, 0.0f, 1.0f, 1.0f},{0.0f, 0.0f, 1.0f, 1.0f},{0.0f, 0.0f, 1.0f, 1.0f},100.0));
    suelo->setMaterial(new Material({0.5f, 0.5f, 0.5f, 1.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.4f, 0.2f, 0.0f, 1.0f},100.0));
    cortinas->setMaterial(new Material({0.5f, 0.1f, 0.1f, 1.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.3f, 0.1f, 0.1f, 1.0f},100.0));
    cartel->setMaterial(new Material({1.0f, 1.0f, 1.0f, 1.0f},{1.0f, 1.0f, 1.0f, 1.0f},{1.0f, 1.0f, 1.0f, 1.0f},100.0));
    cuadro->setMaterial(new Material({1.0f, 1.0f, 1.0f, 1.0f},{1.0f, 1.0f, 1.0f, 1.0f},{1.0f, 1.0f, 1.0f, 1.0f},100.0));
    cuadro->setTextura(new Textura("./imagenes/cuadro2.jpg"));
    cartel->setTextura(new Textura("./imagenes/cartel.jpg"));
    suelo->setTextura(new Textura("./imagenes/madera2.jpg"));
    pared3->setTextura(new Textura("./imagenes/pared_ladrillo2.jpg"));

}

void Escenario::draw(char opcion){
    glPushMatrix();
    glTranslatef(0,0,300);
    glRotatef(-90,1,0,0);
    glScalef(1000,1000,20);
    suelo->draw(opcion);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(500,0,-200);
    glScalef(20,700,1001);
    pared1->draw(opcion);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-500,0,-200);
    glScalef(20,700,1001);
    pared2->draw(opcion);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,-700);
    glScalef(1000,700,20);
    pared3->draw(opcion);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,700,-200);
    glScalef(1000,20,1000);
    techo->draw(opcion);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,20,550);
    glScalef(4,3,2);
    cortinas->draw(opcion);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,20,100);
    glScalef(130,20,130);
    plataforma->draw(opcion);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,121,200);
    glRotatef(180,0,1,0);
    glScalef(100,80,100);
    microfono->draw(opcion);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,250,-650);
    glScalef(600,400,1);
    cartel->draw(opcion);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-490,200,0);
    glRotatef(90,0,1,0);
    glScalef(200,300,1);
    cuadro->draw(opcion);
    glPopMatrix();
}

