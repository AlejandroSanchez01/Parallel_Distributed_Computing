/********************************************************************************************
* Fecha: 9 Agosto 2022 
* Profesor: John Corredor, PhD
* Autor: Alejandro Sanchez
* Tema: Construcción Benchmark Multiplicacion de matrices
*Evaluar de forma exhaustiva de cualquier aspecto (Jerarquia de memoria y procesamiento)
*********************************************************************************************/



#include <stdlib.h> /*Para el atof*/
#include "mm_lib.h"

/***** Se requiere reservar un Espacio de memoria *****/
#define DATA_SIZE (1024*1024*64*3)/*Memoria de la ram reservada 9000*9000 buena memoria*/

static double MEM_CHUNK_DOUBLE[DATA_SIZE];

int main(int argc, char **argv){
	/*Puntero no se de que dimension es, apunta a un metaVector cuya dimension no se cual es*/
        int N;
        N=(int)atof(argv[1]); 
		
	/****Declaración de matrices con apuntadores a memoria de tipo double ****/
	double *a2,*b2,*c2; /*NO se adonde estan apuntando*/
	a2=MEM_CHUNK_DOUBLE;
	b2=a2+(N*N);
	c2=b2+(N*N);
	inicializar_double_rnd(a2,b2,c2,N);
	impresion_double(a2,N);
	impresion_double(b2,N);
	punto_prueba_inicial();
	mm_c_double(a2,b2,c2,N);
	impresion_double(c2,N);
	punto_prueba_final();
	
return 0;
}
