#ifndef CIENTISTA_H
#define CIENTISTA_H

typedef struct {
    int vida;
    int vidaMaxima;

    int forca;
    int resistencia;
    int precisao;
    int evasao;

    int chanceEnvenenamento;
    int chanceQueimadura;

    int chanceFrascoSangue;
    int chancePocaoCura;
    int chanceAntidoto;

} Cientista;

void iniciarCientista(Cientista *cientista);

#endif