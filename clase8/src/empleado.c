/*
 * empleado.c
 *
 *  Created on: Sep 13, 2019
 *      Author: gabriel
 */
#include "empleado.h"
#include <stdio.h>
#include <stdlib.h>

int imprimirArrayEmpleados(struct sEmpleado *aEmpleado, int cantidad){
	int i;
	int retorno = -1;
	if(aEmpleado != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0;i<cantidad;i++)
		{
			printf("Id: %d - Apellido: %s - Nombre: %s \n",aEmpleado[i].idEmpleado,aEmpleado[i].apellido,aEmpleado[i].nombre);
		}
	}
	return retorno;
}

int ordenarArrayEmpleados(struct sEmpleado *aEmpleados, int cantidad, int ascendente){
	int i;
	int retorno = -1;
	struct sEmpleado buffer;
	int fSwap;
	if(aEmpleados != NULL && cantidad>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				if(	(ascendente &&
						(strncmp(aEmpleados[i].apellido,aEmpleados[i+1].apellido,QTY_CARACTERES)>0
						|| (strncmp(aEmpleados[i].apellido,aEmpleados[i+1].apellido,QTY_CARACTERES) == 0
						&& strncmp(aEmpleados[i].nombre,aEmpleados[i+1].nombre,QTY_CARACTERES)>0))
					) ||
					(!ascendente &&
						(strncmp(aEmpleados[i].apellido,aEmpleados[i+1].apellido,QTY_CARACTERES)<0
						|| (strncmp(aEmpleados[i].apellido,aEmpleados[i+1].apellido,QTY_CARACTERES) == 0
						&& strncmp(aEmpleados[i].nombre,aEmpleados[i+1].nombre,QTY_CARACTERES)<0))
					)
				)
				{
					fSwap = 1;
					buffer = aEmpleados[i];
					aEmpleados[i] = aEmpleados[i+1];
					aEmpleados[i+1] = buffer;
				}

			}
		}while(fSwap);
	}
	return retorno;
}


