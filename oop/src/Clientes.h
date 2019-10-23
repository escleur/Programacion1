/*
 * Clientes.h
 *
 *  Created on: 22 oct. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CLIENTES_H_
#define CLIENTES_H_

typedef struct
{
	int idCliente;
	int status;
	//------------
	char nombre[51];
	char direccion[51];
	char cuit[51];
	char localidad[51];
} Cliente;

Cliente* cli_new(void);
void cli_delete(Cliente* this);
int cli_setNombre(Cliente* this, char* nombre);
int cli_getNombre(Cliente* this, char* nombre);

int cli_setDireccion(Cliente* this, char* direccion);
int cli_getDireccion(Cliente* this, char* direccion);

int cli_setCuit(Cliente* this, char* cuit);
int cli_getCuit(Cliente* this, char* cuit);
static int isValidCuit(char* cuit);

int cli_setLocalidad(Cliente* this, char* localidad);
int cli_getLocalidad(Cliente* this, char* localidad);

#endif /* CLIENTES_H_ */
