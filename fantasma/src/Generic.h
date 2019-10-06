/*
 * Pantalla.h
 *
 *  Created on: 17 sep. 2019
 *      Author: Sanjurjo Gabriel
 */

#ifndef SGEN_H_
#define SGEN_H_

#define QTY_PANTALLAS 100
#define QTY_CARACTERES 50

#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

typedef struct
{
	int id;
	int status;
	//***************
	char nombre[50];
	char direccion[50];
	float precio;
	int tipo;
} dGen;

int sGen_InitLugarLibre(dGen *list, int len);

int sGen_ImprimirArray(dGen *list, int len);
int sGen_OrdenarArray(dGen *list, int len, int orden);

int sGen_BuscarLugarLibre(dGen *list, int len);
int sGen_BuscarPorId(dGen *list, int len,int id);
int sGen_AltaPorId(dGen *list, int len, dGen item);
int sGen_BajaPorId(dGen *list, int len,int id);
int sGen_ModificarPorId(dGen *list, int len,dGen item);
int sGen_GetPorId(dGen *list, int len, dGen *buffer);

#endif /* SGEN_H_ */
