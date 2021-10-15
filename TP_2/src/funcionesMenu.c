/*
 * funcionesMenu.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Compumar
 */
#include "funcionesMenu.h"

/** \brief Inicia la estructura usada en el programa
 *
 * \param Employee list[] = Estructura de Empleados
 * \param int len = Tamaño de estructura Empleados
 *
 * \return Si se inicializa la estructura retorna 0, en caso de error retorna -1
 */
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

/** \brief Agrega un Empleado al programa
 *
 *	Carga en una estructura auxiliar una Empleado utilizando la funcion addEmployeeNew,
 *	con los datos obtenidos le da los datos a la funcion addEmployee en caso de cargar el Empleado
 *	imprime el nuevo Empleado
 *
 * \param eClient list[] = Estructura de Cliente
 * \param int len = Tamaño de estructura Cliente
 * \param int proxId = obtiene el id que se le va a dar al nuevo cliente
 *
 * \return Si se agrega un cliente retorna 0 en caso de error retorna -1
 */
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
            printf("__________________________________________________________________________\n");
            printf("  ID EMPLEADO   |  SECTOR  |   SALARIO   |     NOMBRE     |    APELLIDO   |\n");
        	printEmploye(auxEmpelado);
            error=0;
        }
    }
    return error;
}

/** \brief Modifica los datos de un Empleado del programa
 *
 * \param Employee list[] = Estructura de Empleado
 * \param int len = Tamaño de estructura Empleado
 * \param int ultimoId = ultimo id ingresado para validar
 *
 */
void modiEmpleado(Employee list[], int len, int ultimoId)
{
    int aux;
    aux=-1;
    if(list != NULL)
    {
    	aux = modificarEmpleado(list, len, ultimoId);
    	if(aux==-1){
    		printf("\nError, al modificar empleado...\n");
    	}
    }
}

/** \brief Elimina los datos de un Empleado del programa
 *
 * \param Employee list[] = Estructura de Empleado
 * \param int len = Tamaño de estructura Empleado
 * \param int ultimoId = ultimo id ingresado para validar
 *
 */
int eliminarEmpleado(Employee list[], int len, int ultimoId)
{
    int aux;
    aux=-1;
    if(list != NULL)
    {
    	aux = removeEmployee(list, len, ultimoId);
    	if(aux==-1){
    		printf("\nError, al eliminar empleado...\n");
    	}
    }
    return aux;
}

/** \brief Informes con los datos del programa
 *
 *	Muestra un menu con informes del programa.
 *
 *
 * \param eClient clientes[] = Estructura de Cliente
 * \param int lenCliente = Tamaño de estructura Cliente
 *
 */
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
