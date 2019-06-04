#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"
#include "sistem.h"
#include "arregloEmpleados.h"


void inicializarEmpleados (eEmpleados lista[], int tam){
    int funciona=-1;
    for(int i=0; i<tam; i++){
        lista[i].isEmpty=1;
        lista[i].id=-1;
    }

}
void mostrarEmpleado (eEmpleados lista[], int ind){

    printf(" %d    %10s %10s    %12.2f   %6d    \n\n", lista[ind].id, lista[ind].apellido, lista[ind].nombre, lista[ind].sueldo, lista[ind].sector);
}
int buscarVacio (eEmpleados lista[], int tam){
    int vacio=-1;
    for (int i=0;i<tam;i++){
        if(lista[i].isEmpty == 1){
            vacio=i;
            break;
        }
    }
    return vacio;
}
int altaEmpleados (eEmpleados lista [], int tam, int contId){

    int vacio;

    vacio=buscarVacio(lista, tam);

    if(vacio==-1){
        printf("No hay lugar libre\n");
    }
    else{


        lista[vacio].id=contId;

        getString(lista[vacio].nombre, "Ingrese el nombre :", "Demasiado largo, no puede pasar los 51 caracteres, pruebe nuevamente", 0, 51);

        getString(lista[vacio].apellido, "Ingrese el apellido :", "Demasiado largo, no puede pasar los 51 caracteres, pruebe nuevamente", 0, 51);

        getFloat(&lista[vacio].sueldo, "Ingrese el salario", "Error", 0,999999999);

        getInt(&lista[vacio].sector, "Ingrese el sector del 1 al 5", "El sector no puede ser negativo",1, 5);

        getInt(&lista[vacio].isEmpty, "Elija una opción [0-alta / 1-baja]", "No es una opción", 0,1);

    }
    contId ++;
    return contId;
}
int buscarEmpleado (eEmpleados lista[], int tam, int idIndicado){

    int encontrado=-1;
     for(int i=0; i<tam; i++){
        if(lista[i].id==idIndicado){
           encontrado=i;
           break;
        }
    }

    return encontrado;
}
void modificarEmpleados (eEmpleados lista[], int tam){

    int idIndicado;
    int existe;
    int mod;

    printf("Ingrese el id del socio que desea modificar: \n");
    scanf("%d", &idIndicado);
    existe=buscarEmpleado(lista,tam,idIndicado);

    if (existe == -1){
        printf("El empleado no existe\n ");
    }
    if (existe != -1){

        printf("El empleado existe\n");

        printf("ID  -         Nombre        -    Sueldo   -   Sector\n");
        mostrarEmpleado(lista, existe);
        printf("Elija que desea modificar\n");
        printf("1-Apellido\n");
        printf("2-Nombre\n");
        printf("3-Sector\n");
        printf("4-Sueldo\n");
        printf("0-No hacer modificación\n");
        scanf("%d", &mod);

        switch (mod){
            case 1:
                getString(lista[existe].apellido, "Ingrese el nuevo apellido (maximo 51 caracteres):", "Se exedió en la cantidad de caracteres, pruebe nuevamente", 0, 31);
                printf("El apellido se cambió con exito");
                break;
            case 2:
                getString(lista[existe].nombre, "Ingrese el nuevo nombre (maximo 51 caracteres):", "Se exedió en la cantidad de caracteres, pruebe nuevamente", 0, 31);
                printf("El nombre se cambió con exito \n");
                break;
            case 3:
                getInt(&lista[existe].sector, "Ingrese el nuevo Sector", "Error, debe ser del 1 al 5", 1,5);
                printf("El sector ya fue modificado exitosamente\n");
                break;
            case 4:
                getFloat(&lista[existe].sueldo, "Ingrese el nuevo Sueldo", "El Sueldo no puede ser negativo",0, 99999999);
                printf("El sueldo se cambió con exito");
                break;
            case 0:
                printf("no se haran modificaciones\n");
                break;
            default:
                printf("La opcion no es correcta, intente nueva opcion\n");
                break;
        }
    }

}
void bajaEmpelado (eEmpleados lista[], int tam){

    int idEmp;
    int encontrado=-1;
    char resp;
    printf("Ingrese el ID del empleado que desea dar de baja:\n\n");
    scanf("%d", &idEmp);

    encontrado=buscarEmpleado(lista,tam,idEmp);

    if(encontrado==-1){
        printf("No se encontró un socio con ese ID\n");
    }
    else if (lista[encontrado].isEmpty==1){
        printf("El socio ya fue dado de baja\n");
    }
    else
    {
        printf("Se encontro el socio\n");
        mostrarEmpleado(lista, encontrado);
        getChar(&resp,"Está seguro que desea darlo de baja? S/N", "Error, lo ingresado no es una opción",'S', 'N' );
            if(resp=='S'){
                lista[encontrado].isEmpty=1;
                printf("La baja se hizo con exito\n\n");
                pausa();
            }
            else{
                printf("No se hizo la baja\n");
                pausa();
            }

    }



}
void mostrarEmpleados(eEmpleados lista[], int tam){
    int contador=0;
    for(int i=0; i<tam; i++){
        if(lista[i].isEmpty==0)
        {
            contador++;
            break;
        }
    }
    if(contador!=0){

        printf("ID  -  Apellido   -   Nombre   -   Sueldo   -   Sector\n");
        for(int i=0; i<tam; i++){
            if(lista[i].isEmpty==0)
            {
                mostrarEmpleado(lista, i);
            }
        }
    }

    else{
        printf("No hay empleado para mostrar\n");
    }

}
void ordenarPorApellido (eEmpleados lista[], int tam){
    //ORDENA POR APELLIDO Y DESPUES NOMBRE...
    eEmpleados aux;
    for(int i=0; i<tam-1; i++){
       for(int j=i+1; j<tam;j++){

            if(strcmp(lista[i].apellido, lista[j].apellido)>0){
                aux=lista[i];
                lista [i]=lista[j];
                lista[j]=aux;
            }
            else if(strcmp(lista[i].apellido, lista[j].apellido)==0){
                if(lista[i].sector>lista[j].sector){
                    aux=lista[i];
                    lista [i]=lista[j];
                    lista[j]=aux;
                }

            }
        }
    }

    mostrarEmpleados(lista, tam);
}
float promedioSalarios (eEmpleados lista [], int tam){
    float promedio;
    float acumulador=0;
    int contador =0;

    for (int i=0; i<tam;i++){
        if (lista[i].isEmpty==0){

            acumulador = acumulador + lista[i].sueldo;
            contador++;

        }

    }


    promedio=acumulador/contador;

    printf("\nEl total de todos los salarios es %2.f:\n", acumulador);
    printf("El promedio total es %2.f.:\n", promedio);

    return promedio;
}
void bienPagos (eEmpleados lista [], int tam){
    float promedio;
    int contador=0;
    promedio = promedioSalarios(lista, tam);

    for (int i=0;i<tam;i++){

        if (lista[i].sueldo > promedio){

            contador++;
        }
    }
    printf("Hay %d empleados que superan el promedio", contador);
}
