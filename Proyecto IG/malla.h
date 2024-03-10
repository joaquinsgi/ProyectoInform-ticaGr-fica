// #############################################################################
//
// Informática Gráfica D (Grado Informática)
//
// Archivo: Malla3D.h
// -- declaraciones de clase Malla3D (mallas indexadas) y derivados
//
// #############################################################################

#ifndef MALLA3D_H_INCLUDED
#define MALLA3D_H_INCLUDED

#include "aux.h"
#include "material.h"
#include "textura.h"
// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************

class Malla3D
{
   public:
      void setMaterial(Material *mat);
      void draw(char tipo) ;
      std::vector<Tupla3f> CalcularNormales();
      void setTextura(Textura *tex);

     
      
   protected:


      std::vector<Tupla3f> setColor(float a, float b, float c, int n);
      std::vector<Tupla3f> setColorInvisible(float a, float b, float c, int n);
      std::vector<Tupla3f> v ;   // tabla de coordenadas de vértices (una tupla por vértice, con tres floats)
      std::vector<Tupla3i> f ; // una terna de 3 enteros por cada cara o triángulo
      std::vector<Tupla3f> c_vertices ; // una terna de 3 float por cada color
      std::vector<Tupla3f> c_lineas ;
      std::vector<Tupla3f> c_solido ;
      std::vector<Tupla3f> nv;
      //std::vector<Tupla3f>nc;
      Textura * textura = nullptr ;
      Material * m = nullptr;
      std::vector<Tupla2f> ct;
      
      GLuint id_vbo_vertices = 0;
      GLuint id_vbo_triangulos = 0;
      GLuint id_vbo_c_solido = 0;
      GLuint id_vbo_c_triangulos = 0;
      GLuint id_vbo_c_vertices = 0;
      GLuint id_vbo_nv = 0;
      GLuint id_vbo_ct = 0;

   
 
   GLuint CrearVBO(GLuint tipo_vbo , GLuint tam ,GLvoid * puntero_ram );
} ;


#endif
