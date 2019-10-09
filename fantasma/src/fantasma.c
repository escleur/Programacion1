/*
 ============================================================================
 Name        : fantasma.c
 Author      : Sanjurjo Gabriel Alejandro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Generic.h"
#include "UI.h"

int main(void) {
	dGen aPantallas[QTY_PANTALLAS];
	int opcion;
	char tel[21];
	sGen_InitLugarLibre(aPantallas, QTY_PANTALLAS);
	//cargaForzadaPantallas(aPantallas,QTY_PANTALLAS);
	do {
		getTelefono(&tel,"Ingrese el telefono\n", "Error\n",4,20,10);
		printf("%s\n",tel);
		printf( "1. Alta de pantallas\n"
				"2. Modificacion de pantallas\n"
				"3. Baja de pantallas\n"
				"4. Listado pantallas\n"
				"0. Salir\n");
		getInt(&opcion, "Ingrese la opcion\n", "Error\n", 0, 11, 2);
		switch(opcion)
		{
		case 1:
			sGen_UIAlta(aPantallas, QTY_PANTALLAS);
			break;
		case 2:
			sGen_UIModificacion(aPantallas, QTY_PANTALLAS);
			break;
		case 3:
			sGen_UIBaja(aPantallas, QTY_PANTALLAS);
			break;
		case 4:
			sGen_ImprimirArray(aPantallas, QTY_PANTALLAS);
			break;
		}
	}while(opcion!=0);
	return 0;
}
