#include "cono.h"


Cono::Cono(const int num_vert_perfil, const int num_instancias_perf, const float altura, const float radio){
    std::vector<Tupla3f> perfil; 
    float x,y,z;
    float incremento_x = radio / num_vert_perfil;
    float incremento_y = altura / num_vert_perfil;

    perfil.emplace_back(0,0,0);
   for (int i = 0; i < num_vert_perfil; i++) {
      
        x = radio - (i*incremento_x);
        z = 0;
        y = i*incremento_y;
        perfil.emplace_back(x, y, z);
    } 
    perfil.emplace_back(0,altura,0);

    crearMalla(perfil,num_instancias_perf);
     c_vertices = setColor(1.0f, 0.0f, 1.0f,v.size()); 

        c_lineas = setColor(0.0f, 1.0f, 0.0f,v.size()); 

        c_solido = setColor(1.0f, 0.0f, 0.0f,v.size()); 

        this->nv = CalcularNormales();
}
