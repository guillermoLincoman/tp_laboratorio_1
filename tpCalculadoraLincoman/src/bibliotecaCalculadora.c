/*
 * bibliotecaCalculadora.c
 *
 *  Created on: 18 sep. 2021
 *      Author: Compumar
 */
#include "bibliotecaCalculadora.h"

/** \brief Pone una pausa y borra pantalla.
 *
 */
void limpiar()
{
	printf("\n");
    system("pause");
    system("cls");
}

/** \brief Suma Dos numeros enteros.
 *
 * \param int numUno recibe el primer operando
 * \param int numDos recibe el segundo  operando
 * \return retorna la suma de los Dos operando
 *
 */
int suma(int numUno, int numDos)
{
	int resultado;

	resultado = numUno + numDos;
	return resultado;
}

/** \brief Resta Dos numeros enteros.
 *
 * \param int numUno recibe el primer operando
 * \param int numDos recibe el segundo  operando
 * \return retorna la resta de los Dos operando
 *
 */
int resta(int numUno, int numDos)
{
	int resultado;

	resultado = numUno - numDos;
	return resultado;
}

/** \brief Divide Dos numeros enteros.
 *
 * \param int numUno recibe el primer operando
 * \param int numDos recibe el segundo  operando
 * \return retorna la division de los dos operando
 *
 */
float division(int numUno, int numDos)
{
	float resultado;

	resultado = (float) numUno / numDos;
	return resultado;
}

/** \brief Multiplica Dos numeros enteros.
 *
 * \param int numUno recibe el primer operando
 * \param int numDos recibe el segundo  operando
 * \return retorna la Multiplicacion de los dos operando
 *
 */
int multiplicacion(int numUno, int numDos)
{
	int resultado;

	resultado = numUno * numDos;
	return resultado;
}

/** \brief Calcula el factorial de un numero
 *
 * \param int num recibe un operando
 * \return retorna el factorial del operando recibido
 *
 */
unsigned long factorial(int num)
{
	long fact;
	fact = 0;
	if(num>0){
		fact=factorial(num-1);
	    fact=fact*num;
	}else{
	    fact=1;
	}
	return fact;
}

/** \brief Carga y valida un numero entero.
 *
 * \param char* mensaje recibe el mensaje para pedir el entero.
 * \param char* mensajeError el mensaje de error en caso de no ingresar un entero entero.
 * \param int rangoMin recibe el menor numero que va a recibir.
 * \param int rangoMax recibe el mayor numero que va a recibir.
 * \param int intentos recibe la cantidad de intentos de error al ingresar un entero.
 *
 * \return retorna un numero entero ingresado por el usuario.
 *
 */
int cargarUnEntero(char* mensaje, char* mensajeError,int rangoMin, int rangoMax, int intentos)
{
	char* auxInt;
	int aux;
	int band;

	auxInt = malloc(sizeof(int));
	//muestro el mensaje
	printf("%s", mensaje);
	//guardo el valor ingresado en el puntero
	scanf("%s", auxInt);
	//valido que no sea una letra
	band = validarLetra(auxInt);
	aux = atoi(auxInt);
	if(band==0 ||aux<rangoMin||aux>rangoMax)
	{
		//realiza intentos hasta llegar a 0
		while(intentos>0)
		{
			printf("%s", mensajeError);
			scanf("%s", auxInt);
			band = validarLetra(auxInt);
			aux = atoi(auxInt);
			if(band==0 ||aux<rangoMin||aux>rangoMax)
			{
				intentos--;
				band=-1;
			}else{
				intentos = 0;
				aux = atoi(auxInt);
			}
		}
	}else
	{
		//utilizo la variable con la que valide para guardar el numero ingresado
		//convierto el el valor de auxInt en un entero y lo guardo en la var aux
		aux = atoi(auxInt);
	}
    return aux;
}
/** \brief Valida que sea un int o un char
 *
 * \param char num[] recibe un dato para validar
 *
 * \return en caso de ser un numero retorna 0 en caso de un char retorna 1
 *
 */
int validarLetra(char num[])
{
   int i=0;
   //repite hasta llegar al final de la cadena
   while(num[i] != '\0')
   {
       if (i == 0 && num[i] == '-')
       {
           i++;
           continue;
       }
       if(num[i] < '0' || num[i] > '9')
       {
          return 0;
       }
       i++;
   }
   return 1;
}
