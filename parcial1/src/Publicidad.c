/*
 * Empleado.c
 *
 *  Created on: 17 sep. 2019
 *      Author: profesor
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Publicidad.h"

static int generarId(void){
	static int id = 0;
	id++;
	return id;
}


/*
int ordenarArrayPantallas(struct sPantalla *aArray, int cantidad){
	int i;
	int retorno = -1;
	struct sPantalla buffer;
	int fSwap;
	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				if(strncmp(aArray[i].nombre,aArray[i+1].nombre,QTY_CARACTERES)>0)
				{
					fSwap = 1;
					buffer = aArray[i];
					aArray[i]=aArray[i+1];
					aArray[i+1]=buffer;
				}
				else if(strncmp(aArray[i].nombre,aArray[i+1].nombre,QTY_CARACTERES)==0)
				{
					if(strncmp(aArray[i].apellido,aArray[i+1].apellido,QTY_CARACTERES)>0)
					{
						fSwap = 1;
						buffer = aArray[i];
						aArray[i]=aArray[i+1];
						aArray[i+1]=buffer;
					}
				}
			}
		}while(fSwap);
	}
	return retorno;
}
*/

int imprimirArrayPublicidad(struct sPublicidad *aArray, int cantidad,struct sPantalla *aArray2, int cantidad2){
	int i;
	int indexPantalla;
	int retorno = -1;
	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		printf("id     Nombre de Pantalla    Nombre del Video    Cantidad de Dias     Cuit de cliente\n");
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status == STATUS_NOT_EMPTY){
				indexPantalla = buscarPantallaPorId(aArray2,cantidad2,aArray[i].idPantalla);
				printf("%d -- %s -- %s -- %d -- %s \n",aArray[i].id,aArray2[indexPantalla].nombre,aArray[i].nombreArchivo,aArray[i].dias,aArray[i].cuit);
			}

		}
	}
	return retorno;
}

int initLugarLibrePublicidad(struct sPublicidad *aArray, int cantidad){
	int i;
	int retorno = -1;
	if(aArray != NULL && cantidad > 0){
		for(i=0;i<cantidad;i++){
			aArray[i].status = STATUS_EMPTY;
		}
		retorno = 0;
	}
	return retorno;
}

int buscarLugarLibrePublicidad(struct sPublicidad *aArray, int cantidad){
	int retorno = -1;
	int i;
	if(aArray != NULL && cantidad > 0){
		for(i=0;i<cantidad;i++){
			if(aArray[i].status == STATUS_EMPTY){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}



int buscarPublicidadPorId(struct sPublicidad *aArray, int cantidad,int id){
	int retorno = -1;
	int i;
	if(aArray!=NULL && cantidad > 0 ){
		for(i=0;i<cantidad;i++){
			if(aArray[i].id == id && aArray[i].status == STATUS_NOT_EMPTY){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int altaPublicidadPorId(struct sPublicidad *aArray, int cantidad,struct sPublicidad item){
	int retorno = -1;
	int index;
	if(aArray!=NULL && cantidad>0){
		index = buscarLugarLibrePublicidad(aArray, cantidad);
		if(index>=0){
			aArray[index] = item;
			aArray[index].status = STATUS_NOT_EMPTY;
			aArray[index].id = generarId();
			retorno = 0;
		}
	}
	return retorno;
}


int listarPantallasPorCuit(struct sPantalla *aPantallas,int cantidadPantallas,struct sPublicidad *aPublicidad,int cantidadPublicidad, char *cuit )
{
	int retorno = -1;
	int i;
	if(aPantallas != NULL && cantidadPantallas>0 && aPublicidad != NULL && cantidadPublicidad >0 && cuit != NULL){
		retorno = 0;
		for(i=0;i<cantidadPublicidad;i++){
			if(strncmp(aPublicidad[i].cuit, cuit, 50) == 0 && aPublicidad[i].status == STATUS_NOT_EMPTY){
				imprimirPantallaConCuit(aPantallas, cantidadPantallas, aPublicidad[i].idPantalla, cuit);
			}
		}

	}
	return retorno;
}
int imprimirPantallaConCuit(struct sPantalla *aPantallas, int cantidadPantallas,int idPantalla,char *cuit){
	int index;
	int retorno = -1;
	if(aPantallas != NULL && cantidadPantallas>0 && idPantalla>=0 && cuit!=NULL){
		retorno = 0;
		index=buscarPantallaPorId(aPantallas, cantidadPantallas, idPantalla);
		if(index != -1){
			printf("id - %d - nombre - %s - direccion - %s - precio - %f - tipo - %d- cuit - %s \n"
					,aPantallas[index].id,aPantallas[index].nombre,aPantallas[index].direccion,aPantallas[index].precio,aPantallas[index].tipo,cuit );
		}
	}
	return retorno;
}
int buscarPublicidadPorCuitYIdPantalla(struct sPublicidad *aArray, int cantidad,char *cuit,int idPantalla){
	int retorno = -1;
	int i;
	if(aArray!=NULL && cantidad > 0 ){
		for(i=0;i<cantidad;i++){
			if(strncmp(aArray[i].cuit, cuit, 50) == 0 && aArray[i].idPantalla == idPantalla && aArray[i].status == STATUS_NOT_EMPTY){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/*Anulado
int listarPantallasPorCuit(struct sPantalla *aPantallas,int cantidadPantallas,struct sPublicidad *aPublicidad,int cantidadPublicidad, char *cuit )
{
	int retorno = -1;
	if(aPantallas != NULL && cantidadPantallas>0 && aPublicidad != NULL && cantidadPublicidad >0 && cuit != NULL){
		int posicionActual=-1;
		int incremento=0;
		retorno = 0;
		do{
			incremento = buscarPublicidadPorCuit(aPublicidad+posicionActual+1, cantidadPublicidad-posicionActual-1, cuit);
			if(incremento == -1){
				break;
			}
			posicionActual += incremento+1;
			printf("%d\n",posicionActual);
			imprimirPantallaConCuit(aPantallas, cantidadPantallas, aPublicidad[posicionActual].idPantalla, cuit);

		}while(1);
	}
	return retorno;
}

int buscarPublicidadPorCuit(struct sPublicidad *aArray, int cantidad,char *cuit){
	int retorno = -1;
	int i;
	if(aArray!=NULL && cantidad > 0 ){
		for(i=0;i<cantidad;i++){
			if(strncmp(aArray[i].cuit, cuit, 50) == 0 && aArray[i].status == STATUS_NOT_EMPTY){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
*/
/*
int bajaPantallaPorId(struct sPantalla *aArray, int cantidad,int id){
	int retorno = -1;
	int index;
	if(aArray!=NULL && cantidad > 0){
		index = buscarPantallaPorId(aArray, cantidad, id);
		if(index != -1){
			aArray[index].status = STATUS_EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}
*/
int modificarPublicidadPorId(struct sPublicidad *aArray, int cantidad,struct sPublicidad item){
	int retorno = -1;
	int index;
	if(aArray!=NULL && cantidad>0){
		index = buscarPublicidadPorId(aArray, cantidad, item.id);
		if(index!=-1){
			aArray[index] = item;
			aArray[index].status = STATUS_NOT_EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}

int consultaFacturacion(struct sPantalla *aPantallas,int cantidadPantallas,struct sPublicidad *aPublicidad,int cantidadPublicidad,char *cuit){
	int retorno = -1;
	int i;
	int indexPantalla;
	float monto;
	if(aPantallas != NULL && cantidadPantallas>0 && aPublicidad != NULL && cantidadPublicidad >0 && cuit != NULL){
		retorno = 0;
		for(i=0;i<cantidadPublicidad;i++){
			if(aPublicidad[i].status == STATUS_NOT_EMPTY && strncmp(aPublicidad[i].cuit, cuit, 50) == 0 ){
				indexPantalla = buscarPantallaPorId(aPantallas, cantidadPantallas,aPublicidad[i].idPantalla);
				if(indexPantalla==-1){
					printf("referencia con pantalla rota\n");
				}else{
					monto = aPantallas[indexPantalla].precio * aPublicidad[i].dias;
					printf("id %d - nombre %s - monto %f\n", aPantallas[indexPantalla].id, aPantallas[indexPantalla].nombre,monto);
				}
			}
		}

	}
	return retorno;
}

int ordenarPublicidad(struct sPublicidad *array, int limite){
	int retorno = -1;
	int i;
	int j;
	int flagOrdeno;
	struct sPublicidad swap;

	if(array != NULL && limite > 0){
		retorno = 0;
		for(i=1; i<limite; i++){
			j=i;
			flagOrdeno = 1;
			while(flagOrdeno != 0 && j!=0){
				flagOrdeno = 0;

				if((	array[j-1].status == STATUS_EMPTY &&
						array[j].status == STATUS_NOT_EMPTY) ||
						strcmp(array[j-1].cuit, array[j].cuit) > 0){
					swap = array[j-1];
					array[j-1] = array[j];
					array[j] = swap;
					flagOrdeno = 1;
				}
				j--;
			}
		}

	}
	return retorno;
}

corteControl(struct sPublicidad *aPublicidad, int cantidadPublicidad, struct sPantalla *aPantallas,int cantidadPantalla){
	int retorno = -1;
	int i;
	int indexPantalla;
	float importe=0;
	int flagPrimero = 1;
	struct sPublicidad bPublicidadAnterior;

	int contador = 0;
	if(aPublicidad != NULL && cantidadPublicidad > 0){
		ordenarPublicidad(aPublicidad, cantidadPublicidad);

		for(i=0;i<cantidadPublicidad;i++){

			if(aPublicidad[i].status == STATUS_EMPTY){
				continue;
			}
			if(flagPrimero){
				bPublicidadAnterior = aPublicidad[i];

				printf("Cuit: %s - total contrataciones: %d" ,aPublicidad[i].cuit,
						contarContrataciones(aPublicidad, cantidadPublicidad,aPublicidad[i].cuit));
				flagPrimero = 0;

			}else{
				if(strncmp(bPublicidadAnterior.cuit, aPublicidad[i].cuit, 50)==0){


					indexPantalla = buscarPantallaPorId(aPantallas, cantidadPantalla, aPublicidad[i].idPantalla);
					importe = aPublicidad[i].dias * aPantallas[indexPantalla].precio;
					printf("Contratacion: %d Importe %f",aPublicidad[i].id,importe);
				}else{
					printf("Cuit: %s - total contrataciones: %d" ,aPublicidad[i].cuit,
							contarContrataciones(aPublicidad, cantidadPublicidad,aPublicidad[i].cuit));
					bPublicidadAnterior = aPublicidad[i];

				}
			}
		}

	}
	return retorno;
}


int contarContrataciones(struct sPublicidad *aPublicidad, int cantidadPublicidad,char *cuit)
{
	int i;
	int contador;
	int retorno = -1;
	if(aPublicidad != NULL && cantidadPublicidad > 0){
		for(i=0;i<cantidadPublicidad;i++){
			if(aPublicidad[i].status == STATUS_NOT_EMPTY && strncmp(cuit, aPublicidad[i].cuit,50)==0){
				contador++;
			}
		}
		retorno = contador;
	}
	return retorno;

}






