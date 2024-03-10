#include "peon.h"


Peon::Peon (const int num_vert_perfil , const int num_instancias_perf , const float radio, const float altura){
    std::vector<Tupla3f> perfil; 
    float angulo,x,y,z;
    perfil.emplace_back(0.0,0.0,0.0); 
    perfil.emplace_back(1.5,0.0,0.0); //A
    perfil.emplace_back(1.5,0.5,0.0); //B
    perfil.emplace_back(1.25,0.5,0.0); //C
    perfil.emplace_back(1,0.5,0.0);    //D
    perfil.emplace_back(0.75,1.0,0.0); //E
    perfil.emplace_back(0.5,1.5,0.0); //F
    perfil.emplace_back(0.5,1.75,0.0); //G
    perfil.emplace_back(1,1.75,0.0); //H
    perfil.emplace_back(1,1.75,0.0); //I
    perfil.emplace_back(1,2.0,0.0); //J
    perfil.emplace_back(0.5,2.0,0.0); //K
    
    for (int i = 0; i <num_vert_perfil; i++) {
        angulo = 2.0 * M_PI * i / num_vert_perfil;
        x = 0.75 * cos(angulo);
        y = -0.75 * sin(angulo)+2.5;
        z = 0;

        perfil.emplace_back(x,y,z);
    }   
    crearMalla(perfil,num_instancias_perf);
    c_vertices = setColor(1.0f, 0.0f, 1.0f,v.size());

        c_lineas = setColor(0.0f, 1.0f, 0.0f,v.size()); 

        c_solido = setColor(0.0f, 0.5f, 0.5f,v.size()); 

    nv = CalcularNormales();
}