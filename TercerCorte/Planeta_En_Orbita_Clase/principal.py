"""
Fecha: 1 nov 2022
Autor: Alejandro Sanchez
Tema: Cython
Topico: Planetas orbitas gravitacional 
Princiapl: llama a ambos programa Cy/Py

La idea principal es crear un ".csv" con 
la toma de tiempos.
"""

import planet_orbit_py
import planet_orbit_cy
import time
from timeit import repeat
from subprocess import check_output


formato_datos = "{:.5f},{:.5f}\n"
#Se define una funcion para medir el tiempo
def timer(arg,niter,name,module):
    stmt = "%s(%s)" % (name, arg)
    setup = "from %s import %s" % (module, name)
    times = repeat(stmt=stmt, setup=setup, repeat=3, number=niter)
    return min(times) / niter

#Se inicializa el planeta para Python
#Datos de wikipedia
tierraPy = planet_orbit_py.Planet()
tierraPy.x = 100*10**3
tierraPy.y = 300*10**3
tierraPy.z = 700*10**3
tierraPy.vx = 2.00*10**3
tierraPy.vy = 29.87*10**3
tierraPy.vz = 0.34*10**3
tierraPy.m = 5.9742*10**24

#Se inicializa el planeta para Cython
#Datos de wikipedia
tierraCy = planet_orbit_cy.Planet()
tierraCy.x = 100*10**3
tierraCy.y = 300*10**3
tierraCy.z = 700*10**3
tierraCy.vx = 2.00*10**3
tierraCy.vy = 29.87*10**3
tierraCy.vz = 0.34*10**3
tierraCy.m = 5.9742*10**24


#Se condieran las otras variables
time_span = 400
n_steps = 2000000

#Definiccion de experimentos
#Reduccion ruido Gaussiano

for i in range(2):
    #Toma de tiempos para python
    ini_time = time.time()
    planet_orbit_py.step_time(tierraPy, time_span, n_steps)
    fin_time = time.time()
    time_python = fin_time - ini_time

    #Toma de tiempos para cython
    ini_time = time.time()
    planet_orbit_cy.step_time(tierraCy, time_span, n_steps)
    fin_time = time.time()
    time_cython = fin_time - ini_time

    with(open("planeta.csv","a")) as archivo:
        archivo.write(formato_datos.format(time_python,time_cython))

    print("El tiempo de Cython es: ", time_cython,"seg")
    print("El tiempo de Python es: ", time_python,"seg")
    print("Cython es ", time_python/time_cython," veces más rápido que Python\n")
