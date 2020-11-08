/*-------------------------------------
 funciones.c
-------------------------------------*/

// Añadir los includes que sean necesarios
#include <nds.h>
#include <stdio.h>
#include "defines.h"
#include "sprites.h"
#include "fondos.h"
#include "temporizadores.h"

//Imprimir Resultado:

void printResult(){

 	double resultado=((0+(As*5)+(Bs*3)+(Cs*2)-(Fs*5)));	//ContA*5+ContB*3+ContC*2+ContD-ContF*6;


	if (resultado>20){iprintf("\x1b[12;03H SUPER SOBRESALIENTE!!!");}
	else if (resultado>15){iprintf("\x1b[12;03H SOBRESALIENTE!!");}
	else if (resultado>10){iprintf("\x1b[12;03H NOTABLE!");}
	else if (resultado>5){iprintf("\x1b[12;03H Cero bien redondo!");}
	else if (resultado>-5){iprintf("\x1b[12;01H Suspenso bastante hardcore!");}
	else if (resultado<=-5){iprintf("\x1b[12;01H Suspenso que da verguenza!");}
				
				


}

//Obtener HitBox:

bool getHitBox(double a, double b){


	double i;
	bool si=false;
	//int A[14]

	if (a<=x+25 && a>=x+2){

		if(b>=y && b<=y+20){

		si=true;
		}
	}

	return si;

}


//Limpiar Pantalla:

void LimpiarPantalla(){

	printf("\e[1;1H\e[2J"); 
	
}

//MOVIMIENTO:

void MovDerecha(){
	
	if (x<233){

		
		x=x+3;
		MostrarSprite(30,x,y);
		

		}

}

void MovIzquierda(){
	if (x>0){
		x=x-3;
		MostrarSprite(30,x,y);
	}

}



void Jump(){
		
	y=y-4.0;
	MostrarSprite(30,x,y);
	if (y==ground-distance){
	inAir=false;}

	
}
void Fall(){
	y=y+3.0;
	MostrarSprite(30,x,y);
	if(y==ground){inAir=true;canJump=true;}
	
}







