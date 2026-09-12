#include <stdio.h>
#include "evolucao.h"

void subirNivel(Luke *luke) {
    if (luke->nivel >= 5) {
        return;
    }

    luke->nivel++;

    luke->vidaMaxima += 20;
    luke->vida = luke->vidaMaxima;

    luke->pontosAtributo += 3;
}

void distribuirAtributos(Luke *luke) {
    int opcao;

    while (luke->pontosAtributo > 0) {
        printf("\nPontos disponiveis: %d\n", luke->pontosAtributo);
        printf("1. Forca: %d/5\n", luke->forca);
        printf("2. Resistencia: %d/5\n", luke->resistencia);
        printf("3. Agilidade: %d/5\n", luke->agilidade);
        printf("4. Precisao: %d/5\n", luke->precisao);
        printf("5. Sair\n");

        printf("\nEscolha um atributo: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (luke->forca < 5) {
                    luke->forca++;
                    luke->pontosAtributo--;
                }
                break;

            case 2:
                if (luke->resistencia < 5) {
                    luke->resistencia++;
                    luke->pontosAtributo--;
                }
                break;

            case 3:
                if (luke->agilidade < 5) {
                    luke->agilidade++;
                    luke->pontosAtributo--;
                }
                break;

            case 4:
                if (luke->precisao < 5) {
                    luke->precisao++;
                    luke->pontosAtributo--;
                }
                break;

            case 5:
                return;

            default:
                break;
        }
    }
}

int calcularResistencia(Luke *luke) {
    return luke->resistencia * 10;
}

int calcularEvasaoAtiva(Luke *luke) {
    return 5 + (luke->agilidade * 14);
}

int calcularEvasaoPassiva(Luke *luke) {
    return calcularEvasaoAtiva(luke) / 3;
}

int calcularCritico(Luke *luke) {
    return 5 + (luke->precisao * 9);
}

int calcularPenetracao(Luke *luke) {
    return luke->precisao * 6;
}