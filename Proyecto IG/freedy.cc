#include "freedy.h"

Freedy::Freedy(){
    psup = new PSup();
    piernaDcha = new Pierna();
    piernaIzda = new Pierna();
   
    giroPajarita = 0;
    giroHombroDcho = 0;
    giroHombroIzdo = 0;
    giroTronco = 0;
    alturaCabeza = 60;
    giroPiernaDcha = 0;
    giroPiernaIzda = 0;
    giroCabeza = 0;

}

void Freedy::draw(char opcion) {
    glPushMatrix();
        glRotatef(torsionTronco,1,0,0);
        psup->draw(opcion,giroHombroDcho,giroHombroIzdo,giroPajarita,alturaCabeza, giroCabeza, giroTronco, torsionTronco);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-12,0,0);
        glRotatef(giroPiernaDcha,1,0,0);
        piernaDcha->draw(opcion);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(12,0,0);
        glRotatef(-giroPiernaIzda,1,0,0);
        piernaIzda->draw(opcion);
    glPopMatrix();
    
};

void Freedy::modificaGiroHombro(float valor){
    float valor_devuelto = giroHombroDcho + valor;
    float valor_devuelto2 = giroHombroIzdo + valor;
    
    if(valor_devuelto > 45 || valor_devuelto < -45){
        std::cout << "TOPE HOMBRO DERECHO" <<std::endl;
    }
    else
        giroHombroDcho += valor;
    
    if(valor_devuelto2 > 45 || valor_devuelto2 < -45){
        std::cout << "TOPE HOMBRO IZQUIERDO" <<std::endl;
    }
    else
        giroHombroIzdo += valor;  
}

void Freedy::modificaGiroHombroAuto(float valor){
    float valor_devuelto = giroHombroDcho + valor;
    float valor_devuelto2 = giroHombroIzdo + valor;
    

        giroHombroDcho += valor;

        giroHombroIzdo += valor;  
}

void Freedy::modificaGiroPajarita(float valor){
        giroPajarita += valor;
}


void Freedy::modificaGiroTronco(float valor){
    
    float valor_devuelto = giroTronco + valor;
    if(valor_devuelto  <= 46 || valor_devuelto >= -46){
       std::cout << "TOPE GIRO TRONCO " << std::endl;
       giroTronco = 0;
    }
    else
        giroTronco += valor;
}

void Freedy::modificaTorsionTronco(float valor){
    
    float valor_devuelto = torsionTronco + valor;
    if(valor_devuelto  <= -15 || valor_devuelto >= 30){
       std::cout << "TOPE TORSION TRONCO " << std::endl;
       torsionTronco = 0;
    }
    else
        torsionTronco += valor;
}

void Freedy::modificaGiroCabeza(float valor){
    
    float valor_devuelto = giroCabeza + valor;
    if(valor_devuelto  == 46 || valor_devuelto == -46){
       std::cout << "TOPE GIRO CABEZA " << std::endl;
       giroCabeza = 0;
    }
    else
        giroCabeza += valor;
}

//PARA LA ENTREGA FINAL
void Freedy::modificaGiroTroncoAuto(float valor){
        giroTronco += valor;
}

void Freedy::modificaTorsionTroncoAuto(float valor){
        torsionTronco += valor;
}

void Freedy::modificaGiroPierna(float valor){
    float valor_devuelto = giroPiernaDcha + valor;
    float valor_devuelto2 = giroPiernaIzda + valor;
    
    if(valor_devuelto > 45 || valor_devuelto < -45)
        std::cout << "TOPE PIERNA DERECHA" <<std::endl;
    else
        giroPiernaDcha += valor;
    
    if(valor_devuelto2 > 45 || valor_devuelto2 < -45)
        std::cout << "TOPE PIERNA IZQUIERDA" <<std::endl;
    else
        giroPiernaIzda += valor;  
}

void Freedy::modificaGiroCabezaAuto(float valor){
    float valor_devuelto = giroCabeza + valor;

        giroCabeza += valor;
}
float Freedy::getGiroHombroDcho(){
    return giroHombroDcho;
}

void Freedy::modificaAlturaCabeza(float valor){
   float valor_devuelto = alturaCabeza + valor;
    if(valor_devuelto > 80 || valor_devuelto < 60)
        std::cout << "TOPE ALTURA CABEZA" <<std::endl;
    else
        alturaCabeza += valor;
}

void Freedy::modificaAlturaCabezaAuto(float valor){
   alturaCabeza+=valor;
}

float Freedy::getGiroHombroIzdo(){
    return giroHombroIzdo;
}

float Freedy::getAlturaCabeza(){
    return alturaCabeza;
}

float Freedy::getGiroCabeza(){
    return giroCabeza;
}

float Freedy::getTorsionTronco(){
    return torsionTronco;
}

float Freedy::getGiroTronco(){
    return giroTronco;
}
