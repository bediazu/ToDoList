/*
    PROYECTO ESTRUCTURA DE DATOS

    BRUNO ESTEBAN DIAZ URETA
    DANIEL ALEJANDRO DELGADO ZAMBRANO
    BRUNO ANTONIO AGUILAR BURGOS

*/

#include "src/form.h"
#include "src/events.h"

void asignacion_widgets(Form* formulario);
void asignacion_eventos(Form* formulario);
void asignacion_tareas(Form* formulario);
void asignacion_calendario(Form* formulario);

int main(int argc,char* argv[])
{
    /**<Creacion de la estructura principal del programa>**/
    Form* formulario = createForm();

    /**<Lectura de un archivo csv en caso de existir>**/
    /**<Almacena los valores del archivo en los arboles correspondientes>**/
    asignacion_tareas(formulario);

    /**<Funcion de precargado para la interfaz grafica>**/
    gtk_init(&argc,&argv);

    formulario->builder=gtk_builder_new(); //Instanciar un constructor.
    gtk_builder_add_from_file(formulario->builder,"rsc/plantilla1.glade",NULL); //Lectura del archivo plantilla

    /**<Asignacion de cada componente visual>**/
    asignacion_widgets(formulario);

    /**<Asignacion de cada evento para los componentes visual>**/
    asignacion_eventos(formulario);

    /**<Posicionar el calendario en una posicion inicial>**/
    asignacion_calendario(formulario);

    /**<Mostrar las tareas cargadas en caso de existir>**/
    mostrar_tareas_mes(NULL,formulario);

    /**<Mostrar todos los componentes visuales>**/
    gtk_widget_show_all(formulario->main_form->ventana);
    gtk_main();

    return 0;
}

/*
    (LIBRERIA GRAFICA)
    Asignacion inicial del calendario

    Dado que el componente de calendario se inicia en un valor aleatorio,
    le seleccionamos el dia actual para facilitar busqueda futuras.
*/

void asignacion_calendario(Form* formulario)
{
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


    gtk_calendar_select_month((GtkCalendar*)formulario->main_form->calendario,atoi(buffer_mes)-1,+atoi(buffer_anio));
    gtk_calendar_select_day((GtkCalendar*)formulario->main_form->calendario,atoi(buffer_dia));
}

/*
    (APLICACION DE TDA Y FICHERO CSV)

    Asignacion_tareas:

    Lee el archivo "tareas.csv" e instancia cada tarea con una respectiva estructura de datos
    "Tarea"

    Inserta cada tarea leida en los arboles de prioridad baja, media y alta.
*/

void asignacion_tareas(Form* formulario)
{
    FILE* archivo = fopen("tareas.csv","rt");
    if(!archivo) return;

    jump_line(archivo);
    int total_lineas = contador_lineas(archivo);
    fflush(archivo);
    jump_line(archivo);
    Tarea* nueva_tarea;

    int prioridad,dia,mes,anio,key;
    char* nombre;
    int i;

    for(i=0;i<total_lineas;i++)
    {
        if(i==total_lineas) break;
        fflush(stdin);
        nombre = (char*)malloc(sizeof(char)*101);
        prioridad = get_number_int(archivo);
        strcpy(nombre,get_token(archivo));

        dia = get_number_int(archivo);
        mes = get_number_int(archivo);
        anio = get_number_int(archivo);
        key = get_number_int(archivo);

        printf("<<<TAREA CARGADA>>>\n");
        printf("Prioridad: %i\n",prioridad);
        printf("Nombre: %s\n",nombre);
        printf("Dia: %i\n",dia);
        printf("Mes: %i\n",mes);
        printf("Anio: %i\n",anio);
        printf("Key :%i\n",key);
        printf("-----------------\n");

        nueva_tarea = createTarea(nombre,key,dia,mes,anio,prioridad);
        switch(prioridad)
        {
            case 1:
                insert(formulario->tree_low_level,nueva_tarea,nueva_tarea);
                break;
            case 2:
                insert(formulario->tree_medium_level,nueva_tarea,nueva_tarea);
                break;
            default:
                insert(formulario->tree_high_level,nueva_tarea,nueva_tarea);
        }
    }
    fclose(archivo);
}

/*
    (LIBRERIA GRAFICA)
    Asignacion Widgets:

    A partir del tipo de dato "GTKBUILDER" instancia cada tipo de dato con su respectivo valor.
    Es importante la asignacion previa de los elementos, para luego definir su uso

    Los tipos de datos son todos "GTKWIDGET", lo cual nos permite un manejo general de cada componente.
*/

void asignacion_widgets(Form* formulario)
{

    /**<TODOS LOS COMPONENTES (WIDGETS) SON OBTENIDOS POR MEDIO DE EL TIPO DE DATO BUILDER>**/
    /**<ESTE TIPO DE DATO SE ENCUENTRA EN "formulario->builder" >**/


    /**<VENTANA PRINCIPAL>**/

        formulario->main_form->ventana=(GtkWidget*)gtk_builder_get_object(formulario->builder,"window1");

        /**<Botones**/
        formulario->main_form->boton_menu_nuevo=(GtkWidget*)gtk_builder_get_object(formulario->builder,"imagemenuitem1");
        formulario->main_form->boton_menu_guardar=(GtkWidget*)gtk_builder_get_object(formulario->builder,"imagemenuitem3");
        formulario->main_form->boton_menu_salir=(GtkWidget*)gtk_builder_get_object(formulario->builder,"imagemenuitem5");
        formulario->main_form->boton_ok=(GtkWidget*)gtk_builder_get_object(formulario->builder,"button1");
            /**<Botones de menu>**/
            formulario->main_form->boton_ver_tareas_hoy=(GtkWidget*)gtk_builder_get_object(formulario->builder,"ver_hoy");
            formulario->main_form->boton_ver_tareas_semana=(GtkWidget*)gtk_builder_get_object(formulario->builder,"ver_semana");
            formulario->main_form->boton_ver_tareas_mes=(GtkWidget*)gtk_builder_get_object(formulario->builder,"ver_mes");
            formulario->main_form->boton_ver_tareas_todas=(GtkWidget*)gtk_builder_get_object(formulario->builder,"ver_todo");
            formulario->main_form->boton_menu_eliminar=(GtkWidget*)gtk_builder_get_object(formulario->builder,"imagemenuitem9");
            formulario->main_form->boton_menu_formateo=(GtkWidget*)gtk_builder_get_object(formulario->builder,"imagemenuitem2");
            formulario->main_form->boton_menu_acerca_de=(GtkWidget*)gtk_builder_get_object(formulario->builder,"imagemenuitem10");
            /**<Botones de radio>**/
            formulario->main_form->boton_radio1=(GtkWidget*)gtk_builder_get_object(formulario->builder,"radiobutton1");
            formulario->main_form->boton_radio2=(GtkWidget*)gtk_builder_get_object(formulario->builder,"radiobutton2");
            formulario->main_form->boton_radio3=(GtkWidget*)gtk_builder_get_object(formulario->builder,"radiobutton3");
        /**<TextBox>**/
        formulario->main_form->textbox=(GtkWidget*)gtk_builder_get_object(formulario->builder,"entry1");
        /**<Calendario>**/
        formulario->main_form->calendario=(GtkWidget*)gtk_builder_get_object(formulario->builder,"calendar1");
        /**<ListStore>**/
        formulario->main_form->liststore=(GtkWidget*)gtk_builder_get_object(formulario->builder,"liststore1");
        /**<TreeView>**/
        formulario->main_form->treeview=(GtkWidget*)gtk_builder_get_object(formulario->builder,"treeview1");

    /**<VENTA DE ELIMINACION>**/

        /**<Ventana>**/
        formulario->tareas_form->ventana=(GtkWidget*)gtk_builder_get_object(formulario->builder,"window2");

        /**<ListStore>**/
        formulario->tareas_form->liststore=(GtkWidget*)gtk_builder_get_object(formulario->builder,"liststore2");

        /**<Botones>**/

        formulario->tareas_form->boton=(GtkWidget*)gtk_builder_get_object(formulario->builder,"button2");
        formulario->tareas_form->boton_salir=(GtkWidget*)gtk_builder_get_object(formulario->builder,"button3");
        formulario->tareas_form->spin_button=(GtkWidget*)gtk_builder_get_object(formulario->builder,"spinbutton1");

    /**<VENTANA DE DIALOGO>**/

        /**<VENTANA>**/
        formulario->dialog_form->ventana=(GtkWidget*)gtk_builder_get_object(formulario->builder,"messagedialog1");
        formulario->dialog_form->boton_aceptar=(GtkWidget*)gtk_builder_get_object(formulario->builder,"button4");
        formulario->dialog_form->boton_cancelar=(GtkWidget*)gtk_builder_get_object(formulario->builder,"button5");

    /**<VENTANA ACERCA DE>**/
        formulario->about_form->ventana=(GtkWidget*)gtk_builder_get_object(formulario->builder,"aboutdialog1");
        formulario->about_form->ventana=(GtkWidget*)gtk_builder_get_object(formulario->builder,"aboutdialog1");
}

/*
    (LIBRERIA GRAFICA)
    asignacion_eventos:

    Dado que cada componente (widget) puede representar acciones (Por ejemplo: pulsar un boton),
    se debe asignar un evento a cada accion.

    La funcion g_signal_connect recibe el componente a asignar su accion,
    el evento deseado propio de cada widget, un traspaso por funcion y un elemento como traspaso

    Importante: La funcion g_signal_connect recibe solo un argumento, es por esto que todos los componentes,
    se estructuraron en un solo tipo de datos ("FORM")

*/

void asignacion_eventos(Form* formulario)
{
    /**<VENTANA PRINCIPAL>**/
    g_signal_connect((GObject*)formulario->main_form->ventana,"destroy",(GCallback)gtk_main_quit,formulario);

    g_signal_connect((GObject*)formulario->main_form->boton_menu_salir,"activate",(GCallback)gtk_main_quit,formulario); //Activate es igual a clicked
    g_signal_connect((GObject*)formulario->main_form->boton_menu_nuevo,"activate",(GCallback)agregar_tarea,formulario);
    g_signal_connect((GObject*)formulario->main_form->boton_menu_guardar,"activate",(GCallback)guardar_todo,formulario);
    g_signal_connect((GObject*)formulario->main_form->boton_menu_formateo,"activate",(GCallback)dialogo_formateo,formulario);

    g_signal_connect((GObject*)formulario->main_form->boton_ok,"clicked",(GCallback)agregar_tarea,formulario);

    g_signal_connect((GObject*)formulario->main_form->boton_ver_tareas_hoy,"activate",(GCallback)mostrar_tareas_hoy,formulario);
    g_signal_connect((GObject*)formulario->main_form->boton_ver_tareas_semana,"activate",(GCallback)mostrar_tareas_semana,formulario);
    g_signal_connect((GObject*)formulario->main_form->boton_ver_tareas_mes,"activate",(GCallback)mostrar_tareas_mes,formulario);
    g_signal_connect((GObject*)formulario->main_form->boton_ver_tareas_todas,"activate",(GCallback)mostrar_tareas_todas,formulario);

    g_signal_connect((GObject*)formulario->main_form->boton_menu_eliminar,"activate",(GCallback)mostrar_tareas_eliminar,formulario);

    /**<VENTANA ELIMINACION>**/
    g_signal_connect((GObject*)formulario->tareas_form->boton_salir,"clicked",(GCallback)ocultar_ventana,formulario);
    g_signal_connect((GObject*)formulario->tareas_form->boton,"clicked",(GCallback)eliminar_tarea,formulario);

    /**<VENTANA DIALOGO>**/
    g_signal_connect((GObject*)formulario->dialog_form->boton_aceptar,"clicked",(GCallback)formateo,formulario);
    g_signal_connect((GObject*)formulario->dialog_form->boton_cancelar,"clicked",(GCallback)ocultar_ventana_dialogo,formulario);

    /**<VENTANA ACERCA DE>**/
    g_signal_connect((GObject*)formulario->main_form->boton_menu_acerca_de,"activate",(GCallback)mostrar_acerca_de,formulario);

}
