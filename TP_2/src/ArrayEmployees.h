/*
 * ArrayEmployees.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Compumar
 */
#include "extras.h"
#define OCUPADO 0
#define VACIO -1
#define TE 1000

struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;


#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

int initEmployees(Employee list[], int len);
int BuscarLibre(Employee list[], int len);
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);
Employee addEmployeeNew(int idNuevoEmpleado);
void eSort(Employee *prodUno, Employee *prodDos);
int findEmployeeById(Employee list[], int len,int id);
void printEmployees(Employee list[], int len);
void printEmploye(Employee empleado);
int removeEmployee(Employee list[], int len, int ultimoId);
int sortEmployees(Employee list[], int len, int order);
int modificarEmpleado(Employee list[], int len, int ultimoId);
float totalSalarios(Employee list[], int len);
float promSalario(Employee list[], int len, float totalSalario);
int cantSalarioPromedio(Employee list[], int len, float salarioProm);


#endif /* ARRAYEMPLOYEES_H_ */
