#ifndef TAREA_H_INCLUDED
#define TAREA_H_INCLUDED

#include <stdlib.h>
#include <string.h>


typedef struct
{
    char* nombre;
    int key;
    int prioridad;

    int dia;
    int mes;
    int anio;

    char* informacion;

}Tarea;

Tarea* createTarea(char* nombre,int key,int dia,int mes,int anio,int prioridad);

#endif // TAREA_H_INCLUDED
