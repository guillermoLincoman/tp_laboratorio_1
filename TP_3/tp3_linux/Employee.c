#include "Employee.h"


/** \brief Inicializa un nuevo empleado
 *
 *
 * \return Retorna un empleado con sus campos inicializados
  */
Employee* employee_new()
{
	Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
	//inicializo las variables
	employee_setId(newEmployee, 0);
	employee_setNombre(newEmployee, " ");
	employee_setSueldo(newEmployee, 0);
	employee_setHorasTrabajadas(newEmployee, 0);
	return newEmployee;
}

/** \brief Carga un empleado con parametros recibidos
 *
 * \param char* idStr = id a cargar en la estructura.
 * \param char* nombreStr = nombre a cargar en la estructura.
 * \param char* horasTrabajadasStr = horas trabajadas a cargar en la estructura.
 * \param char* sueldoStr = sueldo a cargar en la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se cargo correctamente
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* employee =employee_new();
	employee_setId(employee, atoi(idStr));
	employee_setNombre(employee, nombreStr);
	employee_setSueldo(employee, atoi(sueldoStr));
	employee_setHorasTrabajadas(employee, atoi(horasTrabajadasStr));
	return employee;
}

/** \brief Borra un empleado de la estructura
 *
 * \param Employee* this = puntero a estructura de empleados
 *
 */
void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/** \brief Carga un id en el campo de la estructura empleado
 *
 * \param Employee* this = puntero a estructura de empleados
 * \param int id = id a cargar en la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se cargo correctamente
 */
int employee_setId(Employee* this,int id)
{
	int error;
	error = 0;
	if(this != NULL && id >= 0)
	{
		this->id = id;
		error = 1;
	}
	return error;
}

/** \brief Obtiene un id del campo de una estructura empleado
 *
 * \param Employee* this = puntero a estructura de empleados
 * \param int* id = id obtenido de la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se cargo correctamente
 */
int employee_getId(Employee* this,int* id)
{
	int error;
	error = 1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		error = 0;
	}
	return error;
}

/** \brief Carga un nombre en el campo de la estructura empleado
 *
 * \param Employee* this = puntero a estructura de empleados
 * \param char* nombre = nombre a cargar en la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el id correctamente
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int error;
	error=1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(this->nombre, nombre, 124);
		error = 0;
	}
	return error;
}

/** \brief Obtiene un nombre del campo de una estructura empleado
 *
 * \param Employee* this = puntero a estructura de empleados
 * \param int* id = nombre obtenido de la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se obtuvo el nombre correctamente
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int error;
	error=1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre, this->nombre,124);
		error = 0;
	}
	return error;
}

/** \brief Carga las horas trabajadas en el campo de la estructura de un empleado
 *
 * \param Employee* this = puntero a estructura de empleados
 * \param horasTrabajadas = horas Trabajadas a cargar en la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se cargo correctamente
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int error;
	error = 0;
	if(this != NULL && horasTrabajadas >= 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		error = 1;
	}
	return error;
}

/** \brief Obtiene las horas trabajadas del campo de una estructura de un empleado
 *
 * \param Employee* this = puntero a estructura de empleados
 * \param int* horasTrabajadas = horas Trabajadas obtenidas de la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se cargo correctamente
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int error;
	error = 1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		error = 0;
	}
	return error;
}

/** \brief Carga el sueldo en el campo de la estructura de un empleado
 *
 * \param Employee* this = puntero a estructura de empleados
 * \param int sueldo = sueldo a cargar en la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se cargo correctamente
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int error;
	error = 0;
	if(this != NULL && sueldo >= 0)
	{
		this->sueldo = sueldo;
		error = 1;
	}
	return error;
}

/** \brief Obtiene el sueldo del campo de una estructura de un empleado
 *
 * \param Employee* this = puntero a estructura de empleados
 * \param int* horasTrabajadas = sueldo obtenido de la estructura.
 *
 * \return Devuelve 1 si hay un error y 0 si se cargo correctamente
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int error;
	error = 1;
	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		error = 0;
	}
	return error;
}

/** \brief Compara empleados segun el nombre
 *
 * \param void* emp1 = puntero a nombre Uno
 * \param void* emp2 = puntero a nombre Dos
 *
 * \return Retorna 1 si compara de mayor a menor
 * 		   Retorna -1 si compara de menor a mayor
 */
int employee_compareByName(void* emp1, void* emp2)
{
	int retorno;
	char nombreUno[124];
	char nombreDos[124];
	Employee* unEmpleado;
	Employee* otroEmpleado;

	unEmpleado = (Employee*) emp1;
	otroEmpleado = (Employee*) emp2;

	if(unEmpleado != NULL && otroEmpleado != NULL)
	{
		employee_getNombre(unEmpleado, nombreUno);
		employee_getNombre(otroEmpleado, nombreDos);
		if(strcmp(nombreUno, nombreDos)<0)
		{
			retorno = 1;
		}else{
			if(strcmp(nombreUno, nombreDos)>0)
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

/** \brief Compara empleados segun el ID
 *
 * \param void* emp1 = puntero a ID Uno
 * \param void* emp2 = puntero a ID Dos
 *
 * \return Retorna 1 si compara de mayor a menor
 * 		   Retorna -1 si compara de menor a mayor
 */
int employee_compareById(void* emp1, void* emp2)
{
	int retorno;
	int idUno;
	int idDos;
	retorno = 0;
	Employee* unEmpleado;
	Employee* otroEmpleado;

	unEmpleado = (Employee*) emp1;
	otroEmpleado = (Employee*) emp2;
	if(unEmpleado != NULL && otroEmpleado != NULL)
	{
		employee_getId(unEmpleado, &idUno);
		employee_getId(otroEmpleado, &idDos);
		if(idUno > idDos){
			retorno=1;
		}else{
			if(idUno < idDos){
				retorno = -1;
			}
		}
	}

	return retorno;
}

/** \brief Compara empleados segun el sueldo
 *
 * \param void* emp1 = puntero a sueldo Uno
 * \param void* emp2 = puntero a sueldo Dos
 *
 * \return Retorna 1 si compara de mayor a menor
 * 		   Retorna -1 si compara de menor a mayor
 */
int employee_compareBySueldo(void* emp1, void* emp2)
{
	int retorno;
	int sueldoUno;
	int sueldoDos;
	retorno = 0;
	Employee* unEmpleado;
	Employee* otroEmpleado;

	unEmpleado = (Employee*) emp1;
	otroEmpleado = (Employee*) emp2;
	if(unEmpleado != NULL && otroEmpleado != NULL)
	{
		employee_getSueldo(unEmpleado, &sueldoUno);
		employee_getSueldo(otroEmpleado, &sueldoDos);
		if(sueldoUno > sueldoDos){
			retorno=1;
		}else{
			if(sueldoUno < sueldoDos){
				retorno = -1;
			}
		}
	}

	return retorno;
}

/** \brief Compara empleados segun el horas
 *
 * \param void* emp1 = puntero a horas Uno
 * \param void* emp2 = puntero a horas Dos
 *
 * \return Retorna 1 si compara de mayor a menor
 * 		   Retorna -1 si compara de menor a mayor
 */
int employee_compareByHoras(void* emp1, void* emp2)
{
	int retorno;
	int horasUno;
	int horasDos;
	retorno = 0;
	Employee* unEmpleado;
	Employee* otroEmpleado;

	unEmpleado = (Employee*) emp1;
	otroEmpleado = (Employee*) emp2;
	if(unEmpleado != NULL && otroEmpleado != NULL)
	{
		employee_getHorasTrabajadas(unEmpleado, &horasUno);
		employee_getHorasTrabajadas(otroEmpleado, &horasDos);
		if(horasUno > horasDos){
			retorno=1;
		}else{
			if(horasUno < horasDos){
				retorno = -1;
			}
		}
	}

	return retorno;
}

/** \brief Imprime un empleado con cabecera incluida
 *
 * \param Employee* this = puntero a empleado que se va a mostrar
 *
 */
void employee_printOneEmployee(Employee* this)
{
	int idN;
	char nombre[124];
	int horas;
	int sueldo;
	if(this != NULL )
	{
		employee_getId(this, &idN);
		employee_getNombre(this, nombre);
		employee_getHorasTrabajadas(this, &horas);
		employee_getSueldo(this, &sueldo);
		printf("\n __________________________________________________\n");
		printf("|   ID   |       NOMBRE       |  HORAS  |  SUELDO  |\n");
		printf("|________|____________________|_________|__________|\n");
		printf("|  %4d  | %18s |%9d|%10d|\n", idN, nombre, horas, sueldo);
		printf("*--------------------------------------------------*\n");

	}
}

/** \brief Imprime un empleado sin cabecera, Complementaria de funcion controller_ListEmployee
 *
 * \param Employee* this = puntero a empleado que se va a mostrar
 *
 */
void employee_printEmployee(Employee* this)
{
	int idN;
	char nombre[124];
	int horas;
	int sueldo;
	if(this != NULL )
	{
		employee_getId(this, &idN);
		employee_getNombre(this, nombre);
		employee_getHorasTrabajadas(this, &horas);
		employee_getSueldo(this, &sueldo);
		printf("|  %4d  | %18s |%9d|%10d|\n", idN, nombre, horas, sueldo);
		printf("*--------------------------------------------------*\n");

	}
}
