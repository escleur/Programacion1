/*
 ============================================================================
 Name        : clase3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int calculaMaximoMinimoPromedio(int *maximo, int *minimo, float *promedio, int cantidad);

int main(void) {
	int maximo;
	int minimo;
	float promedio;
	int cantidad;

	printf("Ingrese la cantidad de casos ");
	scanf("%d", &cantidad);

	if(calculaMaximoMinimoPromedio(&maximo, &minimo, &promedio, cantidad) == 0){
		printf("El maximo es %d el minimo es %d el promedio es %d", maximo, minimo, promedio);
	}
	return EXIT_SUCCESS;
}

int calculaMaximoMinimoPromedio(int *maximo, int *minimo, float *promedio, int cantidad){
	int retorno = -1;
	int flag = 0;
	int numero;
	int i;
	int suma = 0;

	for(i = 0; i < cantidad; i++){
		printf("Ingrese un numero\n");
		scanf("%d", &numero);

		suma += numero;

		if(flag == 0){
			flag = 1;
			*maximo = numero;
			*minimo = numero;
		}else if(numero > *maximo){
			*maximo = numero;
		}else if(numero < *minimo){
			*minimo = numero;
		}

	}

	*promedio = (float)suma / cantidad;
	retorno = 0;

	return retorno;
}
