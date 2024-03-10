#include "aux.h"
#include "objrevolucion.h"
#include "ply_reader.h"
#include <algorithm>


// *****************************************************************************
//
// Clase ObjRevolucion (práctica 2)
//
// *****************************************************************************


// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un PLY)

ObjRevolucion::ObjRevolucion() {}

ObjRevolucion::ObjRevolucion(const std::string & archivo, int num_instancias, bool tapa_sup, bool tapa_inf) {
   // completar ......(práctica 2)
   ply::read_vertices(archivo,perfil);
   crearMalla(perfil,num_instancias);

}

// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un vector de puntos)

 
ObjRevolucion::ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias, bool tapa_sup, bool tapa_inf) {
   crearMalla(archivo,num_instancias);
}


int modulo(int num, int divisor) {
    int resultado = num % divisor;
    return (resultado < 0) ? resultado + divisor : resultado;
}


void ObjRevolucion::crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias) {
      for(int i = 0; i < perfil_original.size(); i++){
      if(perfil_original[i][0] == 0 and perfil_original[i][2] == 0){
         polos.emplace_back(perfil_original[i]);
         //std::cout << "polo metido: "<< perfil_original[i]<< std::endl;
      }
      else
         aux_no_polos.emplace_back(perfil_original[i]);  
   }

   if(aux_no_polos[0][1] >= aux_no_polos[aux_no_polos.size()-1][1]){
      for(int i=aux_no_polos.size()-1; i>=0; i--){
            aux.emplace_back(aux_no_polos[i]);
            //std::cout << "Perfil Descendente" << std::endl;
      }
   }
   else{
      for(int i = 0; i < aux_no_polos.size(); i++){
         aux.emplace_back(aux_no_polos[i]);  
         //std::cout << "Perfil Ascendente" << std::endl; 
      }
   }

   int num_vertices = aux.size();
   v.clear();
   //std::cout << "num vertices: " << num_vertices<< std::endl;
   //std::cout << "num instacias: " << num_instancias<< std::endl;;
   for(int i = 0; i < num_instancias; i++){
      for(int j = 0; j < num_vertices; j++){
         angulo = 2.0 * M_PI * i / (num_instancias-1);
         x = aux[j][0] * cos(angulo)+aux[j][2] * sin(angulo);
         //std::cout << "X: " << x << std::endl;
         y = aux[j][1];
         //std::cout << "Y: " << y << std::endl;
         z = -aux[j][0] * sin(angulo)+ aux[j][2] * cos(angulo);
         //std::cout << "Z: " << z << std::endl;
         v.emplace_back(x,y,z);
      }
   }

   bool tapa_inf = false;
   bool tapa_sup = false;

   //std::cout << "polos size: " << polos.size() << std::endl;
   if(polos.size() == 2){
      tapa_inf = true;
      tapa_sup = true;
   }
   else if(polos.size() == 1){
      if(polos[0][1] == aux[0][1]){
         tapa_inf = true;
         tapa_sup = false;
      }
      else{
         tapa_sup = true;
         tapa_inf = false;
      }
   }
 

   std::sort(polos.begin(),polos.end());
   //std::cout << "tam " << polos.size() << std::endl;
    for(int i = 0; i < polos.size(); i++){
      v.emplace_back(polos[i]);
   }


   f.clear();
   for(int i = 0; i < num_instancias-1; i++){
      for(int j = 0; j < num_vertices-1; j++){
         float a = (num_vertices*i)+j;
         float b =  num_vertices*((i+1)%num_instancias) + j;
         f.emplace_back(a,b,b+1);
         f.emplace_back(a,b+1,a+1);
      }
   }

   
   for (int i = 0; i <= num_instancias; i++) {
        for (int j = 0; j < num_vertices; j++) {
            float u = static_cast<float>(i) / static_cast<float>(num_instancias);
            float v = 1- static_cast<float>(j) / static_cast<float>(num_vertices - 1);
            ct.emplace_back(u,v);
        }
    } 

   int v1, v2, v3;

   v1 = num_vertices*num_instancias; 


   if(tapa_inf == true && tapa_sup == true){
      for(int i=0; i<num_instancias+1; i++) {   
         v2 = modulo((v1-(num_vertices*i)),v1);
         //std::cout << " v2 " << v2 << std::endl;
         v3 = modulo(v1-(num_vertices*(i+1)),v1);
         //std::cout << " v3 " << v3 << std::endl;
         f.emplace_back(v1,v2,v3);
      }

      v1 += 1;
      for(int i=num_instancias-1; i >= 1; i--) {
            
         v2 = modulo((v1-(num_vertices*i)-2),v1);
         //std::cout << " v2 " << v2 << std::endl;
         v3 = modulo(v2+(num_vertices),v1);
         //std::cout << " v3 " << v3 << std::endl;
         f.emplace_back(v1,v2,v3);
      }

      f.emplace_back(v1,v3,v3-v2-1);
   }
   else if(tapa_sup == true && tapa_inf == false){
      for(int i=num_instancias-1; i >= 1; i--) {
            
      v2 = modulo((v1-(num_vertices*i)-2),v1);
      //std::cout << " v2 " << v2 << std::endl;
      v3 = modulo(v2+(num_vertices),v1);
      //std::cout << " v3 " << v3 << std::endl;

      f.emplace_back(v1,v2,v3);
   }

   f.emplace_back(v1,v3,v3-v2-1);

   }
   else if(tapa_inf == true and tapa_sup == false){
      for(int i=0; i<num_instancias+1; i++) {   
         v2 = modulo((v1-(num_vertices*i)),v1);
         //std::cout << " v2 " << v2 << std::endl;
         v3 = modulo(v1-(num_vertices*(i+1)),v1);
         //std::cout << " v3 " << v3 << std::endl;
         f.emplace_back(v1,v2,v3);
      }
   }

   

    

}

