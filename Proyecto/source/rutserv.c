/*-------------------------------------
 rutserv.c
-------------------------------------*/

// Añadir los includes que sean necesarios
#include <nds.h>
#include <stdio.h>
#include "teclado.h"
#include "defines.h"
#include "temporizadores.h"

// Este procedimiento inicializa la tabla de interrupciones para que el gestor de interrupciones sepa
// qué rutina de atención tiene que ejecutar cuando le llega una petición de interrupción. 
// Además es aquí donde se configuran los registros de control de los periféricos.

void HabilitarInterrupciones() { // En el Controlador de Interrupciones

  // Primero se inhiben todas las interrupciones
	IME=0;
  
  // Escribir un 1 en el bit correspondiente 
   
	IE = 0x1018; //IRQ_KEYS (bit 12) y IRQ_TIMER0 (bit 3) y IRQ_TIMER1 (bit 4)

  // Se vuelven a habilitar todas las interrupciones    
 	IME=1;
}


void ProgramarRegistrosControl() { 

  // Registro de Control del Teclado
  
	TECLAS_CNT=0x4039; //bit de activacion (14), teclas A (0), Start (3), Derecha (4), Izquierda (5).

  	TIMER0_CNT=0x00C3;  //1024 ticks por segundo 
	TIMER1_CNT=0x00C3;

  //   El temporizador se activa poniendo un 1 en el 7º bit.
  //   El temporizador interrumpirá al desbordarse el contador, 
  //      si hay un 1 en el 6º bit.
  //   Los dos bits de menos peso indican lo siguiente:
  //      00 frecuencia 33554432 hz
  //      01 frecuencia 33554432/64 hz
  //      10 frecuencia 33554432/256 hz
  //      11 frecuencia 33554432/1024 hz
    
  	TIMER0_DAT=32768; //Cada segundo
	TIMER1_DAT=64444; //30 FPS
  //   Indica a partir de qué valor tiene que empezar a contar (latch)
   
}

void DefinirVectorInterrupciones() { // Rutinas de atención

  // Rutina de Atención al Teclado
	irqSet(IRQ_KEYS,IntTec);
    
  // Rutinas de Atención a los Temporizadores
  	irqSet(IRQ_TIMER0,IntTemp);
	irqSet(IRQ_TIMER1,FPS);
}

void InhibirInterrupciones() { // En el Controlador de Interrupciones

  // Primero se inhiben todas las interrupciones
    
  // Escribir un 0 en el bit correspondiente 
    
  // Se vuelven a habilitar todas las interrupciones
  	
}


void interrupciones()
{
  HabilitarInterrupciones();
  ProgramarRegistrosControl();
  DefinirVectorInterrupciones();
}



