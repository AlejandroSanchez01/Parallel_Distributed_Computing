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

/*#define DATA_SIZE_DOUBLE (1024*1024*64*3*4) *//*Multiplico por 4 porque el dataSIZE asumo que son 2bytes y el double son 8 y 4*2=8*/
/**4 sale el siguiente error
reubicación truncada para ajustar: R_X86_64_PC32 contra el símbolo `inicioCuenta' definido en la sección .bss en mm_lib.o*/

static int MEM_CHUNK[DATA_SIZE];

int main(int argc, char **argv){
	/*Puntero no se de que dimension es, apunta a un metaVector cuya dimension no se cual es*/
        int N;
        N=(int)atof(argv[1]); 
	
	/****Declaración de matrices con apuntadores a memoria de tipo int****/
	int *a,*b,*c; /*NO se adonde estan apuntando*/
	a=MEM_CHUNK;
	b=a+(N*N);
	c=b+(N*N);
	
	inicializar_int(a,b,c,N);
	impresion_int(a,N);
	impresion_int(b,N);
	punto_prueba_inicial();
	mm_c_int(a,b,c,N);
	impresion_int(c,N);
	punto_prueba_final();
	
return 0;
}
