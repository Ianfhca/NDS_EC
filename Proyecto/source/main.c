#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>       	

#include "fondos.h"
#include "sprites.h"
#include "defines.h"
#include "rutserv.h"
#include "teclado.h"
#include "temporizadores.h"
#include "tactil.h"
#include "funciones.h"

//-----------------------------------------------------
// Variables globales
//-----------------------------------------------------

int estado;
int segs=0;
int segs2=0;
int segs3=0;
int maxF=1; //Tiene que ser 10.
int fps=0;
bool canJump=true;
bool inAir=true;
bool derecha=false;
bool izquierda=false;
bool notasCaer=false;
bool FIN=false;
double distance =60.0;
double x=110.0;
double y=150.0;
double ground=0.0;

int Fs =0;
int As =0;
int Bs=0;
int Cs=0;





int main() {

	//  Poner en marcha el motor gráfico 2D.
    	powerOn(POWER_ALL_2D);

     	// Establecer la pantalla inferior como principal, inicializar el sistema gráfico
     	// y configurar el sistema de fondos.
    	lcdMainOnBottom();
    	initVideo();
    	initFondos();

	// Inicializar memoria de sprites y guardar en ella los sprites 
	initSpriteMem();
	guardarSpritesEnMemoria();

	// Establecer las paletas para los sprites 
	establecerPaletaPrincipal();

	// Para poder imprimir en pantalla (hacer trazas) 
	consoleDemoInit();
	
 	// Para inicializar el generador de números aleatorios en función de una semilla,
	// en este caso time(NULL). 
	// srand() sólo se suele activar una vez por ejecución y no devuelve ningún valor 
	srand (time(NULL));


	//ESTADOS
    	estado = 0; //0=INICIAL, 1=TIRARNOTAS, 2=JUEGO
    	
	//Variables locales
	
	ground=y;	
	interrupciones();


	while(1)
	{
		switch(estado){


		case 0: //INICIAL

			//Implementar Start Screen
			//MostrarClassroom();
			iprintf("\x1b[02;09H EsquiviNotas");

			iprintf("\x1b[08;03H Como jugar:");
			iprintf("\x1b[10;03H Mover    <---  --->");
			iprintf("\x1b[12;03H Saltar    [______]");
			iprintf("\x1b[20;03H Pulsa 'Start' para jugar!");

			if(segs==0){MostrarAnim1();}
			

			if (segs3==10){
				
				MostrarAnim1();	
				
			}
			else if (segs3==20){
				MostrarAnim2();	
			}
			else if (segs3==30){
				MostrarAnim3();	
			}
			else if (segs3==40){
				MostrarAnim4();	
			}
			else if (segs3==50){
				MostrarAnim3();	
			}
			else if (segs3==60){
				MostrarAnim2();	
			}
			else if (segs3==69){
				MostrarAnim1();	
			}


			
		
			int a=TeclaPulsada();
			if (a==3){

				LimpiarPantalla();
				MostrarSprite(30,x,y); 
				MostrarClassroom();
				segs=0;
				estado=1;
			}
			

		break;

		case 1: //COUNTER

			if (segs<5){iprintf("\x1b[08;05H Las Notas caen en:");}
			
			if (segs==1){iprintf("\x1b[12;12H 3..");}
			if (segs==2){iprintf("\x1b[12;12H 2..");}
			if (segs==3){iprintf("\x1b[12;12H 1..");}	
			if (segs==4){LimpiarPantalla(); segs=0; segs2=0;estado=2;}
			
		break;

		case 2: //JUEGO

			
			notasCaer=true;

			iprintf("\x1b[20;03H Time:%d",segs2);
			iprintf("\x1b[04;03H Notas Recogidas: ");			
			iprintf("\x1b[06;03H A:%d",As);	
			iprintf("\x1b[08;03H B:%d",Bs);			
			iprintf("\x1b[10;03H C:%d",Cs);			
			iprintf("\x1b[12;03H F:%d",Fs);						

			if ((segs%2)==0){
				MostrarClassroom();		
			}
			else{
				MostrarClassroom2();
			}
			
		
			if (Fs==maxF || segs2==120){
				LimpiarPantalla();
				
				FIN=true;
				segs2=0;
				estado=3;}
			

		break;

		/*case 3: //GAME OVER

			if ((segs%2)==0){
				MostrarGo1();
				MostrarGo2();
			}
			else {
				MostrarGo3();
				MostrarGo4();

			}
			
			
			if (segs2>=3){
				
				segs2=0;
				estado=4;

			}
			
		break;*/
		case 3: //FINAL
			
			//mostrar pantalla: Resumen
			if ((segs%2)==0){
				MostrarGo1();
				MostrarGo2();
			}
			else {
				MostrarGo3();
				MostrarGo4();

			}
			
			iprintf("\x1b[02;10H GAME OVER");
			

			

			
			//Imprimir cont de todas las Notas
			if(segs2==0){iprintf("\x1b[07;03H Notas recogidas:");}
			if(segs2==1){iprintf("\x1b[09;03H A:%d",As);}	
			if(segs2==2){iprintf("\x1b[11;03H B:%d",Bs);}			
			if(segs2==3){iprintf("\x1b[13;03H C:%d",Cs);}			
			if(segs2==4){iprintf("\x1b[15;03H F:%d",Fs);}

			if (segs2==6){iprintf("\x1b[20;00H Pulsa 'Start' para ver tu Nota!");}

			if (segs2>5){

				if (TeclaPulsada()==3){segs2=0; LimpiarPantalla(); estado=4;}

			}
		break;

		case 4: //NOTAS

			if ((segs%2)==0){
				MostrarGo1();
				MostrarGo2();
			}
			else {
				MostrarGo3();
				MostrarGo4();

			}

			if (segs2==1){iprintf("\x1b[12;12H 3..");}
			if (segs2==2){iprintf("\x1b[12;12H 2..");}
			if (segs2==3){iprintf("\x1b[12;12H 1..");}	
			if (segs2==4){LimpiarPantalla();}
										
			if (segs2==5){

				iprintf("\x1b[08;03H Has sacado un:...");

			}
				

			if (segs2==6){	
		
				printResult();
	
			}


			if (segs2==8){	iprintf("\x1b[20;02H Pulsa 'ESC' para terminar!");}
			

		
			


		break;

		}//Switch
	}
} 


