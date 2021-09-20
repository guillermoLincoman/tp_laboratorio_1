/*
 * bibliotecaCalculadora.h
 *
 *  Created on: 18 sep. 2021
 *      Author: Compumar
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <unistd.h>
#include "menu.h"

#ifndef BIBLIOTECACALCULADORA_H_
#define BIBLIOTECACALCULADORA_H_
void limpiar();
int cargarUnEntero(char* mensaje, char* mensajeError,int rangoMin, int rangoMax, int intentos);
int validarLetra(char num[]);
int resta(int numUno, int numDos);
int suma(int numUno, int numDos);
float division(int numUno, int numDos);
int multiplicacion(int numUno, int numDos);
unsigned long factorial(int num);
#endif /* BIBLIOTECACALCULADORA_H_ */
