/* 
Universidad Provincial de Ezeiza
Trabajo Final: Estructura de Datos y Algoritmos
Estudiantes: Gianluca Curras y Lucia Rodriguez


Objetivo: Crear un programa que facilite para clientes como empleados, la gestion de turnos.
pensado principalmente para personas autonomas que ofrezcan algun tipo de servicio y para que sus clientes puedan reservar con anticipacion.
en este programa se utiliza el programa para gestionar turnos de manicuristas.
*/




// Liberias Utilizadas
#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#include "clientes.h"



// Funcion para ejecutar la seccion dedicada al cliente
void cliente() {
	ejecutar_cliente();
}



// Funcion para ejecutar la seccion dedicada al empleado
void empleado() {
    sistema_login();
}



// Menu de Inicio.
void mostrar_menu_principal() {
	
    int opcion; 				// variable para almacenar la opcion seleccionada en el menu
    
    do {		
    	
        printf("BIENVENIDO\n");
        printf("\nIngresar como:\n");
        printf("1. cliente\n");
        printf("2. empleado\n");
        printf("3. salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        system("cls");  		
        
        switch (opcion) {
        	
            case 1:
                cliente();		// Llama al menú de cliente
            break;
                
            case 2:
                empleado();		// Llama al menú de empleado
            break;
                
            case 3:
                return;			// Salir del programa
            break;    
                
            default:
                printf("Opcion no valida. Por favor, seleccione nuevamente.\n");
            break;
        }
        
    } while (opcion != 3); 		// Salir del bucle cuando se selecciona la opción "3. salir"
}




// Main
int main() {
    mostrar_menu_principal();   // Ejecuta el menu de inicio
    return 0;
}
