#include "lucius.h"

void iniciarLucius(Lucius *lucius) {
    lucius->vidaMaxima = 0;
    lucius->vida = lucius->vidaMaxima;

    lucius->forca = 0;

    lucius->resistenciaBase = 0;

    lucius->bonusExoesqueleto = 40;

    lucius->resistencia =
        lucius->resistenciaBase +
        (lucius->resistenciaBase * lucius->bonusExoesqueleto / 100);

    lucius->evasao = 10;

    lucius->sangramento = 0;
}