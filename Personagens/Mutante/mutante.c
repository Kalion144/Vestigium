#include "mutante.h"

void iniciarMutante(Mutante *mutante) {
    mutante->vidaMaxima = 85;
    mutante->vida = mutante->vidaMaxima;

    mutante->forca = 7;
    mutante->resistencia = 0;
    mutante->evasao = 8;

    mutante->sangramento = 0;
    mutante->envenenamento = 0;
}
