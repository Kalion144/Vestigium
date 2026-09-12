#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "tela.h"
#include "informacoes.h"
#include "creditos.h"
#include "../Mecanicas/Jogo/jogo.h"

void mostrarMenu() {
    int opcao;

    do {
        limparTela();

        printf("╔══════════════════════════════════════╗\n");
        printf("║              VESTIGIUM               ║\n");
        printf("╠══════════════════════════════════════╣\n");
        printf("║  1. Iniciar Jogo                     ║\n");
        printf("║  2. Informações                      ║\n");
        printf("║  3. Créditos                         ║\n");
        printf("║  4. Sair                             ║\n");
        printf("╚══════════════════════════════════════╝\n");

        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                iniciarJogo();
                break;

            case 2:
                mostrarInformacoes();
                break;

            case 3:
                mostrarCreditos();
                break;

            case 4:
                limparTela();
                printf("Encerrando VESTIGIUM...\n");
                break;

            default:
                printf("\nOpção inválida.\n");
                esperarEnter();
                break;
        }

    } while (opcao != 4);
}