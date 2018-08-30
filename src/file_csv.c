/*
    PROYECTO ESTRUCTURA DE DATOS

    BRUNO ESTEBAN DIAZ URETA
    DANIEL ALEJANDRO DELGADO ZAMBRANO
    BRUNO ANTONIO AGUILAR BURGOS

*/

#include "file_csv.h"

/*

    Funciones de lectura y escritura para archivos .csv

    Muchas de estas funciones fueron obtenidas por tareas anteriores :D

*/

/*
    (FICHERO CSV Y TIPO DE DATO TAREA)

    Guarda cada tarea en el archivo csv, considera que si el archivo no ha sido creado,
    se asignan los valores para las columnas
*/

void guardar_todo(GtkWidget* widget,Form* formulario)
{
    FILE* archivo = fopen("tareas.csv","wt");
    fprintf(archivo,"\"Prioridad\",\"Nombre\",\"Dia\",\"Mes\",\"Anio\",\"Key\"\n");

    Tarea* tarea = (Tarea*)first(formulario->tree_high_level);
    while(tarea)
    {
        fprintf(archivo,"\"%i\",\"%s\",\"%i\",\"%i\",\"%i\",\"%i\"\n",tarea->prioridad,tarea->nombre,tarea->dia,tarea->mes,tarea->anio,tarea->key);
        tarea=(Tarea*)next(formulario->tree_high_level);
    }

    tarea = (Tarea*)first(formulario->tree_medium_level);
    while(tarea)
    {
        fprintf(archivo,"\"%i\",\"%s\",\"%i\",\"%i\",\"%i\",\"%i\"\n",tarea->prioridad,tarea->nombre,tarea->dia,tarea->mes,tarea->anio,tarea->key);
        tarea=(Tarea*)next(formulario->tree_medium_level);
    }

    tarea = (Tarea*)first(formulario->tree_low_level);
    while(tarea)
    {
        fprintf(archivo,"\"%i\",\"%s\",\"%i\",\"%i\",\"%i\",\"%i\"\n",tarea->prioridad,tarea->nombre,tarea->dia,tarea->mes,tarea->anio,tarea->key);
        tarea=(Tarea*)next(formulario->tree_low_level);
    }

    printf("<<Tareas guardadas con exito>>\n");
    fclose(archivo);
}

/*
    (FICHERO CSV)

    Guarda cada tarea en el archivo csv, considera que si el archivo no ha sido creado,
    se asignan los valores para las columnas
*/

void guardar_tarea(Tarea* tarea)
{
    FILE* archivo = fopen("tareas.csv","rt");
    if(!archivo)
    {
        archivo = fopen("tareas.csv","wt");
        fprintf(archivo,"\"Prioridad\",\"Nombre\",\"Dia\",\"Mes\",\"Anio\",\"Key\"\n");
        fclose(archivo);
    }
    archivo = fopen("tareas.csv","a+");
    fprintf(archivo,"\"%i\",\"%s\",\"%i\",\"%i\",\"%i\",\"%i\"\n",tarea->prioridad,tarea->nombre,tarea->dia,tarea->mes,tarea->anio,tarea->key);
    fclose(archivo);
}

/*
    (FICHERO CSV)

    Cuenta la cantidad de lineas de un archivo de texto.

    Nota: Considera la posicion actual del archivo y devuelve el INICIO DEL ARCHIVO
*/

int contador_lineas(FILE* archivo)
{
    char caracter_actual;
    int contador = 0;
    while(!feof(archivo))
    {
        caracter_actual=fgetc(archivo);
        if(caracter_actual=='\n') contador++;
    }
    rewind(archivo);
    return contador;
}

/*
    (FICHERO CSV)

    Obtiene un token de un archivo transformado a entero.

    La funcion atoi presentaba comportamientos no deseados.
*/

int get_number_int(FILE* archivo)
{
    int base=0;
    char caracter ='a';
    caracter = fgetc(archivo); //'"'
    caracter = fgetc(archivo);
    while(caracter!='"')
    {
        switch(caracter)
        {
            case '0':
                base = base*10 +0;break;
            case '1':
                base = base*10 +1;break;
            case '2':
                base = base*10 +2;break;
            case '3':
                base = base*10 +3;break;
            case '4':
                base = base*10 +4;break;
            case '5':
                base = base*10 +5;break;
            case '6':
                base = base*10 +6;break;
            case '7':
                base = base*10 +7;break;
            case '8':
                base = base*10 +8;break;
            case '9':
                base = base*10 +9;break;
            case ' ':
                base =0;break;

        }
        caracter = fgetc(archivo);
    }
    fgetc(archivo);//Leer la coma
    return base;
}

/*
    (FICHERO CSV)

    Obtiene un token de un archivo hasta encontrar una coma.
    Reemplaza strtok para evitar la lectura de comillas

    NOTA: Omite "" y se asegura que los valores leidos sean numeros y letras

*/
char* get_token(FILE* archivo)
{
    char* cadena = (char*)malloc(sizeof(char)*41);
    fflush(stdin);
    char caracter = 'a';
    int i=0;
    int flag=0; //Evita la lectura de comillas

    while(1)
    {
        caracter=fgetc(archivo);
        if(caracter!='"')
        {
            if(caracter>64  && caracter<123|| caracter == ' ')
            {
                cadena[i]=caracter;
                i++;
            }

        }
        else
        {
            if(flag==1){caracter=fgetc(archivo);return cadena;}
            flag++;
        }
    }
    return cadena;
}

/*
    (FICHERO CSV)

    Produce un salto de linea en la lectura de un archivo
*/
void jump_line(FILE* archivo)
{
    char caracter = 'a';
    while(caracter!='\n')
    {
        caracter=fgetc(archivo);
    }
}
