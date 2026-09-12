#include "luke.h"

void iniciarLuke(Luke *luke) {

    luke->nivel = 1;

    luke->vidaMaxima = 100;
    luke->vida = luke->vidaMaxima;

    luke->forca = 0;
    luke->resistencia = 0;
    luke->agilidade = 0;
    luke->precisao = 0;

    luke->sangramento = 0;
    luke->queimadura = 0;
    luke->envenenamento = 0;

    luke->pontosAtributo = 3;
}