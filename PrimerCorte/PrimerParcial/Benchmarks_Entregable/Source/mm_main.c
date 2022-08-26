/********************************************************************************************
* Fecha: 9 Agosto 2022 
* Profesor: John Corredor, PhD
* Autor: Alejandro Sanchez
* Tema: Construcción Benchmark Multiplicacion de matrices
*Evaluar de forma exhaustiva de cualquier aspecto (Jerarquia de memoria y procesamiento)
*********************************************************************************************/


#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h> /*Para el atoi*/


/**************** Función Inicialización ****************/
void inicializarMM(int matrizA[],int matrizB[], int matrizC[],int n){
	int i,j;
	/*Todo lo que pasa en esta funcion se ve reflejado en el vector a,b,c */
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
		  matrizA[i+j*n]= 1*(i+j);
		  matrizB[i+j*n] = 2*(j-i);
		  matrizC[i+j*n]= 0;
		}
	}
}

/**************** Función Impresión ****************/
void impresionMM(int matriz[], int n){
	int i,j;
	printf("\n");
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
		  printf("%d",matriz[i+j*n]);	  
		}
		printf("\n");
	}
}


void mm_clasica(int matrizA[],int matrizB[],int matrizC[],int n){
	/***** Multiplicación de Matrices: Clásica *****/
	int suma,i,j,k;
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
		  suma=0;
			for(k=0;k<n;k++){
				suma+=matrizA[j+k*n]*matrizB[k+i*n];
			}
			matrizC[j+i*n]=suma;
		}
	}
}



/*Se implementa la multiplicación de matrices con iguales dimensiones*/
/*Se inicializa las matrices con números aleatorios*/


int main(int argc, char *argv[]){
	/*Puntero no se de que dimension es, apunta a un metaVector cuya dimension no se cual es*/
        int N,SIZE;
        int i,j,k;
        /*argv[] Argumento de entrada 0 ./a.out y Argumento de entrada 1 es el tamanho*/
        /*argc Cantidad de argumentos de entrada*/
        N=(int)atof(argv[1]); 
 	/*printf("Indique la dimensión de la matriz (NxN):");
	scanf("%d",&N);*/
	SIZE = N*N;
	
	/****Declaración e Inicialización de matrices ****/
	int a[SIZE],b[SIZE],c[SIZE]; /*Vector reservado de memoria*/
	/*Simular que fuera una matriz manejando las posiciones i,j,k*/

	inicializarMM(a,b,c,N);
	impresionMM(a,N);
	impresionMM(b,N);
	mm_clasica(a,b,c,N);
	impresionMM(c,N);
	
return 0;
}
