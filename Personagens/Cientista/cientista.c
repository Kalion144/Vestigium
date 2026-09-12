#include "cientista.h"

void iniciarCientista(Cientista *cientista) {
    cientista->vidaMaxima = 180;
    cientista->vida = cientista->vidaMaxima;

    cientista->forca = 20;
    cientista->resistencia = 10;
    cientista->precisao = 15;
    cientista->evasao = 10;

    cientista->chanceEnvenenamento = 30;
    cientista->chanceQueimadura = 30;

    cientista->chanceFrascoSangue = 10;
    cientista->chancePocaoCura = 60;
    cientista->chanceAntidoto = 60;
}
