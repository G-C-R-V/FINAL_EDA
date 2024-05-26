/*

Aqui se desarrolla el entorno para empleados
su acceso es restringido por lo que unicamente una persona
con las credenciales correctas puede ver esta seccion.


*/


// Liberias Utilizadas
#include <stdio.h>
#include <string.h>
#include "clientes.h"
#include "base_de_datos.h"



// Funcion para mostrar la lista de servicios
void servicios(){
	printf("Servicios Disponibles:\n");
	mostrar_contenido("lista_servicios_db.csv");
}



// Funcion para enviar un turno a la agenda
void solicitar_turno(){
	printf("Para agregar un nuevo turno\n");
	printf("ingrese nombre, apellido,dia, hora, servicio, telefono \n");
	printf("\nATENCION: debe separar los valores por comas \n");
	agregar_fila("turnos_db.csv");
}



// Funcion para ejecutar la seccion de clientes
void ejecutar_cliente() {
    int opcion, opcion_agenda, opcion_empleados;
    int seguir = 1;

    do {
    	// Menu principal
    	servicios();
    	printf("\n\nQue desea hacer:\n");
        printf("1. Sacar Turno\n");
        printf("2. volver\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); 					// Limpiar el buffer de entrada
        system("cls");

        switch (opcion) {
        	
        	case 1:
        		solicitar_turno(); // Ejecuta la funcion para enviar un turno
        		break;
        		
        	case 2:
        		seguir = 0; 	   // Salir del bucle
                system("cls"); 	   // Limpiar la pantalla
        		break;
        		
        	default:
        		printf("opcion incorrecta");
        		break;
	
	
	}
  } while (seguir);
}
