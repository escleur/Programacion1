#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Pantalla.h"

int main(void) {

	struct sPantalla aPantallas[QTY_PANTALLAS];

	struct sPantalla bPantalla;

	int opcion;
	char conf;
	int id;

	initLugarLibrePantalla(aPantallas, QTY_PANTALLAS);

	do {

		printf("1. Alta\n"
				"2. Baja\n"
				"3. Modificacion\n"
				"4. Listado\n"
				"5. Ordenar\n"
				"6. Salir\n");

		getInt(&opcion, "Ingrese la opcion\n", "Error", 0, 9, 2);

		switch (opcion) {
		case 1:
			printf("Alta de pantallas\n");
			if (buscarLugarLibrePantalla(aPantallas, QTY_PANTALLAS) == -1) {
				printf("Error no hay mas lugar para pantallas");
				break;
			}
			if (getString(bPantalla.nombre, "Ingrese el nombre\n", "Error", 1,
					49, 2) == -1) {
				printf("Error en el nombre\n");
				break;
			}
			if (getString(bPantalla.direccion, "Ingrese la direccion\n",
					"Error", 1, 49, 2) == -1) {
				printf("Error en la direccion\n");
				break;
			}
			if (getFloat(&bPantalla.precio, "Ingrese el precio\n", "Error", 0,
					1000000, 2) == -1) {
				printf("Error en el precio\n");
				break;
			}
			if (getInt(&bPantalla.tipo, "Ingrese el tipo 1-lcd 2-led\n", "Error",
					1, 2, 2) == -1) {
				printf("Error en el tipo\n");
				break;
			}
			if (altaPantallaPorId(aPantallas, QTY_PANTALLAS, bPantalla) == 0) {
				printf("Alta exitosa\n");
			} else {
				printf("Error al hacer el alta\n");

			}

			break;
		case 3:
			printf("Baja\n");
			getInt(&id,"Ingrese el id para dar de baja","Error",0,100000,2);
			getChar(&conf,"Ingrese s para confirmar la baja","Error",'a', 'z', 2);
			if(bajaPantallaPorId(aPantallas,QTY_PANTALLAS,id)==0){
				printf("Baja exitosa\n");
			}else{
				printf("Error al dar baja, verifique que el id existe\n");
			}
			break;




		case 9:
			imprimirArrayPantallas(aPantallas, QTY_PANTALLAS);
			break;
		}

	} while (opcion != 0);

	return EXIT_SUCCESS;
}
