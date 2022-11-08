# Presentación
<p align="center"><img src="https://res-5.cloudinary.com/crunchbase-production/image/upload/c_lpad,h_256,w_256,f_auto,q_auto:eco/v1455514364/pim02bzqvgz0hibsra41.png"width="200" height="200">
</img><br>
<i><b>Docente:</b></i> John Corredor, PhD.
<br>
<i><b>Asignatura:</b></i> Computación Paralela y Distribuida
<br>
<i><b>Estudiantes:</b></i> Herlendy Alejandro Sánchez Gaitán
<br>
<i><b>Tema:</b></i> Taller Problema planeta en orbita
<br>
<i><b>Fecha:</b></i>8/10/22
<br>
</p>



# Resumen

Este informe tiene como objetivo corroborar que Cython tiene un mayor rendimiento que Python para el problema de planeta en Orbita.

![Problema a solucionar](https://github.com/AlejandroSanchez01/Parallel_Distributed_Computing/blob/6b97c28d2fa246a8cbdff581f780a163304ca20a/TercerCorte/Imagenes/Problema.png)

# Introducción

El programa a utilizar en este ejercicio, mide los tiempos de ejecución de cython y python para diferentes pruebas, con el fin de corroborar cual presenta un mejor rendimiento

Archivos utilizados:

* makefile: Script para la automatización del proceso de compilación.<br>
* planet_orbit_cy.pyx: Archivo que contiene la estructura de las clases principales en lenguaje de Cython.<br>
* planet_orbit_py.py: Archivo que contiene la estructura de las clases principales en lenguaje de Python.<br>
* principal.py: Genera los tiempos de ejecución en segundos, de cython y python y los agrega a un archivo .csv, adicional a ello este script de python,lama el fichero generado por el setup.py para poder importar dicho código de Cython como si fuera un modulo, para psoterior a ello acceder a sus funciones.<br>
* setup.py: Es el encargado de generar la extensión de Cython al compilarlo.<br>

# Observaciones


Se puede acelerar Python es combinándolo con código en Cython, dado Cython permite el uso de módulos y variables de tipo C. De esta manera, se puede obtener una velocidad de C, manteniendo la simplicidad de sintaxis proporcionada por Python.

Python es un lenguaje interpretado, lo que significa que ejecuta directamente el código línea por línea, si existen errores en el código del programa, su ejecución se detiene. Así, los programadores pueden encontrar errores en el código con rapidez. Sin embargo, esto hace que su rendimiento disminuya respecto a Cython, el cual es un lenguaje de programación para simplificar la escritura de módulos de extensión para Python en C y C++.


Las funciones que utiliza cython, se pueden declarar de tres formas distintas: 

* def: Indica que la función solo puede ser accedida desde una función de Python
* cpdef: La función puede acceder desde Python y desde Cython
* cdef: La funcion unicamente es accesible desde Cython.


# Desarrollo

![Ejecucion del programa](https://github.com/AlejandroSanchez01/Parallel_Distributed_Computing/blob/b00d5f699bcede9ec5b783e8ff9b6df2bd87af3d/TercerCorte/Imagenes/Ejecuci%C3%B3n%20del%20programa.png)

A continuación se presentan algunos de los tiempos que se obtuvieron en la ejecución del programa

![Tiempos obtenidos](https://github.com/AlejandroSanchez01/Parallel_Distributed_Computing/blob/adb9e3d916319017aa575ea008e26aa14b5c0bc4/TercerCorte/Imagenes/TiemposObtenidos.png)

# Conclusiones

* Los ficheros que se utilizaron para realizar este experimento se pueden encontrar en Github, los cuales estan a disposición para que se pueda replicar el experimento.

* Se hace un analisis exhaustivo de los resultados de bateria de experimentos realizados en Cython y en Python.

* Se realiza una metodologia, en donde se replica el código de Python en Cython, para poder obtener un mayor rendimiento, donde se obtuvo que la mayor cantidad de veces Cython es 17 veces aproximadamente más rápido que Python.

* Se recomienda dejar el computador aislado, para que no afecte los tiempos de ejecución de un lenguaje de programación respecto al otro.

# Referencias

* Cython: C-Extensions for Python. (s. f.). https://cython.org/
* ¿Qué es Python? | Guía de Python para principiantes de la nube | AWS. (s. f.). Amazon Web Services, Inc. https://aws.amazon.com/es/what-is/python/
* Optimizando Python con Cython. (2022, 22 febrero). INLOC Robotics. https://inlocrobotics.com/es/optimizando-python-con-cython/

