#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "inputs.h"


/** \brief Menu Principal
 *
 */
void menu()
{
    printf("\n\n**********************************************************************************\n");
    printf("* MENU PRINCIPAL                                                                 *\n");
    printf("**********************************************************************************\n");
	printf("*                                                                                *\n");
    printf("* 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).   *\n");
    printf("* 2. Cargar los datos de los empleados desde el archivo data.bin (modo binario). *\n");
    printf("* 3. Alta de empleado                                                            *\n");
    printf("* 4. Modificar datos de empleado                                                 *\n");
    printf("* 5. Baja de empleado                                                            *\n");
    printf("* 6. Listar empleados                                                            *\n");
    printf("* 7. Ordenar empleados                                                           *\n");
    printf("* 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).     *\n");
    printf("* 9. Guardar los datos de los empleados en el archivo data.bin (modo binario).   *\n");
    printf("* 0. Salir                                                                       *\n");
    printf("*********************************************************************************\n\n");
}

/** \brief Menu Modificar
 *
 */
void menuModificar()
{

	printf("\n************************************\n");
	printf("* MENU MODIFICAR                   *\n");
	printf("************************************\n");
	printf("* Seleccione el campo a modificar  *\n");
	printf("*                                  *\n");
    printf("* 1. NOMBRE                        *\n");
    printf("* 2. HORAS TRABAJADAS              *\n");
    printf("* 3. SUELDO                        *\n");
    printf("* 0. Volver al menu principal      *\n");
    printf("************************************\n\n");
}

/** \brief Menu Ordenamiento
 *
 */
void menuOrden()
{

	printf("\n**************************************\n");
	printf("* MENU ORDENAMIENTO                  *\n");
	printf("**************************************\n");
	printf("* Seleccione el criterio a ordenar   *\n");
	printf("*                                    *\n");
    printf("* 1. ID                              *\n");
    printf("* 2. NOMBRE                          *\n");
    printf("* 3. SUELDO                          *\n");
    printf("* 4. HORAS TRABAJADAS                *\n");
    printf("* 0. Volver al menu principal        *\n");
    printf("**************************************\n\n");
}

/** \brief Menu Criterio
 *
 */
void menuOrdenCriterio()
{

	printf("\n**********************************\n");
	printf("* MENU CRITERIO DE ORDENAMIENTO  *\n");
	printf("**********************************\n");
	printf("* Seleccione como ordena         *\n");
	printf("*                                *\n");
    printf("* 0. De mayor a menor            *\n");
    printf("* 1. De menor a mayor            *\n");
    printf("* 2. Volver al menu principal    *\n");
    printf("***********************************\n\n");
}



/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* = lista para mostrar
 *
 * \return int error = En caso de error retorna 1, si puede listar a los empleados retorna 0
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int error;
	int i;
	int len;
	Employee* newEmployee;
	newEmployee = employee_new();
	error = 1;

	if(newEmployee != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		if(len > 1)
		{
			error = 0;
			printf("\n __________________________________________________\n");
			printf("|   ID   |       NOMBRE       |  HORAS  |  SUELDO  |\n");
			printf("|________|____________________|_________|__________|\n");
			for (i = 0; i < len; ++i) {
				newEmployee = ll_get(pArrayListEmployee, i);
				employee_printEmployee(newEmployee);
			}

		}
	}else{
		employee_delete(newEmployee);
	}

    return error;
}



/** \brief Busca la posicion de un empleado segun el id
 *
 * \param pArrayListEmployee LinkedList* = lista para analizar
 * \param int id = id a buscar en la lista de empleados
 *
 * \return int ultimoId = Retorna el la posicion del empleado que coincide con el id,
 * 						  en caso de error retorna -1
 *
 */
int controller_buscarId(LinkedList* pArrayListEmployee, int id)
{
	int posError;
	int i;
	int len;
	Employee* empleadoId;
	posError = -1;
	if(pArrayListEmployee != NULL && id >= 0)
	{
		//1.Obtengo el tamaño de la lista
		len = ll_len(pArrayListEmployee);
		//2.Recorro la lista
		for (i = 0; i < len; ++i) {
			//3.Analizo empleado por empleado hasta encontrar el buscado
			empleadoId = ll_get(pArrayListEmployee, i);
			if(empleadoId != NULL)
			{
				//4 Obtengo el id del empleado
				employee_getId(empleadoId, &posError);
				//5.Valido si es el id que busco
				if(id==posError)
				{
					//6. Cargo el index del empleado buscado, libero memoria y rompo la condicion
					posError = i;
					break;
				}
			}
		}
	}

	return posError;
}



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* = Direccion del archivo
 * \param pArrayListEmployee LinkedList* = Lista donde se cargan los datos
 *
 * \return int error = Si los datos se cargan correctamente retorna 0, en caso de error retorna 1
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int error;
	FILE* pArchivo;
	error = 1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		printf("*-------------------------*\n");
		printf("| CARGAR ARCHIVO DE TEXTO |\n");
		printf("*-------------------------*");
		//1. Abro el archivo en modo escritura
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL)
		{
			//2. Si hay un error devuelve 1, si funciona retorna 0
			parser_EmployeeFromText(pArchivo, pArrayListEmployee);
			error = 0;
		}
		//3. Cierro el archivo
		fclose(pArchivo);
	}

    return error;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
  * \param path char* = Direccion del archivo
 * \param pArrayListEmployee LinkedList* = Lista donde se cargan los datos
 *
 * \return int error = Si los datos se cargan correctamente retorna 0, en caso de error retorna 1
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int error;
	FILE* pArchivo;
	error = 1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		printf("*------------------------*\n");
		printf("| CARGAR ARCHIVO BINARIO |\n");
		printf("*------------------------*");
		//1. Abro el archivo en modo escritura
		pArchivo = fopen(path, "rb");
		if(pArchivo != NULL)
		{
			//2. Si hay un error devuelve 1, si funciona retorna 0
			parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
			error = 0;
		}
		//3. Cierro el archivo
		fclose(pArchivo);
	}

    return error;
}

/** \brief Busca el ultimo Id cargado en la lista empleado
 *
 * \param pArrayListEmployee LinkedList* = lista para analizar
 *
 * \return int ultimoId = Retorna el ultimo id de la lista +1, en caso de error retorna -1
 * 						  en caso de que la lista no tenga ningun empleado la funcion devuelve 1 como el primer id
 *
 */
int controller_ultimoId(LinkedList* pArrayListEmployee)
{
	int ultimoId;
	int len;
	Employee* empleado;
	ultimoId = -2;//en caso de error retorna -1 ->retorno ultimoId +1

	if(pArrayListEmployee != NULL)
	{

		//1. obtengo el tamaño de la lista
		len = ll_len(pArrayListEmployee);
		if(len > 0)
		{
			//2. Obtengo el empleado que tiene el ultimo id
			empleado = ll_get(pArrayListEmployee, len-1);
			if(empleado != NULL)
			{

				employee_getId(empleado, &ultimoId);
			}
		}else{
			ultimoId = 0;
		}
	}
	//3. Retorno el id del ultimo empleado +1
	return ultimoId+1;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList* = lista donde se carga el empleado
 *
 * \return int error = Si carga al empleado retorna 0, en caso de error retorna 1
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* newEmployee;
	int error;
	int ultimoId;
	char nombre[124];
	int sueldo;
	int horas;
	int aux;
	int confirmar;
	error = 1;

	if(pArrayListEmployee != NULL)
	{
		newEmployee = employee_new();

		if(newEmployee != NULL)
		{
			printf("*----------------------*\n");
			printf("| CREAR NUEVO EMPLEADO |\n");
			printf("*----------------------*\n\n");
			ultimoId = controller_ultimoId(pArrayListEmployee);

			employee_setId(newEmployee, ultimoId);

			getUsuario(nombre, "Ingresar nombre: ", "Error, ingrese un nombre valido: ", 0, 125, 4);
			employee_setNombre(newEmployee, nombre);

			horas = cargarUnEntero("Ingrese las horas trabajadas: ", "Error, ingrese una cantidad de horas validas(entre 0 y 400)", 0, 400, 4);
			employee_setHorasTrabajadas(newEmployee, horas);

			sueldo = cargarUnEntero("Ingrese el sueldo: ", "Error, ingrese un sueldo valido (entre 10000 y 60000)", 10000, 60000, 4);
			employee_setSueldo(newEmployee, sueldo);
			limpiarLinux();
			employee_printOneEmployee(newEmployee);
			confirmar = cargarUnEntero("\nDesea cargar el nuevo empleado?(1.Si || 2.No):", "\nError,ingrese un numero valido?(1.Si || 2.No):", 1, 2, 4);
			if(confirmar == 1)
			{
				aux = ll_add(pArrayListEmployee, newEmployee);
				if(aux == 0)
				{
					printf("\nEmpleado cargado con exito....\n");
					error = 0;
				}else{
					printf("\nError al cargar Empleado....\n");
					employee_delete(newEmployee);
				}
			}else{
				printf("\nEl Empleado no fue cargado....\n");
			}
		}
	}

    return error;
}

/** \brief Modificar datos de empleado
 *
 *
 * \param pArrayListEmployee LinkedList* = lista donde se busca el empleado a modificar
 *
 * \return int error = Si modifica al empleado retorna 0, en caso de error retorna 1
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	char newNombre[124];
	int newSueldo;
	int newHoras;
	int idMod;
	int ultimoId;
	int pos;
	int error;
	int opcion;
	int confirmar;
	Employee* empleadoMod;
	error = 1;

	if(pArrayListEmployee != NULL)
	{
		printf("*--------------------*\n");
		printf("| MODIFICAR EMPLEADO |\n");
		printf("*--------------------*\n\n");
			//2. Muestro la lista de empleados
			controller_ListEmployee(pArrayListEmployee);
			puts("\n\n");

			//3.Obtengo el ultimo id para validar
			ultimoId = controller_ultimoId(pArrayListEmployee);

			//4.Obtengo el id del empleado a modificar
			idMod = cargarUnEntero("\n Ingrese el ID del empleado a modificar: ", "Error, ingrese un ID valido: ", 0, ultimoId-1, 4);

			//5. busco la posicion del empleado con el id ingresado por el usuario
			pos = controller_buscarId(pArrayListEmployee, idMod);

			//6. Apunto el puntero al empleado en la posicion encontrada
			empleadoMod =ll_get(pArrayListEmployee, pos);

			limpiarLinux();

			if(empleadoMod != NULL)
			{
				error = 0;
				do{
					employee_printOneEmployee(empleadoMod);
					menuModificar();
					opcion = cargarUnEntero("Ingrese una opcion: ", "Error, ingrese una opcion", 0, 3, 4);
					switch(opcion)
					{
						case 1:
							getUsuario(newNombre, "\nIngrese el nuevo nombre: ", "\nError, ingrese un nombre valido: ", 1, 124, 4);
							printf("\nEl nuevo nombre es %s\n", newNombre);
							confirmar = cargarUnEntero("\nDesea cargar el nuevo nombre?(1.Si || 2.No):", "\nError,ingrese un numero valido?(1.Si || 2.No):", 1, 2, 4);
							if(confirmar == 1)
							{
								employee_setNombre(empleadoMod, newNombre);
								printf("\nEl nombre fue moficado con exito...\n");
							}else{
								printf("\nEl nombre no fue moficado...\n");

							}
							break;
						case 2:
							newHoras = cargarUnEntero("\nIngrese las nuevas horas: ", "\nError, ingrese una cantidad de horas validas valido(entre 0 y 400): ", 0, 400, 4);
							printf("\nLa nueva cantidad de horas es $%d\n", newHoras);
							confirmar = cargarUnEntero("\nDesea cargar la nueva cantidad de horas?(1.Si || 2.No):", "\nError,ingrese un numero valido?(1.Si || 2.No):", 1, 2, 4);
							if(confirmar == 1)
							{
								employee_setHorasTrabajadas(empleadoMod, newHoras);
								printf("\nLa cantidad de horas fueron moficado con exito...\n");
							}else{
								printf("\nLa cantidad de horas no fueron moficado...\n");
							}
							break;
						case 3:
							newSueldo = cargarUnEntero("\nIngrese el nuevo sueldo:$ ", "\nError, ingrese un sueldo valido(entre 10000 y 60000):$ ", 10000, 60000, 4);
							printf("\nEl nuevo sueldo es $%d\n", newSueldo);
							confirmar = cargarUnEntero("\nDesea cargar el nuevo sueldo?(1.Si || 2.No):", "\nError,ingrese un numero valido?(1.Si || 2.No):", 1, 2, 4);
							if(confirmar == 1)
							{
								employee_setSueldo(empleadoMod, newSueldo);
								printf("\nEl sueldo fue moficado con exito...\n");
							}else{
								printf("\nEl sueldo no fue moficado...\n");
							}
							break;
					}
				}while(opcion != 0);
			}
	}
    return error;
}






/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* = lista que se va a clonar para odenar y mostrar
 *
 * \return int error = Si la lista se puede clonar retorna 0, en caso de error retorna 1
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int error;
	int opcion;
	int criterio;
	LinkedList* clone;
	error = 1;
	if(pArrayListEmployee != NULL)
	{
		clone = ll_clone(pArrayListEmployee);
		if(clone != NULL)
		{
			error=0;
			menuOrdenCriterio();
			criterio = cargarUnEntero("Selccione un criterio: ", "Error, seleccione un criterio valido: ", 0, 2, 4);
			do{
				limpiarLinux();
				menuOrden();
				opcion = cargarUnEntero("Selccione un orden: ", "Error, seleccione un orden valido: ", 0, 4, 4);
				printf("\nSu lista se esta ordenando, este proceso puede tardar unos segundos...\n");
				switch(opcion)
				{
					case 1:
						ll_sort(clone, employee_compareById,criterio);
						controller_ListEmployee(clone);
						printf("\nSu listado por ID fue ordenado con exito...\n");
						break;
					case 2:
						ll_sort(clone, employee_compareByName,criterio);
						controller_ListEmployee(clone);
						printf("\nSu listado por NOMBRE fue ordenado con exito...\n");
						break;
					case 3:
						ll_sort(clone, employee_compareBySueldo,criterio);
						controller_ListEmployee(clone);
						printf("\nSu listado por SUELDO fue ordenado con exito...\n");
						break;
					case 4:
						ll_sort(clone, employee_compareByHoras,criterio);
						controller_ListEmployee(clone);
						printf("\nSu listado por HORAS fue ordenado con exito...\n");
						break;
				}
			}while(opcion != 0);
		}
	}
    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* = Direccion del archivo
 * \param pArrayListEmployee LinkedList* = Lista donde se van a guardar los datos
 *
 * \return int error = Si los datos se guardan correctamente retorna 0, en caso de error retorna 1
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int id;
	char nombre[124];
	int sueldo;
	int horas;
	int len;
	int i;
	int error;
	Employee* newEmployee;
	FILE* pArchivo;
	error = 1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		printf("*--------------------------*\n");
		printf("| GUARDAR ARCHIVO DE TEXTO |\n");
		printf("*--------------------------*");
		//1. Abro el archivo en modo escritura
		pArchivo = fopen(path, "w");

		//2. Asigno espacio en memoria para el puntero a empleado
		newEmployee = employee_new();

		//3. Obtengo el tamaño de la lista
		len = ll_len(pArrayListEmployee);

		//4. Coloco la cabecera
		fprintf(pArchivo, "id,nombre,horasTrabajadas,sueldo\n");
		for(i=0; i<len;i++)
		{
			//5. obtengo el empleado con sus datos
			newEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			if(newEmployee != NULL)
			{
				//6. le paso los datos el empleado a las variables
				employee_getId(newEmployee, &id);
				employee_getNombre(newEmployee, nombre);
				employee_getHorasTrabajadas(newEmployee, &horas);
				employee_getSueldo(newEmployee, &sueldo);
				//7. Escribo los datos del empleado en el archivo
				fprintf(pArchivo, "%d,%s,%d,%d\n", id, nombre, horas, sueldo);
				error = 0;
			}else{
				error = 1;
				break;
			}
		}
		fclose(pArchivo);
	}

    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* = Direccion del archivo
 * \param pArrayListEmployee LinkedList* = Lista donde se van a guardar los datos
 *
 * \return int error = Si los datos se guardan correctamente retorna 0, en caso de error retorna 1
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int len;
	int i;
	int error;
	Employee* newEmpleado;
	FILE* pArchivo;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		printf("*-------------------------*\n");
		printf("| GUARDAR ARCHIVO BINARIO |\n");
		printf("*-------------------------*");
		//1. Abro el archivo en escritura binaria
		pArchivo = fopen(path, "wb");

		//2. Asigno espacio en memoria para el puntero a empleado
		newEmpleado = (Employee*) employee_new();

		if(newEmpleado != NULL)
		{
			//3. Obtengo el tamaño de la lista
			len = ll_len(pArrayListEmployee);
			for (i = 1; i < len; ++i) {
				//4. Obtengo uno a uno cada empleado a escribir
				newEmpleado = ll_get(pArrayListEmployee, i);
				//5. Escribo el empleado
				fwrite(newEmpleado, sizeof(Employee), 1, pArchivo);
			}
			error = 0;
		}
		//6. Cierro el archivo
		fclose(pArchivo);
	}

	return error;
}



/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* = lista donde se busca el empleado a dar de baja
 *
 * \return int error = Si baja al empleado retorna 0, en caso de error retorna 1
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

	int idBorrar;
	int ultimoId;
	int pos;
	int error;
	int confirmar;
	Employee* empleado;

	error = 1;

	if(pArrayListEmployee != NULL)
	{
		printf("*-------------------*\n");
		printf("| ELIMINAR EMPLEADO |\n");
		printf("*-------------------*");

		//2. Muestro la lista de empleados
		controller_ListEmployee(pArrayListEmployee);
		puts("\n\n");
		empleado = employee_new();

		//3.Obtengo el ultimo id para validar
		ultimoId = controller_ultimoId(pArrayListEmployee);

		//4.Obtengo el id del empleado a borrar
		idBorrar = cargarUnEntero("\n Ingrese el ID del empleado a Borrar: ", "Error, ingrese un ID valido: ", 0, ultimoId-1, 4);

		//5. busco la posicion del empleado con el id ingresado por el usuario
		pos = controller_buscarId(pArrayListEmployee, idBorrar);

		//6. Guardo el empleado en el puntero a empleado
		empleado = ll_get(pArrayListEmployee, pos);
		//7. Imprimo el empleado
		employee_printOneEmployee(empleado);
		confirmar = cargarUnEntero("\nDesea eliminar al empleado?(1.Si || 2.No):", "\nError, ingrese una opcion valida?(1.Si || 2.No):", 1, 2, 4);

		if(confirmar == 1)
		{
			ll_remove(pArrayListEmployee, pos);
			employee_delete(empleado);
			printf("\nEL empleado fue borrado con exito....\n");
			error = 0;
		}else{
			printf("\nEL empleado no fue borrado....\n");
		}
	}
    return error;
}

