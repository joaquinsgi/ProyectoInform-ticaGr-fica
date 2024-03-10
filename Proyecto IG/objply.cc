#include "objply.h"
#include "ply_reader.h"
 

// *****************************************************************************
//
// Clase ObjPLY (práctica 2)
//
// *****************************************************************************

ObjPLY::ObjPLY( const std::string & nombre_archivo )
{
   // leer la lista de caras y vértices
   ply::read( nombre_archivo, this->v, this->f );
c_vertices = setColor(1.0f, 0.0f, 1.0f,v.size());

        c_lineas = setColor(0.0f, 1.0f, 0.0f,v.size()); 

        c_solido = setColor(0.0f, 0.5f, 0.5f,v.size());
   this->nv = CalcularNormales();
}


