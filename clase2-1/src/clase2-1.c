/*
 ============================================================================
 Name        : clase2-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int calculaMaximoMinimoPromedio(int *maximo, int *minimo, int *promedio, int *cantidad);

int main(void) {
	int maximo;
	int minimo;
	int promedio;
	int cantidad;

	if(calculaMaximoMinimoPromedio(&maximo, &minimo, &promedio, &cantidad) == 0){
		printf("El maximo es %d el minimo es %d el promedio es %d y la cantidad de casos fue %d", maximo, minimo, promedio, cantidad);
	}
	return EXIT_SUCCESS;
}

int calculaMaximoMinimoPromedio(int *maximo, int *minimo, int *promedio, int *cantidad){
	int retorno = -1;
	char pregunta;
	int flag = 0;
	int numero;

	*cantidad = 0;
	*promedio = 0;

	do{
		printf("Ingrese un numero\n");
		scanf("%d", &numero);

		(*cantidad)++;
		(*promedio) += numero;

		if(flag == 0){
			flag = 1;
			*maximo = numero;
			*minimo = numero;
		}else if(numero > *maximo){
			*maximo = numero;
		}else if(numero < *minimo){
			*minimo = numero;
		}



		printf("Ingrese s para continuar\n");
		scanf("%s", &pregunta);
	}while(pregunta == 's');

	(*promedio) /= (*cantidad);
	retorno = 0;

	return retorno;
}
