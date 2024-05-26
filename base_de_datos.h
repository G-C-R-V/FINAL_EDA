#ifndef TURNOS_DB_H
#define TURNOS_DB_H
#define LONG__MAX 1024

// Funciones para la base de datos
void mostrar_contenido(const char *filename);
void agregar_fila(const char *filename);
void eliminar_fila(const char *filename, int fila_a_eliminar);

#endif 

