#include "sombrero.h"
Sombrero::Sombrero(int num_instancias_perf){
    std::vector<Tupla3f> perfil;
    perfil.emplace_back(0,4,0);
    perfil.emplace_back(1,4,0); 
    perfil.emplace_back(2,4,0); 
    perfil.emplace_back(2,3,0); 
    perfil.emplace_back(2,2,0); 
    perfil.emplace_back(2,1,0); 
    perfil.emplace_back(3,1,0); 
    perfil.emplace_back(4,1,0); 
    perfil.emplace_back(4,0,0); 
    perfil.emplace_back(3,0,0); 
    perfil.emplace_back(2,0,0); 
    perfil.emplace_back(1,0,0); 
    perfil.emplace_back(0,0,0); 
    crearMalla(perfil,num_instancias_perf);
    c_vertices = setColor(1.0f, 0.0f, 1.0f,v.size());

    c_lineas = setColor(0.0f, 1.0f, 0.0f,v.size()); 

    c_solido = setColor(0.0f, 0.5f, 0.5f,v.size()); 

    nv = CalcularNormales();

}