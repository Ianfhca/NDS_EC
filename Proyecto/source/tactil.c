/*-------------------------------------
 tactil.c
-------------------------------------*/

// Añadir los includes que sean necesarios
#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h> 

touchPosition pos_pantalla;

// Esta funcion tiene que devolver si la pantalla ha sido pulsada
int  PantallaPulsada() {
	
	int x=0;

	touchRead(&pos_pantalla); 
	if (pos_pantalla.px!=0 && pos_pantalla.py!=0){
	
	 x=1;

	}
	
	return x;

}


// Rutina de atencion a la interrupcion del teclado




