/*

Aqui se desarrolla el entorno para empleados
su acceso es restringido por lo que unicamente una persona
con las credenciales correctas puede ver esta seccion.


*/


// Liberias Utilizadas
#include <stdio.h>
#include <string.h>
#include "empleados.h"
#include "base_de_datos.h"




/*
	LOGIN
*/



// Funcion para restringir el acceso a la seccion de empleados
void sistema_login() {
	
    char usuario[LONGITUD + 1], clave[LONGITUD + 1]; // Variables para almacenar el ingreso de datos
    int intento = 0;
	
	// Bucle que se ejecutara hasta que intento sea igual a 3
    while (intento < MAX_INTENTOS) {
    	// Login
    	system("cls");
    	printf("Bienvenido al sistema de empleados\n");
    	printf("Por favor ingrese usuario y clave para acceder\n");
        printf("\nINICIO DE SESION");
        printf("\n-------------------");
        printf("\nUSUARIO: ");
        gets(usuario);
        printf("\nCLAVE: ");
        gets(clave);

		
		// Si los datos ingresados coinciden con las credenciales se concede el acceso
        if (strcmp(usuario, USUARIO) == 0 && strcmp(clave, CLAVE) == 0) { 
            printf("\nSISTEMA DE EMPLEADOS \n");
            system("cls");
            ejecutar_empleado();// Ejecuta la seccion de empleados
            break;
        }
        // Si la condicion no es cumplida el acceso no es otorgado
        else {
        	system("cls");
            printf("\nUsuario y/o clave incorrectos\n");
            intento++; // se incrementa el valor de 'intento' para evitar intentos infinitos
        }
    }
    
    
	
	// Si se llega a los 3 intentos se muestra mensaje
    if (intento == MAX_INTENTOS) {
    	
        printf("\nDemasiados intentos fallidos. Bloqueando el acceso.\n");
        
    }

}






/*
	FUNCIONES PARA EMPLEADOS
*/



// Funcion para ver los turnos agendados 
void lista_turnos(){
	printf("Turnos Agendados\n");
	mostrar_contenido("turnos_db.csv");
}



// Funcion para agregar nuevos turnos 
void agregar_turnos(){
	printf("Para agregar un nuevo turno\n");
	printf("ingrese nombre, apellido,dia, hora, servicio, telefono \n");
	printf("\nATENCION: debe separar los valores por comas \n");
	agregar_fila("turnos_db.csv");
}



// Funcion para eliminar turnos 
void eliminar_turnos(){
	int fila_a_eliminar;
	printf("Para eliminar un servicio ingrese el valor de fila\n");
	printf("fila a eliminar: ");
	scanf("%i",&fila_a_eliminar);
	eliminar_fila("turnos_db.csv", fila_a_eliminar);
}



// Funcion para ver los empleados registrados 
void lista_empleados(){
	printf("\nLISTA=\n");
	mostrar_contenido("lista_empleados_db.csv");
}



// Funcion para registrar un nuevo empleado 
void agregar_empleado(){
	printf("Para agregar un nuevo empleado\n");
	printf("ingrese nombre, apellido y cargo \n");
	printf("\nATENCION: debe separar los valores por comas \n");
	agregar_fila("lista_empleados_db.csv");
}



// Funcion para eliminar un empleado 
void eliminar_empleado(){
	int fila_a_eliminar;
	printf("Para eliminar un servicio ingrese el valor de fila\n");
	printf("fila a eliminar: ");
	scanf("%i",&fila_a_eliminar);
	eliminar_fila("lista_empleados_db.csv", fila_a_eliminar);
}



// Funcion para ver los servicios ofrecidos
void lista_servicios(){
	printf("\nLISTA=\n");
	mostrar_contenido("lista_servicios_db.csv");
}



// Funcion para agregar un nuevo servicio
void agregar_servicio(){
	printf("Para agregar un nuevo empleado\n");
	printf("ingrese servicio y costo \n");
	printf("\nATENCION: debe separar los valores por comas \n");
	agregar_fila("lista_servicios_db.csv");
}



// Funcion para eliminar un servicio ofrecido
void eliminar_servicio(){
	int fila_a_eliminar;
	printf("Para eliminar un servicio ingrese el valor de fila\n");
	printf("fila a eliminar: ");
	scanf("%i",&fila_a_eliminar);
	eliminar_fila("lista_servicios_db.csv", fila_a_eliminar);
}



/*
	SECCION DE EMPLEADOS 
*/



// Funcion para ejecuta la seccion de empleados (acceso restringido)
void ejecutar_empleado() {
	
    int opcion, opcion_agenda, opcion_empleados; // variables para las opciones a seleccionar en los menus 
    int seguir = 1; // variable dedicada para el control del bucle while

    do {
    	// Menu Principal en la seccion empleados 
        printf("Donde desea ir:\n");
        printf("1. Agenda de Turnos\n");
        printf("2. Lista de Empleados\n");
        printf("3. Lista de Servicios\n");
        printf("4. volver\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion); 
        getchar(); // Limpia el buffer de entrada
        system("cls"); // Limpia el contenido en pantalla

        switch (opcion) {
        	
            case 1:
                do {
                	// Menu para la opcion 1. Agenda de turnos
                    printf("\nAGENDA:\n");
                    printf("1. Mostrar turnos agendados\n");
                    printf("2. Agregar un nuevo turno\n");
                    printf("3. Eliminar turno agendado\n");
                    printf("4. Volver\n");
                    printf("Seleccione una opcion: ");
                    scanf("%d", &opcion_agenda);
                    getchar(); // Limpiar el buffer de entrada
                    system("cls");// Limpia el contenido en pantalla

                    switch (opcion_agenda) {
                    	
                        case 1:
                            lista_turnos(); 		// ejecuta la funcion lista_turnos
                        break;
                        
                        case 2:
                            agregar_turnos(); 		// ejecuta la funcion agregar_turnos
                        break;
                        
                        case 3:
                            eliminar_turnos(); 		// ejecuta la funcion eliminar_turnos
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
            		// Menu para la opcion 2. Lista de empleados
                    printf("\nEMPLEADOS:\n");
                    printf("1. Mostrar la lista de empleados\n");
                    printf("2. Agregar nuevo empleado a la lista\n");
                    printf("3. Eliminar un empleado de la lista\n");
                    printf("4. Volver\n");
                    printf("Seleccione una opcion: ");
                    scanf("%d", &opcion_empleados);
                    getchar(); // Limpiar el buffer de entrada
                    system("cls");// Limpia el contenido en pantalla

                    switch (opcion_empleados) {
                    	
                        case 1:
                            lista_empleados();		// ejecuta la funcion lista_empleados
                        break;
                        
                        case 2:
                            agregar_empleado();		// ejecuta la funcion agregar_empleado
                        break;
                        
                        case 3:
                            eliminar_empleado();	// ejecuta la funcion eliminar_empleado
                        break;
                        
                        case 4:
                            system("cls");
                        break;
                        
                        default:
                            printf("Opcion no valida. Por favor, seleccione nuevamente.\n");
                        break;
                    }
                } while (opcion_empleados != 4);
            break;
                
            case 3:
                do {
                	// Menu para la opcion 3. Lista de servicios
                    printf("\nSERVICIOS:\n");
                    printf("1. Mostrar servicios ofrecidos\n");
                    printf("2. Agregar nuevo servicio\n");
                    printf("3. Eliminar un servicio de la lista\n");
                    printf("4. Volver\n");
                    printf("Seleccione una opcion: ");
                    scanf("%d", &opcion_empleados);
                    getchar(); // Limpiar el buffer de entrada
                    system("cls");// Limpia el contenido en pantalla

                    switch (opcion_empleados) {
                    	
                        case 1:
                            lista_servicios();		// ejecuta la funcion lista_servicios
                        break;
                        
                        case 2:
                            agregar_servicio();		// ejecuta la funcion agregar_servicio
                        break;
                        
                        case 3:
                            eliminar_servicio();	// ejecuta la funcion eliminar_servicio
                        break;
                        
                        case 4:
                            system("cls");			// Limpia el contenido en pantalla
                        break;
                        
                        default:
                            printf("Opcion no valida. Por favor, seleccione nuevamente.\n");
                        break;
                    }
                } while (opcion_empleados != 4); 	// Finaliza el bucle cuando se selecciona la opción "4. salir"
            break;
                
            case 4:
                seguir = 0; 						// Salir del menu principal
                system("cls");						// Limpia el contenido en pantalla
            break;
                
            default:
                printf("Opcion no valida. Por favor, seleccione nuevamente.\n");
            break;
        }
    } while (seguir);
}






