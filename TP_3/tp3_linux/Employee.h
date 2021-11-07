#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_compareByName(void* emp1, void* emp2);
int employee_compareById(void* emp1, void* emp2);
int employee_compareBySueldo(void* emp1, void* emp2);
int employee_compareByHoras(void* emp1, void* emp2);
void employee_printOneEmployee(Employee* this);
void employee_printEmployee(Employee* this);
#endif // employee_H_INCLUDED
