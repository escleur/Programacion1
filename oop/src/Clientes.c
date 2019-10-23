/*
 * Clientes.c
 *
 *  Created on: 22 oct. 2019
 *      Author: alumno
 */
#include "Clientes.h"
static int isValidNombre(char* nombre);
static int isValidDireccion(char* direccion);
static int isValidLocalidad(char* localidad);

Cliente* cli_new(void) {
	return malloc(sizeof(Cliente));
}

Cliente* cli_newParametros(char* nombre, char* direccion, char* cuit, char* localidad) {
	Cliente* this;
	Cliente* retorno = NULL;
	this = cli_new();
	if(this != NULL){
		if(	cli_setNombre(this, nombre) == 0 &&
			cli_setDireccion(this, direccion) == 0 &&
			cli_setCuit(this, cuit) == 0 &&
			cli_setLocalidad(this, localidad) == 0){
			retorno = this;
		}else{
			cli_delete(this);
		}
	}
	return retorno;
}

void cli_delete(Cliente *this) {
	free(this);
}

int cli_setNombre(Cliente *this, char *nombre) {
	int retorno = -1;
	if (this != NULL && isValidNombre(nombre)) {
		strncpy(this->nombre, nombre, 51);
		retorno = 0;
	}
	return retorno;
}

int cli_getNombre(Cliente *this, char *nombre) {
	int retorno = -1;
	if (this != NULL && nombre != NULL) {
		strncpy(nombre, this->nombre, 51);
		retorno = 0;
	}
	return retorno;

}
static int isValidNombre(char *nombre) {
	return 1;
}

int cli_setDireccion(Cliente *this, char *direccion) {
	int retorno = -1;
	if (this != NULL && isValidDireccion(direccion)) {
		strncpy(this->direccion, direccion, 51);
		retorno = 0;
	}
	return retorno;
}

int cli_getDireccion(Cliente *this, char *direccion) {
	int retorno = -1;
	if (this != NULL && direccion != NULL) {
		strncpy(direccion, this->direccion, 51);
		retorno = 0;
	}
	return retorno;

}
static int isValidDireccion(char *direccion) {
	return 1;
}

int cli_setCuit(Cliente *this, char *cuit) {
	int retorno = -1;
	if (this != NULL && isValidCuit(cuit)) {
		strncpy(this->cuit, cuit, 51);
		retorno = 0;
	}
	return retorno;
}

int cli_getCuit(Cliente *this, char *cuit) {
	int retorno = -1;
	if (this != NULL && cuit != NULL) {
		strncpy(cuit, this->cuit, 51);
		retorno = 0;
	}
	return retorno;

}
static int isValidCuit(char *cuit) {
	return 1;
}

int cli_setLocalidad(Cliente *this, char *localidad) {
	int retorno = -1;
	if (this != NULL && isValidLocalidad(localidad)) {
		strncpy(this->localidad, localidad, 51);
		retorno = 0;
	}
	return retorno;
}

int cli_getLocalidad(Cliente *this, char *localidad) {
	int retorno = -1;
	if (this != NULL && localidad != NULL) {
		strncpy(localidad, this->localidad, 51);
		retorno = 0;
	}
	return retorno;

}
static int isValidLocalidad(char *localidad) {
	return 1;
}
