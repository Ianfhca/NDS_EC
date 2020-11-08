extern u16* gfxBola;
extern u16* gfxRaqueta;

/* Inicializar la memoria de Sprites. */
extern void initSpriteMem();

/* Dentro de esta función hay que definir el color con el que se mostrará cada uno de los 256 
 * colores posibles en la pantalla principal. El 0 es transparente y los no definidos son negros.
 */
extern void establecerPaletaPrincipal();

/* Dentro de esta función hay que definir el color con el que se mostrará cada uno de los 256 
 * colores posibles en la pantalla secundaria. El 0 es transparente y los no definidos son negros.
 */
extern void establecerPaletaSecundaria();

/* Para guardar los sprites en memoria y luego poder usarlos. */

extern void guardarSpritesEnMemoria();

/* Funciones específicas para manejar los sprites. */

extern void MostrarF(int indice, int x, int y);
extern void BorrarF(int indice, int x, int y);

extern void MostrarAAA(int indice, int x, int y);
extern void BorrarAAA(int indice, int x, int y);

extern void MostrarCCC(int indice, int x, int y);
extern void BorrarCCC(int indice, int x, int y);

extern void MostrarBBB(int indice, int x, int y);
extern void BorrarBBB(int indice, int x, int y);

extern void MostrarSprite(int indice, int x, int y);
extern void BorrarSprite(int indice, int x, int y);

/*
//TopLeft
extern void MostrarRombo(int indice, int x, int y);
extern void BorrarRombo(int indice, int x, int y);
//TopRight
extern void MostrarTopRight(int indice, int x, int y);
extern void BorrarTopRight(int indice, int x, int y);
//DownLeft
extern void MostrarDownLeft(int indice, int x, int y);
extern void BorrarDownLeft(int indice, int x, int y);
//DownRight
extern void MostrarDownRight(int indice, int x, int y);
extern void BorrarDownRight(int indice, int x, int y);
*/



