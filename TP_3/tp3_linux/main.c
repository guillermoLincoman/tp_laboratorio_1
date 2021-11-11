#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "inputs.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);
	int opcion;
	int banderaLista;
	int bandearArchivoTexto;
	int bandearArchivoBinario;
	int aux;
	bandearArchivoTexto = 1;
	bandearArchivoBinario = 1;
	banderaLista = 1;
	LinkedList* listaEmpleados = ll_newLinkedList();

	do{
		menu();
		opcion = cargarUnEntero("Ingrese una opcion: ", "Error, ingrese una opcion", 0, 9, 4);
		switch(opcion)
		{
			case 1:
				aux = controller_loadFromText("data.csv", listaEmpleados);
				if(aux == 0)
				{
					printf("\n\nEl archivo de texto fue cargado correctamente....\n");
					banderaLista = 0;
					bandearArchivoTexto = 0;
					bandearArchivoBinario = 1;

				}else{
					printf("\n\nNo se encontro el archivo....\n");
				}
				limpiarLinux();
				break;
			case 2:
				aux = controller_loadFromBinary("data.bin", listaEmpleados);
				if(aux == 0)
				{
					printf("\n\nEl archivo binario fue cargado correctamente....\n");
					banderaLista = 0;
					bandearArchivoBinario = 0;
					bandearArchivoTexto = 1;

				}else{
					printf("\n\nNo se encontro el archivo....\n");
				}
				limpiarLinux();
				break;
			case 3:
				if(banderaLista == 0)
				{
				controller_addEmployee(listaEmpleados);
				banderaLista = 0;
				}else{
					printf("\n\nNo se cargar empleados sin crear un archivo primero....\n");
				}
				limpiarLinux();
				break;
			case 4:
				if(banderaLista == 0)
				{
					controller_editEmployee(listaEmpleados);
				}else{
					printf("\n\nNo se encuentran empleados cargados para editar....\n");
				}
				limpiarLinux();
				break;
			case 5:
				if(banderaLista == 0)
				{
					controller_removeEmployee(listaEmpleados);
				}else{
					printf("\n\nNo se encuentran empleados cargados para eliminar....\n");
				}
				limpiarLinux();

				break;
			case 6:
				if(banderaLista == 0)
				{
					controller_ListEmployee(listaEmpleados);
				}else{
					printf("\n\nNo se encuentran empleados cargados para mostrar....\n");
				}
				limpiarLinux();
				break;
			case 7:
				if(banderaLista == 0)
				{
					controller_sortEmployee(listaEmpleados);
				}else{
					printf("\n\nNo se encuentran empleados cargados para ordenar....\n");
				}
				limpiarLinux();
				break;
			case 8:
				if(bandearArchivoTexto == 0)
				{
					aux = controller_saveAsText("data.csv", listaEmpleados);
					if(aux == 0)
					{
						printf("\n\nEl archivo de texto fue guardado correctamente....\n");
					}else
					{
						printf("\n\nOcurrio un error al guardar el archivo de texto....\n");
					}
				}else{
					printf("\n\nNo se puede guardar un archivo de texto hasta no crear uno....\n");
				}
				limpiarLinux();
				break;
			case 9:
				if(bandearArchivoBinario == 0)
				{
					aux = controller_saveAsBinary("data.bin", listaEmpleados);
					if(aux == 0)
					{
						printf("\n\nEl archivo bin fue guardado correctamente....\n");
					}else
					{
						printf("\n\nOcurrio un error al guardar el archivo bin....\n");

					}
				}else{
					printf("\n\nNo se puede guardar un archivo binario hasta no crear uno....\n");
				}
				limpiarLinux();
				break;
		}
	}while(opcion != 0);

    return 0;
}

