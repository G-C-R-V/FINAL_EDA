#include <stdio.h>
#include <string.h>
#include "empleados.h"
#include "base_de_datos.h"

void lista_turnos(){
	printf("Turnos Agendados\n");
	mostrar_contenido("turnos_db.csv");
}


void agregar_turnos(){
	printf("Para agregar un nuevo turno\n");
	printf("ingrese nombre, apellido,dia, hora, servicio, telefono \n");
	printf("\nATENCION: debe separar los valores por comas \n");
	agregar_fila("turnos_db.csv");
}

void eliminar_turnos(){
	int fila_a_eliminar;
	printf("Para eliminar un servicio ingrese el valor de fila\n");
	printf("fila a eliminar: ");
	scanf("%i",&fila_a_eliminar);
	eliminar_fila("turnos_db.csv", fila_a_eliminar);
}





void lista_empleados(){
	printf("\nLISTA=\n");
	mostrar_contenido("lista_empleados_db.csv");
}


void agregar_empleado(){
	printf("Para agregar un nuevo empleado\n");
	printf("ingrese nombre, apellido y cargo \n");
	printf("\nATENCION: debe separar los valores por comas \n");
	agregar_fila("lista_empleados_db.csv");
}

void eliminar_empleado(){
	int fila_a_eliminar;
	printf("Para eliminar un servicio ingrese el valor de fila\n");
	printf("fila a eliminar: ");
	scanf("%i",&fila_a_eliminar);
	eliminar_fila("lista_empleados_db.csv", fila_a_eliminar);
}





void lista_servicios(){
	printf("\nLISTA=\n");
	mostrar_contenido("lista_servicios_db.csv");
}

void agregar_servicio(){
	printf("Para agregar un nuevo empleado\n");
	printf("ingrese servicio y costo \n");
	printf("\nATENCION: debe separar los valores por comas \n");
	agregar_fila("lista_servicios_db.csv");
}

void eliminar_servicio(){
	int fila_a_eliminar;
	printf("Para eliminar un servicio ingrese el valor de fila\n");
	printf("fila a eliminar: ");
	scanf("%i",&fila_a_eliminar);
	eliminar_fila("lista_servicios_db.csv", fila_a_eliminar);
}





void ejecutar_empleado() {
    int opcion, opcion_agenda, opcion_empleados;
    int seguir = 1;

    do {
        printf("Que desea ver:\n");
        printf("1. Agenda de Turnos\n");
        printf("2. Lista de Empleados\n");
        printf("3. Lista de Servicios\n");
        printf("4. volver\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar el buffer de entrada
        system("cls");

        switch (opcion) {
        	
            case 1:
                do {
                    printf("\nAGENDA:\n");
                    printf("1. Mostrar turnos agendados\n");
                    printf("2. Agregar un nuevo turno\n");
                    printf("3. Eliminar turno agendado\n");
                    printf("4. Volver\n");
                    printf("Seleccione una opcion: ");
                    scanf("%d", &opcion_agenda);
                    getchar(); // Limpiar el buffer de entrada
                    system("cls");

                    switch (opcion_agenda) {
                        case 1:
                            lista_turnos();
                            break;
                        case 2:
                            agregar_turnos();
                            break;
                        case 3:
                            eliminar_turnos();
                            break;
                        case 4:
                            system("cls");
                            break;
                        default:
                            printf("Opcion no valida. Por favor, seleccione nuevamente.\n");
                            break;
                    }
                } while (opcion_agenda != 4);
            break;
            
                
            case 2:
            	do {
                    printf("\nEMPLEADOS:\n");
                    printf("1. Mostrar la lista de empleados\n");
                    printf("2. Agregar nuevo empleado a la lista\n");
                    printf("3. Eliminar un empleado de la lista\n");
                    printf("4. Volver\n");
                    printf("Seleccione una opcion: ");
                    scanf("%d", &opcion_empleados);
                    getchar(); // Limpiar el buffer de entrada
                    system("cls");

                    switch (opcion_empleados) {
                        case 1:
                            lista_empleados();
                            break;
                        case 2:
                            agregar_empleado();
                            break;
                        case 3:
                            eliminar_empleado();
                            break;
                        case 4:
                            system("cls");
                            break;
                        default:
                            printf("Opcion no valida. Por favor, seleccione nuevamente.\n");
                            break;
                    }
                } while (opcion_empleados != 4);
                // Lógica para listar empleados
                break;
                
            case 3:
                do {
                    printf("\nSERVICIOS:\n");
                    printf("1. Mostrar servicios ofrecidos\n");
                    printf("2. Agregar nuevo servicio\n");
                    printf("3. Eliminar un servicio de la lista\n");
                    printf("4. Volver\n");
                    printf("Seleccione una opcion: ");
                    scanf("%d", &opcion_empleados);
                    getchar(); // Limpiar el buffer de entrada
                    system("cls");

                    switch (opcion_empleados) {
                        case 1:
                            lista_servicios();
                            break;
                        case 2:
                            agregar_servicio();
                            break;
                        case 3:
                            eliminar_servicio();
                            break;
                        case 4:
                            system("cls");
                            break;
                        default:
                            printf("Opcion no valida. Por favor, seleccione nuevamente.\n");
                            break;
                    }
                } while (opcion_empleados != 4);
                // Lógica para listar servicios
                break;
                
            case 4:
                seguir = 0; // Salir del bucle
                system("cls"); // Limpiar la pantalla
                break;
            default:
                printf("Opcion no valida. Por favor, seleccione nuevamente.\n");
                break;
        }
    } while (seguir);
}


void sistema_login() {
    char usuario[LONGITUD + 1], clave[LONGITUD + 1];
    int intento = 0;

    while (intento < MAX_INTENTOS) {
    	system("cls");
    	printf("Bienvenido al sistema de empleados\n");
    	printf("Por favor ingrese usuario y clave para acceder\n");
        printf("\nINICIO DE SESION");
        printf("\n-------------------");
        printf("\nUSUARIO: ");
        gets(usuario);
        printf("\nCLAVE: ");
        gets(clave);

        if (strcmp(usuario, USUARIO) == 0 && strcmp(clave, CLAVE) == 0) {
            printf("\nSISTEMA DE EMPLEADOS \n");
            system("cls");
            ejecutar_empleado();
            break; // Salir del bucle si el inicio de sesión es exitoso
        } else {
        	system("cls");
            printf("\nUsuario y/o clave incorrectos\n");
            intento++;
        }
    }

    if (intento == MAX_INTENTOS) {
    	
        printf("\nDemasiados intentos fallidos. Bloqueando el acceso.\n");
    }

}



