#include "itens.h"
#include "efeitos.h"

void usarFrascoSangue(Luke *luke) {
    if (luke->frascoSangue <= 0) {
        return;
    }

    luke->vida = luke->vidaMaxima;

    removerSangramento(luke);
    removerQueimadura(luke);
    removerEnvenenamento(luke);

    luke->frascoSangue--;
}

void usarPocaoCura(Luke *luke) {
    if (luke->pocaoCura <= 0) {
        return;
    }

    int cura = luke->vidaMaxima * 30 / 100;

    luke->vida += cura;

    if (luke->vida > luke->vidaMaxima) {
        luke->vida = luke->vidaMaxima;
    }

    luke->pocaoCura--;
}

void usarAntidoto(Luke *luke) {
    if (luke->antidoto <= 0) {
        return;
    }

    if (luke->envenenamento == 0) {
        return;
    }

    removerEnvenenamento(luke);

    luke->antidoto--;
}

void usarAtadura(Luke *luke) {
    if (luke->ataduras <= 0) {
        return;
    }

    if (luke->sangramento == 0 && luke->queimadura == 0) {
        return;
    }

    removerSangramento(luke);
    removerQueimadura(luke);

    luke->ataduras--;
}