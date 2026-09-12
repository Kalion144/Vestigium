#include <stdio.h>
#include <stdlib.h>

#include "informacoes.h"
#include "tela.h"

void mostrarCreditos(void) {
    limparTela();

    printf("╔══════════════════════════════════════╗\n");
    printf("║                CRÉDITOS              ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║                                      ║\n");
    printf("║              VESTIGIUM               ║\n");
    printf("║                                      ║\n");
    printf("║          Desenvolvido por            ║\n");
    printf("║             Dhiogo Dias              ║\n");
    printf("║                                      ║\n");
    printf("║        História e Conceito           ║\n");
    printf("║             Dhiogo Dias              ║\n");
    printf("║                                      ║\n");
    printf("║          Projeto Acadêmico           ║\n");
    printf("║        Universidade Catolica         ║\n");
    printf("║                                      ║\n");
    printf("╚══════════════════════════════════════╝\n");

    esperarEnter();
}