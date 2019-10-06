/*
 * UI.c
 *
 *  Created on: Oct 5, 2019
 *      Author: Sanjurjo Gabriel
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Generic.h"
#include "UI.h"


int sGen_UIAlta(dGen *list, int len)
{
	dGen buffer;
	int step = 0;
	int retorno = -1;
	printf("Alta de pantallas\n");
	do
	{
		switch(step){
		case 0:
			if (sGen_BuscarLugarLibre(list, len) == -1)
			{
				printf("Error no hay mas lugar para pantallas\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 1:
			if (getString(buffer.nombre, "Ingrese el nombre\n", "Error", 1,
					49, 2) == -1) {
				printf("Error en el nombre\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 2:
			if (getString(buffer.direccion, "Ingrese la direccion\n",
					"Error", 1, 49, 2) == -1) {
				printf("Error en la direccion\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 3:
			if (getFloat(&buffer.precio, "Ingrese el precio\n", "Error", 0,
					1000000, 2) == -1) {
				printf("Error en el precio\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 4:
			if (getInt(&buffer.tipo, "Ingrese el tipo 1-lcd 2-led\n", "Error",
					1, 2, 2) == -1) {
				printf("Error en el tipo\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 5:
			if (sGen_AltaPorId(list, len, buffer) == 0) {
				printf("Alta exitosa\n");
				retorno = 0;
			} else {
				printf("Error al hacer el alta\n");
			}
			step = 100;
			break;
		}
	}while(step!=100);
	return retorno;
}

int sGen_UIModificacion(dGen *list, int len)
{
	int step = 0;
	int retorno = -1;
	dGen buffer;
	printf("Modificacion de pantallas\n");
	getInt(&buffer.id,"Ingrese el id para modificar\n","Error\n",0,100000,2);

	if (sGen_GetPorId(list, len, &buffer) == -1) {
		printf("Error el id no existe\n");
	}
	else
	{
		do{
			printf("1. Modificar nombre\n"
					"2. Modificar direccion\n"
					"3. Modificar precio\n"
					"4. Modificar tipo\n"
					"9. Guardar\n"
					"0. Cancelar\n");
			getInt(&step, "Ingrese la opcion 0 a 9\n", "Error", 0, 9, 2);
			switch(step){
			case 0:
				printf("Cancelado por usuario\n");
				step = 100;
				break;
			case 1:
				if (getString(buffer.nombre, "Ingrese el nombre\n", "Error", 1,
						49, 2) == -1) {
					printf("Error en el nombre\n");
					step = 100;
				}
				break;
			case 2:
				if (getString(buffer.direccion, "Ingrese la direccion\n",
						"Error", 1, 49, 2) == -1) {
					printf("Error en la direccion\n");
					step = 100;
				}
				break;
			case 3:
				if (getFloat(&buffer.precio, "Ingrese el precio\n", "Error", 0,
						1000000, 2) == -1) {
					printf("Error en el precio\n");
					step = 100;
				}
				break;
			case 4:
				if (getInt(&buffer.tipo, "Ingrese el tipo 1-lcd 2-led\n", "Error",
						1, 2, 2) == -1) {
					printf("Error en el tipo\n");
					step = 100;
				}
				break;
			case 9:
				if (sGen_ModificarPorId(list, len, buffer) == 0) {
					printf("Modificacion exitosa\n");
					retorno = 0;
				} else {
					printf("Error al hacer la modificacion\n");
				}
				step = 100;
			}
		}while(step!=100);
	}
	return retorno;
}

int sGen_UIBaja(dGen *list, int len)
{
	int id;
	int retorno = -1;
	char conf;
	printf("Baja\n");
	getInt(&id,"Ingrese el id para dar de baja\n","Error\n",0,100000,2);
	getChar(&conf,"Ingrese s para confirmar la baja\n","Error\n",'a', 'z', 2);
	if(conf=='s'){
		if(sGen_BajaPorId(list,len,id)==0){
			printf("Baja exitosa\n");
			retorno = 0;
		}else{
			printf("Error al dar baja, verifique que el id existe\n");
		}
	}
	return retorno;
}
