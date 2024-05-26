// lista_empleados_db.h

#ifndef LISTA_EMPLEADOS_DB_H
#define LISTA_EMPLEADOS_DB_H

#define FILENAME "turnos_bd.csv"
#define LONG__MAX 1024

// Funciones para manipular la base de datos
void mostrar_lista(const char *filename);
void agregar_filas(const char *filename);
void eliminar_filas(const char *filename, int fila_a_eliminar);

#endif // TURNOS_DB_H

