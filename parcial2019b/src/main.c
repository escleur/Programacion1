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

#include "Cliente.h"
#include "Pedido.h"
#include "utn.h"
#include "UI.h"

void clienteCargaForzada(Cliente *list, int len);

int main(void) {
	Cliente aClientes[QTY_CLIENTES];
	Pedido aPedidos[QTY_PEDIDOS];
	int opcion;
	cliente_InitLugarLibre(aClientes, QTY_CLIENTES);
	pedido_InitLugarLibre(aPedidos, QTY_PEDIDOS);
	clienteCargaForzada(aClientes,QTY_CLIENTES);
	do {
		printf( "1. Alta de cliente\n"
				"2. Modificacion de clientes\n"
				"3. Baja de cliente\n"
				"4. Pedido de recoleccion\n"
				"5. Procesar residuos\n"
				"0. Salir\n");
		getInt(&opcion, "Ingrese la opcion\n", "Error\n", 0, 11, 2);
		switch(opcion)
		{
		case 1:
			cliente_UIAlta(aClientes, QTY_CLIENTES);
			break;
		case 2:
			cliente_UIModificacion(aClientes, QTY_CLIENTES);
			break;
		case 3:
			cliente_UIBaja(aClientes, QTY_CLIENTES);
			break;
		case 4:
			pedido_UIAlta(aPedidos , QTY_PEDIDOS, aClientes , QTY_CLIENTES);
			//cliente_ImprimirArray(aClientes, QTY_CLIENTES);
			break;
		case 5:
			pedido_UIModificacion(aPedidos, QTY_PEDIDOS);
			break;
		}
	}while(opcion!=0);
	return 0;
}

void clienteCargaForzada(Cliente *list, int len)
{
	char aNombre[][QTY_CARACTERES]={"Los tipos","Corintia","Angeles","Corus","La Sonata"};
	char aCuit[][QTY_CARACTERES]={"3283283284","895375743","723178762","23298383","218988394"};
	char aDireccion[][QTY_CARACTERES]={"tacuari ","chile","independencia","chacabuco","chile"};
	char aLocalidad[][QTY_CARACTERES]={"Nuñes","Martines","lomas","devoto","chacarita"};
	Cliente buffer;
	int i;
	for(i=0;i<5;i++){
		strncpy(buffer.nombre,aNombre[i],QTY_CARACTERES);
		strncpy(buffer.cuit,aCuit[i],QTY_CARACTERES);
		strncpy(buffer.direccion,aDireccion[i],QTY_CARACTERES);
		strncpy(buffer.localidad,aLocalidad[i],QTY_CARACTERES);

		cliente_AltaPorId(list, len, buffer);
	}

}
/*
void pedidoCargaForzada(Cliente *list, int len)
{
	int aCantidad[]={1000,100,150,10,1000};
	char aEstado[][QTY_CARACTERES]={"Pendiente","Pendiente","Completado","Pendiente","Pendiente"};
	char aDireccion[][QTY_CARACTERES]={"tacuari ","chile","independencia","chacabuco","chile"};
	char aLocalidad[][QTY_CARACTERES]={"Nuñes","Martines","lomas","devoto","chacarita"};
	Cliente buffer;
	int i;
	for(i=0;i<5;i++){
		strncpy(buffer.nombre,aNombre[i],QTY_CARACTERES);
		strncpy(buffer.cuit,aCuit[i],QTY_CARACTERES);
		strncpy(buffer.direccion,aDireccion[i],QTY_CARACTERES);
		strncpy(buffer.localidad,aLocalidad[i],QTY_CARACTERES);

		cliente_AltaPorId(list, len, buffer);
	}

}
*/



