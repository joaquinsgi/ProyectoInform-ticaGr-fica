#ifndef TEXTURA_H_INCLUDED
#define TEXTURA_H_INCLUDED

#include "aux.h"
#include "jpg_imagen.hpp"
class Textura {
        GLuint textura_id = 0;
        unsigned char * data ;
        int width , height ;
    public:
        Textura(std::string archivo );
        void activar ();
};


#endif