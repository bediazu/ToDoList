/*
    PROYECTO ESTRUCTURA DE DATOS

    BRUNO ESTEBAN DIAZ URETA
    DANIEL ALEJANDRO DELGADO ZAMBRANO
    BRUNO ANTONIO AGUILAR BURGOS

*/

#ifndef FILE_CSV_H_INCLUDED
#define FILE_CSV_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
#include <ctype.h>

#include <gtk/gtk.h>

#include "tarea.h"
#include "form.h"

#define MAX_NOMBRE 101

/*

    Funciones de lectura y escritura para archivos .csv

    Muchas de estas funciones fueron obtenidas por tareas anteriores :D

*/

/**<Funcion para obtener un valor numerico de la lectura de un archivo csv>**/
int get_number_int(FILE* archivo);

/**<Funcion que almacena todas las tareas en un archivo csv>**/
void guardar_todo(GtkWidget* widget,Form* formulario);

/**<Funcion que almacena una tarea en un archivo csv>**/
void guardar_tarea(Tarea* tarea);

/**<Funciones para un archivo csv>**/
void jump_line(FILE* archivo);
char* get_token(FILE* archivo);
int contador_lineas(FILE* archivo);

#endif // FILE_CSV_H_INCLUDED
