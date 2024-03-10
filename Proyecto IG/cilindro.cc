#include "cilindro.h"
#include "aux.h"

   Cilindro::Cilindro(const int num_vert_perfil,const int num_instancias_perf, const float altura, const float radio) {
        std::vector<Tupla3f> perfil; 
        float x,y,z;
        perfil.emplace_back(0,0,0);
        perfil.emplace_back(0.0,altura,0.0);
        for(int i = 0; i <=num_vert_perfil; i++){
                x = radio;      
                z = 0;
                y = i*altura/num_vert_perfil;
                perfil.emplace_back(x,y,z); 
        }
        
        crearMalla(perfil,num_instancias_perf);  

        c_vertices = setColor(1.0f, 0.0f, 1.0f,v.size()); //color rosa

        c_lineas = setColor(0.0f, 1.0f, 0.0f,v.size());  //color verde

        c_solido = setColor(0.0f, 0.0f, 1.0f,v.size()); // color azul
        nv = CalcularNormales();
   }