#include "tarea.h"

Tarea* createTarea(char* nombre,int key,int dia,int mes,int anio,int prioridad)
{
    Tarea* nueva_tarea = (Tarea*)malloc(sizeof(Tarea));
    nueva_tarea->nombre=(char*)malloc(sizeof(char)*100);
    strcpy(nueva_tarea->nombre,nombre);
    nueva_tarea->key=key;
    nueva_tarea->dia=dia;
    nueva_tarea->mes=mes;
    nueva_tarea->anio=anio;
    nueva_tarea->prioridad=prioridad;

    return nueva_tarea;
}


