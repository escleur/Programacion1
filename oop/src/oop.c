/*
 ============================================================================
 Name        : oop.c
 Author      : Sanjurjo Gabriel Alejandro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Clientes.h"

int main(void) {
	Cliente *listaClientes[100];
	int cantidadClientes=0;
	FILE *fp;
	int r;
	char strId[51];
	char nombre[51];
	char cuit[51];
	char localidad[51];
	char direccion[51];
	fp = fopen("clientes.txt","r");
	if(fp != NULL){
		return -1;
	}
	do
	{
		r = fscanf(fp,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",strId,nombre,cuit,localidad,direccion)
		if(r==5){
			listaClientes[0] = cli_new();

		}
	}while(!feof(fp));
	return EXIT_SUCCESS;
}
