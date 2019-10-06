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

int sGen_initLugarLibre(dGen *list, int len);

int sGen_imprimirArray(dGen *list, int len);
int sGen_ordenarArray(dGen *list, int len, int orden);

int sGen_buscarLugarLibre(dGen *list, int len);
int sGen_buscarPorId(dGen *list, int len,int id);
int sGen_altaPorId(dGen *list, int len, dGen item);
int sGen_bajaPorId(dGen *list, int len,int id);
int sGen_modificarPorId(dGen *list, int len,dGen item);


#endif /* SGEN_H_ */
