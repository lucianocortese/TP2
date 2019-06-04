#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "input.h"
#include "arregloEmpleados.h"
#define TAM 50



int main()
{
        int menu;
        char continuar= 'N';
        int contId = 1;
        int menuInformes= 'N';
        char continuarInformes;
        int promedioSal;
        eEmpleados lista[TAM];

        inicializarEmpleados(lista, TAM);

        do{
            printf("ABM EMPLEADOS\n\n");
            printf("1-ALTA\n");
            printf("2-MODIFICAR\n");
            printf("3-BAJA\n");
            printf("4-INFORMES\n");
            printf("0-SALIR\n\n");

        getInt(&menu, "Ingrese una opcion:", "No existe esa opcion",0,4);
        printf("\e[1;1H\e[2J");

        switch (menu){

            case 1:
                contId=altaEmpleados (lista, TAM, contId);
                pausa();
                clscreen();
                break;
            case 2:
                modificarEmpleados (lista, TAM);
                pausa();
                clscreen();
                break;
            case 3:
                bajaEmpelado(lista, TAM);
                pausa();
                clscreen();
                break;

            case 4:
                do{
                    printf("MENU INFORMES\n\n");
                    printf("1-LISTADO DE EMPLEADOS\n");
                    printf("2-PROMEDIO DE SALARIOS Y CANTIDAD QUE LO SUPERAN\n");
                    printf("0-VOLVER AL MENU DEL ABM\n\n");

                    getInt(&menuInformes, "Ingrese una opcion:", "No existe esa opcion",0,2);

                switch (menuInformes){
                    case 1:
                        ordenarPorApellido(lista, TAM);
                        pausa();
                        clscreen();
                        break;
                    case 2:
                        promedioSal=promedioSalarios(lista, TAM);
                        bienPagos(lista, TAM);
                        pausa();
                        clscreen();
                        break;
                    case 0:
                        continuarInformes='S';
                        break;
                 }
                }while (continuarInformes!='S');
                clscreen();
                break;
            case 0:
                getChar(&continuar, "Desea continuar [S/N]", "No existe esa opcion", 'S', 'N');
                break;
     }


        }while (continuar != 'S');





    return 0;
}

