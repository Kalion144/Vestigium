#include "lucius.h"

void iniciarLucius(Lucius *lucius) {
    lucius->vidaMaxima = 300;
    lucius->vida = lucius->vidaMaxima;

    lucius->forca = 22;

    lucius->resistenciaBase = 20;
    lucius->bonusExoesqueleto = 40;
    lucius->resistencia =
        lucius->resistenciaBase +
        (lucius->resistenciaBase * lucius->bonusExoesqueleto / 100);

    lucius->evasao = 12;
    lucius->sangramento = 0;
}
