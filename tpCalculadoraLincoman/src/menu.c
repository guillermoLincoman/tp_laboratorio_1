/*
 * menu.c
 *
 *  Created on: 18 sep. 2021
 *      Author: Compumar
 */
#include "menu.h"

void inicio()
{
	printf("\n**************************************\n");
	printf("*  TRABAJO PRACTICO 1 - CALCULADORA  *\n");
	printf("**************************************\n");

}

void menuPrincipalNum(int numUno, int numDos)
{
	printf("\n**************************************\n");
	printf("*  TRABAJO PRACTICO 1 - CALCULADORA  *\n");
	printf("**************************************\n");
	printf("*                                    *\n");
    printf("* 1. Ingresar 1er operando (A=%d)     *\n", numUno);
    printf("* 2. Ingresar 2do operando (B=%d)     *\n", numDos);
    printf("* 3. Calcular todas las operaciones  *\n");
    printf("* 4. Informar resultados             *\n");
    printf("* 5. SALIR                           *\n");
    printf("**************************************\n");
}
