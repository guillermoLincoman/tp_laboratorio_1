/*
 ============================================================================
 Name        : tpCalculadoraLincoman.c
 Author      : Guillermo Lincoman
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "bibliotecaCalculadora.h"
int main()
{
	setbuf(stdout, NULL);
	int numUno;
	int numDos;
	int opcion;
    int resSuma;
    int resResta;
    int resMultiplicacion;
    float resDivision;
    int resFactorialUno;
    int resFactorialDos;
    int band;
    band = 1;
    inicio();
    numUno = cargarUnEntero("Ingresar 1er operando: ", "Error, ingrese un numero: ", -2147483647, 2147483647, 4);
    numDos = cargarUnEntero("Ingresar 2do operando: ", "Error, ingrese un numero: ", -2147483647, 2147483647, 4);
    limpiar();
    do{
    	menuPrincipalNum(numUno, numDos);
    	opcion = cargarUnEntero("\nIngrese una opcion: ", "\nIngrese una opcion dentro del rango: ", 1, 5, 4);
        switch(opcion)
        {
            case 1:
            	numUno = cargarUnEntero("Ingresar 1er operando: ", "Error, ingrese un numero: ", -2147483647, 2147483647, 4);
            	band = 1;
            	limpiar();
                break;
            case 2:
                numDos = cargarUnEntero("Ingresar 2do operando: ", "Error, ingrese un numero: ", -2147483647, 2147483647, 4);
                band = 1;
            	limpiar();
            	break;
            case 3:
            	band = 0;
            	printf("\n\nCalculando operaciones....\n\n");
            	printf("a) Calcular la suma (%d+%d)\n", numUno, numDos);
            	resSuma = suma(numUno, numDos);
            	printf("b) Calcular la resta (%d-%d)\n", numUno, numDos);
                resResta = resta(numUno, numDos);
            	printf("c) Calcular la division (%d/%d)\n", numUno, numDos);
            	if(numDos != 0){
            		resDivision = division(numUno, numDos);
            	}
            	printf("d) Calcular la multiplicacion (%d*%d)\n", numUno, numDos);
            	resMultiplicacion = multiplicacion(numUno, numDos);
            	printf("e) Calcular el factorial de %d\n", numUno);
            	if(numUno < 0){
            		resFactorialUno = factorial(numUno);
            	}
            	printf("e) Calcular el factorial de %d\n", numDos);
            	if(numDos < 0){
            		resFactorialUno = factorial(numDos);
            	}
            	limpiar();
            	break;
            case 4:
            	if(band == 0)
            	{
            		printf("\nResultados.....\n\n");
            		printf("El resultado de %d+%d es: %d\n", numUno, numDos, resSuma);
            		printf("El resultado de %d-%d es: %d\n", numUno, numDos, resResta);
            		printf("El resultado de %d*%d es: %d\n", numUno, numDos, resMultiplicacion);
            		if(numDos == 0){
            			printf("No se puede dividir por 0......\n");
            		}else{
            			printf("El resultado de %d/%d es: %.2f\n", numUno, numDos, resDivision);
            		}
            		if(numUno < 0){
            			printf("No se puede factorizar por numeros negativos......\n");
            		}else{
            			printf("El factorial de %d es: %d\n", numUno, resFactorialUno);
            		}
            		if(numDos < 0){
            			printf("No se puede factorizar por numeros negativos......\n");
            		}else{
            			resFactorialDos = factorial(numDos);
            			printf("El factorial de %d es: %d\n", numDos, resFactorialDos);
            		}
            	}else{
            		printf("\nAntes de informar los resultados debe calcularlos.....\n\n");
            	}
            	limpiar();
            	break;
        }
    }while(opcion != 5);
    return 0;
}
