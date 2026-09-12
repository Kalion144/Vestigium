#ifndef MUTANTE_H
#define MUTANTE_H

typedef struct {
    int vida;
    int vidaMaxima;

    int forca;
    int resistencia;
    int evasao;

    int sangramento;
    int envenenamento;
} Mutante;

void iniciarMutante(Mutante *mutante);

#endif