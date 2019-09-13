/*
 ============================================================================
 Name        : clase7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

//Linux
#define PURGAR __fpurge(stdin);
//Windows
//#define PURGAR fflush(stdin);

#define EXIT_ERROR -1
#define QTY_CHARS 50
#define QTY_NOMBRES 5

int getString (char *pResultado,
		      char *pMensaje,
			  char *pMensajeError,
			  int minimo,
			  int maximo,
			  int reintentos);

int imprimirArrayString(char aNombre[][QTY_CHARS], int cantidad);

void insercionString(char array[][QTY_CHARS], int limite);

int imprimirArrayStringInt(char array[][QTY_CHARS], int cantidad, int arrayLong[]);

void insercionStringInt(char array[][QTY_CHARS], int limite, int arrayInt[]);

/*int getLong(	long *pResultado,
			char *pMensaje,
			char *pMensajeError,
			long minimo,
			long maximo,
			int reintentos)
{
	int retorno = EXIT_ERROR;
	long buffer;
	if(	pResultado != NULL &&
		pMensaje	!= NULL &&
		pMensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s", pMensaje);
			PURGAR
			if(scanf("%d",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*pResultado = buffer;
					break;
				}
			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}*/

int getInt(	int *pResultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno = EXIT_ERROR;
	int buffer;
	if(	pResultado != NULL &&
		pMensaje	!= NULL &&
		pMensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s", pMensaje);
			PURGAR
			if(scanf("%d",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*pResultado = buffer;
					break;
				}
			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}
int getString (char *pResultado,
		      char *pMensaje,
			  char *pMensajeError,
			  int minimo,
			  int maximo,
			  int reintentos)
{
	int retorno = EXIT_ERROR;
	char buffer[500];
	if(	pResultado != NULL &&
		pMensaje	!= NULL &&
		pMensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s",pMensaje);
			PURGAR
			fgets(buffer,sizeof(buffer),stdin);
			buffer[strlen(buffer)-1] = '\0';
			if(strlen(buffer)>=minimo && strlen(buffer) <= maximo)
			{
				strncpy(pResultado,buffer,maximo+1);
				retorno = 0;
				break;
			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

int main(void) {

	char arrayNombres[QTY_NOMBRES][QTY_CHARS];
	int arrayDni[QTY_NOMBRES];
	int i;
	for(i=0;i<QTY_NOMBRES;i++){
		getString (arrayNombres[i], "Ingrese un nombre", "Error", 0, 49, 2);
		getInt(&arrayDni[i], "Ingrese el dni", "Error", 0, 99999999, 2);
	}
	//insercionString(arrayNombres, QTY_NOMBRES);
	insercionStringInt(arrayNombres, QTY_NOMBRES, arrayDni );
	imprimirArrayStringInt(arrayNombres, QTY_NOMBRES, arrayDni);

	return EXIT_SUCCESS;



}

int imprimirArrayStringInt(char array[][QTY_CHARS], int cantidad, int arrayInt[]){
	int i;
	int retorno = -1;
	if(array!=NULL && arrayInt!=NULL && cantidad > 0){
		retorno = 0;
		for(i=0;i<cantidad;i++){
			printf("%s     %d\n",array[i], arrayInt[i]);
		}
	}
	return retorno;

}

int imprimirArrayString(char array[][QTY_CHARS], int cantidad){
	int i;
	int retorno = -1;
	if(array!=NULL && cantidad > 0){
		retorno = 0;
		for(i=0;i<cantidad;i++){
			printf("%s\n",array[i]);
		}
	}
	return retorno;

}


void insercionString(char array[][QTY_CHARS], int limite){
	int i;
	int j;
	int flagOrdeno;
	char swap[QTY_CHARS];


	for(i=1; i<limite; i++){
		j=i;
		flagOrdeno = 1;
		while(flagOrdeno != 0 && j!=0){
			flagOrdeno = 0;

			if(strcmp(array[j-1], array[j]) > 0){
				strcpy(swap, array[j-1]);
				strcpy(array[j-1], array[j]);
				strcpy(array[j], swap);
				flagOrdeno = 1;
			}
			j--;
		}
	}
}

void insercionStringInt(char array[][QTY_CHARS], int limite, int arrayInt[]){
	int i;
	int j;
	int flagOrdeno;
	char swap[QTY_CHARS];
	int swapInt;

	for(i=1; i<limite; i++){
		j=i;
		flagOrdeno = 1;
		while(flagOrdeno != 0 && j!=0){
			flagOrdeno = 0;

			if(strncmp(array[j-1], array[j], QTY_CHARS) > 0){
				strncpy(swap, array[j-1], QTY_CHARS);
				strncpy(array[j-1], array[j], QTY_CHARS);
				strncpy(array[j], swap, QTY_CHARS);
				swapInt = arrayInt[j-1];
				arrayInt[j-1] = arrayInt[j];
				arrayInt[j] = swapInt;
				flagOrdeno = 1;
			}else if(strncmp(array[j-1], array[j], QTY_CHARS)==0 && arrayInt[j-1] > arrayInt[j]){
				strncpy(swap, array[j-1], QTY_CHARS);
				strncpy(array[j-1], array[j], QTY_CHARS);
				strncpy(array[j], swap, QTY_CHARS);
				swapInt = arrayInt[j-1];
				arrayInt[j-1] = arrayInt[j];
				arrayInt[j] = swapInt;
				flagOrdeno = 1;

			}
			j--;
		}
	}
}

