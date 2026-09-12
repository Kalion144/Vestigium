#ifndef SEGURANCA_H
#define SEGURANCA_H

typedef struct {
    int vida;
    int vidaMaxima;

    int forca;
    int resistencia;
    int precisao;
    int evasao;

    int chanceQueimadura;

    int chanceAtadura;
    int chanceFrascoSangue;

} Seguranca;

void iniciarSeguranca(Seguranca *seguranca);

#endif