/*-------------------------------------
 temporizadores.c
-------------------------------------*/
// Añadir los includes que sean necesarios
#include "defines.h"
#include "sprites.h"
#include <nds.h>
#include <stdio.h>
#include "funciones.h"

	time_t t;
	//F
	double xRombo1,xRombo2,xRombo3,xRombo4,xRombo5,xRombo6,xRombo7,xRombo8,xRombo9,xRombo10;
	double yRombo1;
	double yRombo2;
	double yRombo3;
	double yRombo4;
	double yRombo5;
	double yRombo6;
	double yRombo7;
	double yRombo8;
	double yRombo9;
	double yRombo10;
	bool aux= false;
	bool r1=false;
	bool r2=false;
	bool r3=false;
	bool r4=false;
	bool r5=false;
	bool r6=false;
	bool r7=false;
	bool r8=false;
	bool r9=false;
	bool r10=false;
   	double auxi;

	//A

	double xARombo1,xARombo2,xARombo3,xARombo4,xARombo5;
	double yARombo1;
	double yARombo2;
	double yARombo3;
	double yARombo4;
	double yARombo5;
	
	bool rA1=false;
	bool rA2=false;
	bool rA3=false;
	bool rA4=false;
	bool rA5=false;

	//C

	double xCRombo1,xCRombo2,xCRombo3,xCRombo4,xCRombo5;
	double yCRombo1;
	double yCRombo2;
	double yCRombo3;
	double yCRombo4;
	double yCRombo5;
	
	bool rC1=false;
	bool rC2=false;
	bool rC3=false;
	bool rC4=false;
	bool rC5=false;

	//B

	double xBRombo1,xBRombo2,xBRombo3,xBRombo4,xBRombo5;
	double yBRombo1;
	double yBRombo2;
	double yBRombo3;
	double yBRombo4;
	double yBRombo5;
	
	bool rB1=false;
	bool rB2=false;
	bool rB3=false;
	bool rB4=false;
	bool rB5=false;





// Rutina de atención a la interrupción del temporizador
void IntTemp() {

	segs++;
	segs2++;
	
	
	
	
	//CAER NOTAS:

	if (notasCaer==true ){ 

	
			srand((unsigned) time(&t));


			//F


			if(r1==false){xRombo1 = (rand()%238);yRombo1 = 0.0;r1=true;}

	
	
			if(r2==false && segs%2==0){

				auxi = (rand()%238);

				if (auxi>=xRombo1+15.0 || auxi<=xRombo1-15.0){xRombo2 = auxi; 	yRombo2 = 0.0;r2=true;}
				else{xRombo2=0.0;}
			}



			if(r3==false && segs%3==0){

				auxi = (rand()%238);

				if (auxi>=xRombo2+15.0 || auxi<=xRombo2-15.0){xRombo3 = auxi; yRombo3 = 0.0; r3=true;}
				else{xRombo3=0.0;}

			}


			if(r4==false && segs%4==0){

				auxi = (rand()%238);

				if (auxi>=xRombo3+15.0 || auxi<=xRombo3-15.0){xRombo4 = auxi; yRombo4 = 0.0; r4=true;}
				else{xRombo4=0.0;}

			}


			if(r5==false && segs%5==0){

				auxi = (rand()%238);

				if (auxi>=xRombo4+15.0 || auxi<=xRombo4-15.0){xRombo5 = auxi; yRombo5 = 0.0; r5=true;}
				else{xRombo5=0.0;}

			}
			if(r6==false && segs%6==0){

				auxi = (rand()%238);

				if (auxi>=xRombo5+15.0 || auxi<=xRombo5-15.0){xRombo6 = auxi; yRombo6 = 0.0; r6=true;}
				else{xRombo6=0.0;}

			}
			if(r7==false && segs%7==0){

				auxi = (rand()%238);

				if (auxi>=xRombo6+15.0 || auxi<=xRombo6-15.0){xRombo7 = auxi; yRombo7 = 0.0; r7=true;}
				else{xRombo7=0.0;}

			}
			if(r8==false && segs%8==0){

				auxi = (rand()%238);

				if (auxi>=xRombo7+15.0 || auxi<=xRombo7-15.0){xRombo8 = auxi; yRombo8 = 0.0; r8=true;}
				else{xRombo8=0.0;}

			}
			if(r9==false && segs%9==0){

				auxi = (rand()%238);

				if (auxi>=xRombo8+15.0 || auxi<=xRombo8-15.0){xRombo9 = auxi; yRombo9 = 0.0; r9=true;}
				else{xRombo9=0.0;}

			}
			if(r10==false && segs%10==0){

				auxi = (rand()%238);

				if (auxi>=xRombo9+15.0 || auxi<=xRombo9-15.0){xRombo10 = auxi; yRombo10 = 0.0; r10=true;}
				else{xRombo10=0.0;}

			}

	

			//A

			if(rA1==false){xARombo1 = (rand()%238);yARombo1 = 0.0;rA1=true;}

	
	
			if(rA2==false && segs%6==0){

				auxi = (rand()%238);

				if (auxi>=xARombo1+15.0 || auxi<=xARombo1-15.0){xARombo2 = auxi; 	yARombo2 = 0.0;rA2=true;}
				else{xARombo2=0.0;}
			}



			if(rA3==false && segs%7==0){

				auxi = (rand()%238);

				if (auxi>=xARombo2+15.0 || auxi<=xARombo2-15.0){xARombo3 = auxi; yARombo3 = 0.0; rA3=true;}
				else{xARombo3=0.0;}

			}


			if(rA4==false && segs%8==0){

				auxi = (rand()%238);

				if (auxi>=xARombo3+15.0 || auxi<=xARombo3-15.0){xARombo4 = auxi; yARombo4 = 0.0; rA4=true;}
				else{xARombo4=0.0;}

			}


			if(rA5==false && segs%9==0){

				auxi = (rand()%238);

				if (auxi>=xARombo4+15.0 || auxi<=xARombo4-15.0){xARombo5 = auxi; yARombo5 = 0.0; rA5=true;}
				else{xARombo5=0.0;}

			}

			//C

			if(rC1==false){xCRombo1 = (rand()%238);yCRombo1 = 0.0;rC1=true;}

	
	
			if(rC2==false && segs%2==0){

				auxi = (rand()%238);

				if (auxi>=xCRombo1+15.0 || auxi<=xCRombo1-15.0){xCRombo2 = auxi; 	yCRombo2 = 0.0;rC2=true;}
				else{xCRombo2=0.0;}
			}



			if(rC3==false && segs%3==0){

				auxi = (rand()%238);

				if (auxi>=xCRombo2+15.0 || auxi<=xCRombo2-15.0){xCRombo3 = auxi; yCRombo3 = 0.0; rC3=true;}
				else{xCRombo3=0.0;}

			}


			if(rC4==false && segs%4==0){

				auxi = (rand()%238);

				if (auxi>=xCRombo3+15.0 || auxi<=xCRombo3-15.0){xCRombo4 = auxi; yCRombo4 = 0.0; rC4=true;}
				else{xCRombo4=0.0;}

			}


			if(rC5==false && segs%5==0){

				auxi = (rand()%238);

				if (auxi>=xCRombo4+15.0 || auxi<=xCRombo4-15.0){xCRombo5 = auxi; yCRombo5 = 0.0; rC5=true;}
				else{xCRombo5=0.0;}

			}
			//B

			if(rB1==false){xBRombo1 = (rand()%238);yBRombo1 = 0.0;rB1=true;}

	
	
			if(rB2==false && segs%2==0){

				auxi = (rand()%238);

				if (auxi>=xBRombo1+15.0 || auxi<=xBRombo1-15.0){xBRombo2 = auxi; 	yBRombo2 = 0.0;rB2=true;}
				else{xBRombo2=0.0;}
			}



			if(rB3==false && segs%3==0){

				auxi = (rand()%238);

				if (auxi>=xBRombo2+15.0 || auxi<=xBRombo2-15.0){xBRombo3 = auxi; yBRombo3 = 0.0; rB3=true;}
				else{xBRombo3=0.0;}

			}


			if(rB4==false && segs%4==0){

				auxi = (rand()%238);

				if (auxi>=xBRombo3+15.0 || auxi<=xBRombo3-15.0){xBRombo4 = auxi; yBRombo4 = 0.0; rB4=true;}
				else{xBRombo4=0.0;}

			}


			if(rB5==false && segs%5==0){

				auxi = (rand()%238);

				if (auxi>=xBRombo4+15.0 || auxi<=xBRombo4-15.0){xBRombo5 = auxi; yBRombo5 = 0.0; rB5=true;}
				else{xBRombo5=0.0;}

			}
	
			aux=true;
	
		}//CAER NOTAS
	
}	


void FPS(){


	if(segs3<70){

		segs3++;
		if (segs3==70){
			segs3=0;
		}
	}
	

	
	//MOVIMIENTO:

	// Derecha:
	if (estado==2 && derecha==true){
		
		
		MovDerecha();

		if (TeclaPulsada()==0 && canJump==true){
			
			
			canJump=false;
			inAir=true;
			
		}
		
		if (TeclaPulsada()==0){derecha=true;}
		else if (TeclaPulsada()==4){derecha=true;}
		else {derecha=false;}
		
	}


	//Izquierda:
	if (estado==2 && izquierda==true){
		
		
		MovIzquierda();

		if (TeclaPulsada()==0 && canJump==true){
			
			
			canJump=false;
			inAir=true;
			
		}
		
		
		if (TeclaPulsada()==0){izquierda=true;}
		else if (TeclaPulsada()==5){izquierda=true;}
		else {izquierda=false;}
		
	}
	
	
	//Jump:
	if (estado==2 && canJump==false){
		
		if(inAir==true){

			Jump();

		}
		if(inAir==false){

			Fall();

		}
	}


	//CAER NOTAS:

	if (estado==2 && aux==true && notasCaer==true){
	
	//F
	if (yRombo1!=0.1 && r1==true){MostrarF(5, xRombo1,yRombo1);yRombo1=yRombo1+0.5;}
	if (yRombo2!=0.1 && r2==true){MostrarF(6, xRombo2,yRombo2);yRombo2=yRombo2+0.5;}
	if (yRombo3!=0.1 && r3==true){MostrarF(7, xRombo3,yRombo3);yRombo3=yRombo3+0.5;}
	if (yRombo4!=0.1 && r4==true){MostrarF(8, xRombo4,yRombo4);yRombo4=yRombo4+0.5;}
	if (yRombo5!=0.1 && r5==true){MostrarF(9, xRombo5,yRombo5);yRombo5=yRombo5+0.5;}
	if (yRombo6!=0.1 && r6==true){MostrarF(25, xRombo6,yRombo6);yRombo6=yRombo6+0.5;}
	if (yRombo7!=0.1 && r7==true){MostrarF(26, xRombo7,yRombo7);yRombo7=yRombo7+0.5;}
	if (yRombo8!=0.1 && r8==true){MostrarF(27, xRombo8,yRombo8);yRombo8=yRombo8+0.5;}
	if (yRombo9!=0.1 && r9==true){MostrarF(28, xRombo9,yRombo9);yRombo9=yRombo9+0.5;}
	if (yRombo10!=0.1 && r10==true){MostrarF(29, xRombo10,yRombo10);yRombo10=yRombo10+0.5;}

	//A
	if (yARombo1!=0.1 && rA1==true){MostrarAAA(10, xARombo1,yARombo1);yARombo1=yARombo1+0.5;}
	if (yARombo2!=0.1 && rA2==true){MostrarAAA(11, xARombo2,yARombo2);yARombo2=yARombo2+0.5;}
	if (yARombo3!=0.1 && rA3==true){MostrarAAA(12, xARombo3,yARombo3);yARombo3=yARombo3+0.5;}
	if (yARombo4!=0.1 && rA4==true){MostrarAAA(13, xARombo4,yARombo4);yARombo4=yARombo4+0.5;}
	if (yARombo5!=0.1 && rA5==true){MostrarAAA(14, xARombo5,yARombo5);yARombo5=yARombo5+0.5;}

	//C
	if (yCRombo1!=0.1 && rC1==true){MostrarCCC(15, xCRombo1,yCRombo1);yCRombo1=yCRombo1+0.5;}
	if (yCRombo2!=0.1 && rC2==true){MostrarCCC(16, xCRombo2,yCRombo2);yCRombo2=yCRombo2+0.5;}
	if (yCRombo3!=0.1 && rC3==true){MostrarCCC(17, xCRombo3,yCRombo3);yCRombo3=yCRombo3+0.5;}

	if (yCRombo4!=0.1 && rC4==true){MostrarCCC(18, xCRombo4,yCRombo4);yCRombo4=yCRombo4+0.5;}
	if (yCRombo5!=0.1 && rC5==true){MostrarCCC(19, xCRombo5,yCRombo5);yCRombo5=yCRombo5+0.5;}

	//B
	if (yBRombo1!=0.1 && rB1==true){MostrarBBB(20, xBRombo1,yBRombo1);yBRombo1=yBRombo1+0.5;}
	if (yBRombo2!=0.1 && rB2==true){MostrarBBB(21, xBRombo2,yBRombo2);yBRombo2=yBRombo2+0.5;}
	if (yBRombo3!=0.1 && rB3==true){MostrarBBB(22, xBRombo3,yBRombo3);yBRombo3=yBRombo3+0.5;}
	if (yBRombo4!=0.1 && rB4==true){MostrarBBB(23, xBRombo4,yBRombo4);yBRombo4=yBRombo4+0.5;}
	if (yBRombo5!=0.1 && rB5==true){MostrarBBB(24, xBRombo5,yBRombo5);yBRombo5=yBRombo5+0.5;}


		

		
	
		//BORRAR:

		//F
		if(yRombo1==190.0){
		BorrarF(5, xRombo1,yRombo1);
		yRombo1=0.1;
		r1=false;
				
		}
		if(yRombo2==190.0){
		BorrarF(6, xRombo2,yRombo2);
		yRombo2=0.1;
		r2=false;
		
		}
		if(yRombo3==190.0){
		BorrarF(7, xRombo3,yRombo3);
		yRombo3=0.1;
		r3=false;
		
		}
		if(yRombo4==190.0){
		BorrarF(8, xRombo4,yRombo4);
		yRombo4=0.1;
		r4=false;
		
		}
		if(yRombo5==190.0){
		BorrarF(9, xRombo5,yRombo5);
		yRombo5=0.1;
		r5=false;
		
		}

		if(yRombo6==190.0){
		BorrarF(25, xRombo6,yRombo6);
		yRombo6=0.1;
		r6=false;
				
		}
		if(yRombo7==190.0){
		BorrarF(26, xRombo7,yRombo7);
		yRombo7=0.1;
		r7=false;
		
		}
		if(yRombo8==190.0){
		BorrarF(27, xRombo8,yRombo8);
		yRombo8=0.1;
		r3=false;
		
		}
		if(yRombo9==190.0){
		BorrarF(28, xRombo9,yRombo9);
		yRombo9=0.1;
		r9=false;
		
		}
		if(yRombo10==190.0){
		BorrarF(29, xRombo10,yRombo10);
		yRombo10=0.1;
		r10=false;
		
		}

		//A
		if(yARombo1==190.0){
		BorrarAAA(10, xARombo1,yARombo1);
		yARombo1=0.1;
		rA1=false;
				
		}
		if(yARombo2==190.0){
		BorrarAAA(11, xARombo2,yARombo2);
		yARombo2=0.1;
		rA2=false;
		
		}
		if(yARombo3==190.0){
		BorrarAAA(12, xARombo3,yARombo3);
		yARombo3=0.1;
		rA3=false;
		
		}
		if(yARombo4==190.0){
		BorrarAAA(13, xARombo4,yARombo4);
		yARombo4=0.1;
		rA4=false;
		
		}
		if(yARombo5==190.0){
		BorrarAAA(14, xARombo5,yARombo5);
		yARombo5=0.1;
		rA5=false;
		
		}

		//C
		if(yCRombo1==190.0){
		BorrarCCC(15, xCRombo1,yCRombo1);
		yCRombo1=0.1;
		rC1=false;
				
		}
		if(yCRombo2==190.0){
		BorrarCCC(16, xCRombo2,yCRombo2);
		yCRombo2=0.1;
		rC2=false;
		
		}
		if(yCRombo3==190.0){
		BorrarCCC(17, xCRombo3,yCRombo3);
		yCRombo3=0.1;
		rC3=false;
		
		}
		if(yCRombo4==190.0){
		BorrarCCC(18, xCRombo4,yCRombo4);
		yCRombo4=0.1;
		rC4=false;
		
		}
		if(yCRombo5==190.0){
		BorrarCCC(19, xCRombo5,yCRombo5);
		yCRombo5=0.1;
		rC5=false;
		
		}

		//B
		if(yBRombo1==190.0){
		BorrarBBB(20, xBRombo1,yBRombo1);
		yBRombo1=0.1;
		rB1=false;
				
		}
		if(yBRombo2==190.0){
		BorrarBBB(21, xBRombo2,yBRombo2);
		yBRombo2=0.1;
		rB2=false;
		
		}
		if(yBRombo3==190.0){
		BorrarBBB(22, xBRombo3,yBRombo3);
		yBRombo3=0.1;
		rB3=false;
		
		}
		if(yBRombo4==190.0){
		BorrarBBB(23, xBRombo4,yBRombo4);
		yBRombo4=0.1;
		rB4=false;
		
		}
		if(yBRombo5==190.0){
		BorrarBBB(24, xBRombo5,yBRombo5);
		yBRombo5=0.1;
		rB5=false;
		
		}


		//Tocar Notas

		//F
		
		if(getHitBox(xRombo1, yRombo1) && r1==true){
		BorrarF(5, xRombo1,yRombo1);
		Fs++;
		yRombo1=0.1;
		r1=false;
				
		}
		if(getHitBox(xRombo2, yRombo2)&& r2==true){
		BorrarF(6, xRombo2,yRombo2);
		Fs++;
		yRombo2=0.1;
		r2=false;
				
		}
		if(getHitBox(xRombo3, yRombo3)&& r3==true){
		BorrarF(7, xRombo3,yRombo3);
		Fs++;
		yRombo3=0.1;
		r3=false;
				
		}
		if(getHitBox(xRombo4, yRombo4)&& r4==true){
		BorrarF(8, xRombo4,yRombo4);
		Fs++;
		yRombo4=0.1;
		r4=false;
				
		}
		if(getHitBox(xRombo5,yRombo5)&& r5==true){
		BorrarF(9, xRombo5,yRombo5);
		Fs++;
		yRombo5=0.1;
		r5=false;
				
		}
		if(getHitBox(xRombo6, yRombo6) && r6==true){
		BorrarF(25, xRombo6,yRombo6);
		Fs++;
		yRombo6=0.1;
		r6=false;
				
		}
		if(getHitBox(xRombo7, yRombo7)&& r7==true){
		BorrarF(26, xRombo7,yRombo7);
		Fs++;
		yRombo7=0.1;
		r7=false;
				
		}
		if(getHitBox(xRombo8, yRombo8)&& r8==true){
		BorrarF(2, xRombo8,yRombo8);
		Fs++;
		yRombo8=0.1;
		r8=false;
				
		}
		if(getHitBox(xRombo9, yRombo9)&& r9==true){
		BorrarF(28, xRombo9,yRombo9);
		Fs++;
		yRombo9=0.1;
		r9=false;
				
		}
		if(getHitBox(xRombo10,yRombo10)&& r10==true){
		BorrarF(29, xRombo10,yRombo10);
		Fs++;
		yRombo10=0.1;
		r10=false;
				
		}

		//A
		if(getHitBox(xARombo1, yARombo1) && rA1==true){
		BorrarAAA(10, xARombo1,yARombo1);
		As++;
		yARombo1=0.1;
		rA1=false;
				
		}
		if(getHitBox(xARombo2, yARombo2)&& rA2==true){
		BorrarAAA(11, xARombo2,yARombo2);
		As++;
		yARombo2=0.1;
		rA2=false;
				
		}
		if(getHitBox(xARombo3, yARombo3)&& rA3==true){
		BorrarAAA(12, xARombo3,yARombo3);
		As++;
		yARombo3=0.1;
		rA3=false;
				
		}
		if(getHitBox(xARombo4, yARombo4)&& rA4==true){
		BorrarAAA(13, xARombo4,yARombo4);
		As++;
		yARombo4=0.1;
		rA4=false;
				
		}
		if(getHitBox(xARombo5,yARombo5)&& rA5==true){
		BorrarAAA(14, xARombo5,yARombo5);
		As++;
		yARombo5=0.1;
		rA5=false;
				
		}

		//C
		if(getHitBox(xCRombo1, yCRombo1) && rC1==true){
		BorrarCCC(15, xCRombo1,yCRombo1);
		Cs++;
		yCRombo1=0.1;
		rC1=false;
				
		}
		if(getHitBox(xCRombo2, yCRombo2)&& rC2==true){
		BorrarCCC(16, xCRombo2,yCRombo2);
		Cs++;
		yCRombo2=0.1;
		rC2=false;
				
		}
		if(getHitBox(xCRombo3, yCRombo3)&& rC3==true){
		BorrarCCC(17, xCRombo3,yCRombo3);
		Cs++;
		yCRombo3=0.1;
		rC3=false;
				
		}
		if(getHitBox(xCRombo4, yCRombo4)&& rC4==true){
		BorrarCCC(18, xCRombo4,yCRombo4);
		Cs++;
		yCRombo4=0.1;
		rC4=false;
				
		}

		if(getHitBox(xCRombo5,yCRombo5)&& rC5==true){
		BorrarCCC(19, xCRombo5,yCRombo5);
		Cs++;
		yCRombo5=0.1;
		rC5=false;
				
		}

		//B
		if(getHitBox(xBRombo1, yBRombo1) && rB1==true){
		BorrarBBB(20, xBRombo1,yBRombo1);
		Bs++;
		yBRombo1=0.1;
		rB1=false;
				
		}
		if(getHitBox(xBRombo2, yBRombo2)&& rB2==true){
		BorrarBBB(21, xBRombo2,yBRombo2);
		Bs++;
		yBRombo2=0.1;
		rB2=false;
				
		}
		if(getHitBox(xBRombo3, yBRombo3)&& rB3==true){
		BorrarBBB(22, xBRombo3,yBRombo3);
		Bs++;
		yBRombo3=0.1;
		rB3=false;
				
		}
		if(getHitBox(xBRombo4, yBRombo4)&& rB4==true){
		BorrarBBB(23, xBRombo4,yBRombo4);
		Bs++;
		yBRombo4=0.1;
		rB4=false;
				
		}

		if(getHitBox(xBRombo5,yBRombo5)&& rB5==true){
		BorrarBBB(24, xBRombo5,yBRombo5);
		Bs++;
		yBRombo5=0.1;
		rB5=false;
				
		}



	}//CAER NOTAS

		//FIN:

		if (FIN==true){

		notasCaer=false;
		//F
		BorrarF(5,xRombo1,yRombo1);
		yRombo1=0.1;
		r1=false;
		BorrarF(6,xRombo2,yRombo2);
		yRombo2=0.1;
		r2=false;
		BorrarF(7,xRombo3,yRombo3);
		yRombo3=0.1;
		r3=false;
		BorrarF(8,xRombo4,yRombo4);
		yRombo4=0.1;
		r4=false;
		BorrarF(9,xRombo5,yRombo5);
		yRombo5=0.1;
		r5=false;

		BorrarF(25,xRombo6,yRombo6);
		yRombo6=0.1;
		r6=false;
		BorrarF(26,xRombo7,yRombo7);
		yRombo7=0.1;
		r7=false;
		BorrarF(27,xRombo8,yRombo8);
		yRombo8=0.1;
		r8=false;
		BorrarF(28,xRombo9,yRombo9);
		yRombo9=0.1;
		r9=false;
		BorrarF(29,xRombo10,yRombo10);
		yRombo10=0.1;
		r10=false;
		//A
		BorrarAAA(10,xARombo1,yARombo1);
		yARombo1=0.1;
		rA1=false;
		BorrarAAA(11,xARombo2,yARombo2);
		yARombo1=0.1;
		rA2=false;
		BorrarAAA(12,xARombo3,yARombo3);
		yARombo1=0.1;
		rA3=false;
		BorrarAAA(13,xARombo4,yARombo4);
		yARombo1=0.1;
		rA4=false;
		BorrarAAA(14,xARombo5,yARombo5);
		yARombo1=0.1;
		rA5=false;
		//C
		BorrarCCC(15,xCRombo1,yCRombo1);
		yCRombo1=0.1;
		rC1=false;
		BorrarCCC(16,xCRombo2,yCRombo2);
		yCRombo1=0.1;
		rC2=false;
		BorrarCCC(17,xCRombo3,yCRombo3);
		yCRombo1=0.1;
		rC3=false;
		BorrarCCC(18,xCRombo4,yCRombo4);
		yCRombo1=0.1;
		rC4=false;
		BorrarCCC(19,xCRombo5,yCRombo5);
		yCRombo1=0.1;
		rC5=false;
		//B
		BorrarBBB(20,xBRombo1,yBRombo1);
		yBRombo1=0.1;
		rB1=false;
		BorrarBBB(21,xBRombo2,yBRombo2);
		yBRombo1=0.1;
		rB2=false;
		BorrarBBB(22,xBRombo3,yBRombo3);
		yBRombo1=0.1;
		rB3=false;
		BorrarBBB(23,xBRombo4,yBRombo4);
		yBRombo1=0.1;
		rB4=false;
		BorrarBBB(24,xBRombo5,yBRombo5);
		yBRombo1=0.1;
		rB5=false;


		//Jugador
		BorrarSprite(30,x,y);

		FIN=false;


			
		}//FIN

			



}

