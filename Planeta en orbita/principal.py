import planet_orbit_py
import planet_orbit_cy
import time

ini_time = time.time()
planet_orbit_cy.main()
fin_time = time.time()

time_cython = fin_time - ini_time

ini_time = time.time()
planet_orbit_py.main()
fin_time = time.time()

time_python = fin_time - ini_time
print("El tiempo de Cython es: ", time_cython,"seg")
print("El tiempo de Python es: ", time_python,"seg")


print("Cython es ", time_python/time_cython," veces más rápido que Python")
