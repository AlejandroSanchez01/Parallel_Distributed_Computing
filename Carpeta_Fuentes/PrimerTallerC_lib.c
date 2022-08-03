/*******************************************************************
* Fecha: 10 - Agosto - 2022
* Profesor: John Corredor, PhD
* Autor: Alejandro Sánchez
* Materia: Parallel and Distributed Computing 
* Tema: Primer taller en C
* Todas las funciones 
*******************************************************************/

#include <math.h>
#include <stdio.h> /*Biblioteca estandar de entrada y salida*/
#include <stdlib.h> /*Números Random  */  
#include <string.h> /*strcmp*/

/*Funciones correspondientes a cada uno de los puntos del taller*/


void ejercicio1(){
/* 1.- Escribe un programa en C que acepte dos enteros del usuario y calcule el producto de los
dos enteros.
Datos de prueba :
Introduzca el primer entero: 25
Introduzca el segundo entero: 15
Salida esperada:
Producto de los dos enteros anteriores = 375*/
int num1,num2;
printf("\n\n--------------");
printf(" Ejercicio 1 ");
printf("--------------\n\n");
printf("Introduzca el primer entero: ");
scanf("%d",&num1);
printf("Introduzca el segundo entero: ");
scanf("%d",&num2);
printf("\nProducto de los dos enteros anteriores = %d",(num1*num2));        
}


void ejercicio2(){
/*2.- Escribe un programa en C para convertir los días especificados en años, semanas y días.
Nota: Ignore el año bisiesto.
Datos de prueba :
Número de días : 1329
Salida esperada :
Años: 3
Semanas 33
Días: 3*/
int nDias,residuoAnhos,residuoSemanas;
printf("\n\n--------------");
printf(" Ejercicio 2 ");
printf("--------------\n\n");
printf("Número de días : ");
scanf("%d",&nDias);

residuoAnhos = (nDias%365);

printf("\nAños : %d",(nDias/365));
residuoSemanas=residuoAnhos%7;
printf("\nSemanas : %d",residuoAnhos/7);
printf("\nDias : %d",residuoSemanas);     
}


void ejercicio3(){
/*3.- Escribe un programa en C para calcular la distancia entre los dos puntos.
Datos de prueba :
Entrada x1: 25
Entrada y1: 15
Entrada x2: 35
Entrada y2: 10
Resultado esperado:
Distancia entre dichos puntos: 11.1803*/

float x1,y1,x2,y2,distancia;
printf("\n\n--------------");
printf(" Ejercicio 3 ");
printf("--------------\n\n");
printf("Entrada x1: ");
scanf("%f",&x1);
printf("Entrada y1: ");
scanf("%f",&y1);
printf("Entrada x2: ");
scanf("%f",&x2);
printf("Entrada y2: ");
scanf("%f",&y2);

distancia = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
printf("\nDistancia entre dichos puntos : %0.4f",distancia);     
}


void ejercicio4(){
/*4.- Escribe un programa en C para mostrar los 10 primeros números naturales.
Salida esperada :
1 2 3 4 5 6 7 8 9 10*/
int i;

printf("\n\n--------------");
printf(" Ejercicio 4 ");
printf("--------------\n\n");


for (i=1;i<=10;i++){
    printf("%d ",i);
}
}


void ejercicio5(){
/*5.- Escribe un programa en C para mostrar el patrón como triángulo rectángulo usando un
asterisco. La cantidad de líneas del triangulo es ingresada por consola por el usuario, y el valor
máximo de líneas es de 14.
El patrón como :
*
**
***
*****/

int cantidadLineas,contador,i;
printf("\n\n--------------");
printf(" Ejercicio 5 ");
printf("--------------\n\n");

printf("Entrada la cantidad de lineas: ");
scanf("%d",&cantidadLineas);

printf("\n");
if(cantidadLineas<=14 && cantidadLineas>0){
contador=0;  
for (i=1;i<=cantidadLineas;i++){
    do{
        printf("*");
        contador++;
    }while(contador<i);
    if(contador==i){
        contador=0;
        printf("\n");
    }
}
}
else{
    printf("El numero maximo de lineas permitido es de 14");
}
}

void ejercicio6(){
    /*6.- Escribe un programa que imprima una matriz de “1”, de tamaño NxN. El tamaño es
indicado por el usuario y debe ser siempre menor que 8.*/

int tamanho;
printf("\n\n--------------");
printf(" Ejercicio 6 ");
printf("--------------\n\n");

printf("Indique el tamaño de la matriz NxN de \"1\" : ");
scanf("%d",&tamanho);

printf("\n");
if(tamanho<8 && tamanho>0){ 
int i,j; 
for (i=0;i<tamanho;i++){
   for (j=0;j<tamanho;j++){
    printf("1 ");
   }
   printf("\n");
}
}
else{
    printf("El tamanho de la matriz debe ser siempre menor que 8");
}

}


void ejercicio7(){
/*7.- Escribe un programa que imprima una matriz de números aleatorios enteros, entre 0 y 9, de
de tamaño NxN. El tamaño es indicado por el usuario y debe ser siempre menor que 8.*/

int tamanho,numero;
printf("\n\n--------------");
printf(" Ejercicio 7 ");
printf("--------------\n\n");

printf("Indique el tamaño de la matriz NxN de \"Numeros Aleatorios\" : ");
scanf("%d",&tamanho);

printf("\n");
if(tamanho<8 && tamanho>0){  
int i,j;
for (i=0;i<tamanho;i++){
   for (j=0;j<tamanho;j++){
    numero = rand ()%10;
    printf("%d ",numero);
   }
   printf("\n");
}
}
else{
    printf("El tamanho de la matriz debe ser siempre menor que 8");
}

}


void ejercicioMatrices(char ejercicio[1], char operacionMatrices[1]){

int tamanho,numero;
printf("\n\n--------------");
printf(" Ejercicio %s ",ejercicio);
printf("--------------\n\n");

printf("Indique el tamaño de la matriz 1 y 2 NxN de \"Numeros Aleatorios\" : ");
scanf("%d",&tamanho);

printf("\n");
if(tamanho<8 && tamanho>0){  
    /*Llenar e imprimir la primer matriz*/

    printf("\n* Matriz 1 NxN *\n\n");
    int matriz1[tamanho][tamanho];

int i,j;
for (i=0;i<tamanho;i++){
   for (j=0;j<tamanho;j++){
    numero = rand ()%10;
    matriz1[i][j] = numero;
    printf("%d ",numero);
   }
   printf("\n");
}

/*Llenar e imprimir la segunda matriz*/
   int matriz2[tamanho][tamanho];
   printf("\n* Matriz 2 NxN *\n\n");

for (i=0;i<tamanho;i++){ 
   for (j=0;j<tamanho;j++){
    numero = rand ()%10;
    matriz2[i][j] = numero;
    printf("%d ",numero);
   }
   printf("\n");
}

/*Operacion de las matrices*/
int operacion[tamanho][tamanho];
if(strcmp(operacionMatrices,"+")){
printf("\n* Sumatoria de Matrices *\n\n");
}
else{
printf("\n* Resta de Matrices *\n\n");
}


for (i=0;i<tamanho;i++){
   for (j=0;j<tamanho;j++){
    if(strcmp(operacionMatrices,"+")){
    operacion[i][j] = matriz1[i][j]+matriz2[i][j];
    }
    else{
        operacion[i][j] = matriz1[i][j]-matriz2[i][j];
    }

    if(operacion[i][j]<10){
        printf(" %d ",operacion[i][j]);
    }
    else{
        printf("%d ",operacion[i][j]);
    } 
   }
   printf("\n");
}
}
else{
    printf("El tamanho de la matriz debe ser siempre menor que 8");
}
}

void ejercicio8(){
/*8.- Escribe un programa que muestre dos matrices de números aleatorios, entre 0 y 9, de
tamaño NxN. El tamaño es indicado por el usuario y debe ser siempre menor que 8.
Finalmente, se presenta la suma de las dos matrices.*/

ejercicioMatrices("8","+");
}

void ejercicio9(){
/*9.- Escribe un programa que muestre dos matrices de números aleatorios, entre 0 y 9, de
tamaño NxN. El tamaño es indicado por el usuario y debe ser siempre menor que 8.
Finalmente, se presenta la resta de las dos matrices.*/
ejercicioMatrices("9","-");
}


void ejercicio10(){

/*10.- Escribe un programa que muestre dos matrices de números aleatorios, entre 0 y 9, de
tamaño NxN. El tamaño es indicado por el usuario y debe ser siempre menor que 8.
Finalmente, se presenta el producto de las dos matrices.*/

 int tamanho=0,numero,i,j,suma,k;
printf("\n\n--------------");
printf(" Ejercicio 10 ");
printf("--------------\n\n");

printf("Indique el tamaño de la matriz 1 y 2 NxN de \"Numeros Aleatorios\" : ");
scanf("%d",&tamanho);

printf("\n");
if(tamanho<8 && tamanho>0){

int matriz1[tamanho][tamanho],matriz2[tamanho][tamanho],producto[tamanho][tamanho];  
    /*Llenar e imprimir la primer matriz*/
    printf("\n* Matriz 1 NxN *\n\n");
    
for (i=0;i<tamanho;i++){
   for (j=0;j<tamanho;j++){
    numero = rand ()%10;
    matriz1[i][j] = numero;
    printf("%d ",numero);
   }
   printf("\n");
}

/*Llenar e imprimir la segunda matriz*/
   printf("\n* Matriz 2 NxN *\n\n");  
for (i=0;i<tamanho;i++){
   for (j=0;j<tamanho;j++){
    numero = rand ()%10;
    matriz2[i][j] = numero;
    printf("%d ",numero);
   }
   printf("\n");
}

/*Producto de las matrices*/

printf("\n* Producto de Matrices *\n\n");

for (i=0;i<tamanho;i++){
   for (j=0;j<tamanho;j++){
    for (suma=0,k=0;k<tamanho;k++){
    suma+=matriz1[i][k]*matriz2[k][j];
    producto[j][i] = suma; 
    }
    if(producto[j][i]<10){
        printf(" %d ",producto[j][i]);
    }
    else{
        printf("%d ",producto[j][i]);
    }
   }
   printf("\n");
}


}
else{
    printf("El tamanho de la matriz debe ser siempre menor que 8");
}
}



void menu(){
#define TRUE 1
#define FALSE 0

    int opcion;
    char repetir = TRUE;
    
    do {

        printf("\n\n\n#######################################################################\n");
        printf("#                     Ejercicios primer taller en C                   #\n");
        printf("#                           Alejandro Sánchez                         #\n");
        printf("#######################################################################\n");
        printf("\n\nSeleccione un ejercicio\n\n");
        printf(" 1. Producto de dos enteros\n");
        printf(" 2. Convertir dias (Años, Semanas, Dias)\n");
        printf(" 3. Distancia entre dos puntos\n");
        printf(" 4. Mostrar primeros 10 numeros naturales\n");
        printf(" 5. Triangulo rectangulo de asteriscos\n");
        printf(" 6. Matriz NxN de \"1\" \n");
        printf(" 7. Matriz NxN de \"Numeros Aleatorios\" \n");
        printf(" 8. Sumatoria de Matrices\n");
        printf(" 9. Resta de Matrices\n");
        printf("10. Producto de Matrices\n");
        printf(" 0. SALIR\n");
        
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                ejercicio1();
                break;
                
            case 2:
                ejercicio2();
                
                break;
                
            case 3:
               ejercicio3();                        
                break;
                
            case 4:
                ejercicio4();             
                break;
            case 5:
               ejercicio5();                        
                break;
                
            case 6:
               ejercicio6();                        
                break;

            case 7:
               ejercicio7();                        
                break;
            case 8:
               ejercicio8();                        
                break;
            case 9:
               ejercicio9();                        
                break;
            case 10:
               ejercicio10();                        
                break;                    
            case 0:
            	repetir = FALSE;
            	break;
        }        
    } while (repetir);
}
