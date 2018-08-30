/*
    PROYECTO ESTRUCTURA DE DATOS

    BRUNO ESTEBAN DIAZ URETA
    DANIEL ALEJANDRO DELGADO ZAMBRANO
    BRUNO ANTONIO AGUILAR BURGOS

*/

#include "events.h"

void mostrar_tareas_hoy(GtkWidget* widget,Form* formulario)
{
    /**<Limpieza de la lista>**/
    GtkTreeIter iter;
    gtk_list_store_clear((GtkListStore*)formulario->main_form->liststore);

    char buffer_dia[5];
    char buffer_mes[5];
    char buffer_anio[5];

    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    strftime(buffer_dia, 5, "%d", timeinfo);
    strftime(buffer_mes, 5, "%m", timeinfo);
    strftime(buffer_anio, 5, "%Y", timeinfo);

    Tarea* aux = (Tarea*)first(formulario->tree_high_level);

    while(aux)
    {

        if(aux->dia==atoi(buffer_dia) && aux->mes==atoi(buffer_mes) && aux->anio==atoi(buffer_anio))
        {
            gtk_list_store_append((GtkListStore*)formulario->main_form->liststore, &iter);
            gtk_list_store_set((GtkListStore*)formulario->main_form->liststore, &iter,0,aux->nombre,1,aux->prioridad,2,aux->dia,3,aux->mes,4,aux->anio,-1);
        }
        aux=(Tarea*)next(formulario->tree_high_level);
    }

    aux = (Tarea*)first(formulario->tree_medium_level);
    while(aux)
    {
        if(aux->dia==atoi(buffer_dia) && aux->mes==atoi(buffer_mes) && aux->anio==atoi(buffer_anio))
        {
            gtk_list_store_append((GtkListStore*)formulario->main_form->liststore, &iter);
            gtk_list_store_set((GtkListStore*)formulario->main_form->liststore, &iter,0,aux->nombre,1,aux->prioridad,2,aux->dia,3,aux->mes,4,aux->anio,-1);
        }
        aux=(Tarea*)next(formulario->tree_medium_level);
    }


    aux = (Tarea*)first(formulario->tree_low_level);
    while(aux)
    {
        if(aux->dia==atoi(buffer_dia) && aux->mes==atoi(buffer_mes) && aux->anio==atoi(buffer_anio))
        {
            gtk_list_store_append((GtkListStore*)formulario->main_form->liststore, &iter);
            gtk_list_store_set((GtkListStore*)formulario->main_form->liststore, &iter,0,aux->nombre,1,aux->prioridad,2,aux->dia,3,aux->mes,4,aux->anio,-1);
        }
        aux=(Tarea*)next(formulario->tree_low_level);
    }


}
void mostrar_tareas_semana(GtkWidget* widget,Form* formulario)
{
    /**<Limpieza de la lista>**/
    GtkTreeIter iter;
    gtk_list_store_clear((GtkListStore*)formulario->main_form->liststore);

    char buffer_dia[5];
    char buffer_mes[5];
    char buffer_anio[5];

    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );


    strftime(buffer_dia, 5, "%d", timeinfo);
    strftime(buffer_mes, 5, "%m", timeinfo);
    strftime(buffer_anio, 5, "%Y", timeinfo);

    Tarea* aux = (Tarea*)first(formulario->tree_high_level);

    while(aux)
    {

        if(aux->dia<=atoi(buffer_dia)+7 && aux->mes==atoi(buffer_mes) && aux->anio==atoi(buffer_anio))
        {
            gtk_list_store_append((GtkListStore*)formulario->main_form->liststore, &iter);
            gtk_list_store_set((GtkListStore*)formulario->main_form->liststore, &iter,0,aux->nombre,1,aux->prioridad,2,aux->dia,3,aux->mes,4,aux->anio,-1);
        }
        aux=(Tarea*)next(formulario->tree_high_level);
    }

    aux = (Tarea*)first(formulario->tree_medium_level);
    while(aux)
    {
        if(aux->dia<=atoi(buffer_dia)+7 && aux->mes==atoi(buffer_mes) && aux->anio==atoi(buffer_anio))
        {
            gtk_list_store_append((GtkListStore*)formulario->main_form->liststore, &iter);
            gtk_list_store_set((GtkListStore*)formulario->main_form->liststore, &iter,0,aux->nombre,1,aux->prioridad,2,aux->dia,3,aux->mes,4,aux->anio,-1);
        }
        aux=(Tarea*)next(formulario->tree_medium_level);
    }


    aux = (Tarea*)first(formulario->tree_low_level);
    while(aux)
    {
        if(aux->dia<=atoi(buffer_dia)+7 && aux->mes==atoi(buffer_mes) && aux->anio==atoi(buffer_anio))
        {
            gtk_list_store_append((GtkListStore*)formulario->main_form->liststore, &iter);
            gtk_list_store_set((GtkListStore*)formulario->main_form->liststore, &iter,0,aux->nombre,1,aux->prioridad,2,aux->dia,3,aux->mes,4,aux->anio,-1);
        }
        aux=(Tarea*)next(formulario->tree_low_level);
    }


}
void mostrar_tareas_mes(GtkWidget* widget,Form* formulario)
{
    /**<Limpieza de la lista>**/
    GtkTreeIter iter;
    gtk_list_store_clear((GtkListStore*)formulario->main_form->liststore);

    char buffer_dia[5];
    char buffer_mes[5];
    char buffer_anio[5];

    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    strftime(buffer_dia, 5, "%d", timeinfo);
    strftime(buffer_mes, 5, "%m", timeinfo);
    strftime(buffer_anio, 5, "%Y", timeinfo);

    Tarea* aux = (Tarea*)first(formulario->tree_high_level);

    while(aux)
    {

        if(aux->mes==atoi(buffer_mes) && aux->anio==atoi(buffer_anio))
        {
            gtk_list_store_append((GtkListStore*)formulario->main_form->liststore, &iter);
            gtk_list_store_set((GtkListStore*)formulario->main_form->liststore, &iter,0,aux->nombre,1,aux->prioridad,2,aux->dia,3,aux->mes,4,aux->anio,-1);
        }
        aux=(Tarea*)next(formulario->tree_high_level);
    }

    aux = (Tarea*)first(formulario->tree_medium_level);
    while(aux)
    {
        if(aux->mes==atoi(buffer_mes) && aux->anio==atoi(buffer_anio))
        {
            gtk_list_store_append((GtkListStore*)formulario->main_form->liststore, &iter);
            gtk_list_store_set((GtkListStore*)formulario->main_form->liststore, &iter,0,aux->nombre,1,aux->prioridad,2,aux->dia,3,aux->mes,4,aux->anio,-1);
        }
        aux=(Tarea*)next(formulario->tree_medium_level);
    }


    aux = (Tarea*)first(formulario->tree_low_level);
    while(aux)
    {
        if(aux->mes==atoi(buffer_mes) && aux->anio==atoi(buffer_anio))
        {
            gtk_list_store_append((GtkListStore*)formulario->main_form->liststore, &iter);
            gtk_list_store_set((GtkListStore*)formulario->main_form->liststore, &iter,0,aux->nombre,1,aux->prioridad,2,aux->dia,3,aux->mes,4,aux->anio,-1);
        }
        aux=(Tarea*)next(formulario->tree_low_level);
    }
}

void ocultar_ventana(GtkWidget* widget,Form* formulario)
{
    gtk_widget_hide(formulario->tareas_form->ventana);
}

void mostrar_tareas_eliminar(GtkWidget* widget,Form* formulario)
{
    gtk_widget_show_now(formulario->tareas_form->ventana);
    gtk_widget_show_all(formulario->tareas_form->ventana);

    /**<Limpieza de la lista>**/
    GtkTreeIter iter;
    gtk_list_store_clear((GtkListStore*)formulario->tareas_form->liststore);

    Tarea* aux = (Tarea*)first(formulario->tree_high_level);
    gint posicion=1;
    gdouble max_valor;

    while(aux)
    {
        gtk_list_store_append((GtkListStore*)formulario->tareas_form->liststore, &iter);
        gtk_list_store_set((GtkListStore*)formulario->tareas_form->liststore,&iter,0,posicion,1,aux->nombre,2,aux->dia,3,aux->mes,4,aux->anio,-1);
        aux=(Tarea*)next(formulario->tree_high_level);
        posicion++;
    }

    aux = (Tarea*)first(formulario->tree_medium_level);
    while(aux)
    {
        gtk_list_store_append((GtkListStore*)formulario->tareas_form->liststore, &iter);
        gtk_list_store_set((GtkListStore*)formulario->tareas_form->liststore,&iter,0,posicion,1,aux->nombre,2,aux->dia,3,aux->mes,4,aux->anio,-1);
        aux=(Tarea*)next(formulario->tree_medium_level);
        posicion++;
    }

    aux = (Tarea*)first(formulario->tree_low_level);
    while(aux)
    {
        gtk_list_store_append((GtkListStore*)formulario->tareas_form->liststore, &iter);
        gtk_list_store_set((GtkListStore*)formulario->tareas_form->liststore,&iter,0,posicion,1,aux->nombre,2,aux->dia,3,aux->mes,4,aux->anio,-1);
        aux=(Tarea*)next(formulario->tree_low_level);
        posicion++;
    }

    max_valor = posicion-1;

    gtk_spin_button_set_range((GtkSpinButton*)formulario->tareas_form->spin_button,1,max_valor);

}

void eliminar_tarea(GtkWidget* widget, Form* formulario)
{
    int valor_seleccionado = gtk_spin_button_get_value_as_int((GtkSpinButton*)formulario->tareas_form->spin_button);
    int i=1;

    printf("Valor seleccionado: %i\n",valor_seleccionado);
    int j=0;
    Tarea* aux;
    while(j<1){
        aux = (Tarea*)first(formulario->tree_high_level);
        while(aux && i<valor_seleccionado)
        {
            aux=(Tarea*)next(formulario->tree_high_level);
            i++;
        }

        if(aux && valor_seleccionado==i)
        {
            printf("<<<Eliminar tarea>>>\n");
            printf("Nombre: %s\n",aux->nombre);
            erase(formulario->tree_high_level,aux);
            break;
        }

        aux = (Tarea*)first(formulario->tree_medium_level);
        while(aux && i<valor_seleccionado)
        {
            aux=(Tarea*)next(formulario->tree_medium_level);
            i++;
        }

        if(aux && valor_seleccionado==i)
        {
            printf("<<<Eliminar tarea>>>\n");
            printf("Nombre: %s\n",aux->nombre);
            erase(formulario->tree_medium_level,aux);
            break;
        }

        aux = (Tarea*)first(formulario->tree_low_level);
        while(aux && i<valor_seleccionado)
        {
            aux=(Tarea*)next(formulario->tree_low_level);
            i++;
        }

        if(aux && valor_seleccionado==i)
        {
            printf("<<<Eliminar tarea>>>\n");
            printf("Nombre: %s\n",aux->nombre);
            erase(formulario->tree_low_level,aux);
            break;
        }
        j++;
    }

    mostrar_tareas_mes(NULL,formulario);
    mostrar_tareas_eliminar(NULL,formulario);

    guardar_todo(NULL,formulario);

}

void mostrar_tareas_todas(GtkWidget* widget,Form* formulario)
{
    /**<Limpieza de la lista>**/
    GtkTreeIter iter;
    gtk_list_store_clear((GtkListStore*)formulario->main_form->liststore);

    Tarea* aux = (Tarea*)first(formulario->tree_high_level);
    while(aux)
    {
        gtk_list_store_append((GtkListStore*)formulario->main_form->liststore, &iter);
        gtk_list_store_set((GtkListStore*)formulario->main_form->liststore, &iter,0,aux->nombre,1,aux->prioridad,2,aux->dia,3,aux->mes,4,aux->anio,-1);
        aux=(Tarea*)next(formulario->tree_high_level);
    }

    aux = (Tarea*)first(formulario->tree_medium_level);
    while(aux)
    {

        gtk_list_store_append((GtkListStore*)formulario->main_form->liststore, &iter);
        gtk_list_store_set((GtkListStore*)formulario->main_form->liststore, &iter,0,aux->nombre,1,aux->prioridad,2,aux->dia,3,aux->mes,4,aux->anio,-1);
        aux=(Tarea*)next(formulario->tree_medium_level);
    }

    aux = (Tarea*)first(formulario->tree_low_level);
    while(aux)
    {
        gtk_list_store_append((GtkListStore*)formulario->main_form->liststore, &iter);
        gtk_list_store_set((GtkListStore*)formulario->main_form->liststore, &iter,0,aux->nombre,1,aux->prioridad,2,aux->dia,3,aux->mes,4,aux->anio,-1);
        aux=(Tarea*)next(formulario->tree_low_level);
    }

}

void agregar_tarea(GtkWidget* widget,Form* formulario)
{
    GtkEntryBuffer* buffer;
    buffer=gtk_entry_get_buffer((GtkEntry*)formulario->main_form->textbox);
    gchar* msg=gtk_entry_buffer_get_text(buffer);
    buffer=NULL;

    guint* dia = (guint*)malloc(sizeof(guint));
    guint* mes = (guint*)malloc(sizeof(guint));
    guint* anio = (guint*)malloc(sizeof(guint));

    gchar* importancia_cadena=(gchar*)malloc(sizeof(gchar)*100);
    strcpy(importancia_cadena,"eale");

    int importancia;

    if(gtk_toggle_button_get_active((GtkToggleButton*)formulario->main_form->boton_radio1))
        importancia=1;
    else
        if(gtk_toggle_button_get_active((GtkToggleButton*)formulario->main_form->boton_radio2))
            importancia=2;
        else importancia=3;


    gtk_calendar_get_date((GtkCalendar*)formulario->main_form->calendario,anio,mes,dia);

    int fecha_key=*(int*)anio*10000;
    fecha_key+=*(int*)mes*100;
    fecha_key+=*(int*)dia;

    /**<La funcion de obtener la fecha del calendario entrega los meses desde 0>**/
    Tarea* nueva_tarea = createTarea((char*)msg,fecha_key,*(int*)dia,*(int*)mes+1,*(int*)anio,importancia);

    g_print("\n<<AGREGAR NUEVA TAREA>>\n");
    g_print("*Nombre: %s\n",msg);
    g_print("*Fecha: %i/%i/%i\n",*(int*)dia,*(int*)mes+1,*(int*)anio);
    g_print("*Importancia: %i\n",importancia);
    g_print("<<Key: %i>>\n",fecha_key);

    GtkTreeIter iter;

    gtk_list_store_append((GtkListStore*)formulario->main_form->liststore, &iter);
    gtk_list_store_set((GtkListStore*)formulario->main_form->liststore, &iter,0,msg,1,importancia,2,*(int*)dia,3,*(int*)mes+1,4,*(int*)anio,-1);

    switch(importancia)
    {
        case 1:
            insert(formulario->tree_low_level,nueva_tarea,nueva_tarea);
            break;
        case 2:
            insert(formulario->tree_medium_level,nueva_tarea,nueva_tarea);
            break;
        default:
            insert(formulario->tree_high_level,nueva_tarea,nueva_tarea);
            break;
    }
    g_print("<<Tarea creada con exito>>\n");
    guardar_tarea(nueva_tarea);
}

void dialogo_formateo(GtkWidget* widget, Form* formulario)
{
    gtk_widget_show_all(formulario->dialog_form->ventana);
}

void formateo(GtkWidget* widget,Form* formulario)
{
    gtk_widget_hide(formulario->dialog_form->ventana);
    gtk_list_store_clear((GtkListStore*)formulario->main_form->liststore);
    gtk_list_store_clear((GtkListStore*)formulario->tareas_form->liststore);
    if(remove("tareas.csv")==0) printf("Fichero de tareas eliminado correctamente");

    free(formulario->tree_high_level);
    free(formulario->tree_medium_level);
    free(formulario->tree_low_level);

    formulario->tree_high_level = createTreeMap(lower_than);
    formulario->tree_medium_level = createTreeMap(lower_than);
    formulario->tree_low_level = createTreeMap(lower_than);
}

void ocultar_ventana_dialogo(GtkWidget* widget,Form* formulario)
{
    gtk_widget_hide(formulario->dialog_form->ventana);
}

void mostrar_acerca_de(GtkWidget* widget,Form* formulario)
{
    gtk_widget_show_all(formulario->about_form->ventana);
}

