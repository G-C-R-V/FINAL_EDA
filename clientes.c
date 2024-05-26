#include <stdio.h>
#include <string.h>
#include "clientes.h"
#include "base_de_datos.h"

void servicios(){
	printf("Servicios Disponibles:\n");
	mostrar_contenido("lista_servicios_db.csv");
}


void ejecutar_cliente() {
    int opcion, opcion_agenda, opcion_empleados;
    int seguir = 1;

    do {
    	servicios();
    	printf("\n\nQue desea hacer:\n");
        printf("1. Sacar Turno\n");
        printf("2. volver\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar el buffer de entrada
        system("cls");

        switch (opcion) {
        	
        	case 1:
        		printf("prueba");
        		break;
        		
        	case 2:
        		seguir = 0; // Salir del bucle
                system("cls"); // Limpiar la pantalla
        		break;
        		
        	default:
        		printf("opcion incorrecta");
        		break;
	
	
	}
  } while (seguir);
}
