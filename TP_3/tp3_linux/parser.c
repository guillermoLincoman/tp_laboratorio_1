#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int error;
	char id[60];
	char nombre[60];
	char horas[60];
	char sueldo[60];
	Employee* newEmployee;
	int aux;
	error = 1;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{

		//1. Cabecera del archivo
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, horas, sueldo);
		//2. Repito hasta llegar al final de archivo
		while(!feof(pFile))
		{

			//3. cuento que lea los datos necesarios y los cargo en aux
			aux =  fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, horas, sueldo);
			if(aux == 4)
			{
				//4. cargo los datos leidos en el empleado
				newEmployee = employee_newParametros(id, nombre, horas, sueldo);
				//5. valido que el empleado no sea nulo
				if(newEmployee!=NULL)
				{
					//6. en caso de cargar el empleado retorna 0
					aux = ll_add(pArrayListEmployee, newEmployee);
					if(aux != 0)
					{
						//7. Si retorna un numero diferente a 0 borro el empleado y rompo la condicion while
						employee_delete(newEmployee);
						error = 1;
						break;
					}else{
						error = 0;
					}
				}
			}else{
				break;
			}
		}

	}

    return error;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* newEmployee;
	int error;
	int aux;
	error  = 1;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{

		while(feof(pFile)==0)
		{	//1.inicializo el empleado
			newEmployee = employee_new();
			//2. cargo los datos
				fread(newEmployee, sizeof(Employee), 1, pFile);
				if(!feof(pFile))
				{
					//3. agrego al empleado
					aux = ll_add(pArrayListEmployee, newEmployee);
					if(aux != 0)
					{
						//4. Si retorna un numero diferente a 0 borro el empleado y rompo la condicion while
						employee_delete(newEmployee);
						error = 1;
						break;
					}else{
						error = 0;
					}
				}else{
					break;
				}

		}
	}


	return error;
}
