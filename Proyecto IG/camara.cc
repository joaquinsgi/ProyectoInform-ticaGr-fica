#include "camara.h"

Camara::Camara(Tupla3f _eye, Tupla3f _at, Tupla3f _up, int _tipo, float _left, float _right, float _near, float _far, float _top, float _bottom, int _obj){
    eye = _eye;
    at = _at;
    up = _up;
    left = _left;
    tipo = _tipo;
    right = _right;
    near = _near;
    far = _far;
    top = _top;
    bottom = _bottom;
    numObj = _obj;
}

void Camara::rotarXExaminar(float angulo){
    eye = {(float)cos(angulo*M_PI/180)*eye[0] - (float)sin(angulo*M_PI/180)*eye[2], eye[1], (float)sin(angulo*M_PI/180)*eye[0] + (float)cos(angulo*M_PI/180)*eye[2]};
    up = {(float)cos(angulo*M_PI/180)*up[0] - (float)sin(angulo*M_PI/180)*up[2], up[1], (float)sin(angulo*M_PI/180)*up[0] + (float)cos(angulo*M_PI/180)*up[2]};
    
}

void Camara::rotarYExaminar(float angulo){ 
    eye = {eye[0], (float)cos(angulo*M_PI/180)*eye[1] + (float)sin(angulo*M_PI/180)*eye[2], (float)-sin(angulo*M_PI/180)*eye[1] + (float)cos(angulo*M_PI/180)*eye[2]};

    up = {up[0], (float)cos(angulo*M_PI/180)*up[1] + (float)sin(angulo*M_PI/180)*up[2], (float)-sin(angulo*M_PI/180)*up[1] + (float)cos(angulo*M_PI/180)*up[2]};
}

void Camara::rotarZExaminar(float angulo){
    eye = eye - at;
    Tupla3f aux;
    aux = eye;
    eye[0] = aux[0] * cos(angulo) - aux[2] * sin(angulo);
    eye[1] = aux[0] * sin(angulo) + aux[2] * cos(angulo);
    eye = eye + at;
}

void Camara::rotarXFirstPerson(float angulo){
    at[0] = at[0] + angulo;
}

void Camara::rotarYFirstPerson(float angulo){
    at[1] = at[1] + angulo;
}

void Camara::rotarZFirstPerson(float angulo){
    eye = eye - at;
    Tupla3f aux;
    aux = at;
    eye[0] = aux[0] * cos(angulo) - aux[2] * sin(angulo);
    eye[1] = aux[0] * sin(angulo) + aux[2] * cos(angulo);
    at = eye + at;
}

void Camara::mover(float x, float y, float z){
    eye[0] = x;
    eye[1] = y;
    eye[2] = z;
}

void Camara::girarPP(float x, float y){
    rotarXFirstPerson(x);
    rotarYFirstPerson(y);
}

void Camara::zoom(float factor){
    left *= factor;
    right *= factor;
    top *= factor;
    bottom *= factor;
}

void Camara::setObserver(){
    gluLookAt(eye[0], eye[1], eye[2], at[0], at[1], at[2], up[0], up[1], up[2]) ;
}

void Camara::setProyeccion(){
    if (tipo == 0)
        glFrustum(left,right,bottom,top,near,far);
    else if (tipo == 1)
        glOrtho(left,right,bottom,top,near,far);
}

void Camara::girar(float x, float y){
    rotarXExaminar(x);
    rotarYExaminar(y);
}

void Camara::setLeft(float _left){
    left = _left;
}

void Camara::setRight(float _right){
    right = _right;
}

float Camara::getBottom(){
    return bottom;
}

float Camara::getTop(){
    return top;
} 


void Camara::setNear(float _near){
    near = _near;
}

void Camara::setFar(float _far){
    far = _far;
}

void Camara::setBottom(float _bottom){
    bottom = _bottom;
}

void Camara::setTop(float _top){
    top = _top;
}
void Camara::setObjetoSeleccionado(int numobj){
    numObj = numobj;
}

void Camara::setEye(Tupla3f _eye){
    eye = _eye;
}

void Camara::setAt(Tupla3f _at){
    at = _at;

}

void Camara::setUp(Tupla3f _up){
    up = _up;
}

int Camara::getNumObjetoSeleccionado(){
    return numObj;
}
        
float Camara::getNear(){
    return near;
}

float Camara::getFar(){
    return far;
}
        
Tupla3f Camara::getEye(){
    return eye;
}

Tupla3f Camara::getAt(){
    return at;
}

Tupla3f Camara::getUp(){
    return up;
}

float Camara::getLeft(){
    return left;
}
        
float Camara::getRight(){
    return right;
}


