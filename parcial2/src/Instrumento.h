/*
 * Pantalla.h
 *
 *  Created on: 17 sep. 2019
 *      Author: Sanjurjo Gabriel
 */

#ifndef INSTRUMENTO_H_
#define INSTRUMENTO_H_

#define QTY_INSTRUMENTOS 20
#define QTY_CARACTERES 51

#define FALSE 0
#define TRUE 1

typedef struct
{
	int id;
	int isEmpty;
	//***************
	char nombre[QTY_CARACTERES];
	int tipo;
} Instrumento;

int instrumentoInitLugarLibre(Instrumento *list, int len);

int instrumentoImprimirArray(Instrumento *list, int len);
int instrumentoOrdenarArray(Instrumento *list, int len, int orden);

int instrumentoBuscarLugarLibre(Instrumento *list, int len);
int instrumentoBuscarPorId(Instrumento *list, int len,int id);
int instrumentoAltaPorId(Instrumento *list, int len, Instrumento item);
int instrumentoBajaPorId(Instrumento *list, int len,int id);
int instrumentoModificarPorId(Instrumento *list, int len,Instrumento item);
int instrumentoGetPorId(Instrumento *list, int len, Instrumento *buffer);

#endif /* INSTRUMENTO_H_ */
