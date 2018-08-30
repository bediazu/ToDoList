/*
    PROYECTO ESTRUCTURA DE DATOS

    BRUNO ESTEBAN DIAZ URETA
    DANIEL ALEJANDRO DELGADO ZAMBRANO
    BRUNO ANTONIO AGUILAR BURGOS

*/

#include "form.h"

Form* createForm()
{
    Form* nuevo_formulario = (Form*)malloc(sizeof(Form));

    nuevo_formulario->builder=NULL;
    nuevo_formulario->main_form=(MainForm*)malloc(sizeof(MainForm));
    nuevo_formulario->tareas_form=(TareasForm*)malloc(sizeof(TareasForm));
    nuevo_formulario->dialog_form=(DialogForm*)malloc(sizeof(DialogForm));
    nuevo_formulario->about_form=(AboutForm*)malloc(sizeof(AboutForm));

    nuevo_formulario->tree_low_level=createTreeMap(lower_than);
    nuevo_formulario->tree_medium_level=createTreeMap(lower_than);
    nuevo_formulario->tree_high_level=createTreeMap(lower_than);

    return nuevo_formulario;
}
