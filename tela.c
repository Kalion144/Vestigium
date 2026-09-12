#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "tela.h"

void limparTela() {
    system("cls");
}

void esperarEnter() {

    printf("\n              Pressione Enter para continuar...");

    int tecla;

    do {
        tecla = _getch();
    } while (tecla != 13);
}

void mostrarTexto(
    const char *linha1,
    const char *linha2,
    const char *linha3
) {

    limparTela();

    printf("\n");
    printf("====================================================\n");
    printf("|                                                  \n");
    printf("|  %s\n", linha1);
    printf("|  %s\n", linha2);
    printf("|  %s\n", linha3);
    printf("|                                                  \n");
    printf("====================================================\n");

    esperarEnter();
}