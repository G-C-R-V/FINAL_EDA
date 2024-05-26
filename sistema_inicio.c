// sistema_inicio.c

#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#include "clientes.h"


void cliente() {
	ejecutar_cliente();
    // Agrega aqu� la l�gica para la opci�n cliente
}

void empleado() {
    printf("Ingresando...\n");
    sistema_login();  // Agrega aqu� la l�gica para la opci�n empleado
}


void mostrar_menu_principal() {
    int opcion;
    do {
        printf("BIENVENIDO\n");
        printf("\nIngresar como:\n");
        printf("1. cliente\n");
        printf("2. empleado\n");
        printf("3. salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        system("cls");  // Opci�n para limpiar la pantalla (en Windows)
        
        switch (opcion) {
            case 1:
                cliente();
                break;
            case 2:
                empleado(); // Llama al men� de empleado
                break;
            case 3:
                return; // Salir del programa
            default:
                printf("Opcion no valida. Por favor, seleccione nuevamente.\n");
                break;
        }
        
    } while (opcion != 3); // Salir cuando se selecciona la opci�n "salir"
}





int main() {
    mostrar_menu_principal();
    return 0;
}
