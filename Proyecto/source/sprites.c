/*---------------------------------------------------------------------------------
Este código se ha implementado basándose en el ejemplo "Simple sprite demo" de 
dovoto y otro de Jaeden Amero
---------------------------------------------------------------------------------*/

#include <nds.h>			//librería desarrollada para la nds
#include <stdio.h>			//librería estandar de c que define las funciones estandar de entrada y salida
#include <stdlib.h>			//librería estandar de c para hacer reservas de memoria y conversión de números
#include <unistd.h>			//librería para asegurar la compatibilidad entre sistemas operativos
#include "sprites.h"
#include "defines.h"

u16* gfxF;
u16* gfxCCC;

u16* gfxTopLeft; 
u16* gfxTopRight;
u16* gfxDownLeft;
u16* gfxDownRight;
u16* gfxAAA;
u16* gfxBBB;

/* Inicializar la memoria de Sprites. */
void initSpriteMem() {

	//int i;
	oamInit(&oamMain, SpriteMapping_1D_32, false);
	oamInit(&oamSub, SpriteMapping_1D_32, false);

	gfxF =    oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	
	gfxTopLeft =    oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color); //TopLeft
	gfxTopRight =    oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxDownLeft =    oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxDownRight =    oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxAAA =    oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxCCC =    oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxBBB =    oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
}



/* Dentro de esta función hay que definir el color con el que se mostrará cada uno de los 256 
 * colores posibles en la pantalla principal. El 0 es transparente y los no definidos son negros.
 */
void establecerPaletaPrincipal() {
                                         // 0: TRANSPARENTE
   SPRITE_PALETTE[1]  = RGB15(31,0,0);   // ROJO:           RGB24={FF,00,00} los pixels con valor 1 aparecen en rojo
   SPRITE_PALETTE[2]  = RGB15(31,31,0);  // AMARILLO:       RGB24={FF,FF,00}
   SPRITE_PALETTE[3]  = RGB15(31,31,31); // BLANCO:         RGB24={FF,FF,FF}
   SPRITE_PALETTE[4]  = RGB15(0,31,0);   // VERDE:          RGB24={00,FF,00}
   SPRITE_PALETTE[5]  = RGB15(0,0,31);   // AZUL:           RGB24={00,00,FF}
   SPRITE_PALETTE[6]  = RGB15(0,0,0);    // NEGRO:          RGB24={00,00,00}
   SPRITE_PALETTE[7]  = RGB15(0,31,31);  // CYAN:           RGB24={00,FF,FF}
   SPRITE_PALETTE[8]  = RGB15(31,0,31);  // MAGENTA:        RGB24={FF,00,FF}
   SPRITE_PALETTE[9]  = RGB15(16,16,16); // GRIS:           RGB24={80,80,80}
   SPRITE_PALETTE[10] = RGB15(25,25,25); // GRIS CLARO:     RGB24={D0,D0,D0}
   SPRITE_PALETTE[11] = RGB15(8,8,8);    // GRIS OSCURO:    RGB24={40,40,40}
   SPRITE_PALETTE[12] = RGB15(31,19,0);  // NARANJA:        RGB24={FF,99,00}
   SPRITE_PALETTE[13] = RGB15(19,0,4);   // GRANATE:        RGB24={99,00,21}
   SPRITE_PALETTE[14] = RGB15(25,0,0);   // MARRON:         RGB24={66,00,00}
   SPRITE_PALETTE[15] = RGB15(16,0,16);  // MORADO:         RGB24={80,00,80}
   SPRITE_PALETTE[16] = RGB15(25,19,31); // LILA:           RGB24={CC,99,FF}
   SPRITE_PALETTE[17] = RGB15(31,19,25); // ROSA:           RGB24={FF,99,CC}
   SPRITE_PALETTE[18] = RGB15(23,21,21); // AZUL CLARO:     RGB24={BB,FF,FF}
   SPRITE_PALETTE[19] = RGB15(0,0,16);   // AZUL MARINO:    RGB24={00,00,80}
   SPRITE_PALETTE[20] = RGB15(0,16,16);  // VERDE AZULADO:  RGB24={00,80,80}
   SPRITE_PALETTE[21] = RGB15(0,12,0);   // VERDE OSCURO:   RGB24={00,66,00}
   SPRITE_PALETTE[22] = RGB15(16,16,0);  // VERDE OLIVA:    RGB24={80,80,00}
   SPRITE_PALETTE[23] = RGB15(19,31,19); // VERDE CLARO:    RGB24={99,FF,99}
   SPRITE_PALETTE[24] = RGB15(31,31,19); // AMARILLO CLARO: RGB24={FF,FF,99}
}


/* Dibujado de un Sprite de 16x16 pixels */

/* Debido al funcionamiento de los bancos de memoria, las primeras cuatro filas 
 * forman el cuadrante superior izquiero, las siguientes, el cuadrante superior 
 * derecho, las siguientes el cuadrante inferior izquierdo y las últimas cuatro
 * filas, el cuadrante inferior derecho, como se muestra al lado.
 */

u8 F[256] = 
{



	0, 0, 6, 6, 6, 6, 6, 6, 0, 0, 6, 1, 1, 1, 1, 1, 
	0, 0, 6, 1, 1, 1, 1, 1, 0, 0, 6, 1, 1, 1, 1, 1, 
	0, 0, 6, 1, 1, 13, 13, 13, 0, 0, 6, 1, 1, 13, 6, 6, 
	0, 0, 6, 1, 1, 13, 6, 0, 0, 0, 6, 1, 1, 13, 6, 6, 
	6, 6, 6, 6, 6, 6, 6, 0, 1, 1, 1, 1, 1, 13, 6, 0, 
	1, 1, 1, 1, 1, 13, 6, 0, 1, 1, 1, 1, 1, 13, 6, 0, 
	13, 13, 13, 13, 13, 13, 6, 0, 6, 6, 6, 6, 6, 6, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 0, 0, 0, 0, 
	0, 0, 6, 1, 1, 1, 1, 1, 0, 0, 6, 1, 1, 1, 1, 1, 
	0, 0, 6, 1, 1, 13, 13, 13, 0, 0, 6, 1, 1, 13, 6, 6, 
	0, 0, 6, 1, 1, 13, 6, 0, 0, 0, 6, 1, 1, 13, 6, 0, 
	0, 0, 6, 13, 13, 13, 6, 0, 0, 0, 6, 6, 6, 6, 6, 0, 
	1, 1, 13, 6, 0, 0, 0, 0, 1, 1, 13, 6, 0, 0, 0, 0, 
	13, 13, 13, 6, 0, 0, 0, 0, 6, 6, 6, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
};





u8 TopLeft[256] = //TopLeft
{

0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,
0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,
0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,
0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,
0    ,    0    ,    0    ,    0    ,    15    ,    15    ,    15    ,    15    ,    0    ,    0    ,    0    ,    15    ,    15    ,    6    ,    6    ,    6    ,
0    ,    0    ,    0    ,    15    ,    6    ,    6    ,    6    ,    6    ,    0    ,    0    ,    0    ,    15    ,    6    ,    6    ,    6    ,    6    ,
0    ,    0    ,    15    ,    15    ,    6    ,    6    ,    6    ,    6    ,    0    ,    0    ,    15    ,    15    ,    6    ,    6    ,    6    ,    6    ,
0    ,    0    ,    15    ,    15    ,    6    ,    6    ,    6    ,    6    ,    0    ,    5    ,    5    ,    5    ,    4    ,    6    ,    6    ,    6    ,
0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    4    ,
0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    4    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    4    ,
0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    24    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    24    ,
0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    24    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    24    ,
4    ,    4    ,    5    ,    5    ,    5    ,    4    ,    4    ,    4    ,    4    ,    4    ,    5    ,    5    ,    7    ,    7    ,    7    ,    7    ,
4    ,    4    ,    5    ,    7    ,    7    ,    19    ,    19    ,    19    ,    4    ,    4    ,    7    ,    7    ,    19    ,    19    ,    19    ,    19    ,
4    ,    4    ,    7    ,    19    ,    19    ,    19    ,    19    ,    19    ,    24    ,    7    ,    7    ,    19    ,    19    ,    19    ,    19    ,    5    ,
24    ,    7    ,    19    ,    19    ,    19    ,    5    ,    5    ,    18    ,    24    ,    7    ,    19    ,    19    ,    5    ,    18    ,    18    ,    18    ,





};

u8 TopRight[256] = 
{

15, 15, 15, 15, 0, 0, 0, 0, 6, 6, 6, 15, 15, 0, 0, 0, 
6, 6, 6, 6, 15, 0, 0, 0, 6, 6, 6, 6, 15, 0, 0, 0, 
6, 6, 6, 6, 15, 15, 0, 0, 6, 6, 6, 6, 15, 15, 0, 0, 
6, 6, 6, 6, 15, 15, 0, 0, 6, 6, 6, 4, 5, 5, 5, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
4, 4, 4, 5, 5, 5, 4, 4, 7, 7, 7, 7, 5, 5, 4, 4, 
19, 19, 19, 7, 7, 5, 4, 4, 19, 5, 5, 5, 7, 7, 4, 4, 
5, 18, 18, 18, 5, 7, 4, 4, 18, 18, 18, 18, 18, 5, 7, 24, 
18, 18, 18, 18, 18, 18, 7, 24, 18, 18, 18, 18, 18, 18, 7, 24, 
0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 
4, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 
24, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 
24, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0,
/*
0,0,23,11,11,11,0,0,0,9,3,23,4,11,11,0, // 002311111100002311111100
23,3,3,3,23,4,11,11,11,23,3,3,23,4,11,6, // 0932341111009323411110
11,4,23,23,4,4,11,6,11,11,4,4,4,11,11,0, // 233332341111233332341111
0,11,11,11,11,11,6,0,0,0,11,6,6,11,0,0, // 112333234116112333234116
0,0,23,11,11,11,0,0,0,9,3,23,4,11,11,0, // 114232344116114232344116
23,3,3,3,23,4,11,11,11,23,3,3,23,4,11,6, // 111144411110111144411110
11,4,23,23,4,4,11,6,11,11,4,4,4,11,11,0, // 01111111111600111111111160
0,11,11,11,11,11,6,0,0,0,11,6,6,11,0,0, // 00116611000011661100
6,6,6,0,0,0,0,0,1,1,12,6,6,0,0,0, // 66600000002311111100
1,12,12,2,2,6,0,0,12,12,2,2,4,6,0,0, // 11126600009323411110
12,2,2,2,4,4,6,0,2,2,6,6,6,4,6,0, // 1121222600233332341111
2,6,6,6,6,6,7,6,4,6,6,6,6,6,5,6, // 1212224600112333234116
0,0,23,11,11,11,0,0,0,9,3,23,4,11,11,0, // 122224460114232344116
23,3,3,3,23,4,11,11,11,23,3,3,23,4,11,6, // 22666460111144411110
11,4,23,23,4,4,11,6,11,11,4,4,4,11,11,0, // 266666760111111111160
0,11,11,11,11,11,6,0,0,0,11,6,6,11,0,0, // 466666560011661100
*/
};

u8 DownLeft[256] = 
{

0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 24, 
0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 24, 
0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 24, 
0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 
24, 7, 19, 5, 18, 18, 18, 18, 24, 7, 19, 5, 18, 18, 18, 18, 
24, 7, 5, 18, 18, 18, 18, 18, 24, 7, 5, 18, 18, 18, 18, 18, 
24, 5, 5, 18, 18, 18, 18, 18, 5, 18, 18, 7, 7, 7, 7, 7, 
5, 18, 18, 7, 10, 10, 10, 10, 5, 18, 18, 7, 9, 20, 20, 20, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 5, 18, 7, 20, 20, 20, 20, 0, 0, 5, 5, 7, 20, 20, 20, 
0, 0, 14, 14, 14, 7, 7, 7, 0, 0, 14, 14, 14, 14, 14, 0, 
0, 0, 14, 14, 14, 14, 14, 0, 0, 0, 14, 14, 14, 14, 14, 0, 
0, 0, 6, 6, 6, 6, 6, 0, 0, 0, 6, 6, 6, 6, 6, 0,


/*
0,0,23,11,11,11,0,0,0,9,3,23,4,11,11,0, // 002311111100612666664
23,3,3,3,23,4,11,11,11,23,3,3,23,4,11,6, // 0932341111062266644
11,4,23,23,4,4,11,6,11,11,4,4,4,11,11,0, // 23333234111106244446
0,11,11,11,11,11,6,0,0,0,11,6,6,11,0,0, // 11233323411600647776
6,12,6,6,6,6,6,4,6,2,2,6,6,6,4,4, // 11423234411600067755
0,6,2,4,4,4,4,6,0,0,6,4,7,7,7,6, // 111144411110000655616
0,0,0,6,7,7,5,5,0,0,0,6,5,5,6,16, // 011111111116000061616616
0,0,0,6,16,16,6,16,0,0,0,0,6,6,6,6, // 001166110000006666
0,0,23,11,11,11,0,0,0,9,3,23,4,11,11,0, // 002311111100002311111100
23,3,3,3,23,4,11,11,11,23,3,3,23,4,11,6, // 0932341111009323411110
11,4,23,23,4,4,11,6,11,11,4,4,4,11,11,0, // 233332341111233332341111
0,11,11,11,11,11,6,0,0,0,11,6,6,11,0,0, // 112333234116112333234116
0,0,23,11,11,11,0,0,0,9,3,23,4,11,11,0, // 114232344116114232344116
23,3,3,3,23,4,11,11,11,23,3,3,23,4,11,6, // 111144411110111144411110
11,4,23,23,4,4,11,6,11,11,4,4,4,11,11,0, // 01111111111600111111111160
0,11,11,11,11,11,6,0,0,0,11,6,6,11,0,0, // 00116611000011661100
*/
};

u8 DownRight[256] = 
{

18    ,    18    ,    18    ,    18    ,    18    ,    18    ,    7    ,    24    ,    18    ,    18    ,    18    ,    18    ,    18    ,    18    ,    7    ,    24    ,
18    ,    18    ,    4    ,    3    ,    1    ,    18    ,    7    ,    24    ,    18    ,    18    ,    18    ,    18    ,    18    ,    18    ,    7    ,    24    ,
18    ,    18    ,    18    ,    18    ,    18    ,    5    ,    5    ,    24    ,    7    ,    7    ,    7    ,    7    ,    7    ,    18    ,    18    ,    5    ,
10    ,    10    ,    10    ,    10    ,    7    ,    18    ,    18    ,    5    ,    20    ,    20    ,    20    ,    20    ,    7    ,    18    ,    18    ,    5    ,
24    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    24    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,
24    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    24    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,
24    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    24    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,
24    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,
20    ,    20    ,    20    ,    20    ,    7    ,    18    ,    5    ,    0    ,    20    ,    20    ,    20    ,    7    ,    5    ,    5    ,    0    ,    0    ,
7    ,    7    ,    7    ,    14    ,    14    ,    14    ,    0    ,    0    ,    0    ,    14    ,    14    ,    14    ,    14    ,    14    ,    0    ,    0    ,
0    ,    14    ,    14    ,    14    ,    14    ,    14    ,    0    ,    0    ,    0    ,    14    ,    14    ,    14    ,    14    ,    14    ,    0    ,    0    ,
0    ,    6    ,    6    ,    6    ,    6    ,    6    ,    0    ,    0    ,    0    ,    6    ,    6    ,    6    ,    6    ,    6    ,    0    ,    0    ,
0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,
0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,
0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,
0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,    0    ,
/*
4,6,6,6,6,6,5,6,7,7,6,6,6,16,15,6, // 46666656002311111100
6,5,5,5,16,15,6,0,6,5,16,16,15,6,0,0, // 776661615609323411110
5,16,16,15,6,0,0,0,16,6,15,15,6,0,0,0, // 6555161560233332341111
15,6,15,15,6,0,0,0,6,6,6,6,0,0,0,0, // 65161615600112333234116
0,0,23,11,11,11,0,0,0,9,3,23,4,11,11,0, // 51616156000114232344116
23,3,3,3,23,4,11,11,11,23,3,3,23,4,11,6, // 16615156000111144411110
11,4,23,23,4,4,11,6,11,11,4,4,4,11,11,0, // 156151560000111111111160
0,11,11,11,11,11,6,0,0,0,11,6,6,11,0,0, // 666600000011661100
0,0,23,11,11,11,0,0,0,9,3,23,4,11,11,0, // 002311111100002311111100
23,3,3,3,23,4,11,11,11,23,3,3,23,4,11,6, // 0932341111009323411110
11,4,23,23,4,4,11,6,11,11,4,4,4,11,11,0, // 233332341111233332341111
0,11,11,11,11,11,6,0,0,0,11,6,6,11,0,0, // 112333234116112333234116
0,0,23,11,11,11,0,0,0,9,3,23,4,11,11,0, // 114232344116114232344116
23,3,3,3,23,4,11,11,11,23,3,3,23,4,11,6, // 111144411110111144411110
11,4,23,23,4,4,11,6,11,11,4,4,4,11,11,0, // 01111111111600111111111160
0,11,11,11,11,11,6,0,0,0,11,6,6,11,0,0, // 00116611000011661100

*/
};


u8 AAA[256] = 
{
	

	0, 0, 0, 0, 0, 6, 6, 6, 0, 0, 0, 0, 6, 7, 7, 7, 
	0, 0, 0, 6, 7, 7, 7, 7, 0, 0, 6, 7, 7, 7, 7, 7, 
	0, 0, 6, 7, 7, 5, 5, 5, 0, 0, 6, 7, 7, 5, 6, 6, 
	0, 0, 6, 7, 7, 5, 6, 0, 0, 0, 6, 7, 7, 5, 6, 0, 
	6, 6, 6, 0, 0, 0, 0, 0, 7, 7, 7, 6, 0, 0, 0, 0, 
	7, 7, 7, 7, 6, 0, 0, 0, 7, 7, 7, 7, 7, 6, 0, 0, 
	5, 5, 7, 7, 7, 6, 0, 0, 6, 6, 7, 7, 7, 6, 0, 0, 
	0, 6, 7, 7, 7, 6, 0, 0, 0, 6, 7, 7, 7, 6, 0, 0, 
	0, 0, 6, 7, 7, 5, 6, 6, 0, 0, 6, 7, 7, 7, 7, 7, 
	0, 0, 6, 7, 7, 5, 5, 5, 0, 0, 6, 7, 7, 5, 6, 6, 
	0, 0, 6, 7, 7, 5, 6, 0, 0, 0, 6, 7, 7, 5, 6, 0, 
	0, 0, 6, 5, 5, 5, 6, 0, 0, 0, 6, 6, 6, 6, 6, 0, 
	6, 6, 7, 7, 7, 6, 0, 0, 7, 7, 7, 7, 7, 6, 0, 0, 
	5, 5, 7, 7, 7, 6, 0, 0, 6, 6, 7, 7, 7, 6, 0, 0, 
	0, 6, 7, 7, 7, 6, 0, 0, 0, 6, 7, 7, 7, 6, 0, 0, 
	0, 6, 7, 7, 7, 6, 0, 0, 0, 6, 6, 6, 6, 6, 0, 0,

};

u8 CCC[256] = 
{
	

	0, 0, 0, 0, 6, 6, 6, 6, 0, 0, 0, 6, 6, 12, 12, 12, 
	0, 0, 6, 6, 12, 12, 12, 12, 0, 0, 6, 12, 12, 12, 12, 12, 
	0, 0, 6, 12, 12, 12, 14, 6, 0, 0, 6, 12, 12, 14, 6, 0, 
	0, 0, 6, 12, 12, 14, 6, 0, 0, 0, 6, 12, 12, 14, 6, 0, 
	6, 6, 6, 6, 0, 0, 0, 0, 12, 12, 12, 6, 6, 0, 0, 0, 
	12, 12, 12, 12, 6, 6, 0, 0, 12, 12, 12, 12, 12, 6, 0, 0, 
	6, 12, 12, 12, 12, 6, 0, 0, 0, 6, 12, 12, 12, 6, 0, 0, 
	0, 6, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 6, 12, 12, 14, 6, 0, 0, 0, 6, 12, 12, 14, 6, 0, 
	0, 0, 6, 12, 12, 14, 6, 0, 0, 0, 6, 12, 12, 12, 14, 6, 
	0, 0, 6, 12, 12, 12, 12, 12, 0, 0, 6, 6, 12, 12, 12, 12, 
	0, 0, 0, 6, 6, 14, 14, 14, 0, 0, 0, 0, 6, 6, 6, 6, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6, 6, 6, 0, 0, 
	0, 6, 12, 12, 14, 6, 0, 0, 6, 12, 12, 12, 14, 6, 0, 0, 
	12, 12, 12, 12, 14, 6, 0, 0, 12, 12, 12, 14, 6, 6, 0, 0, 
	14, 14, 14, 6, 6, 0, 0, 0, 6, 6, 6, 6, 0, 0, 0, 0,

};

u8 BBB[256] = 
{
	

	0, 0, 0, 6, 6, 6, 6, 6, 0, 0, 6, 4, 4, 4, 4, 4, 
	0, 0, 6, 4, 4, 4, 4, 4, 0, 0, 6, 4, 4, 23, 6, 6, 
	0, 0, 6, 4, 4, 6, 0, 0, 0, 0, 6, 4, 4, 6, 0, 0, 
	0, 0, 6, 4, 4, 6, 6, 6, 0, 0, 6, 4, 4, 4, 4, 4, 
	6, 6, 6, 6, 0, 0, 0, 0, 4, 4, 4, 4, 6, 0, 0, 0, 
	4, 4, 4, 4, 6, 0, 0, 0, 6, 23, 4, 4, 6, 0, 0, 0, 
	0, 6, 4, 4, 6, 0, 0, 0, 6, 6, 4, 4, 6, 0, 0, 0, 
	6, 4, 4, 6, 6, 0, 0, 0, 4, 4, 6, 6, 0, 0, 0, 0, 
	0, 0, 6, 4, 4, 4, 4, 4, 0, 0, 6, 4, 4, 23, 6, 6, 
	0, 0, 6, 4, 4, 6, 0, 0, 0, 0, 6, 4, 4, 6, 0, 0, 
	0, 0, 6, 4, 4, 6, 6, 6, 0, 0, 6, 4, 4, 4, 4, 4, 
	0, 0, 6, 23, 23, 23, 23, 23, 0, 0, 6, 6, 6, 6, 6, 6, 
	4, 4, 4, 6, 6, 0, 0, 0, 6, 4, 4, 23, 6, 6, 0, 0, 
	6, 6, 4, 4, 23, 6, 0, 0, 0, 6, 4, 4, 23, 6, 0, 0, 
	6, 23, 4, 4, 23, 6, 0, 0, 4, 4, 4, 4, 23, 6, 0, 0, 
	23, 23, 23, 23, 6, 6, 0, 0, 6, 6, 6, 6, 6, 0, 0, 0,

};

/* Dibujado de un Sprite de 32x32 pixels */


/* Para cada Sprite que se quiera llevar a pantalla hay que hacer una de estas funciones. */

void BorrarF(int indice, int x, int y) {

oamSet(&oamMain, //main graphics engine context
	indice,  //oam index (0 to 127)  
	x, y,    //x and y pixle location of the sprite
	0,       //priority, lower renders last (on top)
	0,       //this is the palette index if multiple palettes or the alpha value if bmp sprite	
	SpriteSize_16x16,     
	SpriteColorFormat_256Color, 
	gfxF,//+16*16/2, 	//pointer to the loaded graphics
	-1,                  	//sprite rotation data  
	false,               	//double the size when rotating?
	true,			//hide the sprite?
	false, false, 		//vflip, hflip
	false			//apply mosaic
	); 
oamUpdate(&oamMain); 
}

void MostrarF (int indice, int x, int y){ 
oamSet(&oamMain, //main graphics engine context
	indice,  //oam index (0 to 127)  
	x, y,    //x and y pixle location of the sprite
	0,       //priority, lower renders last (on top)
	0,       //this is the palette index if multiple palettes or the alpha value if bmp sprite	
	SpriteSize_16x16,     
	SpriteColorFormat_256Color, 
	gfxF,//+16*16/2, 	//pointer to the loaded graphics
	-1,                  	//sprite rotation data  
	false,               	//double the size when rotating?
	false,			//hide the sprite?
	false, false, 		//vflip, hflip
	false			//apply mosaic
	); 
oamUpdate(&oamMain);  
}

void BorrarAAA(int indice, int x, int y) {

oamSet(&oamMain, //main graphics engine context
	indice,  //oam index (0 to 127)  
	x, y,    //x and y pixle location of the sprite
	0,       //priority, lower renders last (on top)
	0,       //this is the palette index if multiple palettes or the alpha value if bmp sprite	
	SpriteSize_16x16,     
	SpriteColorFormat_256Color, 
	gfxAAA,//+16*16/2, 	//pointer to the loaded graphics
	-1,                  	//sprite rotation data  
	false,               	//double the size when rotating?
	true,			//hide the sprite?
	false, false, 		//vflip, hflip
	false			//apply mosaic
	); 
oamUpdate(&oamMain); 
}

void MostrarAAA(int indice, int x, int y){ 
oamSet(&oamMain, //main graphics engine context
	indice,  //oam index (0 to 127)  
	x, y,    //x and y pixle location of the sprite
	0,       //priority, lower renders last (on top)
	0,       //this is the palette index if multiple palettes or the alpha value if bmp sprite	
	SpriteSize_16x16,     
	SpriteColorFormat_256Color, 
	gfxAAA,//+16*16/2, 	//pointer to the loaded graphics
	-1,                  	//sprite rotation data  
	false,               	//double the size when rotating?
	false,			//hide the sprite?
	false, false, 		//vflip, hflip
	false			//apply mosaic
	); 
oamUpdate(&oamMain);  
}
void BorrarCCC(int indice, int x, int y) {

oamSet(&oamMain, //main graphics engine context
	indice,  //oam index (0 to 127)  
	x, y,    //x and y pixle location of the sprite
	0,       //priority, lower renders last (on top)
	0,       //this is the palette index if multiple palettes or the alpha value if bmp sprite	
	SpriteSize_16x16,     
	SpriteColorFormat_256Color, 
	gfxCCC,//+16*16/2, 	//pointer to the loaded graphics
	-1,                  	//sprite rotation data  
	false,               	//double the size when rotating?
	true,			//hide the sprite?
	false, false, 		//vflip, hflip
	false			//apply mosaic
	); 
oamUpdate(&oamMain); 
}

void MostrarCCC(int indice, int x, int y){ 
oamSet(&oamMain, //main graphics engine context
	indice,  //oam index (0 to 127)  
	x, y,    //x and y pixle location of the sprite
	0,       //priority, lower renders last (on top)
	0,       //this is the palette index if multiple palettes or the alpha value if bmp sprite	
	SpriteSize_16x16,     
	SpriteColorFormat_256Color, 
	gfxCCC,//+16*16/2, 	//pointer to the loaded graphics
	-1,                  	//sprite rotation data  
	false,               	//double the size when rotating?
	false,			//hide the sprite?
	false, false, 		//vflip, hflip
	false			//apply mosaic
	); 
oamUpdate(&oamMain);  
}

void BorrarBBB(int indice, int x, int y) {

oamSet(&oamMain, //main graphics engine context
	indice,  //oam index (0 to 127)  
	x, y,    //x and y pixle location of the sprite
	0,       //priority, lower renders last (on top)
	0,       //this is the palette index if multiple palettes or the alpha value if bmp sprite	
	SpriteSize_16x16,     
	SpriteColorFormat_256Color, 
	gfxBBB,//+16*16/2, 	//pointer to the loaded graphics
	-1,                  	//sprite rotation data  
	false,               	//double the size when rotating?
	true,			//hide the sprite?
	false, false, 		//vflip, hflip
	false			//apply mosaic
	); 
oamUpdate(&oamMain); 
}

void MostrarBBB(int indice, int x, int y){ 
oamSet(&oamMain, //main graphics engine context
	indice,  //oam index (0 to 127)  
	x, y,    //x and y pixle location of the sprite
	0,       //priority, lower renders last (on top)
	0,       //this is the palette index if multiple palettes or the alpha value if bmp sprite	
	SpriteSize_16x16,     
	SpriteColorFormat_256Color, 
	gfxBBB,//+16*16/2, 	//pointer to the loaded graphics
	-1,                  	//sprite rotation data  
	false,               	//double the size when rotating?
	false,			//hide the sprite?
	false, false, 		//vflip, hflip
	false			//apply mosaic
	); 
oamUpdate(&oamMain);  
}

//TopLeft:!!!

void BorrarTopLeft(int indice, int x, int y) {
oamSet(&oamMain, //main graphics engine context
	indice,  //oam index (0 to 127)  
	x, y,    //x and y pixle location of the sprite
	0,       //priority, lower renders last (on top)
	0,       //this is the palette index if multiple palettes or the alpha value if bmp sprite	
	SpriteSize_16x16,     
	SpriteColorFormat_256Color, 
	gfxTopLeft,//+16*16/2, 	//pointer to the loaded graphics
	-1,                  	//sprite rotation data  
	false,               	//double the size when rotating?
	true,			//hide the sprite?
	false, false, 		//vflip, hflip
	false			//apply mosaic
	); 
oamUpdate(&oamMain); 
}
void MostrarTopLeft (int indice, int x, int y){ 
oamSet(&oamMain, //main graphics engine context
	indice,  //oam index (0 to 127)  
	x, y,    //x and y pixle location of the sprite
	0,       //priority, lower renders last (on top)
	0,       //this is the palette index if multiple palettes or the alpha value if bmp sprite	
	SpriteSize_16x16,     
	SpriteColorFormat_256Color, 
	gfxTopLeft,//+16*16/2, 	//pointer to the loaded graphics
	-1,                  	//sprite rotation data  
	false,               	//double the size when rotating?
	false,			//hide the sprite?
	false, false, 		//vflip, hflip
	false			//apply mosaic
	); 
oamUpdate(&oamMain);  
}

//TopRight!

void BorrarTopRight(int indice, int x, int y) {
oamSet(&oamMain, //main graphics engine context
	indice,  //oam index (0 to 127)  
	x, y,    //x and y pixle location of the sprite
	0,       //priority, lower renders last (on top)
	0,       //this is the palette index if multiple palettes or the alpha value if bmp sprite	
	SpriteSize_16x16,     
	SpriteColorFormat_256Color, 
	gfxTopRight,//+16*16/2, 	//pointer to the loaded graphics
	-1,                  	//sprite rotation data  
	false,               	//double the size when rotating?
	true,			//hide the sprite?
	false, false, 		//vflip, hflip
	false			//apply mosaic
	); 
oamUpdate(&oamMain); 
}
void MostrarTopRight(int indice, int x, int y){ 
oamSet(&oamMain, //main graphics engine context
	indice,  //oam index (0 to 127)  
	x, y,    //x and y pixle location of the sprite
	0,       //priority, lower renders last (on top)
	0,       //this is the palette index if multiple palettes or the alpha value if bmp sprite	
	SpriteSize_16x16,     
	SpriteColorFormat_256Color, 
	gfxTopRight,//+16*16/2, 	//pointer to the loaded graphics
	-1,                  	//sprite rotation data  
	false,               	//double the size when rotating?
	false,			//hide the sprite?
	false, false, 		//vflip, hflip
	false			//apply mosaic
	); 
oamUpdate(&oamMain);  
}

//DownLeft!

void BorrarDownLeft(int indice, int x, int y) {
oamSet(&oamMain, //main graphics engine context
	indice,  //oam index (0 to 127)  
	x, y,    //x and y pixle location of the sprite
	0,       //priority, lower renders last (on top)
	0,       //this is the palette index if multiple palettes or the alpha value if bmp sprite	
	SpriteSize_16x16,     
	SpriteColorFormat_256Color, 
	gfxDownLeft,//+16*16/2, 	//pointer to the loaded graphics
	-1,                  	//sprite rotation data  
	false,               	//double the size when rotating?
	true,			//hide the sprite?
	false, false, 		//vflip, hflip
	false			//apply mosaic
	); 
oamUpdate(&oamMain); 
}
void MostrarDownLeft(int indice, int x, int y){ 
oamSet(&oamMain, //main graphics engine context
	indice,  //oam index (0 to 127)  
	x, y,    //x and y pixle location of the sprite
	0,       //priority, lower renders last (on top)
	0,       //this is the palette index if multiple palettes or the alpha value if bmp sprite	
	SpriteSize_16x16,     
	SpriteColorFormat_256Color, 
	gfxDownLeft,//+16*16/2, 	//pointer to the loaded graphics
	-1,                  	//sprite rotation data  
	false,               	//double the size when rotating?
	false,			//hide the sprite?
	false, false, 		//vflip, hflip
	false			//apply mosaic
	); 
oamUpdate(&oamMain);  
}

//DownRight! 

void BorrarDownRight(int indice, int x, int y) {
oamSet(&oamMain, //main graphics engine context
	indice,  //oam index (0 to 127)  
	x, y,    //x and y pixle location of the sprite
	0,       //priority, lower renders last (on top)
	0,       //this is the palette index if multiple palettes or the alpha value if bmp sprite	
	SpriteSize_16x16,     
	SpriteColorFormat_256Color, 
	gfxDownRight,//+16*16/2, 	//pointer to the loaded graphics
	-1,                  	//sprite rotation data  
	false,               	//double the size when rotating?
	true,			//hide the sprite?
	false, false, 		//vflip, hflip
	false			//apply mosaic
	); 
oamUpdate(&oamMain); 
}



void MostrarDownRight(int indice, int x, int y){ 
oamSet(&oamMain, //main graphics engine context
	indice,  //oam index (0 to 127)  
	x, y,    //x and y pixle location of the sprite
	0,       //priority, lower renders last (on top)
	0,       //this is the palette index if multiple palettes or the alpha value if bmp sprite	
	SpriteSize_16x16,     
	SpriteColorFormat_256Color, 
	gfxDownRight,//+16*16/2, 	//pointer to the loaded graphics
	-1,                  	//sprite rotation data  
	false,               	//double the size when rotating?
	false,			//hide the sprite?
	false, false, 		//vflip, hflip
	false			//apply mosaic
	); 
oamUpdate(&oamMain);  
}

void MostrarSprite(int indice, int x, int y){ 
	MostrarTopLeft(indice    ,x   ,y);  
	MostrarTopRight(indice+1 ,x+16,y); 
	MostrarDownLeft(indice+2 ,x   ,y+16);  
	MostrarDownRight(indice+3,x+16,y+16);  
}

void BorrarSprite(int indice, int x, int y){ 
	BorrarTopLeft(indice    ,x,y);  
	BorrarTopRight(indice+1 ,x+16,y); 
	BorrarDownLeft(indice+2 ,x   ,y+16);  
	BorrarDownRight(indice+3,x+16,y+16);  
}

 
void guardarSpritesEnMemoria(){ 
	
int i;
	//para sprites de 16*16
	for(i = 0; i < 16 * 16 / 2; i++) 
	{	
		gfxTopLeft[i] = TopLeft[i*2] | (TopLeft[(i*2)+1]<<8);	
		gfxF[i] = F[i*2] | (F[(i*2)+1]<<8);
		gfxAAA[i] = AAA[i*2] | (AAA[(i*2)+1]<<8);
		gfxCCC[i] = CCC[i*2] | (CCC[(i*2)+1]<<8);
		gfxBBB[i] = BBB[i*2] | (BBB[(i*2)+1]<<8);
		gfxTopRight[i] = TopRight[i*2] | (TopRight[(i*2)+1]<<8);	
		gfxDownLeft[i] = DownLeft[i*2] | (DownLeft[(i*2)+1]<<8);					
		gfxDownRight[i] = DownRight[i*2] | (DownRight[(i*2)+1]<<8);									
	}

}



