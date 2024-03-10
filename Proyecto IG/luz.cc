#include "luz.h"

void Luz::activar(){
    glEnable(GL_LIGHTING);

    glEnable(id);
    glLightfv(id, GL_DIFFUSE, colorDifuso );
    glLightfv(id, GL_AMBIENT, colorAmbiente );
    glLightfv(id, GL_SPECULAR, colorEspecular );
    glLightfv(id, GL_POSITION, posicion);
    activa = true;
}

void Luz::desactivar(){
    glDisable(GL_LIGHTING);

    glDisable(id);
    activa = false; 
}