#include <stdio.h>
#include "menu.h"
#include "tela.h"
#include "informacoes.h"

void mostrarMenu(void) {

    int opcao;

    do{

        limparTela();

        printf("\n");
        printf("====================================================\n");
        printf("|                                                  |\n");
        printf("|                    VESTIGIUM                     |\n");
        printf("|                                                  |\n");
        printf("|                  1. INICIAR                      |\n");
        printf("|                  2. INFORMAÇÕES                  |\n");
        printf("|                  3. CREDITOS                     |\n");
        printf("|                  4. SAIR                         |\n");
        printf("|                                                  |\n");
        printf("====================================================\n");

        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);
        
        while (getchar() != '\n');
        
        switch (opcao) {
            case 1:
                printf("\nIniciando jogo...\n");
                esperarEnter();
                break;

            case 2:
                mostrarInformacoes();
                break;

            case 3:
                printf("\nCreditos\n");
                esperarEnter();
                break;

            case 4:
                printf("\nSaindo do jogo...\n");
                break;

            default:
                printf("\nOpção invalida!\n");
        }
       
    } while (opcao != 4);
}

