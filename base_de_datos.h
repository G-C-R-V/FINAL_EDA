#ifndef TURNOS_DB_H		// Si base_de_datos.h no esta definido
#define TURNOS_DB_H		// define base_de_datos.h
#define LONG__MAX 1024 	// Longitud maxima establecida para el n~ de lineas.

// Funciones para manipular base de datos
void mostrar_contenido(const char *filename);
void agregar_fila(const char *filename);
void eliminar_fila(const char *filename, int fila_a_eliminar);

#endif 

