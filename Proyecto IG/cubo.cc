#include "aux.h"
#include "malla.h"
#include "cubo.h"

Cubo::Cubo(float lado){

   // inicializar la tabla de vértices
   std::cout << "crea vertice" << std::endl;
   v = {{lado/2, 0, lado/2}, //vertice0
         {lado/2, lado, lado/2}, //vertice1
         {(-lado/2), lado, lado/2}, //vertice2
         {(-lado/2), 0, lado/2}, //vertice3

         {(-lado/2),0,(-lado/2)} , // vertice4
         {lado/2,0, (-lado/2)}, //vertice5
         {lado/2, lado, (-lado/2)}, //vertice6
         {(-lado/2), lado, (-lado/2)}, //vertice7
   };

    // inicializar la tabla de caras o triángulos:
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)
   f ={{0,2,3}, //triangulo0   
         {0,1,2}, //triangulo1
         {0,5,6}, //triangulo2
         {0,6,1}, //triangulo3
         {1,7,2}, //triangulo4
         {1,6,7}, //triangulo5
         {4,6,5}, //triangulo6
         {4,7,6}, //triangulo7
         {3,2,4}, //triangulo8
         {2,7,4}, //triangulo9
         {3,4,5}, //triangulo10
         {3,5,0} //triangulo11
   };
  
      c_vertices = setColor(1.0f, 0.0f, 1.0f,v.size()); //color rosa

      c_lineas = setColor(0.0f, 1.0f, 0.0f,v.size());  //color verde

      c_solido = setColor(0.0f, 1.0f, 0.0f,v.size()); // color blanco

      ct.resize(v.size());
      ct = {
            {1,1},
            {1,0},
            {0,0},
            {0,1},
      };
      //   ct = {
      //       {1,0},
      //       {1,1},
      //       {0,1},
      //       {0,0},
      // };
      
      nv = CalcularNormales();
};

