/********************************************************************************************
* Fecha: 9 Agosto 2022 
* Profesor: John Corredor, PhD
* Autor: Alejandro Sanchez
* Tema: Construcción Benchmark Multiplicacion de matrices
*Evaluar de forma exhaustiva de cualquier aspecto (Jerarquia de memoria y procesamiento)
*********************************************************************************************/

#ifndef MM_LIB_H_INCLUDED /*Si no esta definido */
#define MM_LIB_H_INCLUDED /*definalo */



/**************** PROTOTIPO DE FUNCIONES ****************/


int random_int();

double random_double();

/**************** Función Inicialización Aleatoria int****************/
void inicializar_int_rnd(int *matrizA,int *matrizB, int *matrizC,int n);

/**************** Función Inicialización Aleatoria de tipo double****************/
void inicializar_double_rnd(double *matrizA,double *matrizB, double *matrizC,int n);

/**************** Función Inicialización de tipo int****************/
void inicializar_int(int *matrizA,int *matrizB,int *matrizC,int n);

/**************** Función Inicialización de tipo double****************/
void inicializar_double(double *matrizA,double *matrizB,double *matrizC,int n);

/**************** Función Impresión int****************/
void impresion_int(int *matriz, int n);

/**************** Función Impresión double ****************/
void impresion_double( double *matriz, int n);


/***** Multiplicación de Matrices: Clasica *****/
/*void mm_c_regular(int *matrizA,int *matrizB,int *matrizC,int n);*/

/***** Multiplicación de Matrices: Por punteros int*****/
void mm_c_int(int *matrizA,int *matrizB,int *matrizC,int N);

/***** Multiplicación de Matrices: Por punteros double*****/
void mm_c_double(double *matrizA,double *matrizB,double *matrizC,int N);

/****Funcion evaluacion inicio del tiempo *****/
void punto_prueba_inicial();

/****Funcion evaluacion final del tiempo, impresión de resultados *****/
void punto_prueba_final();

#endif
