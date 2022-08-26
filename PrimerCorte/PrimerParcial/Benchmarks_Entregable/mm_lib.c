/********************************************************************************************
* Fecha: 9 Agosto 2022 
* Profesor: John Corredor, PhD
* Autor: Alejandro Sanchez
* Tema: Construcción Benchmark Multiplicacion de matrices
* Evaluar de forma exhaustiva de cualquier aspecto (Jerarquia de memoria y procesamiento)
*********************************************************************************************/


#include <stdio.h>
#include <math.h>
#include <time.h>
/*#include <stdlib.h>*/ /*Para el atof*/
/*#include "mm_lib.h"*/
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>


/*** Función para crear aleatorios Int***/
int random_int(){
	int min = 0, max = 9;
	static int flag = -1; /*Valor imposible*/
	if((flag = (flag<0)))
		srand(time(NULL)+getpid()); /*Semilla*/
		/*getpid() identificador del proceso*/
	if(min>max)
		return errno= EDOM,NAN; /*Indica cual es el error*/
	return min+ (int)rand()/((int)RAND_MAX/(max-min));	
}

/*** Función para crear aleatorios double***/
double random_double(){
	double min = 0.01, max = 9.999;
	static int flag = -1; /*Valor imposible*/
	if((flag = (flag<0)))
		srand(time(NULL)+getpid()); /*Semilla*/
		/*getpid() identificador del proceso*/
	if(min>max)
		return errno= EDOM,NAN; /*Indica cual es el error*/
	return min+ (double)rand()/((double)RAND_MAX/(max-min));	
}


/**************** Función Inicialización int Aleatoria ****************/
void inicializar_int_rnd(int *matrizA,int *matrizB, int *matrizC,int n){
	int i,j;
	/*Todo lo que pasa en esta funcion se ve reflejado en el vector a,b,c */
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
		  matrizA[i+j*n]= random_int();
		  matrizB[i+j*n] = random_int();
		  matrizC[i+j*n]= 0;
		}
	}
}

/**************** Función Inicialización int ****************/
void inicializar_int(int *matrizA,int *matrizB, int *matrizC,int n){
	int i,j;
	/*Todo lo que pasa en esta funcion se ve reflejado en el vector a,b,c */
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
		  matrizA[i+j*n]= 2*(i+j);
		  matrizB[i+j*n] = 2*i+3*j;
		  matrizC[i+j*n]= 0;
		}
	}
}


/**************** Función Inicialización double Aleatoria ****************/
void inicializar_double_rnd(double *matrizA,double *matrizB, double *matrizC,int n){
	int i,j;
	/*Todo lo que pasa en esta funcion se ve reflejado en el vector a,b,c */
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
		  matrizA[i+j*n]= random_double();
		  matrizB[i+j*n] = random_double();
		  matrizC[i+j*n]= 0;
		}
	}
}

/**************** Función Inicialización double ****************/
void inicializar_double(double *matrizA,double *matrizB, double *matrizC,int n){
	int i,j;
	/*Todo lo que pasa en esta funcion se ve reflejado en el vector a,b,c */
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
		  matrizA[i+j*n]= 2.0*(i+j);
		  matrizB[i+j*n] = 2.0*i+3.0*j;
		  matrizC[i+j*n]= 0;
		}
	}
}


/**************** Función Impresión de tipo int****************/
void impresion_int(int *matriz, int n){
	int i,j;
	if(n<5){
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
		  printf(" %d ",matriz[j+i*n]);	  
		}
		printf("\n");
	}
	printf("\n-------------------\n");
	}
}

/**************** Función Impresión de tipo double****************/
void impresion_double(double *matriz, int n){
	int i,j;
	if(n<5){
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
		  printf(" %f ",matriz[j+i*n]);	  
		}
		printf("\n");
	}
	printf("\n-------------------\n");
	}
}


/**** Benchmark 01 *****/
/***** Multiplicación de Matrices: Por punteros int*****/
void mm_c_int(int *matrizA,int *matrizB,int *matrizC,int N){
	int suma,i,j,k;
	for (i=0;i<N;i++){
		for(j=0;j<N;j++){
		  suma=0;
		  /**Punteros Auxiliares **/
		  int *pA,*pB;
		  pA = matrizA + (i*N);
		  pB = matrizB + j;
		  /*Puntero A aumenta por la misma fila*/
		  /*Puntero B aumenta por la misma columna, lo hace por saltos*/
			for(k=0;k<N;k++,pA++,pB+=N){
				suma+=(*pA * *pB);
			}
			matrizC[j+i*N]=suma;
		}
	}
}

/***** Multiplicación de Matrices: Por punteros double*****/
void mm_c_double(double *matrizA,double *matrizB,double *matrizC,int N){
	int i,j,k;
	double suma;
	for (i=0;i<N;i++){
		for(j=0;j<N;j++){
		  suma=0;
		  /**Punteros Auxiliares **/
		  /*int *pA,*pB;*/
		  double *pA,*pB;
		  pA = matrizA + (i*N);
		  pB = matrizB + j;
		  /*Puntero A aumenta por la misma fila*/
		  /*Puntero B aumenta por la misma columna, lo hace por saltos*/
			for(k=0;k<N;k++,pA++,pB+=N){
				suma+=(*pA * *pB);
			}
			matrizC[j+i*N]=suma;
		}
	}
}


/*Estructura de datos, metodos que representan una estructura de tipo main*/
struct timespec inicioCuenta,  finCuenta;

/****Funcion evaluacion inicio del tiempo *****/
void punto_prueba_inicial(){
	/*Clock principal del kernell*/
	/*Balanceo de cargas multicores*/
	/*Tiempo global Lo ve desde arriba la ejecucion de procesos*/
	/*Planificador poder identificador de proceso, pedir en que momento pedir el tiempo, y segun que hace el proceso
	  			
	*/
 	clock_gettime(CLOCK_MONOTONIC,&inicioCuenta);
}

/****Funcion evaluacion final del tiempo, impresión de resultados *****/
void punto_prueba_final(){
	double total_time;
 	clock_gettime(CLOCK_MONOTONIC,&finCuenta);
 	total_time = (finCuenta.tv_sec - inicioCuenta.tv_sec)*1e9;
 	total_time = (total_time + finCuenta.tv_nsec - inicioCuenta.tv_nsec)*1e-9;
 	/*De segundos a nanosegundos y luego a segundos*/
 	printf("\nTotal time: %f\n",total_time); 	
}

