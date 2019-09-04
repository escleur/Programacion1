/*
 * utn.h
 *
 *  Created on: 31 ago. 2019
 *      Author: gas
 */

#ifndef UTN_H_
#define UTN_H_

#define EXIT_ERROR -1

int getInt(	int *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos);

int getFloat(float *resultado,
			 char *mensaje,
			 char *mensajeError,
			 float minimo,
			 float maximo,
			 int reintentos);

int getChar( char *resultado,
			 char *mensaje,
			 char *mensajeError,
			 char minimo,
			 char maximo,
			 int reintentos);

int getString (char *resultado,
		      char *mensaje,
			  char *mensajeError,
			  int minimo,
			  int maximo,
			  int reintentos);


#endif /* UTN_H_ */
