#ifndef CAMARA_H_INCLUDED
#define CAMARA_H_INCLUDED

#include "aux.h"

class Camara
{
    private:
        Tupla3f eye ;
        Tupla3f at ;
        Tupla3f up ;
        int tipo ; // ORTOGONAL o Perspectiva
        float left , right , near , far, top, bottom ; // o bien aspect, fov, near, far;
        int numObj;
    public:
        Camara(Tupla3f _eye, Tupla3f _at, Tupla3f _up, int _tipo, float _left, float _der, float _near, float _far, float _top, float _bottom, int _obj) ;
        void rotarXExaminar( float angle );
        void rotarYExaminar( float angle );
        void rotarZExaminar( float angle );
        void rotarXFirstPerson(float angle);
        void rotarYFirstPerson( float angle);
        void rotarZFirstPerson( float angle);
        void mover( float x , float y , float z);
        void zoom( float factor);
        void setObserver(); 
        void setProyeccion ();
        void girar(float x, float y);
        void girarPP(float x, float y);
        void setLeft(float _left);
        void setRight(float _right);
        void setNear(float _near);
        void setFar(float _far);
        void setBottom(float _bottom);
        void setTop(float _top);
        void setObjetoSeleccionado(int numobj);
        void setEye(Tupla3f _eye);
        void setAt(Tupla3f _at);
        void setUp(Tupla3f _up);
        int getNumObjetoSeleccionado();
        float getNear();
        float getFar();
        Tupla3f getEye();
        Tupla3f getAt();
        Tupla3f getUp();
        float getLeft();
        float getRight();
        float getBottom();
        float getTop();


};





#endif