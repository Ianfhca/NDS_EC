/*---------------------------------------------------------------------------------
Este código se ha implementado basándose en el ejemplo "Simple sprite demo" de 
dovoto y otro de Jaeden Amero
---------------------------------------------------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "fondos.h"

/* añadir aquí los includes para cada fondo. */

#include "fondos.h"
#include "Puerta.h"
#include "PuertaAbierta.h"
#include "Background.h"
#include "Classroom.h"
#include "Classroom2.h"
#include "go1.h"
#include "go2.h"
#include "go3.h"
#include "go4.h"
#include "Anim1.h"
#include "Anim2.h"
#include "Anim3.h"
#include "Anim4.h"

/* Seleccionar un canal DMA para copiar a memoria las imágenes */
static const int DMA_CHANNEL = 3;

/* Procedimiento para configurar el sistema de fondos. */
void initFondos() {
    /*  Establecer la afinidad del fondo 3 de la pantalla principal con color de 16 bits. */
    REG_BG3CNT = BG_BMP16_256x256 |
                 BG_BMP_BASE(0) | // La dirección inicial de memoria
                 BG_PRIORITY(3); // Baja prioridad

    /*  Establecer la matriz de transformación afin del fondo 3 de la pantalla principal
        a la matriz de identidad. */
    REG_BG3PA = 1 << 8;
    REG_BG3PB = 0;
    REG_BG3PC = 0;
    REG_BG3PD = 1 << 8;

/*******************************************************************************************/
    /*  Definir la situación del fondo 3 de la pantalla principal. */
    /*  Esto deberá cambiar según la posición en la que se quiera poner el gráfico */
    REG_BG3X = 0;
    REG_BG3Y = 0;
/*******************************************************************************************/

    /*  Establecer la afinidad del fondo 2 de la pantalla principal con color de 16 bits. */
    REG_BG2CNT = BG_BMP16_128x128 |
                 BG_BMP_BASE(8) | // La dirección inicial de memoria
                 BG_PRIORITY(2);  // Baja prioridad

    /*  Establecer la matriz de transformación afin del fondo 2 de la pantalla principal 
        a la matriz de identidad. */
    REG_BG2PA = 1 << 8;
    REG_BG2PB = 0;
    REG_BG2PC = 0;
    REG_BG2PD = 1 << 8;

/*******************************************************************************************/
    /*  Definir la situación del fondo 2 de la pantalla principal. */
    /*  Esto deberá cambiar según la posición en la que se quiera poner el gráfico */
    REG_BG2X = -(SCREEN_WIDTH / 2 - 32) << 8;
    REG_BG2Y = -32 << 8;
/*******************************************************************************************/

    /*  Establecer la afinidad del fondo 3 de la pantalla secundaria con color de 16 bits. */
    REG_BG3CNT_SUB = BG_BMP16_256x256 |
                     BG_BMP_BASE(0) | // La dirección inicial de memoria
                     BG_PRIORITY(3); // Baja prioridad

    /*  Establecer la matriz de transformación afin del fondo 3 de la pantalla secundaria
        a la matriz de identidad. */
    REG_BG3PA_SUB = 1 << 8;
    REG_BG3PB_SUB = 0;
    REG_BG3PC_SUB = 0;
    REG_BG3PD_SUB = 1 << 8;

/*******************************************************************************************/
    /*  Definir la situación del fondo 3 de la pantalla secundaria. */
    /*  Esto deberá cambiar según la posición en la que se quiera poner el gráfico */
    REG_BG3X_SUB = 0;
    REG_BG3Y_SUB = 0;
/*******************************************************************************************/
}

/* Para cada imagen que se quiera llevar a pantalla hay que hacer una de estas funciones. */

void MostrarPuerta() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     PuertaBitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */
                     PuertaBitmapLen); /* Longitud (en bytes) generada automáticamente */
}
void MostrarPuertaAbierta() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     PuertaAbiertaBitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */
                     PuertaAbiertaBitmapLen); /* Longitud (en bytes) generada automáticamente */
}
void MostrarBackground() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     BackgroundBitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */

                     BackgroundBitmapLen); /* Longitud (en bytes) generada automáticamente */
}
void MostrarClassroom() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     ClassroomBitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */

                     ClassroomBitmapLen); /* Longitud (en bytes) generada automáticamente */
}
void MostrarClassroom2() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     Classroom2Bitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */

                     Classroom2BitmapLen); /* Longitud (en bytes) generada automáticamente */
}
void MostrarGo1() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     go1Bitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */

                     go1BitmapLen); /* Longitud (en bytes) generada automáticamente */
}
void MostrarGo2() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     go2Bitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */

                     go2BitmapLen); /* Longitud (en bytes) generada automáticamente */
}
void MostrarGo3() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     go3Bitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */

                     go3BitmapLen); /* Longitud (en bytes) generada automáticamente */
}
void MostrarGo4() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     go4Bitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */

                     go4BitmapLen); /* Longitud (en bytes) generada automáticamente */
}
void MostrarAnim1() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     Anim1Bitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */

                     Anim1BitmapLen); /* Longitud (en bytes) generada automáticamente */
}
void MostrarAnim2() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     Anim2Bitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */

                     Anim2BitmapLen); /* Longitud (en bytes) generada automáticamente */
}
void MostrarAnim3() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     Anim3Bitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */

                     Anim3BitmapLen); /* Longitud (en bytes) generada automáticamente */
}
void MostrarAnim4() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     Anim4Bitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */

                     Anim4BitmapLen); /* Longitud (en bytes) generada automáticamente */
}
