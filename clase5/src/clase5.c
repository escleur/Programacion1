/*
 ============================================================================
 Name        : clase5.c
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

#define QTY_EMPLEADOS 100

int main(void) {

	int edadesEmpleados[QTY_EMPLEADOS];

	if(initArrayInt(edadesEmpleados, QTY_EMPLEADOS, 10)){
		imprimirArrayInt(edadesEmpleados, QTY_EMPLEADOS)
	}

	return EXIT_SUCCESS;
}

int initArrayInt(int array[], int limite, int valor){
	int i;
	int retorno = -1;
	if(array != NULL && limite > 0){
		retorno = 0;
		for(i = 0;i < limite; i++){
			array[i]=valor;
		}
	}
	return retorno;
}

int imprimirArrayInt(int array[], int limite){
	int i;
	int retorno = -1;
	if(array != NULL && limite > 0){
		retorno = 0;
		for(i = 0;i < limite; i++){
			printf("%d\n", array[i]);
		}
	}
	return retorno;
}
