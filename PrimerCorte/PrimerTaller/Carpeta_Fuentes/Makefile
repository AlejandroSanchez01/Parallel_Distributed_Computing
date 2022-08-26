#/*******************************************************************
#* Fecha: 10 - Agosto - 2022
#* Profesor: John Corredor, PhD
#* Autor: Alejandro Sánchez
#* Materia: Parallel and Distributed Computing 
#* Tema: Primer taller en C
#*******************************************************************/

GCC = gcc
FLAGS = -ansi -std=c99 -pedantic -Wall
MATHFLAG = -lm

PROGRS = PrimerTallerC_main

all: $(PROGRS)

PrimerTallerC_main:
	$(GCC) $(FLAGS) -c $@.c
	$(GCC) $(FLAGS) -c PrimerTallerC_lib.c
	$(GCC) $(FLAGS) -o $@ $@.o PrimerTallerC_lib.o $(MATHFLAG)
	

clean:
	$(RM) *.o $(PROGRS)
