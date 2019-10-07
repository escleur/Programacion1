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
#include "Orquesta.h"
#include "Instrumento.h"
#include "Musico.h"
#include "UI.h"


int orquestaUIAlta(Orquesta *list, int len)
{
	Orquesta buffer;
	int step = 0;
	int retorno = -1;
	printf("Alta de orquesta\n");
	do
	{
		switch(step){
		case 0:
			if (orquestaBuscarLugarLibre(list, len) == -1)
			{
				printf("Error no hay mas lugar para orquestas\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 1:
			if (getString(buffer.nombre, "Ingrese el nombre\n", "Error", 1,
					QTY_CARACTERES-1, 2) == -1) {
				printf("Error en el nombre\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 2:
			if (getString(buffer.lugar, "Ingrese el lugar\n",
					"Error", 1, QTY_CARACTERES-1, 2) == -1) {
				printf("Error en el lugar\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 3:
			if (getInt(&buffer.tipo, "Ingrese el tipo 1-Sinfonica 2-Filarmonica 3-Camara\n", "Error",
					1, 3, 2) == -1) {
				printf("Error en el tipo\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 4:
			if (orquestaAltaPorId(list, len, buffer) == 0) {
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

int orquestaUIModificacion(Orquesta *list, int len)
{
	int step = 0;
	int retorno = -1;
	Orquesta buffer;
	printf("Modificacion de orquesta\n");
	getInt(&buffer.id,"Ingrese el id para modificar\n","Error\n",0,100000,2);

	if (orquestaGetPorId(list, len, &buffer) == -1) {
		printf("Error el id no existe\n");
	}
	else
	{
		do{
			printf("1. Modificar nombre\n"
					"2. Modificar lugar\n"
					"3. Modificar tipo\n"
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
						QTY_CARACTERES-1, 2) == -1) {
					printf("Error en el nombre\n");
					step = 100;
				}
				break;
			case 2:
				if (getString(buffer.lugar, "Ingrese la direccion\n",
						"Error", 1, QTY_CARACTERES-1, 2) == -1) {
					printf("Error en el lugar\n");
					step = 100;
				}
				break;
			case 3:
				if (getInt(&buffer.tipo, "Ingrese el tipo 1-Sinfonica 2-Filarmonica 3-Camara\n", "Error",
						1, 2, 2) == -1) {
					printf("Error en el tipo\n");
					step = 100;
				}
				break;
			case 9:
				if (orquestaModificarPorId(list, len, buffer) == 0) {
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

int orquestaUIBaja(Orquesta *list, int len)
{
	int id;
	int retorno = -1;
	char conf;
	printf("Baja\n");
	getInt(&id,"Ingrese el id para dar de baja\n","Error\n",0,100000,2);
	getChar(&conf,"Ingrese s para confirmar la baja\n","Error\n",'a', 'z', 2);
	if(conf=='s'){
		if(orquestaBajaPorId(list,len,id)==0){
			printf("Baja exitosa\n");
			retorno = 0;
		}else{
			printf("Error al dar baja, verifique que el id existe\n");
		}
	}
	return retorno;
}

int instrumentoUIAlta(Instrumento *list, int len)
{
	Instrumento buffer;
	int step = 0;
	int retorno = -1;
	printf("Alta de instrumentos\n");
	do
	{
		switch(step){
		case 0:
			if (instrumentoBuscarLugarLibre(list, len) == -1)
			{
				printf("Error no hay mas lugar para instrumentos\n");
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
			if (getInt(&buffer.tipo, "Ingrese el tipo 1-Cuerdas 2-Viento-madera 3-Viento-metal 4-Percusion\n", "Error",
					1, 4, 2) == -1) {
				printf("Error en el tipo\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 3:
			if (instrumentoAltaPorId(list, len, buffer) == 0) {
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

/*----------------------------------Musicos------------------------------------------------------*/
int musicoUIAlta(Musico *list, int len, Instrumento *list2, int len2, Orquesta *list3, int  len3)
{
	Musico buffer;
	int step = 0;
	int retorno = -1;
	printf("Alta de pantallas\n");
	do
	{
		switch(step){
		case 0:
			if (musicoBuscarLugarLibre(list, len) == -1)
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
					QTY_CARACTERES-1, 2) == -1) {
				printf("Error en el nombre\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 2:
			if (getString(buffer.apellido, "Ingrese la direccion\n",
					"Error", 1, QTY_CARACTERES-1, 2) == -1) {
				printf("Error en la direccion\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 3:
			if (getInt(&buffer.edad, "Ingrese la edad\n", "Error", 0,
					150, 2) == -1) {
				printf("Error en el edad\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 4:
			orquestaImprimirArray(list3, len3);
			if (getInt(&buffer.idOrquesta, "Ingrese el id de la orquesta\n", "Error",
					0, 10000000, 2) == -1) {
				printf("Error en el id\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 5:
			if (orquestaBuscarPorId(list3, len3, buffer.idOrquesta) == -1) {
				printf("Error id no existe\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 6:
			instrumentoImprimirArray(list2, len2);
			if (getInt(&buffer.idInstrumento, "Ingrese el id del instrumento\n", "Error",
					0, 10000000, 2) == -1) {
				printf("Error en el id\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 7:
			if (instrumentoBuscarPorId(list2, len2, buffer.idInstrumento) == -1) {
				printf("Error id no existe\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 8:
			if (musicoAltaPorId(list, len, buffer) == 0) {
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

int musicoUIModificacion(Musico *list, int len, Orquesta *list2, int len2)
{
	int step = 0;
	int retorno = -1;
	Musico buffer;
	printf("Modificacion de musico\n");
	musicoImprimirArrayShort(list, len);
	getInt(&buffer.id,"Ingrese el id para modificar\n","Error\n",0,100000,2);

	if (musicoGetPorId(list, len, &buffer) == -1) {
		printf("Error el id no existe\n");
	}
	else
	{
		do{
			printf("1. Modificar edad\n"
					"2. Modificar orquesta\n"
					"9. Guardar\n"
					"0. Cancelar\n");
			getInt(&step, "Ingrese la opcion 0 a 9\n", "Error", 0, 9, 2);
			switch(step){
			case 0:
				printf("Cancelado por usuario\n");
				step = 100;
				break;
			case 1:
				if (getInt(&buffer.edad, "Ingrese la edad\n", "Error",
						0, 150, 2) == -1) {
					printf("Error en la edad\n");
					step = 100;
				}
				break;
			case 2:
				if (getInt(&buffer.idOrquesta, "Ingrese el id de orquesta\n", "Error",
						0, 10000000, 2) == -1) {
					printf("Error en el id\n");
					step = 100;
				}
				if (orquestaBuscarPorId(list2, len2, buffer.idOrquesta) == -1) {
					printf("Error id no existe\n");
					step = 100;
				}
				break;
			case 9:
				if (musicoModificarPorId(list, len, buffer) == 0) {
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

int musicoUIBaja(Musico *list, int len)
{
	int id;
	int retorno = -1;
	char conf;
	printf("Baja\n");
	musicoImprimirArrayShort(list, len);
	getInt(&id,"Ingrese el id para dar de baja\n","Error\n",0,10000000,2);
	getChar(&conf,"Ingrese s para confirmar la baja\n","Error\n",'a', 'z', 2);
	if(conf=='s'){
		if(musicoBajaPorId(list,len,id)==0){
			printf("Baja exitosa\n");
			retorno = 0;
		}else{
			printf("Error al dar baja, verifique que el id existe\n");
		}
	}
	return retorno;
}


