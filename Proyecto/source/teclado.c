/*-------------------------------------
 teclado.c
-------------------------------------*/

// Añadir los includes que sean necesarios
#include <nds.h>
#include <stdio.h>
#include "defines.h"
#include "sprites.h"
#include "fondos.h"
#include "funciones.h"


// Esta funcion tiene que devolver el valor de la tecla pulsada
int  TeclaPulsada() {



	if ((TECLAS_DAT & 0x0001)==0) return 0;
	else if ((TECLAS_DAT & 0x2)==0)return 1;
	else if ((TECLAS_DAT & 0x4)==0)return 2;
	else if ((TECLAS_DAT & 0x8)==0)return 3;
	else if ((TECLAS_DAT & 0x10)==0)return 4;
	else if ((TECLAS_DAT & 0x20)==0)return 5;
	else if ((TECLAS_DAT & 0x40)==0)return 6;
	else if ((TECLAS_DAT & 0x80)==0)return 7;
	else if ((TECLAS_DAT & 0x100)==0)return 8;
	else if ((TECLAS_DAT & 0x200)==0)return 9;
	else return -1;


	

	 
   // Devuelve el valor asociado a la tecla pulsada: 
   // A=0; B=1; Select=2; Start=3; Der=4; Izq=5;
   // Arriba=6; Abajo=7; R=8; L=9;
   // -1 en otros casos

}







// Rutina de atencion a la interrupcion del teclado
void IntTec(){ 
	
	int i=TeclaPulsada();
	
	

	switch(estado){

		case 2:
			
		if (i==0 && canJump==true){inAir=true;canJump=false;}
	
		
		if (i==4){derecha=true;}	
		if (i==5){izquierda=true;}	
		

		break;



	}//switch		
}



