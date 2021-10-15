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
void printEmployees(Employee list[], int len);
void printEmploye(Employee empleado);
int findEmployeeById(Employee list[], int len,int id);
int removeEmployee(Employee list[], int len, int ultimoId);
int modificarEmpleado(Employee list[], int len, int ultimoId);



#endif /* ARRAYEMPLOYEES_H_ */
