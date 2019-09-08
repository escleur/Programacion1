/*
 * utn.c
 *
 *  Created on: 31 ago. 2019
 *      Author: gas
 */


#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

//Linux
//#define PURGAR __fpurge(stdin);
//Windows
#define PURGAR fflush(stdin);


int getInt(	int *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno = EXIT_ERROR;
	int buffer;
	if(	resultado != NULL &&
		mensaje	!= NULL &&
		mensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			PURGAR
			if(scanf("%d",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*resultado = buffer;
					break;
				}
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}
int getArrayInt(	int *array,
					int limite,
					char *mensaje,
					char *mensajeError,
					int minimo,
					int maximo,
					int reintentos){
	int retorno = -1;
	char respuesta;
	int i=0;
	int buffer;
	if( array != NULL &&
		limite > 0 &&
		mensaje != NULL &&
		mensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0){
		do{
			if(getInt(&buffer, mensaje, mensajeError, minimo, maximo, reintentos)==0)
			{
				array[i] = buffer;
				i++;
				limite--;


			}
			getChar(&respuesta, "Ingrese 's' para continuar ingresando enteros", "ERROR", 'a', 'z', 2 );
		}while(respuesta=='s' && limite > 0);
		retorno = i;
	}
	return retorno;
}
int getFloat(float *resultado,
			 char *mensaje,
			 char *mensajeError,
			 float minimo,
			 float maximo,
			 int reintentos)
{
	int retorno = EXIT_ERROR;
	float buffer;
	if(	resultado != NULL &&
		mensaje	!= NULL &&
		mensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			PURGAR
			if(scanf("%f",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*resultado = buffer;
					break;
				}
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}
int getChar( char *resultado,
			  char *mensaje,
			  char *mensajeError,
			  char minimo,
			  char maximo,
			  int reintentos)
{
	int retorno = EXIT_ERROR;
	char buffer;
	if(	resultado != NULL &&
		mensaje	!= NULL &&
		mensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			PURGAR
			if(scanf("%c",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*resultado = buffer;
					break;
				}
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}
int getString (char *resultado,
		      char *mensaje,
			  char *mensajeError,
			  int minimo,
			  int maximo,
			  int reintentos)
{
	int retorno = EXIT_ERROR;
	char buffer[500];
	if(	resultado != NULL &&
		mensaje	!= NULL &&
		mensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			PURGAR
			if(scanf("%s",buffer)==1)
			{
				if(strlen(buffer) >= minimo && strlen(buffer) <= maximo)
				{
					retorno = EXIT_SUCCESS;
					strcpy(resultado, buffer);
					break;
				}
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}
