/*
 * Musico.h
 *
 *  Created on: 17 sep. 2019
 *      Author: Sanjurjo Gabriel
 */

#ifndef MUSICO_H_
#define MUSICO_H_

#include "Instrumento.h"
#define QTY_MUSICOS 1000
#define QTY_CARACTERES 51

#define FALSE 0
#define TRUE 1

typedef struct
{
	int id;
	int isEmpty;
	//***************
	char nombre[QTY_CARACTERES];
	char apellido[QTY_CARACTERES];
	int edad;
	int idOrquesta;
	int idInstrumento;
} Musico;

int musicoInitLugarLibre(Musico *list, int len);

int musicoImprimirArray(Musico *list, int len, Instrumento *list2, int len2);
int musicoImprimirArrayShort(Musico *list, int len);
int musicoOrdenarArray(Musico *list, int len, int orden);

int musicoBuscarLugarLibre(Musico *list, int len);
int musicoBuscarPorId(Musico *list, int len,int id);
int musicoAltaPorId(Musico *list, int len, Musico item);
int musicoBajaPorId(Musico *list, int len,int id);
int musicoModificarPorId(Musico *list, int len,Musico item);
int musicoGetPorId(Musico *list, int len, Musico *buffer);

#endif /* MUSICO_H_ */
