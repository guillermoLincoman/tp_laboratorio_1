/*
 * funcionesMenu.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Compumar
 */
#include "funcionesMenu.h"

int iniciar(Employee list[], int len)
{
    int aux;
    int error;
    error=-1;
    aux=initEmployees(list, len);
    if(aux==0){
        error=0;
    }
    return error;
}

int agregarEmpleado(Employee list[], int len, int proxId)
{
    int aux;
    int error;
    error=-1;
    Employee auxEmpelado;
    if(list != NULL)
    {
        auxEmpelado = addEmployeeNew(proxId);
        aux=addEmployee(list, len, auxEmpelado.id, auxEmpelado.name, auxEmpelado.lastName, auxEmpelado.salary, auxEmpelado.sector);
        if(aux==0){
            printf("\nEmpleado registrado con exito...\n");
            error=0;
        }
    }
    return error;
}

void modiEmpleado(Employee list[], int len, int ultimoId)
{
    int aux;
    if(list != NULL)
    {
    	aux = modificarEmpleado(list, len, ultimoId);
    	if(aux==-1){
    		printf("\nError, al modificar empleado...\n");
    	}
    }
}

void eliminarEmpleado(Employee list[], int len, int ultimoId)
{
    int aux;
    if(list != NULL)
    {
    	aux = removeEmployee(list, len, ultimoId);
    	if(aux==-1){
    		printf("\nError, al eliminar empleado...\n");
    	}
    }
}

void infoSortEmployee(Employee list[], int len)
{
	int criterio;
	int opcion;
	float salarios;
	float salarioPromedio;
	int cantEmpleadosSalarioPromedio;
	if(list != NULL)
	{
        printf("_________________________________________________________________________________________\n");
        printf("| 1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.           |\n");
        printf("| 2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.  |\n");
        printf("| 0. VOLVER AL MENU                                                                      |\n");
        printf("|________________________________________________________________________________________|\n");
        opcion= cargarUnEntero("\nElija una opcion: ", "\nError, elija una opcion entre 1 o 2: ", 0, 2, 4);

        switch(opcion)
        {
        	case 1:
        		criterio = cargarUnEntero("\nComo desea ordernar? 1 UP / 2 DOWN: ","\nError, elija 1 para UP y 2 para DOWN: ", 1, 2, 4);
        		sortEmployees(list, len, criterio);
        		printEmployees(list, len);
        		break;
        	case 2:
        		salarios = totalSalarios(list, len);
        		salarioPromedio = promSalario(list, len, salarios);
        		cantEmpleadosSalarioPromedio = cantSalarioPromedio(list, len, salarioPromedio);
        	    printf("\n\nEl total de los salarios es: $%.2f", salarios);
        		printf("\nEl promedio de los salarios es: $%.2f", salarioPromedio);
        		printf("\nLa cantidad de empleados que superan el salario promedio son: %d \n", cantEmpleadosSalarioPromedio);
        	    break;
        }

	}
}
