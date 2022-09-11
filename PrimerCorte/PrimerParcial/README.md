# Encabezado
<p align="center"><img src="https://res-5.cloudinary.com/crunchbase-production/image/upload/c_lpad,h_256,w_256,f_auto,q_auto:eco/v1455514364/pim02bzqvgz0hibsra41.png"width="200" height="200">
</img><br>
<i><b>Docente:</b></i> John Corredor, PhD.
<br>
<i><b>Asignatura:</b></i> Computación Paralela y Distribuida
<br>
<i><b>Estudiantes:</b></i> Edna Sofía Orjuela Puentes y Herlendy Alejandro Sánchez Gaitán
<br>
<i><b>Tema:</b></i> Primer parcial de Computación Paralela y Distribuida
<br>
<i><b>Fecha:</b></i>12/09/22
<br>
</p>



# Resumen

Este informe tiene como objetivo aplicar definiciones básicas acerca de la computación paralela, conceptos tales como, la jerarquía de memoria, los benchmarks y el uso de memoria dinámica, por medio de punteros. Por lo tanto, se implementan cuatro benchmarks (int, int_rand, double, double_rand) desarrollados en C y ejecutados en 3 nodos de cómputo diferentes, con el fin de obtener el tiempo de ejecución del algoritmo en cada uno de  los nodos. Posterior a ello, se realiza un análisis para comparar el rendimiento de los nodos considerando los componentes a nivel de hardware, de cada nodo. De esta manera, con los resultados obtenidos, se busca conocer que nodos de cómputo lograron obtener mejor tiempo de ejecución con respecto a las diferentes cargas (tamaño de las matrices multiplicadas) proporcionadas, teniendo en cuenta que todos los nodos se encuentran aislados, para evitar la contaminación de los datos.


# Introducción

El programa  o benchmark  a utilizar en este ejercicio, mide los tiempos de ejecución requeridos para la multiplicación de matrices de distintas dimensiones, y para entender qué aspectos influyen en el rendimiento de la máquina y a la vez contener resultados consistentes y significativos, se van a realizar diferentes pruebas de rendimiento, en tres nodos distintos con doce cargas, cada una con treinta iteraciones. 

Archivos utilizados:

* lanzador.pl: Archivo de control en lenguaje perl, para realizar la ejecución automatizada del benchmark.<br>
* makefile: Script para la automatización del proceso de compilación.<br>
* mm lib.c: Archivo para la construcción del Benchmark con la multiplicacion de matrices.<br>
* mm lib.h: Interfaz o header con las funciones a usar.<br>
* mm main double.c: Clase principal que llama las funciones que corresponden a los datos double.<br>
* mm main double rnd.c: Clase principal que llama las funciones que corresponden a los datos double random.<br>
* mm main int.c: Clase principal que llama las funciones que corresponden a los datos int.<br>
* mm main int rnd.c: Clase principal que llama las funciones que corresponden a los datos int random.<br>



# Desarrollo


# Guía para la ejecución del proyecto
Para ejecutar este programa, es necesario:<br>

<br>**1. Instalación de CMAKE** 
```
#sudo apt install cmake
sudo apt update
```

<br>**2. Generar objetos y ejecutables para el correcto funcionamiento**
* Abrir proyecto en "Benchmarks_Entregable"
* En la terminal de ubuntu estando dentro de esa carpeta, escribir el comando *make all* para generar los archivos necesarios
<br>
<p align="center"> <img src="https://github.com/AlejandroSanchez01/Parallel_Distributed_Computing/blob/main/PrimerCorte/PrimerParcial/Imagenes_proceso_ejecucion/crear_objetos_ejecutables.png" width="400"/> </p>

<p align="center"><i><b>Figura 1</i></b></p>

<br>**3. Ejecutar de forma manual los diferentes benchmark para N dimensiones** 

Comandos para ejecutar el programa de multiplicacion de matrices 

* Tipo int se debe escribir en consola *./mm_main_int* seguido de la dimension y presionar enter
<br>
Ejemplo
<p align="center"> <img src="https://github.com/AlejandroSanchez01/Parallel_Distributed_Computing/blob/main/PrimerCorte/PrimerParcial/Imagenes_proceso_ejecucion/int.png" width="400"/> </p>

<p align="center"><i><b>Comando para ejecutar matriz int </i></b></p>


* Tipo int con números random se debe escribir en consola *./mm_main_int_rnd* seguido de la dimension y presionar enter
<br>
Ejemplo
<p align="center"> <img src="https://github.com/AlejandroSanchez01/Parallel_Distributed_Computing/blob/main/PrimerCorte/PrimerParcial/Imagenes_proceso_ejecucion/int_rnd.png" width="400"/> </p>

<p align="center"><i><b>Comando para ejecutar matriz int_rnd </i></b></p>


* Tipo double se debe escribir en consola *./mm_main_double* seguido de la dimension y presionar enter
<br>
Ejemplo
<p align="center"> <img src="https://github.com/AlejandroSanchez01/Parallel_Distributed_Computing/blob/main/PrimerCorte/PrimerParcial/Imagenes_proceso_ejecucion/double.png" width="400"/> </p>

<p align="center"><i><b>Comando para ejecutar matriz double</i></b></p>

* Tipo double con números random se debe escribir en consola *./mm_main_double_rnd* seguido de la dimension y presionar enter
<br>
Ejemplo
<p align="center"> <img src="https://github.com/AlejandroSanchez01/Parallel_Distributed_Computing/blob/main/PrimerCorte/PrimerParcial/Imagenes_proceso_ejecucion/double_rnd.png" width="400"/> </p>

<p align="center"><i><b>Comando para ejecutar matriz double_rnd </i></b></p>


<br>**4. Ejecucion benchmarks para obtener de forma automatica los tiempos para las 12 cargas**
* Escribir en consola *./lanzador.pl* y presionar enter
<br>


# Conclusiones

* Al observar y analizar las gráficas de los tiempos de ejecución, se puede determinar que el nodo de computo U a nivel general obtuvo el mejor rendimiento, debido a que fue el que ejecuto los 4 benchmarks en menor tiempo, seguido a este se encuentra el nodo de computo A el cual tuvo un desempeño promedio ni tan optimo como el nodo U ni tan bajo como el nodo S y finalmente el nodo S, el cual fue el mas "deficiente" considerando los tiempos altos que obtuvo.

*


# Referencias
* "¿Qué es la Ley de Amdahl y cómo se aplica a la informática?" HardZone. https://hardzone.es/reportajes/que-es/ley-de-amdahl/ (accedido el 10 de septiembre de 2022).

* "Pruebas Benchmark - EcuRed". EcuRed. https://www.ecured.cu/Pruebas\_Benchmark (accedido el 10 de septiembre de 2022).

* "Programación paralela". Ferestrepoca.GitHub.io by ferestrepoca. http://ferestrepoca.github.io/paradigmas-de-programacion/paralela/paralela\_teoria/index.html (accedido el 10 de septiembre de 2022).

* "Introducción y medidas de rendimiento ley de amdahl". Universidad Europea de Madrid. https://www.cartagena99.com/recursos/alumnos/apuntes\\/ININF1\_M10\_U1\_T4\_MT.pdf (accedido el 9 de septiembre de 2022).


