/**
Desarrollar en ANSI C:
Una empresa necesita administrar los 20 almuerzos de su comedor en planta, para sus 100 empleados; y para ello se deber� realizar un programa de acuerdo a lo siguiente:

	Menu:
�	C�digo de menu (autoincremental)
�	Descripci�n (m�ximo 51 caracteres)  Validar
�	Importe (debe ser mayor a cero)  Validar

	Empleados:
�	Legajo (autoincremental)
�	Apellido (m�ximo 51 caracteres) Validar
�	Nombre (m�ximo 51 caracteres) Validar
�	sexo Validar
�	salario (debe ser mayor a cero) Validar
�	fecha de ingreso (el dia, mes y a�o debe estar en los rangos correspondientes) Validar
�	idSector (debe existir) Validar

Almuerzo:
�	Codigo de almuerzo (autoincremental)
�	Codigo de menu (debe existir) Validar
�	Legajo de empleado (debe existir) Validar
�	Fecha (el dia, mes y a�o debe estar en los rangos correspondientes) Validar

	Sector:
�	id (autoincremental)
�	Descripci�n (m�ximo 51 caracteres)  Validar

MENUES:
A)	Altas: No es necesario el ingreso de todos los menues.
B)	Modificar: Se ingresar� el c�digo de menu, permitiendo en un submen� modificar:
�	Descripci�n
�	importe
B)	Baja:  Se ingresar� el c�digo de menu y se realizar� una baja l�gica.
C)	Listar: Hacer un �nico listado de todos los menues ordenados por importe (descendente) y descripcion (ascendente).

EMPLEADOS:
A)	Altas: No es necesario el ingreso de todos los empleados.
B)	Modificar: Se ingresar� el C�digo de Empleado, permitiendo en un submen� modificar:
�	Apellido
�	Nombre
�	Sexo
�	Salario
�	Fecha de ingreso
�	Sector
B)	Baja:  Se ingresar� el C�digo de Empleado y se realizar� una baja l�gica.
C)	Listar: Hacer un �nico listado de todos los Empleados ordenados por apellido (ascendente) y nombre (ascendente).

ALMUERZOS: Se dar� de alta cada ocurrencia de Almuerzo, relacionando Menu � Empleado, Fecha y Codigo de Almuerzo.


NOTAS:
I.	Se deber� desarrollar bibliotecas por cada entidad, las cuales contendr�n las funciones Alta, Baja, Modificar y Listar.
II.	Las validaciones deber�n estar en una biblioteca aparte.
III.	Tener en cuenta que no se podr� ingresar a los casos Modificar, Baja y Listar; sin antes haber realizado al menos un Alta (utilizar contadores).
IV.	El c�digo deber� tener comentarios con la documentaci�n de cada una de las funciones y respetar las reglas de estilo de la c�tedra.
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../librerias/persona.h"

#define CANT 3
#define CANT_MENU 3
#define CANT_SECTOR 3
#define CANT_ALMUERZO 3

int main(){
    int opcionEmpleado, opcionPrincipal,opcionMenu,opcionSector,opcionAlmuerzo;
    ePersona pers[CANT];
    eSector sector[CANT_SECTOR];
    eMenu menu[CANT_MENU];
    eAlmuerzo almuerzo[CANT_ALMUERZO];
    do{
            printf("ingrese:\n1.menues:\n2.empleado:\n3.Sector:\n4.Almuerzo:\n5.Salir:\n");
            scanf("%d",&opcionPrincipal);
            switch(opcionPrincipal){
                case 1:
                    do{
                        printf("ingrese menu:\n1.alta:\n2.baja\n3.modificacion:\n4.listar:\n5.salir:\n");
                        scanf("%d",&opcionMenu);
                        switch(opcionMenu){

                            case 1:

                                altaMenu(menu, CANT_MENU);
                                break;
                            case 2:

                                bajaMenu(menu, CANT_MENU);
                                break;
                            case 3:

                                modificacionMenu(menu,CANT_MENU);
                                break;
                            case 4:

                                listarMenu(menu,CANT_MENU);
                                break;
                            case 5:

                                break;
                        }
                    }while(opcionMenu>=1&&opcionMenu<=4);

                    break;
                case 2:
                    printf("ingrese empleado:\n1.alta\n2.baja\n3.modificacion\n4.listar\n5.salir\n");
                    scanf("%d",&opcionEmpleado);
                    do{

                        switch(opcionEmpleado){
                        case 1:

                            alta(pers, CANT);
                            break;
                        case 2:

                            system("cls");
                            mostrarTodos(pers, CANT);
                            break;
                        case 3:

                            baja( pers, CANT );
                            break;
                        case 4:

                            modificacion( pers, CANT );
                            break;
                        case 5:

                            break;

                        }

                    }while(opcionEmpleado>=1&&opcionEmpleado<=4);

                    break;

                case 3:
                    printf("Ingrese:\n1.Alta sector:\n2.Listar sector:\n3.Salir:\n");
                    scanf("%d",&opcionSector);
                    switch(opcionSector){
                        case 1:
                            altaSector(sector,CANT_SECTOR);
                            break;
                        case 2:
                            listarSector(sector,CANT_SECTOR);
                            break;
                        case 3:
                            break;
                    }
                    break;
                case 4:
                    printf("Ingrese:\n1.Alta almuerzo:\n2.Listar almuerzo:\n3.Salir:\n");
                    scanf("%d",&opcionAlmuerzo);
                    switch(opcionAlmuerzo){
                        case 1:
                            altaAlmuerzo(almuerzo, menu, pers, CANT_ALMUERZO, CANT_MENU,CANT);
                            break;
                        case 2:
                            listarAlmuerzo(almuerzo,CANT_ALMUERZO);
                            break;
                        case 3:
                            break;
                    }

            }


    }while(opcionPrincipal>=1&&opcionPrincipal<=4);



    return 0;
}
