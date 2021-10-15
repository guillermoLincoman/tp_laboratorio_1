/*
 * informes.c
 *
 *  Created on: 15 oct. 2021
 *      Author: Compumar
 */
#include "informes.h"


/** \brief Intercambia los valores en una estrucutra
 *
 *	Muestra un menu con informes del programa.
 *
 * \param Employee *prodUno = Datos de la primera posicion
 * \param Employee *prodDos = Datos de la segunda posicion
 *
 */
void eSort(Employee *prodUno, Employee *prodDos)
{
	Employee prodAux;

	prodAux = *prodUno;
	*prodUno = *prodDos;
	*prodDos = prodAux;
}

/** \brief Orena los elementos de la estructura por el apellido y el sector
 * el ordenamiento tiene un criterio de UP / DOWN
 *
 * \param Employee list[] = estructura de empleados
 * \param len = tamaño de estructura empleados.
 * \param int order [1] indica UP - [0] indica DOWN
 *
 * \return Devuelve -1 si hay un error y 0 si ordeno correctamente
 */
int sortEmployees(Employee list[], int len, int order)
{
	int error;
	int i;
	int j;
	error = -1;

	if(list != NULL)
	{
		for (i = 0; i < len-1; ++i) {
			for (j = i+1; j < len; ++j) {
				if(order==1){
					error= 0;
					if(list[i].sector<list[j].sector){
						eSort(&list[i], &list[j]);
					}else{
						if(list[i].sector==list[j].sector){
							if(strcmp(list[i].lastName, list[j].lastName)>0){
								eSort(&list[i], &list[j]);
							}
						}
					}
				}else{
					error= 0;
					if(list[i].sector>list[j].sector){
						eSort(&list[i], &list[j]);
					}else{
						if(list[i].sector==list[j].sector){
							if(strcmp(list[i].lastName, list[j].lastName)<0){
								eSort(&list[i], &list[j]);
							}
						}
					}
				}
			}
		}
	}


	return error;
}

/** \brief Obtiene el total de todos los salarios cargados en una estructura
 *
 * \param Employee list[] = Estructura de empleados
 * \param len = tamaño de Estructura Empleados.
 *
 * \return Devuelve -1 si hay error y el total de los salarios si se realizo la operacion
 */
float totalSalarios(Employee list[], int len)
{
	int i;
	float acumSalarios;
	acumSalarios = -1;
	if(list != NULL)
	{
		acumSalarios = 0;
		for (i = 0; i < len; ++i){
			if(list[i].isEmpty == OCUPADO){
				acumSalarios = acumSalarios + list[i].salary;
			}
		}
	}
	return acumSalarios;
}

/** \brief Obtiene el promedio de un monton
 *
 * \param Employee list[] = Estructura de empleados
 * \param len = tamaño de Estructura Empleados.
 * \param float totalSalario = monto a promediar
 *
 * \return Devuelve -1 si hay error y el total de los salarios si se realizo la operacion
 */
float promSalario(Employee list[], int len, float totalSalario)
{
	int i;
	int contEmpleados;
	float salarioProm;
	contEmpleados = 0;
	if(list != NULL)
	{
		for (i = 0; i < len; ++i){
			if(list[i].isEmpty == OCUPADO){
				contEmpleados++;
			}
		}
		salarioProm = totalSalario/contEmpleados;
	}
	return salarioProm;
}

/** \brief Cantidad de empleados que superan el promedio
 *
 * \param Employee list[] = Estructura de empleados
 * \param len = tamaño de Estructura Empleados.
 * \param float salarioProm = Salario promedio a superar por empleados
 *
 * \return Devuelve -1 si hay error y la cantidad de empledados que superan el salario promedio en caso de funcionar
 */
int cantSalarioPromedio(Employee list[], int len, float salarioProm)
{
	int i;
	int contEmpleados;
	contEmpleados = -1;
	if(list != NULL)
	{
		contEmpleados = 0;
		for (i = 0; i < len; ++i){
			if(list[i].salary > salarioProm){
				contEmpleados++;
			}
		}
	}
	return contEmpleados;
}
