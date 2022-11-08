# Encabezado
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
* principal.py: Genera los tiempos de ejecución en segundos, de cython y python y los agrega a un archivo .csv.<br>
* setup.py: Tiene como finalidad poder configurar nuestro proyecto para su release..<br>

# Desarrollo

![Ejecucion del programa]([https://github.com/AlejandroSanchez01/Parallel_Distributed_Computing/blob/6b97c28d2fa246a8cbdff581f780a163304ca20a/TercerCorte/Imagenes/Problema.png])

A continuación se presentan algunos de los tiempos que se obtuvieron en la ejecución del programa

![Tiempos obtenidos]([https://github.com/AlejandroSanchez01/Parallel_Distributed_Computing/blob/adb9e3d916319017aa575ea008e26aa14b5c0bc4/TercerCorte/Imagenes/TiemposObtenidos.png])



# Conclusiones

* Como medida de rendimiento, se comprueba la eficiencia significativa que tiene Cython con respecto a Python, siendo la mayor cantidad de veces Cython es  17 veces aproximadamente más rápido que Python 

* Python es un lenguaje interpretado, lo que significa que ejecuta directamente el código línea por línea, si existen errores en el código del programa, su ejecución se detiene. Así, los programadores pueden encontrar errores en el código con rapidez. Sin embargo, esto hace que su rendimiento disminuya respecto a Cython, el cual es un lenguaje de programación para simplificar la escritura de módulos de extensión para Python en C y C++.

# Referencias

* https://cython.org/
* https://aws.amazon.com/es/what-is/python/


