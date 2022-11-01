#cython: language_level=3
"""
Se requiere la raiz cuadrada
	Se instancia como funcion externa,
	Se prepara para multhilo
"""

# Importar librerias
# llamar la biblioteca de c para la raiz cuadrada

cdef extern from "math.h":
    double sqrt(double x) nogil

cdef class  Planet(object):
#Variables publicas: declaracion 	
    cdef public float  x,y,z,vx,vy,vz,m
    def __init__(self):  
        self.x = 1.0
        self.y = 0.0
        self.z = 0.0
        self.vx=0.0
        self.vy= 0.5
        self.vz = 0.0
        self.m =1.0

"""
Puede ser la distancia 0
Para evitar lo anterior, preparamos una 
alerta basada en cython: cdivision(True/False):
            Al poner true, invalida la instruccion
            al saltar la bandera (INF)
Se prepara con un decorador de CYTHON
"""

cimport cython
#Se prepara para la division
@cython.cdivision(True)

cdef void single_step(Planet planet, double dt) nogil:
    cdef double distance,Fx,Fy,Fz

    distance =sqrt(planet.x**2 + planet.y**2 + planet.x**2)    
    
    Fx = -planet.x/distance**3
    Fy = -planet.y/distance**3
    Fz = -planet.z/distance**3

    planet.x +=dt*planet.vx
    planet.y += dt*planet.vy
    planet.z += dt*planet.vz

    planet.vx += dt * Fx/planet.m
    planet.vy += dt * Fy/planet.m
    planet.vz += dt * Fz/planet.m

def step_time(Planet planet, double time_span, int n_steps):   

    cdef int j
    cdef double dt
    dt = time_span / n_steps
    
    """
    Se prepara para paralelismo
    Nogil: Sin bloqueo
    """
    
    with nogil:
        for j in range(n_steps):
            single_step(planet,dt)
