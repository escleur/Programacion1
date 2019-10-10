/*
 * informes.c
 *
 *  Created on: Oct 7, 2019
 *      Author: gabriel
 */


#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Orquesta.h"
#include "Musico.h"
#include "Instrumento.h"
#include "informes.h"

int Informes_OrquestaConMasDe5Musicos(Orquesta *list, int len, Musico *list2, int len2){

	int retorno = -1;
	int i;
	int j;
	int contador;
	if(list != NULL && len > 0 && list2 != NULL && len2 > 0 ){
		retorno = 0;
		printf("Orquestas con mas de 5 musicos\n");
		printf("Id        --         Nombre         --          Tipo         --          Lugar\n");
		for(i=0;i<len;i++){
			if(list[i].isEmpty == FALSE){
				contador=0;
				for(j=0;j<len2;j++){
					if(list2[j].isEmpty == FALSE && list[i].id == list2[j].idOrquesta){
						contador++;
					}
				}
				if(contador >= 5){
					printf("%d -- %s -- %d -- %s\n",list[i].id, list[i].nombre, list[i].tipo,list[i].lugar);
				}

			}
		}
	}
	return retorno;
}


int Informes_MusicosConMasDe30( Musico *list, int len,Orquesta *list2, int len2, Instrumento *list3, int len3){

	int retorno = -1;
	int i;
	Orquesta bOrquesta;
	Instrumento bInstrumento;
	if(list != NULL && len > 0 && list2 != NULL && len2 > 0 && list3 != NULL && len3 > 0){
		retorno = 0;
		printf("Musicos de mas de 30 anios\n");
		printf("Id  --  Nombre   --    Apellido   --   Edad   --    Nombre del instrumento   --   Nombre de orquesta \n");
		for(i=0;i<len;i++){
			if(list[i].isEmpty == FALSE && list[i].edad > 30){
				bOrquesta.id = list[i].idOrquesta;
				bInstrumento.id = list[i].idInstrumento;
				orquestaGetPorId(list2, len2, &bOrquesta);
				instrumentoGetPorId(list3, len3, &bInstrumento);
				printf("%d -- %s -- %s -- %d -- %s -- %s\n",list[i].id, list[i].nombre, list[i].apellido,list[i].edad, bInstrumento.nombre, bOrquesta.nombre);

			}
		}
	}
	return retorno;
}

int Informes_OrquestaDeLugar(Orquesta *list, int len){

	int retorno = -1;
	int i;
	Orquesta bOrquesta;
	if(list != NULL && len > 0){

		if (getString(bOrquesta.lugar, "Ingrese el lugar\n",
				"Error", 1, QTY_CARACTERES-1, 2) == -1) {
			printf("Error al ingresar el lugar\n");
		}
		else
		{
			retorno = 0;
			printf("Musicos de mas de 30 anios\n");
			printf("Id  --  Nombre   --    Lugar   --   Tipo\n");
			for(i=0;i<len;i++){
				if(list[i].isEmpty == FALSE && strncmp(list[i].lugar, bOrquesta.lugar,QTY_CARACTERES) == 0){
					printf("%d -- %s -- %s -- %d\n",list[i].id, list[i].nombre, list[i].lugar,list[i].tipo);

				}
			}
		}
	}
	return retorno;
}
