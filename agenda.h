#ifndef AGENDA_H
#define AGENDA_H

#include <time.h>

#define MAX_TURNOS 100

typedef struct {
    char nombre[100];
    time_t fecha;
} Turno;

int agregarTurno(Turno *agenda, int *numTurnos, const char *nombre, const char *fechaStr);
void mostrarTurnos(Turno *agenda, int numTurnos);
int guardarAgenda(Turno *agenda, int numTurnos, const char *nombreArchivo);
int cargarAgenda(Turno *agenda, int *numTurnos, const char *nombreArchivo);

#endif /* AGENDA_H */

