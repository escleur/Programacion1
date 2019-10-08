/*
 ============================================================================
 Name        : fantasma.c
 Author      : Sanjurjo Gabriel Alejandro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Orquesta.h"
#include "Musico.h"
#include "Instrumento.h"
#include "UI.h"

void orquestaCargaForzada(Orquesta *list, int len);
void instrumentoCargaForzada(Instrumento *list, int len);
void musicoCargaForzada(Musico *list, int len);

int main(void) {
	Orquesta aOrquestas[QTY_ORQUESTAS];
	Instrumento aInstrumentos[QTY_INSTRUMENTOS];
	Musico aMusicos[QTY_MUSICOS];
	int opcion;
	char opcion2;
	orquestaInitLugarLibre(aOrquestas, QTY_ORQUESTAS);
	instrumentoInitLugarLibre(aInstrumentos, QTY_INSTRUMENTOS);
	musicoInitLugarLibre(aMusicos, QTY_MUSICOS);
	orquestaCargaForzada(aOrquestas,QTY_ORQUESTAS);
	instrumentoCargaForzada(aInstrumentos,QTY_INSTRUMENTOS);
	musicoCargaForzada(aMusicos,QTY_MUSICOS);
	do {
		printf( "1. Alta de orquesta\n"
				"2. Baja de orquesta\n"
				"3. Listado orquesta\n"
				"4. Alta de musico\n"
				"5. Modificacion de musico\n"
				"6. Baja de musico\n"
				"7. Listado musico\n"
				"8. Alta de instrumento\n"
				"9. Listado instrumento\n"
				"10. Informes\n"
				"0. Salir\n");
		getInt(&opcion, "Ingrese la opcion\n", "Error\n", 0, 11, 2);
		switch(opcion)
		{
		case 1:
			orquestaUIAlta(aOrquestas, QTY_ORQUESTAS);
			break;
		case 2:
			orquestaUIBaja(aOrquestas, QTY_ORQUESTAS);
			break;
		case 3:
			orquestaImprimirArray(aOrquestas, QTY_ORQUESTAS);
			break;
		case 4:
			musicoUIAlta(aMusicos, QTY_MUSICOS,aInstrumentos, QTY_INSTRUMENTOS,aOrquestas, QTY_ORQUESTAS);
			break;
		case 5:
			musicoUIModificacion(aMusicos, QTY_MUSICOS,aOrquestas, QTY_ORQUESTAS);
			break;
		case 6:
			musicoUIBaja(aMusicos, QTY_MUSICOS);
			break;
		case 7:
			musicoImprimirArray(aMusicos, QTY_MUSICOS,aInstrumentos, QTY_INSTRUMENTOS);
			break;
		case 8:
			instrumentoUIAlta(aInstrumentos, QTY_INSTRUMENTOS);
			break;
		case 9:
			instrumentoImprimirArray(aInstrumentos, QTY_INSTRUMENTOS);
			break;
		case 10:
			printf( "a. Listado orquestas con mas de 5 musicos\n"
					"b. \n"
					"c. \n"
					"d. \n"
					"e. \n"
					"f. \n"
					"g. \n"
					"h. \n"
					"\n");
			getChar(&opcion2, "Ingrese la opcion\n", "Error\n", 'a', 'h', 2);
			switch(opcion2)
			{
			case 'a':

				break;
			}
			break;
		}
	}while(opcion!=0);
	return 0;
}


void orquestaCargaForzada(Orquesta *list, int len)
{
	char aNombre[][QTY_CARACTERES]={"La Filarmonica","Corintia","Angeles","Corus","La Sonata"};
	char aLugar[][QTY_CARACTERES]={"USA","España","Finlandia","Canada","Suecia"};
	int aTipo[]={1,1,2,3,2};
	Orquesta buffer;
	int i;
	for(i=0;i<5;i++){
		strncpy(buffer.nombre,aNombre[i],QTY_CARACTERES);
		strncpy(buffer.lugar,aLugar[i],QTY_CARACTERES);
		buffer.tipo = aTipo[i];

		orquestaAltaPorId(list, len, buffer);
	}

}
void instrumentoCargaForzada(Instrumento *list, int len)
{
	char aNombre[][QTY_CARACTERES]={"Harpa","Tambor","Flauta","Trombon","Violin"};
	int aTipo[]={1,4,2,3,1};
	Instrumento buffer;
	int i;
	for(i=0;i<5;i++){
		strncpy(buffer.nombre,aNombre[i],QTY_CARACTERES);
		buffer.tipo = aTipo[i];
		instrumentoAltaPorId(list, len, buffer);
	}

}
void musicoCargaForzada(Musico *list, int len)
{
	char aNombre[][QTY_CARACTERES]={"Vanessa","Pepe","Julian","Emilia","Alejandro"};
	char aApellido[][QTY_CARACTERES]={"Mae","Luna","Straus","Sala","Batuta"};
	int aEdad[]={35,65,25,32,43};
	int aIdOrquesta[]={1,1,2,3,2};
	int aIdInstrumento[]={5,1,3,3,4};
	Musico buffer;
	int i;
	for(i=0;i<5;i++){
		strncpy(buffer.nombre,aNombre[i],QTY_CARACTERES);
		strncpy(buffer.apellido,aApellido[i],QTY_CARACTERES);
		buffer.edad = aEdad[i];
		buffer.idOrquesta = aIdOrquesta[i];
		buffer.idInstrumento = aIdInstrumento[i];

		musicoAltaPorId(list, len, buffer);
	}

}
