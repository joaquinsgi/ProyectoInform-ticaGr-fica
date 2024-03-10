#include "aux.h"
#include "malla.h"
#include "piramidehexagonal.h"

PiramideHexagonal::PiramideHexagonal(float h, float r, float r2)
{

   // inicializar la tabla de vértices
    float angulo = 0.0;
    v.emplace_back(0,0,0); 
    for (int i = 0; i < 6; i++) {
        // Calcular las coordenadas x e y utilizando funciones trigonométricas que hemos visto en el video
        float x = r * cos(angulo);
        float y = r * sin(angulo);

        
        v.emplace_back(x,0.0,y); 
        // El siguiente vertice esta a 60 grados mas al tratarse de un hexagono regular
        angulo += M_PI / 3.0;
    }
    v.emplace_back(0,h,0); 
    for (int i = 0; i < 6; i++) {
    // Calcular las coordenadas x e y utilizando funciones trigonométricas que hemos visto en el video
    float x = r2 * cos(angulo);
    float y = r2 * sin(angulo);

        
    v.emplace_back(x,h,y); 
    // El siguiente vertice esta a 60 grados mas al tratarse de un hexagono regular
    angulo += M_PI / 3.0;
    }
   // inicializar la tabla de caras o triángulos:
   
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)

    f = {{0,1,2},
    {0,2,3},
    {0,3,4},
    {0,4,5},
    {0,5,6},
    {0,6,1},
    {7,9,8},
    {7,10,9},
    {7,11,10},
    {7,12,11},
    {7,13,12},
    {7,8,13},
    {3,2,9},
    {3,9,10},
    {2,1,8},
    {2,8,9},
    {4,10,11},
    {3,10,4},
    {5,4,11},
    {5,11,12},
    {6,12,13},
    {6,5,12},
    {6,13,1},
    {1,13,8}
    };

   // inicializar la/s tabla/s de colores

     c_vertices = setColor(0.0f, 0.0f, 1.0f,v.size()); // color azul

      c_lineas = setColor(0.5f, 0.5f, 0.5f,v.size()); // color violeta

        c_solido = setColor(0.0f, 1.0f, 0.0f, v.size());  // color verde


   
}

