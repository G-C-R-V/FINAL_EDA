#include "agenda.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strptime(const char *buf, const char *format, struct tm *tm) {
    return strptime(buf, format, tm);
}

int agregarTurno(Turno *agenda, int *numTurnos, const char *nombre, const char *fechaStr) {
    if (*numTurnos < MAX_TURNOS) {
        strcpy(agenda[*numTurnos].nombre, nombre);

        struct tm tm;
        strptime(fechaStr, "%Y/%m/%d %H:%M", &tm);
        agenda[*numTurnos].fecha = mktime(&tm);

        (*numTurnos)++;
        return 1; // Turno agregado correctamente
    } else {
        return 0; // No se pueden agregar más turnos, agenda llena
    }
}

void mostrarTurnos(Turno *agenda, int numTurnos) {
    printf("\n--- Turnos en la agenda ---\n");
    int i; // Mover la declaración fuera del bucle
    for (i = 0; i < numTurnos; i++) {
        printf("Turno %d:\n", i+1);
        printf("Nombre: %s\n", agenda[i].nombre);
        printf("Fecha: %s", ctime(&agenda[i].fecha));
    }
}

int guardarAgenda(Turno *agenda, int numTurnos, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        return 0; // Error al abrir el archivo
    }

    int i; // Mover la declaración fuera del bucle
    for (i = 0; i < numTurnos; i++) {
        fprintf(archivo, "%s %ld\n", agenda[i].nombre, agenda[i].fecha);
    }

    fclose(archivo);
    return 1; // Agenda guardada correctamente
}


int cargarAgenda(Turno *agenda, int *numTurnos, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        return 0; // No se encontró el archivo
    }

    while ((*numTurnos < MAX_TURNOS) && (fscanf(archivo, "%s %ld", agenda[*numTurnos].nombre, &agenda[*numTurnos].fecha) == 2)) {
        (*numTurnos)++;
    }

    fclose(archivo);
    return 1; // Agenda cargada correctamente
}

