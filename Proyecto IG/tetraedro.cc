#include "aux.h"
#include "malla.h"
#include "tetraedro.h"

Tetraedro::Tetraedro( float l){
    float h = sqrt(l*l -(l/2)*(l/2));
    v.emplace_back(0,l,0); //A
    v.emplace_back(-l/2,0,l/2); //B izda
    v.emplace_back(l/2,0.0,l/2);//d atras
    v.emplace_back(0.0,0.0,-l/2);//C derecha

    f.emplace_back(0,1,2); //A
    f.emplace_back(2,3,0); //A
    f.emplace_back(3,1,0); //A
    f.emplace_back(1,3,2); //A
     c_vertices = setColor(0.0f, 0.0f, 1.0f,v.size()); // color azul

      c_lineas = setColor(0.5f, 0.5f, 0.5f,v.size()); // color violeta

        c_solido = setColor(0.0f, 1.0f, 0.0f, v.size());  // color verde

}