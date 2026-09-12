#include "seguranca.h"

void iniciarSeguranca(Seguranca *seguranca) {
    seguranca->vidaMaxima = 140;
    seguranca->vida = seguranca->vidaMaxima;

    seguranca->forca = 16;
    seguranca->resistencia = 15;
    seguranca->precisao = 10;
    seguranca->evasao = 8;

    seguranca->chanceQueimadura = 30;

    seguranca->chanceAtadura = 30;
    seguranca->chanceFrascoSangue = 5;
}
