/*
 * funcionesMenu.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Compumar
 */
#include "ArrayEmployees.h"
#ifndef FUNCIONESMENU_H_
#define FUNCIONESMENU_H_

int iniciar(Employee list[], int len);
int agregarEmpleado(Employee list[], int len, int proxId);
void modiEmpleado(Employee list[], int len, int ultimoId);
void eliminarEmpleado(Employee list[], int len, int ultimoId);
void infoSortEmployee(Employee list[], int len);
#endif /* FUNCIONESMENU_H_ */
