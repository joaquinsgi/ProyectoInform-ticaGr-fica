#include "esfera.h"

Esfera::Esfera(const int num_vert_perfil, const int num_instancias_perf , const float radio ){
    std::vector<Tupla3f> perfil; 
    float angulo,x,y,z;
    perfil.emplace_back(0,-radio,0);
    for (int i = 0; i < num_vert_perfil; i++) {
        angulo = 3.0 * M_PI/2;
        x = radio * cos(angulo + M_PI * i / num_vert_perfil);
        y = -radio * sin(angulo + M_PI * i / num_vert_perfil);
        z = 0;

        perfil.emplace_back(x,y,z);
    }   
    perfil.emplace_back(0,radio,0);
    crearMalla(perfil,num_instancias_perf);
    
    c_vertices = setColor(1.0f, 0.0f, 1.0f,v.size());

    c_lineas = setColor(0.0f, 1.0f, 0.0f,v.size()); 

    c_solido = setColor(0.0f, 0.0f, 0.0f,v.size()); 

    nv = CalcularNormales();

   
}