#include <stdio.h>
#include <stdlib.h>

void pausa (){
    printf("'Enter' para continuar.");
    setbuf(stdin, NULL);
    getchar();
}
void clscreen (){    //Arme esta función porque al usar system("clear"); en linux recibia el error "sh:clear: commond not found".
    printf("\e[1;1H\e[2J");
}

