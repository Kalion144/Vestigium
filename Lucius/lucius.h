#ifndef LUCIUS_H
#define LUCIUS_H

typedef struct {
    int vida;
    int vidaMaxima;

    int forca;

    int resistenciaBase;
    int resistencia;

    int evasao;

    int sangramento;

    int bonusExoesqueleto;
} Lucius;

void iniciarLucius(Lucius *lucius);

#endif