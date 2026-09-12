#include "cientista.h"

void iniciarCientista(Cientista *cientista) {

    cientista->vidaMaxima = 60;
    cientista->vida = cientista->vidaMaxima;

    cientista->forca = 10;
    cientista->resistencia = 5;
    cientista->precisao = 15;
    cientista->evasao = 10;

    cientista->chanceEnvenenamento = 30;
    cientista->chanceQueimadura = 30;

    cientista->chanceFrascoSangue = 10;
    cientista->chancePocaoCura = 60;
    cientista->chanceAntidoto = 60;
}