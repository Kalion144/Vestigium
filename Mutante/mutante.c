#include "mutante.h"

void iniciarMutante(Mutante *mutante) {

    mutante->vidaMaxima = 100;
    mutante->vida = mutante->vidaMaxima;

    mutante->forca = 0;
    mutante->resistencia = 0;
    mutante->evasao = 10;

    mutante->sangramento = 0;
    mutante->envenenamento = 0;
}