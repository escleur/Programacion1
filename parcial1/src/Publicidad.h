/*
 * Pantalla.h
 *
 *  Created on: 17 sep. 2019
 *      Author: Sanjurjo Gabriel
 */

#ifndef PUBLICIDAD_H_
#define PUBLICIDAD_H_
#include "Pantalla.h"
#define QTY_PUBLICIDAD 1000
#define QTY_CARACTERES 50

#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

struct sPublicidad
{
	int id;
	int status;
	//***************
	char cuit[50];
	int dias;
	char nombreArchivo[50];
	int idPantalla;
};

int initLugarLibrePublicidad(struct sPublicidad *aArray, int cantidad);

int imprimirArrayPublicidad(struct sPublicidad *aArray, int cantidad,struct sPantalla *aArray2, int cantidad2);
int ordenarArrayPublicidad(struct sPublicidad *aArray, int cantidad);
int listarPantallasPorCuit(struct sPantalla *aPantallas,int cantidadPantallas,struct sPublicidad *aPublicidad,int cantidadPublicidad, char *cuit );
int imprimirPantallaConCuit(struct sPantalla *aPantallas, int cantidadPantallas,int idPantalla,char *cuit);

int buscarPublicidadPorCuitYIdPantalla(struct sPublicidad *aArray, int cantidad,char *cuit,int idPantalla);
int buscarPublicidadPorCuit(struct sPublicidad *aArray, int cantidad,char *cuit);
int buscarLugarLibrePublicidad(struct sPublicidad *aArray, int cantidad);
int buscarPublicidadPorId(struct sPublicidad *aArray, int cantidad,int id);
int altaPublicidadPorId(struct sPublicidad *aArray, int cantidad,struct sPublicidad item);
int bajaPublicidadPorId(struct sPublicidad *aArray, int cantidad,int id);
int modificarPublicidadPorId(struct sPublicidad *aArray, int cantidad,struct sPublicidad item);
int consultaFacturacion(struct sPantalla *aPantallas,int cantidadPantallas,struct sPublicidad *aPublicidad,int cantidadPublicidad,char *cuit);
int ordenarPublicidad(struct sPublicidad *array, int limite);
int contarContrataciones(struct sPublicidad *aPublicidad, int cantidadPublicidad,char *cuit);
int corteControl(struct sPublicidad *aPublicidad, int cantidadPublicidad, struct sPantalla *aPantallas,int cantidadPantalla);
int maximoFacturacion(struct sPublicidad *aPublicidad, int cantidadPublicidad, struct sPantalla *aPantallas,int cantidadPantalla);
#endif /* PUBLICIDAD_H_ */
