/*
 ============================================================================
 Name        : miBiblioteca.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define EXIT_ERROR -1

int main(void)
{

	char resultado[60];
	if(getString(resultado,"Ingrese su nombre?\n","Error\n",2,50,2)==0)
	{
		printf("El resultado es: %s",resultado);
	}

	return EXIT_SUCCESS;
}
