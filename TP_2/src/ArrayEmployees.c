/*
 * ArrayEmployees.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Compumar
 */
#include "ArrayEmployees.h"


/** \brief Indica que todas las posiciones de la estructura estan vacias,
 * Inicializa isEmpty en VACIO (-1)
 * en todas las posiciones de la estructura.
 * \param estructura eEmpleado.
 * \param tamaño de la estructura eEmpleado.
 * \return Devuelve -1 si hay un error y 0 si no hay errores.
 */
int initEmployees(Employee list[], int len)
{
	int i;
	int error;
	error =-1;
	if(list!=NULL)
	{
		for (i = 0; i < len; ++i) {
			list[i].isEmpty = VACIO;
			error = 0;
		}
	}
 return error;
}

/** \brief Busca un lugar libre en la estructura,
 * Busca dentro de la estructura un indice
 * en cual la variable isEmpty se igual a VACIO
 * \param list = estructura Employee.
 * \param len = tamaño de la estructura Employee.
 * \return devuelve un indice vacio, en caso de error devuelve -1
 */
int BuscarLibre(Employee list[], int len)
{
	int i;
	int index;
	index = -1;
	if(list != NULL)
	{
		for(i=0;i<len; i++){
			if(list[i].isEmpty==VACIO){
				index = i;
				break;
			}
		}
	}
	return index;
}

/** \brief Pide la funcion buscarLibre para encontrar un lugar vacio
 * y la funcion addEmployeeNew para agregar un nuevo empleado.
 * \param eEmpleado empleado[]
 * \param tamaño de empleados[], tEmpleado.
 * \param int idNuevoEmpleado id del nuevo empleado a cargar
 * \return Devuelve -1 si hay un error y 0 si se cargo el empleado
*/
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector)
{
	int error;
	int index;
	error= -1;
	if(list != NULL)
	{
		index= BuscarLibre(list, len);
		error=0;
		if(index!=-1){
			list[index].id=id;
			strcpy(list[index].name, name);
			strcpy(list[index].lastName, lastName);
			list[index].salary=salary;
			list[index].sector=sector;
			list[index].isEmpty=OCUPADO;
		}else{
			printf("\nNo hay lugar disponible....\n\n");
		}
	}
	return error;
}

/** \brief Agrega a un estructura auxiliar los valores ingresados por el usuario
 * \param int idNuevoEmpleado id del nuevo empleado a cargar
 * \return Devuelve  una estructura cargada con los datos ingresados por el usuario
*/
Employee addEmployeeNew(int idNuevoEmpleado)
{
	Employee empleadoNuevo;
    empleadoNuevo.id = idNuevoEmpleado;
    getUsuario(empleadoNuevo.name, "\nNOMBRE: ", "\nError ingrese un nombre valido (max 30 caracteres): ", 1, 30, 4);
    getUsuario(empleadoNuevo.lastName, "\nAPELLIDO: ", "\nError ingrese un apellido valido (max 30 caracteres): ", 1, 30, 4);
    empleadoNuevo.salary = cargarUnEntero("\nIngrese el SALARIO:$", "\nError, ingrese un salario valido(entre $30000 y $90000): ", 30000 , 90000, 4);
    empleadoNuevo.sector = cargarUnEntero("\nIngrese el SECTOR: ", "\nError, ingrese un SECTOR valido(entre 1 y 4): ", 1 , 4, 4);
    empleadoNuevo.isEmpty = OCUPADO;

    return empleadoNuevo;
}


/** \brief Busca un empleado por Id e indica en que posicion se encuentra
 *
 * \param Employee list[] = estructura de empleados
 * \param len = tamaño de empleados[], tEmpleado.
 * \param id = id del empleado buscado
 * \return devuelve la posicion en la que se encuentra el empleado buscado
 * \en caso de error devuelve -1
 */
int findEmployeeById(Employee list[], int len,int id)
{
	int i;
 	int index;
 	index=-1;
 	if(list != NULL)
 	{
 		for (i = 0; i < len; ++i) {
			if(list[i].isEmpty == OCUPADO){
				if(list[i].id == id){
					index = i;
				}
			}
		}
 	}
 	return index;
}
/** \brief Muestra el contenido en la estructura de empleados
 *
 * \param Employee list[] = estructura de empleados
 * \param len = tamaño de estructura empleados.

 */
void printEmployees(Employee list[], int len)
{
    int i;
    int banderaMostar;
    banderaMostar=0;
    printf("\n__________________________________________________________________________\n");
    printf("                             LISTADO DE EMPLEADOS                         |");
    printf("\n__________________________________________________________________________|\n");
    printf("  ID EMPLEADO   |  SECTOR  |   SALARIO   |     NOMBRE     |    APELLIDO   |\n");
    printf("________________|__________|_____________|________________|_______________|\n");
    for(i=0; i<len; i++)
    {
    	if(list[i].isEmpty == OCUPADO)
    	{
    		printEmploye(list[i]);
    		 banderaMostar=1;
    	}
    }
    //al terminar las puerbas eliminar este IF ********************%%%%%%*&&&*&*%&
    if(banderaMostar==0)
    {
        printf("\nNo hay EMPLEADO para mostrar...\n");
    }
}
/** \brief Muestra el contenido de un empleado
 *
 * \param Employee list[] = estructura de empleados

 */
void printEmploye(Employee empleado)
{
    printf("--------------------------------------------------------------------------\n");
    printf("         %4.4d   |  %4.d    |  $%5.2f  |%15s |%15s \n", empleado.id, empleado.sector, empleado.salary, empleado.name, empleado.lastName);
    printf("--------------------------------------------------------------------------\n");
}

/** \brief Elimina un empleado por ID
 *
 * \param Employee list[] = estructura de empleados
 * \param len = tamaño de estructura empleados.
 * \param ultimoId = ultimo id ingresado para validar el maximo de id que se puede ingresar
 *
 * \return Devuelve -1 si hay un error y 0 si se elimino el empleado
 */
int removeEmployee(Employee list[], int len, int ultimoId)
{
	int error;
	int i;
	int idIngresado;
	error= -1;
	if(list != NULL)
	{
		printEmployees(list, len);
		idIngresado= cargarUnEntero("Ingrese el id a eliminar: ", "Error, ingrese un id valido: ", 1000, ultimoId-1, 4);
		i = findEmployeeById(list, len, idIngresado);
		if(i != -1){
			list[i].isEmpty=VACIO;
			list[i].salary=0;
			list[i].sector=0;
			strcpy(list[i].name, " ");
			strcpy(list[i].lastName, " ");
	        printf("\nEl EMPLEADO fue borrado con exito....\n\n");
			error=0;
		}
	}
	return error;
}

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

int modificarEmpleado(Employee list[], int len, int ultimoId)
{
    int auxId;
    int opcion;
    int index;
    int error;
    error=-1;
    if(list != NULL)
    {
        printEmployees(list, len);
        printf("--------------------------------------------------------------------------\n");
        auxId=cargarUnEntero("Ingrese el ID del EMPLEADO que quiere modificar: ", "\nError, ingrese un id entre 1000 y 2000 ", 1000,ultimoId-1, 4);
        index= findEmployeeById(list, len, auxId);
        if(index!=-1)
        {
        	limpiar();
            error=0;
            printf("  ID EMPLEADO   |  SECTOR  |   SALARIO   |     NOMBRE     |    APELLIDO   |\n");
            printEmploye(list[index]);
            printf("________________________\n");
            printf("| Que desea modificar? |\n");
            printf("| 1. NOMBRE            |\n");
            printf("| 2. APELLIDO          |\n");
            printf("| 3. SALARIO           |\n");
            printf("| 4. SECTOR            |\n");
            printf("| 0. VOLVER AL MENU    |\n");
            printf("|______________________|\n");
            opcion=cargarUnEntero("\nElija una opcion: ", "\nError, elija una opcion entre 1 o 4: ", 0, 4, 4);

            switch(opcion)
            {
            	case 1:
            		getUsuario(list[index].name, "Ingrese el nuevo NOMBRE: \n", "\nError, ingrese un nombre valido (max 30 caracteres): ", 1, 30, 4);
                    printf("\n El NOMBRE fue modificada con exito...\n");
                    break;
                case 2:
            		getUsuario(list[index].lastName, "Ingrese el nuevo APELLIDO: \n", "\nError, ingrese un APELLIDO valido (max 30 caracteres): ", 1, 30, 4);
                    printf("\n El APELLIDO fue modificada con exito...\n");
                    error=0;
                    break;
                case 3:
                	list[index].salary=cargarUnEntero("Ingrese el SALARIO: \n","Error, ingrese un salario entre 20000 y 99999: \n",20000, 99999, 4);
                    printf("\n El SALARIO fue modificada con exito...\n");
                    break;
                case 4:
                	list[index].sector=cargarUnEntero("Ingrese el SECTOR: \n","Error, ingrese un sector entre 1 y 4: \n",1, 4, 4);
                    printf("\n El SECTOR fue modificada con exito...\n");
                    break;
            }
        }
    }
    return error;
}

float totalSalarios(Employee list[], int len)
{
	int i;
	float acumSalarios;
	acumSalarios = 0;
	if(list != NULL)
	{
		for (i = 0; i < len; ++i){
			if(list[i].isEmpty == OCUPADO){
				acumSalarios = acumSalarios + list[i].salary;
			}
		}
	}
	return acumSalarios;
}
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

int cantSalarioPromedio(Employee list[], int len, float salarioProm)
{
	int i;
	int contEmpleados;
	contEmpleados = 0;
	if(list != NULL)
	{
		for (i = 0; i < len; ++i){
			if(list[i].salary > salarioProm){
				contEmpleados++;
			}
		}
	}
	return contEmpleados;
}
