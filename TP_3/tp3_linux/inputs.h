/*
 * inputs.h
 *
 *  Created on: 4 nov. 2021
 *      Author: guillermolincoman
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <stdio_ext.h>
#include <curses.h>
#include <ncurses.h>
#include <ncurses_dll.h>

#ifndef INPUTS_H_
#define INPUTS_H_

void limpiar();
void limpiarLinux();
int validarLetra(char num[]);
void cadenaMinuscula(char * cadena);
int cargarUnEntero(char* mensaje, char* mensajeError,int rangoMin, int rangoMax, int intentos);
float cargarUnFloat(char* mensaje, char* mensajeError,int rangoMin, int rangoMax, int intentos);
int getUsuario(char *guardar, char *mensaje, char *mensajeError, int rangoMin, int rangoMax, int intentos);
int getString(char *guardar, char *mensaje, char *mensajeError, int rangoMin, int rangoMax, int intentos);

#endif /* INPUTS_H_ */
