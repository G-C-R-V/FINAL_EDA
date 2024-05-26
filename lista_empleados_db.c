// lista_empleados_db.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_empleados_db.h"


void verificar_o_crear_archivos(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error al crear el archivo");
        exit(EXIT_FAILURE);
    }
    fclose(file);
}

void mostrar_lista(const char *filename) {
    verificar_o_crear_archivos(filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
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

void agregar_empleado(const char *filename) {
    verificar_o_crear_archivos(filename);

    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }
    
    char nueva_fila[LONG__MAX];
    printf("Ingrese los nuevos datos separados por comas: ");
    fgets(nueva_fila, sizeof(nueva_fila), stdin);
    
    nueva_fila[strcspn(nueva_fila, "\n")] = 0;
    
    fprintf(file, "%s\n", nueva_fila);
    fclose(file);
}

void eliminar_empleado(const char *filename, int fila_a_eliminar) {
    verificar_o_crear_archivos(filename);

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

