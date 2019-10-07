/*
 * Orquesta.h
 *
 *  Created on: 17 sep. 2019
 *      Author: Sanjurjo Gabriel
 */

#ifndef ORQUESTA_H_
#define ORQUESTA_H_

#define QTY_ORQUESTAS 50
#define QTY_CARACTERES 51

#define FALSE 0
#define TRUE 1

typedef struct
{
	int id;
	int isEmpty;
	//***************
	char nombre[QTY_CARACTERES];
	char lugar[QTY_CARACTERES];
	int tipo;
} Orquesta;

int orquestaInitLugarLibre(Orquesta *list, int len);

int orquestaImprimirArray(Orquesta *list, int len);
int orquestaOrdenarArray(Orquesta *list, int len, int orden);

int orquestaBuscarLugarLibre(Orquesta *list, int len);
int orquestaBuscarPorId(Orquesta *list, int len,int id);
int orquestaAltaPorId(Orquesta *list, int len, Orquesta item);
int orquestaBajaPorId(Orquesta *list, int len,int id);
int orquestaModificarPorId(Orquesta *list, int len,Orquesta item);
int orquestaGetPorId(Orquesta *list, int len, Orquesta *buffer);

#endif /* ORQUESTA_H_ */
