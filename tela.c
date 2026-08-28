#include <stdio.h>
#include <stdlib.h>
#include "tela.h"

void limparTela() {     // Função para limpar a tela
        system("cls");
    }

    void esperarEnter () {      // Função para esperar o usuário pressionar Enter
        printf("\n              Pressione Enter para continuar...");
        while (getchar() != '\n');
    }

    void mostrarTexto(const char *linha1, const char *linha2, const char *linha3) { // Função para mostrar o texto na tela

        limparTela();

        printf("\n");
        printf("====================================================\n");
        printf("|                                                  \n");
        printf("|  %s \n", linha1);
        printf("|  %s \n", linha2);
        printf("|  %s \n", linha3);
        printf("|                                                  \n");
        printf("====================================================\n");

        esperarEnter();
    }