#include "aux.h"
#include "malla.h"

// *****************************************************************************
//
// IG_D Clase Malla3D
//
// *****************************************************************************
// -----------------------------------------------------------------------------
// Función de visualización de la malla,


void Malla3D::draw(char tipo)
{
   // (la primera vez, se deben crear los VBOs y guardar sus identificadores en el objeto)
   // completar (práctica 1)
   // .....
   if(id_vbo_vertices == 0){
      id_vbo_vertices = CrearVBO(GL_ARRAY_BUFFER, 3*v.size()*sizeof(float), v.data());
   }
   
   if(id_vbo_triangulos == 0){
      id_vbo_triangulos = CrearVBO(GL_ELEMENT_ARRAY_BUFFER, 3*f.size()*sizeof(int), f.data());
   }

   if(id_vbo_c_solido == 0){
      
      id_vbo_c_solido = CrearVBO(GL_ARRAY_BUFFER, 3*v.size()*sizeof(float), c_solido.data());
   }

   if(id_vbo_c_vertices == 0){
      
      id_vbo_c_vertices = CrearVBO(GL_ARRAY_BUFFER, 3*v.size()*sizeof(float), c_vertices.data());
   }

   if(id_vbo_c_triangulos == 0){
      
      id_vbo_c_triangulos= CrearVBO(GL_ARRAY_BUFFER, 3*v.size()*sizeof(float), c_lineas.data());
   }

   if(id_vbo_nv == 0){         
      id_vbo_nv= CrearVBO(GL_ARRAY_BUFFER, 3*nv.size()*sizeof(float), nv.data());
   }
   
   if(id_vbo_ct == 0){         
      id_vbo_ct= CrearVBO(GL_ARRAY_BUFFER, 3*v.size()*sizeof(float), ct.data());
   }


   glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_vertices );
   glVertexPointer ( 3 , GL_FLOAT , 0 , 0 );
   glBindBuffer ( GL_ARRAY_BUFFER , 0 );
   glEnableClientState ( GL_VERTEX_ARRAY );

   glBindBuffer ( GL_ELEMENT_ARRAY_BUFFER , id_vbo_triangulos );
   
   if(textura != nullptr && ct.size() > 0){
      glEnable(GL_TEXTURE_2D);
      glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_ct );
      glEnableClientState(GL_TEXTURE_COORD_ARRAY) ;
      glTexCoordPointer(2, GL_FLOAT, 0, 0);
      textura->activar();
   } 
   
   glDisableClientState(GL_COLOR_ARRAY);

   if(tipo=='i' || tipo == 'I'){
      glEnable(GL_LIGHTING);
      m->aplicar();
      
      //glEnable(GL_NORMALIZE);
      
      glBindBuffer(GL_ARRAY_BUFFER, id_vbo_nv);
      glNormalPointer(GL_FLOAT,0,0);
      glBindBuffer(GL_ARRAY_BUFFER,0);
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      glEnableClientState(GL_NORMAL_ARRAY);
      glDrawElements(GL_TRIANGLES, 3*f.size(), GL_UNSIGNED_INT, 0);
      glDisable(GL_NORMALIZE);
      glDisable(GL_NORMAL_ARRAY);
   }  

  

   
   if(tipo == 'S' || tipo == 's'){
      //glColorPointer(4,GL_FLOAT,0,c_solido.data());     
       if ( id_vbo_c_solido != 0 ) {
         // habilitar uso de array de colores
         glEnableClientState( GL_COLOR_ARRAY );
         // especifícar cual es el VBO que vamos a usar
         glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_c_solido );
         // Usar el buffer activo para el color
         glColorPointer ( 3 , GL_FLOAT , 0 , 0 );
      }
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      glDrawElements ( GL_TRIANGLES , 3*f.size () , GL_UNSIGNED_INT , 0 ) ;
    
   }

   

   if(tipo == 'P' || tipo == 'p'){
      // dibujar con el buffer de índices activo
      
      if ( id_vbo_c_vertices != 0 ) {
         // habilitar uso de array de colores
         glEnableClientState( GL_COLOR_ARRAY );
         // especifícar cual es el VBO que vamos a usar
         glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_c_vertices );
         // Usar el buffer activo para el color
         glColorPointer ( 3 , GL_FLOAT , 0 , 0 );
      }
      glPointSize(3);
      glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
      glDrawElements( GL_TRIANGLES , 3*f.size () , GL_UNSIGNED_INT , 0 ) ;
      glPointSize(1);
   }

   
   if(tipo == 'L' || tipo == 'l'){
      
      if ( id_vbo_c_triangulos != 0 ) {
         // habilitar uso de array de colores
         glEnableClientState( GL_COLOR_ARRAY );
         // especifícar cual es el VBO que vamos a usar
         glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_c_triangulos );
         // Usar el buffer activo para el color
         glColorPointer ( 3 , GL_FLOAT , 0 , 0 );
      }
      glLineWidth(2);
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
      glDrawElements( GL_TRIANGLES , 3*f.size () , GL_UNSIGNED_INT , 0 ) ;
      glLineWidth(1);

   }

   if(textura != nullptr && ct.size() > 0){
      glDisableClientState(GL_TEXTURE_COORD_ARRAY) ;
      glDisable(GL_TEXTURE_2D) ;
   }
   //glDisableClientState(GL_COLOR_ARRAY);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0); 
   glDisableClientState(GL_VERTEX_ARRAY);
   glBindBuffer(GL_ARRAY_BUFFER,0);
   glDisableClientState(GL_COLOR_ARRAY);


}


std::vector<Tupla3f> Malla3D::setColor(float a, float b, float c, int n){
   std::vector<Tupla3f> vec;
   for(int i = 0; i < n; i++){
      vec.push_back({a,b,c});
   }
   return vec;
}

GLuint Malla3D::CrearVBO(GLuint tipo_vbo , GLuint tam ,GLvoid * puntero_ram ){
   GLuint id_vbo ; // resultado: identificador de VBO
   glGenBuffers ( 1 , & id_vbo ); // crear nuevo VBO, obtener identificador
   glBindBuffer ( tipo_vbo , id_vbo ); // activar el VBO usando su identificador
   // esta instrucción hace la transferencia de datos desde RAM hacia GPU
   glBufferData ( tipo_vbo , tam , puntero_ram , GL_STATIC_DRAW );
   glBindBuffer ( tipo_vbo , 0 ); // desactivación del VBO (activar 0)
   return id_vbo;
}

std::vector<Tupla3f> Malla3D::CalcularNormales(){
   std::vector<Tupla3f> devolver;
   devolver.resize(v.size());
   int tam = v.size();
   Tupla3f a, b, nc, p, q, r;
   
   for(int i = 0; i < devolver.size(); i++){
      devolver[i][0] = 0.0;
      devolver[i][1] = 0.0;
      devolver[i][2] = 0.0;
      
   }
   
   for(int i = 0; i < f.size(); i++){
      p =  v[f[i][0]];
      q = v[f[i][1]];
      r = v[f[i][2]];
      a =  q - p;
      b =  r - p;
      nc = a.cross(b);
      if(nc.lengthSq() != 0){
         devolver[f[i][0]] = devolver[f[i][0]] + nc;
         devolver[f[i][1]] = devolver[f[i][1]] + nc;
         devolver[f[i][2]] = devolver[f[i][2]] + nc;
      }
   }
   for(int i = 0; i < devolver.size(); i++){
      devolver[i] = devolver[i].normalized();
   }

   return devolver;
}

void Malla3D::setMaterial(Material *mat){
   m = mat;
}

void Malla3D::setTextura(Textura *tex){
   textura = tex;
}
