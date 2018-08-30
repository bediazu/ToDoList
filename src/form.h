/*
    PROYECTO ESTRUCTURA DE DATOS

    BRUNO ESTEBAN DIAZ URETA
    DANIEL ALEJANDRO DELGADO ZAMBRANO
    BRUNO ANTONIO AGUILAR BURGOS

*/

#ifndef FORM_H_INCLUDED
#define FORM_H_INCLUDED

#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include "treeMap.h"

typedef struct
{
    /**<Ventana>**/
    GtkWidget* ventana;

    /**Calendario>**/
    GtkWidget* calendario;

    /**<Botones>**/
    GtkWidget* boton_ok;

        /**<Botones de menu>**/
        GtkWidget* boton_menu_nuevo;
        GtkWidget* boton_menu_guardar;
        GtkWidget* boton_menu_salir;
        GtkWidget* boton_menu_eliminar;
        GtkWidget* boton_menu_formateo;
        GtkWidget* boton_menu_acerca_de;

        /**<Botones de menu> (Visualizacion)**/
        GtkWidget* boton_ver_tareas_hoy;
        GtkWidget* boton_ver_tareas_semana;
        GtkWidget* boton_ver_tareas_mes;
        GtkWidget* boton_ver_tareas_todas;

        /**<Botones de radio>**/
        GtkWidget* boton_radio1;
        GtkWidget* boton_radio2;
        GtkWidget* boton_radio3;

    /**<TextBox>**/
    GtkWidget* textbox;

    /**<ListStore>**/
    GtkWidget* liststore;

    /**<TreeView>**/
    GtkWidget* treeview;

}MainForm;


typedef struct
{
    /**<Ventana>**/
    GtkWidget* ventana;

    /**<Botones>**/
    GtkWidget* boton;
    GtkWidget* boton_salir;
    GtkWidget* spin_button;

    /**<ListStore>**/
    GtkWidget* liststore;

}TareasForm;

typedef struct
{
    /**<Ventana>**/
    GtkWidget* ventana;

    /**<Botones>**/
    GtkWidget* boton_cancelar;
    GtkWidget* boton_aceptar;

}DialogForm;

typedef struct
{
    /**<Ventana>**/
    GtkWidget* ventana;

    /**<Botones>**/
    GtkWidget* boton_cancelar;

}AboutForm;

typedef struct
{
    /**<<Ventanas>>**/
    MainForm* main_form; //Representa la ventana principal con todos sus componentes
    TareasForm* tareas_form; //Representa la ventana de eliminacion con todos sus componentes
    DialogForm* dialog_form; //Representa el cuadro de dialogo del formateo
    AboutForm* about_form; //Representa la ventana de informacion acerca_de

    /**<Constructor> (Carga la plantilla)**/
    GtkBuilder* builder;

    /**<Arboles>**/
    TreeMap* tree_low_level;
    TreeMap* tree_medium_level;
    TreeMap* tree_high_level;
}Form;

/**<Funcion constructora del tipo de dato Form>**/
Form* createForm();

#endif // FORM_H_INCLUDED
