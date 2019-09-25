/*
 * Pantalla.h
 *
 *  Created on: 17 sep. 2019
 *      Author: Sanjurjo Gabriel
 */

#ifndef PUBLICIDAD_H_
#define PUBLICIDAD_H_

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

int imprimirArrayPublicidad(struct sPublicidad *aArray, int cantidad);
int ordenarArrayPublicidad(struct sPublicidad *aArray, int cantidad);
int listarPantallasPorCuit(struct sPantallas *aPantallas,int QTY_PANTALLAS,struct sPublicidad *aPublicidad,int QTY_PUBLICIDAD, int cuit );

int buscarLugarLibrePublicidad(struct sPublicidad *aArray, int cantidad);
int buscarPublicidadPorId(struct sPublicidad *aArray, int cantidad,int id);
int altaPublicidadPorId(struct sPublicidad *aArray, int cantidad,struct sPublicidad item);
int bajaPublicidadPorId(struct sPublicidad *aArray, int cantidad,int id);
int modificarPublicidadPorId(struct sPublicidad *aArray, int cantidad,struct sPublicidad item);


#endif /* PUBLICIDAD_H_ */
