#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "persona.h"

void alta( ePersona pers[], int cantidad ){
    int i=0,legajoAux,flag,j;
    char rta;
    char* mensaje="Ingrese legajo\n";

        do{
            do{
                legajoAux=getInt(mensaje);
                flag=0;
                for (j=0;j<cantidad;j++){
                    if (pers[j].legajo==legajoAux&&pers[j].isEmpty==0){

                        printf("Es un legajo existente\n");
                        flag=1;
                        break;
                }
            }
            }while(flag==1);

            pers[i].legajo=legajoAux;

            printf("Apellido:\n");
            fflush(stdin);
            scanf("%s", pers[i].apellido);

            printf("Nombre:\n");
            fflush(stdin);
            scanf("%s", pers[i].nombre);

            printf("Edad:\n");
            scanf("%d", &pers[i].edad);

            pers[i].isEmpty = 0;

            i++;

            if (i<cantidad) {
                printf("Desea seguir?[S/N]");
                fflush(stdin);
                scanf("%c",&rta);
                rta=toupper(rta);
            }

        }while(rta=='S'&&i<cantidad);

}

void mostrarTodos( ePersona pers[], int cantidad ){
    int i;

    for( i = 0; i < cantidad; i++ ){
        if (pers[i].isEmpty==0){
            mostrarUno(pers[i]);
        }

    }

}

void mostrarUno( ePersona per ){
        printf("%d\t%s\t%s\t%d\t%d\n",per.legajo, per.apellido, per.nombre, per.edad, per.isEmpty);
}

void baja( ePersona pers[], int cantidad){

    int legajoAux,i;

    printf("Ingrese legajo a dar de baja:\n");
    scanf("%d",&legajoAux);

    for (i=0;i<cantidad;i++){

            if (legajoAux==pers[i].legajo){

                pers[i].isEmpty=1;
                break;
            }


    }
}

void modificacion (ePersona pers[],int cantidad){

    int legajoAux,i,flag=0;

    printf("Ingrese el legajo a modificar:\n");
    scanf("%d",&legajoAux);

    for(i=0;i<cantidad;i++){

        if (legajoAux==pers[i].legajo&&pers[i].isEmpty==0){

            mostrarUno(pers[i]);

            printf("Apellido:\n");
            fflush(stdin);
            scanf("%s", pers[i].apellido);

            printf("Nombre:\n");
            fflush(stdin);
            scanf("%s", pers[i].nombre);

            printf("Edad:\n");
            scanf("%d", &pers[i].edad);

            flag=1;
        }
    }
    if (flag==0){

        printf("No se encontro el legajo\n");
        system("pause");
    }
}

char getChar(char mensaje[]){

    char letra;

    printf("%s",mensaje);
    scanf("%c",&letra);

    return letra;
}

int getInt(char mensaje[]){

    int entero;

    printf("%s",mensaje);
    scanf("%d",&entero);

    return entero;
}

float getFloat(char mensaje[]){

    float numero;

    printf("%s",mensaje);
    scanf("%f",&numero);

    return numero;
}

char* getString(char mensaje[]){

    char texto[101];

    printf("%s",mensaje);
    fgets(texto,sizeof(texto)-2,stdin);

    return texto;
}
