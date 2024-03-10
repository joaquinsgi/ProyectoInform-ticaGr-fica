#include "material.h"


Material::Material (Tupla4f mdifuso ,Tupla4f mespecular ,Tupla4f mambiente,float _brillo ){
    difuso = mdifuso; 
    especular = mespecular; 
    ambiente = mambiente; 
    brillo = _brillo;
}
void Material::aplicar(){
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuso);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, especular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambiente);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, brillo);
}