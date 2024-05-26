/*

Aqui se desarrollan las funciones para manejar la base de datos.

BASE DE DATOS en formato:  ".CSV"


*/


// Liberias Utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base_de_datos.h"



// Funcion para verificar la existencia del archivo  o crearlo en caso de no existir
void verificar_o_crear_archivo(const char *filename) // se apunta a una cadena de caracteres que representa el nombre del archivo
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error al crear el archivo");
        exit(EXIT_FAILURE);
    }
    fclose(file);
}



// Funcion para mostrar el contenido del archivo
void mostrar_contenido(const char *filename) {
    verificar_o_crear_archivo(filename);	 // verificacion o creacion del archivo 

    FILE *file = fopen(filename, "r"); 		 // se abre el archivo el modo lectura 'r' {read} 
    if (file == NULL) {						 // si el archivo no se encuentra...
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    char line[LONG__MAX];
    int contador = 1;
    
    while (fgets(line, sizeof(line), file)) {
        printf("%d. %s", contador++, line);
    }
    
    fclose(file);
}



// Funcion para agregar contenido al archivo
void agregar_fila(const char *filename) {
    verificar_o_crear_archivo(filename);

    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }
    
    char nueva_fila[LONG__MAX];
    printf("\nnails@system > ");
    fgets(nueva_fila, sizeof(nueva_fila), stdin);
    
    nueva_fila[strcspn(nueva_fila, "\n")] = 0;
    
    fprintf(file, "%s\n", nueva_fila);
    fclose(file);
    system("cls");
    printf("Operacion realizada exitosamente\n");
}



// Funcion para eliminar contenido del archivo
void eliminar_fila(const char *filename, int fila_a_eliminar) {
    verificar_o_crear_archivo(filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }
    
    FILE *temp_file = fopen("temp.csv", "w");
    if (temp_file == NULL) {
        perror("Error al abrir el archivo temporal");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    
    char line[LONG__MAX];
    int fila_actual = 1;
    
    while (fgets(line, sizeof(line), file)) {
        if (fila_actual != fila_a_eliminar) {
            fputs(line, temp_file);
        }
        fila_actual++;
    }
    
    fclose(file);
    fclose(temp_file);
    
    remove(filename);
    rename("temp.csv", filename);
}

