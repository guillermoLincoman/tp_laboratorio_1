/*
 ============================================================================
 Name        : TP_2_Lincoman.c
 Author      : Guillermo Lincoman
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "funcionesMenu.h"

int main()
{
    setbuf(stdout, NULL);
    int idProxEmpleado;
    int contEmpleado;
    int aux;
    int opcion;
    contEmpleado=0;
    idProxEmpleado=1000;
    Employee empleado[TE];
    aux= iniciar(empleado, TE);
    if(aux!=0){
    	printf("Error, no es posible iniciar el programa....");
    	return 0;
    }else{
        printf("Inicializando programa...\n");
        limpiar();
    }
    aux=-1;
    do
    {
        printf("*******************\n");
        printf("| 1. ALTA         |\n");
        printf("| 2. MODIFICAR    |\n");
        printf("| 3. BAJA TRABAJO |\n");
        printf("| 4. INFORMAR     |\n");
        printf("| 0. SALIR        |\n");
        printf("*******************\n");
        opcion=cargarUnEntero("Elija una opcion: ","Elija una opcion entre 0 y 4: ", 0, 4, 4);
        switch(opcion)
        {
            case 1:
                aux= agregarEmpleado(empleado, TE, idProxEmpleado);
            	if(aux==0){
            		idProxEmpleado++;
            		contEmpleado++;
                }
            	limpiar();
                break;
            case 2:
                if(contEmpleado>0)
                {
                	modiEmpleado(empleado, TE, idProxEmpleado);
                }else{
                    printf("\nNo puede modificar empleados sin antes cargar uno...\n");
                }
                limpiar();
                break;
            case 3:
                if(contEmpleado>0){
                    aux = eliminarEmpleado(empleado, TE, idProxEmpleado);
                    if(aux == 0){
                    	contEmpleado--;
                    }
                }else{
                    printf("\nNo puede eliminar empleados sin antes cargar uno...\n");
                }
                limpiar();
                break;
            case 4:
                if(contEmpleado>0)
                {
                	infoSortEmployee(empleado, TE);
                }else{
                    printf("\nSi no carga un empleado no puede realizar informes...\n");
                }
                limpiar();
                break;
        }
    }while(opcion!=0);

    return 0;
}
