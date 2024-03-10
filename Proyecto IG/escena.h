#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "malla.h"
#include "cubo.h"
#include "piramidehexagonal.h"
#include "objply.h"
#include "objrevolucion.h"
#include "cilindro.h"
#include "esfera.h"
#include "cono.h"
#include "luz.h"
#include "luz_posicional.h"
#include "luz_direccional.h"
#include "peon.h"
#include "tetraedro.h"
#include "freedy.h"
#include "camara.h"
#include "escenario.h"

typedef enum {NADA, SELOBJETO,SELVISUALIZACION,MODOAUTOMATICO, MODOMANUAL, MODOCAMARA} menu;
typedef enum {MOVIENDO_CAMARA_FIRSTPERSON, MOVIENDO_CAMARA_EXAMINAR, NADASELEC} EstadosRaton;

class Escena
{
   private:
        

   

 // ** PARÁMETROS DE LA CÁMARA (PROVISIONAL)
       
       // variables que definen la posicion de la camara en coordenadas polares
   GLfloat Observer_distance;
   GLfloat Observer_angle_x;
   GLfloat Observer_angle_y;
   float aumento_alpha = 0;
    float aumento_beta = 0;


   // variables que controlan la ventana y la transformacion de perspectiva
   GLfloat Width, Height, Front_plane, Back_plane;

    // Transformación de cámara
	void change_projection( const float ratio_xy );
	void change_observer();
    

    bool flag_puntos = false;
    bool flag_camara = false;
    bool flag_lineas = false;
    bool flag_solido = false;
    bool flag_todos = false;
    bool flag_variacion_alpha = false;
    bool flag_iluminacion = false;
    bool flags_iluminaciones[8];
    bool flag_manual = false;
    bool flag_automatico = false;
    bool flag_ilu_pos_automatico = false;
    float valor_brazos= 0;
    float valor_giro_cabeza= 0;
    float valor_altura_cabeza= 0;
    float valor_torsion_tronco= 0;
    float valor_giro_tronco= 0;
    float valor_giro_pajarita = 0;
    float valor_brazos_auto= 1;
    float valor_altura_cabeza_auto= 1;
    float valor_giro_pajarita_auto = 1;
    float valor_giro_cabeza_auto = 1;
    float valor_torsion_tronco_auto = 1;
    float valor_giro_tronco_auto = 1;

    bool flags_GradosLibertad[7];
    bool flag_variacion_beta = false;
    bool flag_ilu_automatico = false;
    float incremento = 0;
    bool cambioA = false;
    bool cambioB = false;
    int valorAlturaCabeza = 0;
    int valorGiroCabeza = 0;
    int valorGiroHombro = 0;
    
    float posx_luz0 = 0.0;
    float posy_luz0 = 0.0;
    float posz_luz0 = 0.0;

    float posx_luz1 = -50.0;
    float posy_luz1 = 50.0;
    float posz_luz1 = 0.0;

    float posx_luz2 = 50.0;
    float posy_luz2 = 0.0;
    float posz_luz2 = 0.0;

    float posx_luz3 = -50.0;
    float posy_luz3 = -50.0;
    float posz_luz3 = 0.0;

    float posx_luz4 = 50.0;
    float posy_luz4 = 0.0;
    float posz_luz4 = 50.0;

    EstadosRaton estadoRaton = NADASELEC;
	int xant = 0;
	int yant = 0;

    //std::vector<Tupla3f> color_luces = {{ 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 },{ 1.0, 1.0, 1.0, 1.0 }};

    void clear_window();
    char tipo_objeto;
    char tipo_visualizacion;
    menu modoMenu=NADA;
   // Objetos de la escena
    Ejes ejes;
    Cubo * cubo = nullptr ; // es importante inicializarlo a 'nullptr'
    PiramideHexagonal * piramide= nullptr ; // es importante inicializarlo a 'nullptr'
    ObjPLY * ply = nullptr;
    ObjRevolucion * objrev = nullptr;
    Cilindro * cilindro = nullptr;
    Cono * cono = nullptr;
    Esfera * esfera = nullptr;
    Peon * peon = nullptr;
    Peon * peon2 = nullptr;
    Freedy * freedy = nullptr;
    Tetraedro * tetraedro = nullptr;
    Escenario * escenario = nullptr;
    LuzPosicional * luz_posicional = nullptr;
    LuzPosicional * luz_posicional2 = nullptr;
    LuzPosicional * luz_posicional3 = nullptr;
    LuzPosicional * luz_posicional4 = nullptr;
    LuzPosicional * luz_posicional1 = nullptr;
    LuzDireccional * luz_direccional = nullptr;
    LuzDireccional * luz_direccional2 = nullptr;
    LuzDireccional * luz_direccional3 = nullptr;
    Material * materialobj1 = nullptr;
    Material * materialobj2 = nullptr;
    Material * materialobj3 = nullptr;

    Material * material_peon = nullptr;
    Material * material_peon2 = nullptr;
    Textura * text_cubo = nullptr;
    Textura * text_esfera = nullptr;
    std::vector<Camara> camaras ;
    Camara * camara0 = nullptr;
    Camara * camara1 = nullptr;
    Camara * camara2 = nullptr;
    Camara * camaranormal = nullptr;
    int camaraActiva;
    int click = 0; // 0 para derecho 1 para izdo

   public:

    Escena();
	void inicializar( int UI_window_width, int UI_window_height );
	void redimensionar( int newWidth, int newHeight ) ;
    void animarModeloJerarquico();
    bool getAutomatico();
    void animarPosicionLuz();
    bool getIluminacion();
	// Dibujar
	void dibujar() ;
    bool getIluminacion_pos();
    void dibujaSeleccion();

    void procesarClick(int x, int y, int click);
	// Interacción con la escena
	bool teclaPulsada( unsigned char Tecla1, int x, int y ) ;
	void teclaEspecial( int Tecla1, int x, int y );

    void clickRaton(int boton, int estado, int x, int y);
	void ratonMovido(int x, int y);

};
#endif
