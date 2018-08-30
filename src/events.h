/*
    PROYECTO ESTRUCTURA DE DATOS

    BRUNO ESTEBAN DIAZ URETA
    DANIEL ALEJANDRO DELGADO ZAMBRANO
    BRUNO ANTONIO AGUILAR BURGOS

*/

#ifndef EVENTS_H_INCLUDED
#define EVENTS_H_INCLUDED

#include <gtk/gtk.h>

#include <time.h>

#include "form.h"
#include "tarea.h"
#include "file_csv.h"
#include "treeMap.h"

/*
    En events, se encuentran todas las funciones de accion para cada componente visual

    Por ejemplo: Hacer click en algun boton

*/

/**<Funcion de ocultado simple>**/
void ocultar_ventana(GtkWidget* widget,Form* formulario);

/**<Funcion de borrado de datos>**/
void mostrar_tareas_eliminar(GtkWidget* widget,Form* formulario);
void eliminar_tarea(GtkWidget* widget,Form* formulario);
void dialogo_formateo(GtkWidget* widget,Form* formulario);
void formateo(GtkWidget* widget,Form* formulario);
void ocultar_ventana_dialogo(GtkWidget* widget,Form* formulario);

/**<Funcion de mostrar una ventana de ayuda>**/
void mostrar_acerca_de(GtkWidget* widget,Form* formulario);

/**<Funciones de visualizacion de las tareas>**/
void mostrar_tareas_hoy(GtkWidget* widget,Form* formulario);
void mostrar_tareas_semana(GtkWidget* widget,Form* formulario);
void mostrar_tareas_mes(GtkWidget* widget,Form* formulario);
void mostrar_tareas_todas(GtkWidget* widget,Form* formulario);

/**<Funcion de agregar una tarea>**/
void agregar_tarea(GtkWidget* widget,Form* formulario);


#endif // EVENTS_H_INCLUDED
