#include "luke.h"

void iniciarLuke(Luke *luke) {

    luke->nivel = 1;

    luke->vidaMaxima = 100;
    luke->vida = luke->vidaMaxima;

    luke->forca = 0;
    luke->resistencia = 0;
    luke->agilidade = 0;
    luke->precisao = 0;

    luke->pontosAtributo = 3;

    luke->sangramento = 0;
    luke->turnosSangramento = 0;

    luke->queimadura = 0;
    luke->turnosQueimadura = 0;

    luke->envenenamento = 0;
    luke->intensidadeVeneno = 1;

    luke->frascoSangue = 0;
    luke->pocaoCura = 1;
    luke->antidoto = 0;
    luke->ataduras = 1;
}