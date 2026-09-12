#include "seguranca.h"

void iniciarSeguranca(Seguranca *seguranca) {

    seguranca->vidaMaxima = 80;
    seguranca->vida = seguranca->vidaMaxima;

    seguranca->forca = 15;
    seguranca->resistencia = 10;
    seguranca->precisao = 10;
    seguranca->evasao = 5;
}