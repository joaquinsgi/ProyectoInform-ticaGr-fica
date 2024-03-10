#include "aux.h"     // includes de OpenGL/glut/glew, windows, y librería std de C++
#include "escena.h"
#include "malla.h" // objetos: Cubo y otros....
#include "objrevolucion.h"

//**************************************************************************
// constructor de la escena (no puede usar ordenes de OpenGL)
//**************************************************************************
   
Escena::Escena()
{
    Front_plane       = 50.0;
    Back_plane        = 2000.0;
    Observer_distance = 4*Front_plane;
    Observer_angle_x  = 0.0 ;
    Observer_angle_y  = 0.0 ;
   
    ejes.changeAxisSize( 5000 );
    // crear los objetos de la escena....
    // .......completar: ...
   // cubo = new Cubo(50);
    for(int i = 0; i < 8; i++){
        flags_iluminaciones[i] = false;
    }
   piramide = new PiramideHexagonal(100.0,50.0, 12.5);
   ply = new ObjPLY("./plys/big_dodge.ply");
   objrev = new ObjRevolucion("./plys/copa.ply",20,true,true);  
   cilindro = new Cilindro(20,100,100,50);
   esfera = new Esfera(10,20,50); 
   peon = new Peon(100,100,50,100);
   peon2 = new Peon(100,100,50,100);
   tetraedro = new Tetraedro(100);
   cono = new Cono(100,100,100,50);
   freedy = new Freedy();
   escenario = new Escenario();
   cubo = new Cubo(5);
   luz_posicional = new LuzPosicional({0,500,0}, GL_LIGHT0, {1.0,1.0,1.0,1.0}, {1.0,1.0,1.0,1.0}, {1.0,1.0,1.0,1.0});
   luz_posicional1 = new LuzPosicional({0,-100,0}, GL_LIGHT1, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 },{ 1.0, 1.0, 1.0, 1.0 });
   luz_posicional2 = new LuzPosicional({0,0,-100}, GL_LIGHT2, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 },{ 1.0, 1.0, 1.0, 1.0 });
   luz_posicional3 = new LuzPosicional({-100,-100,0}, GL_LIGHT3, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 },{ 1.0, 1.0, 1.0, 1.0 });
   luz_posicional4 = new LuzPosicional({-100,0,-100}, GL_LIGHT4, { 1.0, 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0, 1.0 },{ 1.0, 1.0, 1.0, 1.0 });
   luz_direccional = new LuzDireccional({0.0,200.0}, GL_LIGHT5, {0.3,0.2,0.1,1.0}, {0.3,0.2,0.1,1.0},{0.3,0.2,0.1,1.0});
   luz_direccional2= new LuzDireccional({50.0,50.0}, GL_LIGHT6, {0.0, 0.0, 1.0, 1.0}, {0.0, 0.0, 1.0, 1.0},{0.0, 0.0, 1.0, 1.0});
   materialobj1 = new Material({0.5f,0.5f,0.5f,1.0}, {1.0f,1.0f,1.0f,1.0}, {0.4f,0.3f,0.2f,1.0}, 100.0);
   material_peon = new Material({0.8,0.8,0.8,1.0}, {0.8,0.8,0.8,1.0}, {0.8,0.8,0.8,1.0}, 100.0);
   material_peon2 = new Material({ 0.0, 0.0, 0.0, 1.0 }, { 0.8,0.8,0.8,1.0 }, { 0.1, 0.1, 0.1, 1.0 }, 100.0);
   materialobj2 = new Material({ 1.0, 0.6, 0.6, 1.0 }, { 0.5,0.5,0.5 ,1.0 }, { 0.8, 0.5, 0.5, 1.0 }, 100.0);
   materialobj3 = new Material({0.5f,0.5f,0.5f,1.0}, {1.0f,1.0f,1.0f,1.0}, {0.4f,0.3f,0.2f,1.0}, 100.0);

   text_esfera = new Textura("./imagenes/mapa-mundi.jpg");
   text_cubo = new Textura("./imagenes/monalisa.jpg");
   cono->setMaterial(materialobj1);
   ply->setMaterial(materialobj2);   
   esfera->setMaterial(materialobj2);
   peon->setMaterial(material_peon);
   peon2->setMaterial(material_peon2);
   cubo->setMaterial(materialobj2);
   //cubo->setTextura(text_cubo);
   //esfera->setTextura(text_esfera);


   camara0 = new Camara({100.0,300.0,500.0},{-100.0,0.0,-100.0},{0.0,1.0,0.0},0,-100,100,Front_plane, Back_plane, 150.0,-50.0, 0);
   camara1 = new Camara({200.0,300.0,500.0},{-100.0,0.0,-100.0},{0.0,1.0,0.0},1,-100,100,Front_plane, Back_plane, 150.0,-50.0, 0);
   camara2 = new Camara({-100.0,300.0,500.0},{-100.0,0.0,-100.0},{0.0,1.0,0.0},0,-100,100,Front_plane, Back_plane, 150.0,-50.0, 0);
   camaranormal = new Camara({0.0,300.0,-500.0},{100.0,0.0,100.0},{0.0,1.0,0.0},0,-100,100,Front_plane, Back_plane, 150.0,-50.0, 0);
   camaras.push_back(*camara0);
   camaras.push_back(*camara1);
   camaras.push_back(*camara2);
   camaras.push_back(*camaranormal);
   camaraActiva = 0;
}
//**************************************************************************
// inicialización de la escena (se ejecuta cuando ya se ha creado la ventana, por
// tanto sí puede ejecutar ordenes de OpenGL)
// Principalmemnte, inicializa OpenGL y la transf. de vista y proyección
//**************************************************************************

void Escena::inicializar( int UI_window_width, int UI_window_height )
{
	glClearColor( 0.3,0.3,0.3,0.0 );// se indica cual sera el color para limpiar la ventana	(r,v,a,al)
   glEnable(GL_CULL_FACE); // Activar el flag para que no se pinten caras traseras
	glEnable( GL_DEPTH_TEST );	// se habilita el z-bufer
   glShadeModel(GL_SMOOTH);
   glEnable( GL_NORMALIZE );
   //glDisable( GL_LIGHTING );
   flag_iluminacion = true;
   //flags_iluminaciones[0] = true;
   flags_iluminaciones[5] = true;
   flag_automatico = true;
   flag_ilu_automatico = true;
	Width  = UI_window_width/10;
	Height = UI_window_height/10;
   std::cout << "Esta ante el menu de inicio " << std::endl;
   std::cout << "Esta viendo la escena completa animada automaticamente " << std::endl;
   std::cout << "Puede pulsar: " <<
   "\n\t -> 'A' para parar la animacion Automatica " <<
   "\n\t -> 'V' para seleccionar el modo de visionado de la escena "<<
   "\n\t -> 'M' para mover la escena manualmente " <<
   "\n\t -> 'C' para cambiar de camaras " << 
   "\n\t -> 'Q' para salir de la aplicacion " << 
   "\n\t Si clicas con el click izquierdo podras ver a freedy desde vista privilegiada hacia freedy, si clicas con el click derecho en freedy podras rotar la camara, si clicas fuera de freedy con el click derecho podras rotar en primera persona" << std::endl;
   change_projection( float(UI_window_width)/float(UI_window_height) );
	glViewport( 0, 0, UI_window_width, UI_window_height );
}



// **************************************************************************
//
// función de dibujo de la escena: limpia ventana, fija cámara, dibuja ejes,
// y dibuja los objetos
//
// **************************************************************************


void Escena::dibujar()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
   glDisable(GL_LIGHTING);
   ejes.draw();
   if(flag_puntos == true){
     glPushMatrix();
      glTranslatef(0,135,100);
      //glScalef(2,2,2);
      freedy->draw('p');
      glPopMatrix();
      glPushMatrix();
      glScalef(1.5,1,1);
      escenario->draw('p');
      glPopMatrix();
   }
   if(flag_lineas == true){
      glPushMatrix();
      glTranslatef(0,135,100);
      //glScalef(2,2,2);
      freedy->draw('l');
      glPopMatrix();
      glPushMatrix();
      glScalef(1.5,1,1);
      escenario->draw('l');
      glPopMatrix();
   }
   if(flag_solido == true){ 
      luz_posicional->desactivar();
      glPushMatrix();
      glTranslatef(0,135,100);
      //glScalef(2,2,2);
      freedy->draw('s');
      glPopMatrix();
      glPushMatrix();
      glScalef(1.5,1,1);
      escenario->draw('s');
      glPopMatrix();
   }
   if(flag_iluminacion == true){
            if(flags_iluminaciones[0] == true)
               luz_posicional->activar();
            if(flags_iluminaciones[0] == false)
               luz_posicional->desactivar();
            if(flags_iluminaciones[1] == true)
               luz_posicional1->activar();
            if(flags_iluminaciones[1] == false)
               luz_posicional1->desactivar();
            if(flags_iluminaciones[2] == true)
               luz_posicional2->activar();
            if(flags_iluminaciones[2] == false)
               luz_posicional2->desactivar();
            if(flags_iluminaciones[3] == true)
               luz_posicional3->activar();
            if(flags_iluminaciones[3] == false)
               luz_posicional3->desactivar();
            if(flags_iluminaciones[4] == true)
               luz_posicional4->activar();
            if(flags_iluminaciones[4] == false)
               luz_posicional4->desactivar();
            if(flags_iluminaciones[5] == true)
               luz_direccional->activar();
            if(flags_iluminaciones[5] == false)
               luz_direccional->desactivar();
            if(flags_iluminaciones[6] == true)
               luz_direccional2->activar();
            if(flags_iluminaciones[6] == false)
               luz_direccional2->desactivar();
            glPushMatrix();
            glPushMatrix();
            glTranslatef(0,135,100);
            //glScalef(2,2,2);
            freedy->draw('i');
            glPopMatrix();
            glPushMatrix();
            glScalef(1.5,1,1);
            escenario->draw('i');
            glPopMatrix();
            glPopMatrix();
         }

}

void Escena::animarModeloJerarquico(){
   if(freedy->getGiroHombroDcho() == 30 || freedy->getGiroHombroDcho() == -30 || freedy->getGiroHombroIzdo() == 30 || freedy->getGiroHombroIzdo() == -30)
      valor_brazos_auto*=-1;
      
   if(freedy->getGiroTronco() == -45 || freedy->getGiroTronco() == 45)
      valor_giro_tronco_auto *=-1;

   if(freedy->getGiroCabeza() == 46 || freedy->getGiroCabeza() == -46)
      valor_giro_cabeza_auto *=-1;

   if(freedy->getTorsionTronco() == -15 || freedy->getTorsionTronco() == 30)
      valor_torsion_tronco_auto *=-1;

   if(freedy->getAlturaCabeza() == 50 || freedy->getAlturaCabeza() == 80)
      valor_altura_cabeza_auto *=-1;

   freedy->modificaAlturaCabezaAuto(valor_altura_cabeza_auto);
   freedy->modificaGiroCabezaAuto(valor_giro_cabeza_auto);
   freedy->modificaGiroHombroAuto(valor_brazos_auto);
   freedy->modificaGiroTroncoAuto(valor_giro_tronco_auto);
   freedy->modificaTorsionTroncoAuto(0.5*valor_torsion_tronco_auto);
   freedy->modificaGiroPajarita(10*valor_giro_pajarita_auto);  
}


bool Escena::getIluminacion(){
   return flag_ilu_automatico;
}

bool Escena::getIluminacion_pos(){
   return flag_ilu_pos_automatico;
}

void Escena::animarPosicionLuz(){
   if(flag_ilu_pos_automatico == true){
      float incremento = 1;
      if(flags_iluminaciones[0] == true)
         luz_posicional->variarPosicionLuz(incremento,-incremento,incremento);
      if(flags_iluminaciones[1] == true)
         luz_posicional1->variarPosicionLuz(0.0,incremento,2*incremento);
      if(flags_iluminaciones[2] == true)
         luz_posicional2->variarPosicionLuz(incremento,0.0,-incremento);
      if(flags_iluminaciones[3] == true)
         luz_posicional3->variarPosicionLuz(incremento,incremento,incremento);
      if(flags_iluminaciones[4] == true)
         luz_posicional4->variarPosicionLuz(-incremento,-incremento,-incremento);
   }
   if(flag_ilu_automatico == true){
      if(flags_iluminaciones[5])
         luz_direccional->CambiarLuz();
      if(flags_iluminaciones[6] == true)
         luz_direccional2->CambiarLuz();
   }
   
}


bool Escena::getAutomatico(){
   return flag_automatico;
}
//**************************************************************************
//
// función que se invoca cuando se pulsa una tecla
// Devuelve true si se ha pulsado la tecla para terminar el programa (Q),
// devuelve false en otro caso.
//
//**************************************************************************

 
bool Escena::teclaPulsada( unsigned char tecla, int x, int y )
{
   using namespace std ;
   cout << "Tecla pulsada: '" << tecla << "'" << endl;
   bool salir=false;
   switch( toupper(tecla) )
   {
      std::cout << "Puede pulsar: " <<
      "\n\t -> 'A' para parar la animacion Automatica " <<
      "\n\t -> 'V' para seleccionar el modo de visionado de la escena "<<
       "\n\t -> 'M' para mover la escena manualmente " <<
      "\n\t -> 'C' para cambiar de camaras " << 
      "\n\t -> 'Q' para salir de la aplicacion " << std::endl;
      case 'Q' :
         if (modoMenu!=NADA)
            modoMenu=NADA;            
         else {
            salir=true ;
         }
         break ;
      case 'A' :
         cout << "MODO DE MOVIMIENTO AUTOMATICO" << endl;
         modoMenu=MODOAUTOMATICO;
         flag_manual = false;
         flag_automatico = !flag_automatico;
         break ;
      case 'V' :
         cout << "ESTAMOS EN MODO SELECCION DE MODO DE VISUALIZACION" <<endl;
         modoMenu=SELVISUALIZACION;
         flag_manual = false;
         flag_automatico = false;
         flag_solido = false;
         break ;
      case 'M' :
         cout << "MODO MANUAL DE ANIMACION OBJETO" <<endl;
         modoMenu=MODOMANUAL;
         flag_automatico = false;
         flag_manual= !flag_manual;
         break ;     

      case 'C' :
         cout << "MODO SELECCION DE CAMARA" <<endl;
         modoMenu=MODOCAMARA;
         flag_camara = !flag_camara;
         break ;        
   }
   switch(modoMenu){
      case MODOMANUAL:
      std::cout << "Puedes elegir las teclas del 0-6 para seleccionar un grado de libertad y luego '+' o '-' para aumentar o disminuir el grado de libertad " << std::endl;  
         switch(toupper(tecla)){
            case '0':
               flags_GradosLibertad[0] = !flags_GradosLibertad[0];
            break;
            case '1':
               flags_GradosLibertad[1] = !flags_GradosLibertad[1];
            break;
            case '2':
               flags_GradosLibertad[2] = !flags_GradosLibertad[2];
            break;

            case '3':
               flags_GradosLibertad[3] = !flags_GradosLibertad[3];
            break;

            case '4':
               flags_GradosLibertad[4] = !flags_GradosLibertad[4];
            break;

            case '5':
               flags_GradosLibertad[5] = !flags_GradosLibertad[5];
            break;
         }
         break;
      case SELVISUALIZACION:
      cout << "Puede pulsar: " <<
      "\n\t -> 'P' para visualizacion modo puntos " <<
      "\n\t -> 'L' para visualizacion modo lineas " <<
      "\n\t -> 'S' para visualizacion en modo solido " <<
      "\n\t -> 'I' para visualizacion en modo iluminacion " << 
      "\n\t -> 'Q' para salir modo visualizacion " << endl;
         switch(toupper(tecla)){
            case 'P':
               cout << "Visualizacion MODO PUNTOS" << endl;
               flag_iluminacion = false;
               flag_puntos = !flag_puntos;
               flag_iluminacion = false;
            break;

            case 'L':
               cout << "Visualizacion MODO LINEAS" << endl;
               flag_iluminacion = false;
               flag_lineas = !flag_lineas;
               flag_iluminacion = false;

            break;

            case 'S':
               cout << "Visualizacion MODO SOLIDO" << endl;
               flag_iluminacion = false;
               flag_solido = !flag_solido;
               flag_iluminacion = false;

            break;

            case 'I':
               cout << "Visualizacion MODO ILUMINACION" << endl;
               flag_puntos = false;
               flag_solido = false;
               flag_lineas = false;
               flag_automatico = false;
               flag_ilu_automatico = false;
               flags_iluminaciones[5] = false;
               flag_iluminacion = !flag_iluminacion;
            break;

            case 'Q':
            cout << "SALIR" << endl;
               flag_todos = false;
               flag_puntos = false;
               flag_lineas = false;
               flag_solido = false;
            break;
         }
         
      break;

      case MODOCAMARA:
      std::cout << "Al pulsar las teclas '0-3' puedes ir cambiando entre las diferentes camaras que hay " << std::endl;
         switch(toupper(tecla)){
            case '0':
               std::cout << "Usando Camara 0" << std::endl;
               camaraActiva = 0;
               change_projection(1);
            break;

            case '1':
               std::cout << "Usando Camara 1" << std::endl;
               camaraActiva = 1;
               change_projection(1);
            break;

            case '2':
               std::cout << "Usando Camara 2" << std::endl;
               camaraActiva = 2;
               change_projection(1);
            break;

            case '3':
               std::cout << "Usando Camara 3" << std::endl;
               camaraActiva = 3;
               change_projection(1);
            break;
         }
      break;
   }
   if(flag_automatico == true){
      animarModeloJerarquico();
   }
   if(flag_iluminacion == true && flag_camara == false){
      std::cout << "Puedes encender y seleccionar las luces pulsando las teclas '1-6' o apagarlas volviendo a pulsar las teclas '1-6' " << std::endl;
      if(tecla == '0'){
         std::cout << "Encendiendo Luz Posicional 0" << std::endl;
         flags_iluminaciones[0] = !flags_iluminaciones[0];
         if(flags_iluminaciones[0] == true){
             flags_iluminaciones[6] = false;
               flags_iluminaciones[5] = false;
               flags_iluminaciones[1] = false;
               flags_iluminaciones[2] = false;
               flags_iluminaciones[3] = false;
               flags_iluminaciones[4] = false;
         }
      }
       if(tecla == '1'){
         std::cout << "Encendiendo Luz Posicional 1" << std::endl;
         flags_iluminaciones[1] = !flags_iluminaciones[1];
         if(flags_iluminaciones[1] == true){
             flags_iluminaciones[6] = false;
               flags_iluminaciones[5] = false;
               flags_iluminaciones[0] = false;
               flags_iluminaciones[2] = false;
               flags_iluminaciones[3] = false;
               flags_iluminaciones[4] = false;
         }
      }
       if(tecla == '2'){
         std::cout << "Encendiendo Luz Posicional 2" << std::endl;
         flags_iluminaciones[2] = !flags_iluminaciones[2];
         if(flags_iluminaciones[2] == true){
             flags_iluminaciones[6] = false;
               flags_iluminaciones[5] = false;
               flags_iluminaciones[1] = false;
               flags_iluminaciones[0] = false;
               flags_iluminaciones[3] = false;
               flags_iluminaciones[4] = false;
         }
      }
       if(tecla == '3'){
         std::cout << "Encendiendo Luz Posicional 3" << std::endl;
         flags_iluminaciones[3] = !flags_iluminaciones[3];
         if(flags_iluminaciones[3] == true){
             flags_iluminaciones[6] = false;
               flags_iluminaciones[5] = false;
               flags_iluminaciones[1] = false;
               flags_iluminaciones[2] = false;
               flags_iluminaciones[0] = false;
               flags_iluminaciones[4] = false;
         }
      }
       if(tecla == '4'){
         std::cout << "Encendiendo Luz Posicional 4" << std::endl;
         flags_iluminaciones[4] = !flags_iluminaciones[4];
         if(flags_iluminaciones[4] == true){
             flags_iluminaciones[6] = false;
               flags_iluminaciones[5] = false;
               flags_iluminaciones[1] = false;
               flags_iluminaciones[2] = false;
               flags_iluminaciones[3] = false;
               flags_iluminaciones[0] = false;
         }
      }
       if(tecla == '5'){
         std::cout << "Encendiendo Luz Direccional 5" << std::endl;
         flags_iluminaciones[5] = !flags_iluminaciones[5];
         if(flags_iluminaciones[5] == true){
             flags_iluminaciones[6] = false;
               flags_iluminaciones[0] = false;
               flags_iluminaciones[1] = false;
               flags_iluminaciones[2] = false;
               flags_iluminaciones[3] = false;
               flags_iluminaciones[4] = false;
         }
      }
       if(tecla == '6'){
         std::cout << "Encendiendo Luz Direccional 6" << std::endl;
         flags_iluminaciones[6] = !flags_iluminaciones[6];
         if(flags_iluminaciones[6] == true){
             flags_iluminaciones[0] = false;
               flags_iluminaciones[5] = false;
               flags_iluminaciones[1] = false;
               flags_iluminaciones[2] = false;
               flags_iluminaciones[3] = false;
               flags_iluminaciones[4] = false;
         }
      }
      std::cout << "Si pulsas X ccon alguna de las luces direccionales puedes cambiar su angulo ALPHA " << std::endl;
      if(tecla == 'X' || tecla == 'x'){
         std::cout << "Cambiando Angulo Alpha" << std::endl;
         std::cout << "Pulsa '<' para decrementar angulo o '>' para aumentar angulo" << std::endl;
         cambioA =!cambioA;
         flag_variacion_alpha = !flag_variacion_alpha;
      }
      std::cout << "Si pulsas F ccon alguna de las luces direccionales puedes cambiar su angulo BETA " << std::endl;
      if(tecla == 'F' || tecla == 'f'){
         std::cout << "Cambiando Angulo Beta" << std::endl;
         std::cout << "Pulsa '<' para decrementar angulo o '>' para aumentar angulo" << std::endl;
         cambioB = !cambioB;
         flag_variacion_beta = !flag_variacion_beta;
      }
         if(flag_variacion_alpha == true){
            if(flags_iluminaciones[5] == true){
               if(tecla  == '<'){
                  std::cout << "Disminuyendo Angulo ALPHA" << std::endl;
                  incremento = -5;
                  luz_direccional->variarAnguloAlpha(incremento);
               }
               if(tecla  == '>'){
                  std::cout << "Aumentando Angulo ALPHA" << std::endl;
                  incremento = 5;
                  luz_direccional->variarAnguloAlpha(incremento);
               }
            }
            if(flags_iluminaciones[6] == true){
               if(tecla  == '<'){
                  std::cout << "Disminuyendo Angulo ALPHA" << std::endl;
                  incremento = -5;
                  luz_direccional2->variarAnguloAlpha(incremento);
               }
               if(tecla  == '>'){
                  std::cout << "Aumentando Angulo ALPHA" << std::endl;
                  incremento = 5;
                  luz_direccional2->variarAnguloAlpha(incremento);
               }
            }
         }
       if(flag_variacion_beta == true){
         if(flags_iluminaciones[5] == true){
            if(tecla  == '<'){
               std::cout << "Disminuyendo Angulo BETA" << std::endl;
               incremento = -5;
               luz_direccional->variarAnguloBeta(incremento);
             }
            else if(tecla  == '>'){
               std::cout << "Aumentando Angulo BETA" << std::endl;
               incremento = 5;
               luz_direccional->variarAnguloBeta(incremento);
            } 
         }
         if(flags_iluminaciones[6] == true){
            if(tecla  == '<'){
               std::cout << "Disminuyendo Angulo BETA" << std::endl;
               incremento = -5;
               luz_direccional2->variarAnguloBeta(incremento);
             }
            else if(tecla  == '>'){
               std::cout << "Aumentando Angulo BETA" << std::endl;
               incremento = 5;
               luz_direccional2->variarAnguloBeta(incremento);
            } 
         }
         
      }
      std::cout << "Si seleccionas 'N'  con una luz direccional activada se activa el flag de iluminacion automatica de luz direccional " << std::endl;
      if(tecla == 'N' || tecla == 'n'){
         flag_ilu_automatico = !flag_ilu_automatico;
         //animarPosicionLuz();
         if(flag_ilu_automatico == true)
            std::cout << "Activo Luz Modo Automatico" << std::endl;
         else
            std::cout << "Desactivo Luz Modo Automatico" << std::endl;
      }
      std::cout << "Si seleccionas 'D' con una luz posicional activadase activa el flag de iluminacion automatica de luz posicional " << std::endl;
      
      if(tecla == 'D' || tecla == 'd'){
         flag_ilu_pos_automatico = !flag_ilu_pos_automatico;
         if(flag_ilu_pos_automatico == true)
            std::cout << "Activo Luz Modo Automatico POS" << std::endl;
         else
            std::cout << "Desactivo Luz Modo Automatico POS" << std::endl;
      }

      std::cout << "\nSi seleccionas alguna de las luces posicionales (0-4) y pulsas '+' o '-' puedes cambiar su posicion " << std::endl;
      std::cout << "Si seleccionas alguna de las luces direccionales (5-6) y pulsas '+' o '-' puedes cambiar su color " << std::endl;
      if(flag_ilu_automatico == false){
         if(flags_iluminaciones[0] == true){
            if(tecla == '+'){
               std::cout << "Aumentando posicion Luz 0" << std::endl;
               luz_posicional->variarPosicionLuz(20,20,0);
            }
            if(tecla == '-'){
               std::cout << "Disminuyendo posicion Luz 0" << std::endl;
               luz_posicional->variarPosicionLuz(-20,-20,0);
            }
         }
         if(flags_iluminaciones[1] == true){
            if(tecla == '+'){
               std::cout << "Aumentando posicion Luz 1" << std::endl;
                  luz_posicional1->variarPosicionLuz(0,20,0);
            }
            if(tecla == '-'){
               std::cout << "Disminuyendo posicion Luz 1" << std::endl;
               luz_posicional1->variarPosicionLuz(0,-20,0);
               
            }
         }
         if(flags_iluminaciones[2] == true){
            if(tecla == '+'){
               std::cout << "Aumentando posicion Luz 2" << std::endl;
               luz_posicional2->variarPosicionLuz(0,0,20);
               }
            if(tecla == '-'){
               std::cout << "Disminuyendo posicion Luz 2" << std::endl;
               luz_posicional2->variarPosicionLuz(0,0,-20);
            }

         }
         if(flags_iluminaciones[3] == true){
            if(tecla == '+'){
               std::cout << "Aumentando posicion Luz 3" << std::endl;
               luz_posicional3->variarPosicionLuz(20,20,0);
            }
            if(tecla == '-'){
               std::cout << "Disminuyendo posicion Luz 3" << std::endl;
               luz_posicional3->variarPosicionLuz(-20,-20,0);
            }
         }
         if(flags_iluminaciones[4] == true){
            if(tecla == '+'){
               std::cout << "Aumentando posicion Luz 4" << std::endl;
               luz_posicional4->variarPosicionLuz(20,0,20);
            }
            if(tecla == '-'){
               std::cout << "Disminuyendo posicion Luz 4" << std::endl;
               luz_posicional4->variarPosicionLuz(-20,0,20);
               }
         }
         if(flags_iluminaciones[5] == true){
            if(tecla == '+'){
               std::cout << "Aumentando Color Luz 5" << std::endl;
               luz_direccional->CambiarLuz();
            }
            if(tecla == '-'){
               std::cout << "Disminuyendo Color Luz 5" << std::endl;
               luz_direccional->CambiarLuz();
            }

         }
         if(flags_iluminaciones[6] == true){
            if(tecla == '+'){
               std::cout << "Aumentando Color Luz 6" << std::endl;
               luz_direccional2->CambiarLuz();
            }
            if(tecla == '-'){
               std::cout << "Disminuyendo Color Luz 6" << std::endl;
               luz_direccional2->CambiarLuz();
            
            }
         }
      }
   }
   if(flags_GradosLibertad[0] == true ){
      flags_GradosLibertad[2] = false;
      flags_GradosLibertad[1] = false;
     flags_GradosLibertad[3] = false;
        flags_GradosLibertad[4] = false;
        flags_GradosLibertad[5] = false;
         std::cout << "Seleccionado Grado Libertad 1" << std::endl;
         if(tecla == '+'){
            std::cout << "Aumentando valor en Grado Libertad 0" << std::endl;
            valor_brazos=5;
            freedy->modificaGiroHombro(valor_brazos);
         }
         else if(tecla == '-'){
            std::cout << "Disminuyendo valor en Grado Libertad 0" << std::endl;
            valor_brazos=-5;
            freedy->modificaGiroHombro(valor_brazos);

         }
         else
            valor_brazos = 0;
      }
      if(flags_GradosLibertad[1] == true){
        flags_GradosLibertad[2] = false;
        flags_GradosLibertad[0] = false;
        flags_GradosLibertad[3] = false;
        flags_GradosLibertad[4] = false;
        flags_GradosLibertad[5] = false;
         std::cout << "Seleccionado Grado Libertad 2" << std::endl;
         if(tecla == '+'){
            std::cout << "Aumentando valor en Grado Libertad 1" << std::endl;
            valor_giro_cabeza=1;
            freedy->modificaGiroCabeza(valor_giro_cabeza);  

         }
         else if(tecla == '-'){
            std::cout << "Disminuyendo valor en Grado Libertad 1" << std::endl;
            valor_giro_cabeza=-1;
            freedy->modificaGiroCabeza(valor_giro_cabeza);
         }
         else
            valor_giro_cabeza=0;
      }
      if(flags_GradosLibertad[2] == true){
         flags_GradosLibertad[3] = false;
        flags_GradosLibertad[0] = false;
        flags_GradosLibertad[1] = false;
        flags_GradosLibertad[4] = false;
        flags_GradosLibertad[5] = false;
         std::cout << "Seleccionado Grado Libertad 3" << std::endl;
         if(tecla == '+'){
            std::cout << "Aumentando valor en Grado Libertad 3" << std::endl;
            valor_giro_pajarita=10;
            freedy->modificaGiroPajarita(valor_giro_pajarita);
         }
         else if(tecla == '-'){
            std::cout << "Disminuyendo valor en Grado Libertad 3" << std::endl;
            valor_giro_pajarita=-10;
            freedy->modificaGiroPajarita(valor_giro_pajarita);

         }
         else valor_giro_pajarita= 0;
      }
       if(flags_GradosLibertad[3] == true){
         flags_GradosLibertad[2] = false;
        flags_GradosLibertad[0] = false;
        flags_GradosLibertad[1] = false;
        flags_GradosLibertad[4] = false;
        flags_GradosLibertad[5] = false;
         std::cout << "Seleccionado Grado Libertad 4" << std::endl;
         if(tecla == '+'){
            std::cout << "Aumentando valor en Grado Libertad 4" << std::endl;
            valor_giro_tronco=2;
            freedy->modificaGiroTronco(valor_giro_tronco);
         }
         else if(tecla == '-'){
            std::cout << "Disminuyendo valor en Grado Libertad 4" << std::endl;
            valor_giro_tronco=-2;
            freedy->modificaGiroTronco(valor_giro_tronco);

         }
         else valor_giro_tronco= 0;
      }
       if(flags_GradosLibertad[4] == true){
         flags_GradosLibertad[2] = false;
        flags_GradosLibertad[0] = false;
        flags_GradosLibertad[3] = false;
        flags_GradosLibertad[1] = false;
        flags_GradosLibertad[5] = false;
         std::cout << "Seleccionado Grado Libertad 5" << std::endl;
         if(tecla == '+'){
            std::cout << "Aumentando valor en Grado Libertad 5" << std::endl;
            valor_torsion_tronco=2;
            freedy->modificaTorsionTronco(valor_torsion_tronco);
         }
         else if(tecla == '-'){
            std::cout << "Disminuyendo valor en Grado Libertad 5" << std::endl;
            valor_torsion_tronco=-2;
            freedy->modificaTorsionTronco(valor_torsion_tronco);

         }
         else valor_torsion_tronco= 0;
      }
       if(flags_GradosLibertad[5] == true){
         flags_GradosLibertad[2] = false;
        flags_GradosLibertad[0] = false;
        flags_GradosLibertad[3] = false;
        flags_GradosLibertad[1] = false;
        flags_GradosLibertad[4] = false;
         std::cout << "Seleccionado Grado Libertad 6" << std::endl;
         if(tecla == '+'){
            std::cout << "Aumentando valor en Grado Libertad 6" << std::endl;
            valor_altura_cabeza=2;
            freedy->modificaAlturaCabeza(valor_altura_cabeza);
         }
         else if(tecla == '-'){
            std::cout << "Disminuyendo valor en Grado Libertad 6" << std::endl;
            valor_altura_cabeza=-2;
            freedy->modificaAlturaCabeza(valor_altura_cabeza);

         }
         else valor_altura_cabeza = 0;
      }
   return salir;
}

void Escena::clickRaton(int boton, int estado, int x, int y){
	xant = x;
	yant = y;
   //dibujaSeleccion();
	if (boton == GLUT_RIGHT_BUTTON){
      click = 0;
     // dibujaSeleccion();
		if (estado == GLUT_DOWN){
         procesarClick(x,y,click);
			if (camaras[camaraActiva].getNumObjetoSeleccionado() == 0){
            std::cout<<"NO SELECCIONO NADA " << std::endl;
				estadoRaton = MOVIENDO_CAMARA_FIRSTPERSON;
			} else{
            std::cout<<" SELECCIONADO OBJETO " << std::endl;
				estadoRaton = MOVIENDO_CAMARA_EXAMINAR;
			}
		}

	} else if (boton == 3 ){
		camaras[camaraActiva].zoom(0.8);
      change_projection(1.0);
	} else if (boton == 4){
		camaras[camaraActiva].zoom(1.2);
      change_projection(1.0);
	} else if (boton == GLUT_LEFT_BUTTON){
      click = 1;
		if (estado == GLUT_DOWN){
         if(camaras[camaraActiva].getNumObjetoSeleccionado() != 0)
			   procesarClick(x,y,click);
		}
	}
	change_projection(1.0);
}

void Escena::ratonMovido(int x, int y){
   if(estadoRaton == MOVIENDO_CAMARA_FIRSTPERSON){
      std::cout << "MOVIENDO CAMARA FIRST PERSON" << std::endl;
      camaras[camaraActiva].girarPP(x-xant, y-yant);
      xant = x ;
      yant = y ;
   }
   if(estadoRaton == MOVIENDO_CAMARA_EXAMINAR){
      std::cout << "MOVIENDO CAMARA EXAMINAR " << std::endl;
      camaras[camaraActiva].girar(x-xant, y-yant);
      xant = x ;
      yant = y ;
   }
}

void Escena::dibujaSeleccion(){
   glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
   glDisable(GL_LIGHTING);
   
   std::cout << "DIBUJA NUEVO " << std::endl;
   glPushMatrix();
   glPushMatrix();
   glTranslatef(0,135,100);
   //glScalef(2,2,2);
   freedy->draw('s');
   glPopMatrix();
   glPushMatrix();
   glScalef(1.5,1,1);
   escenario->draw('s');
   glPopMatrix();
   glPopMatrix();
}






void Escena::procesarClick(int x, int y, int click){
   dibujaSeleccion();
   GLint viewport[4];
   GLubyte pixel[3];
   glGetIntegerv(GL_VIEWPORT,viewport);
   glReadBuffer(GL_BACK);
   glReadPixels(x,viewport[3]-y,1,1,GL_RGB,GL_UNSIGNED_BYTE, (void *)pixel);

   if(click == 0){ // click derecho
      std::cout << "CLICK DER" << std::endl;
      if(pixel[0] == 0.0 && pixel[1] == 255.0 && pixel[2] == 0.0){
         std::cout << "Ha Seleccionado Freedy" << std::endl;
         camaras[camaraActiva].setObjetoSeleccionado(1);
         //camaras[camaraActiva].mover(0,500.0,400.0);
         std::cout << "Ha Seleccionado algo con valor ahora " << camaras[camaraActiva].getNumObjetoSeleccionado() << std::endl;
      }
   }
   else if(click == 1){ // click izdo
      std::cout << "CLICK IZDO" << std::endl;
      if(pixel[0] == 0.0 && pixel[1] == 255 && pixel[2] == 0.0){
         std::cout << "Ha Seleccionado el freedy" << std::endl;
         camaras[camaraActiva].setObjetoSeleccionado(1);
         std::cout << "Ha Seleccionado el freedy con valor ahora " << camaras[camaraActiva].getNumObjetoSeleccionado() << std::endl;
         camaras[camaraActiva].mover(0,500.0,400.0);
      }
   }
   dibujar();
   if(pixel[0] == 1.0 && pixel[1] == 1.0 && pixel[2] == 1.0){
      std::cout << "No ha seleccionado nada" << std::endl;
      camaras[camaraActiva].setObjetoSeleccionado(0);
      std::cout << " NO Ha Seleccionado NINGUN OBJETO VALE " << camaras[camaraActiva].getNumObjetoSeleccionado() << std::endl;
   }
   
}
//**************************************************************************

void Escena::teclaEspecial( int Tecla1, int x, int y )
{
   switch ( Tecla1 )
   {
	   case GLUT_KEY_LEFT:
         camaras[camaraActiva].rotarYExaminar(-3.0*M_PI/180.0);
         break;
	   case GLUT_KEY_RIGHT:
         camaras[camaraActiva].rotarYExaminar(3.0*M_PI/180.0);
         break;
	   case GLUT_KEY_UP:
         camaras[camaraActiva].rotarXExaminar(3.0*M_PI/180.0);
         break;
	   case GLUT_KEY_DOWN:
         camaras[camaraActiva].rotarXExaminar(-3.0*M_PI/180.0);
         break;
	   case GLUT_KEY_PAGE_UP:
         camaras[camaraActiva].zoom(1/1.2);
         break;
	   case GLUT_KEY_PAGE_DOWN:
         camaras[camaraActiva].zoom(1.2);
         break;
	}

	//std::cout << Observer_distance << std::endl;
}

//**************************************************************************
// Funcion para definir la transformación de proyeccion
//
// ratio_xy : relacción de aspecto del viewport ( == ancho(X) / alto(Y) )
//
//***************************************************************************

void Escena::change_projection( const float ratio_xy )
{
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   camaras[camaraActiva].setProyeccion();
}
//**************************************************************************
// Funcion que se invoca cuando cambia el tamaño de la ventana
//***************************************************************************

void Escena::redimensionar( int newWidth, int newHeight )
{
   Width  = newWidth/10;
   Height = newHeight/10;
   camaras[camaraActiva].setLeft(camaras[camaraActiva].getBottom()*Width/Height);
   camaras[camaraActiva].setRight(camaras[camaraActiva].getTop()*Width/Height);
   change_projection( float(newHeight)/float(newWidth) );
   glViewport( 0, 0, newWidth, newHeight );
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void Escena::change_observer()
{
   // posicion del observador
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   // glTranslatef( 0.0, 0.0, -Observer_distance );
   // glRotatef( Observer_angle_y, 0.0 ,1.0, 0.0 );
   // glRotatef( Observer_angle_x, 1.0, 0.0, 0.0 );
   camaras[camaraActiva].setObserver();
  
}
