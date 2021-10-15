/*
 * informes.h
 *
 *  Created on: 15 oct. 2021
 *      Author: Compumar
 */
#include "ArrayEmployees.h"
#ifndef INFORMES_H_
#define INFORMES_H_

void eSort(Employee *prodUno, Employee *prodDos);
int sortEmployees(Employee list[], int len, int order);
float totalSalarios(Employee list[], int len);
float promSalario(Employee list[], int len, float totalSalario);
int cantSalarioPromedio(Employee list[], int len, float salarioProm);
#endif /* INFORMES_H_ */
