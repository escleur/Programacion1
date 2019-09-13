/*
 * empleado.h
 *
 *  Created on: Sep 13, 2019
 *      Author: gabriel
 */



#ifndef EMPLEADO_H_
#define EMPLEADO_H_

struct sEmpleado
{
	int idEmpleado;
	int status;
	//***************
	char nombre[50];
	char apellido[50];
};

#define QTY_EMPLEADOS 10
#define QTY_NOMBRES 10
#define QTY_CARACTERES 50
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1


int imprimirArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad);
int ordenarArrayEmpleados(struct sEmpleado *aEmpleados, int cantidad, int ascendente);


#endif /* EMPLEADO_H_ */
