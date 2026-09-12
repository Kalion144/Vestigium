#ifndef LUKE_H
#define LUKE_H

typedef struct {
    int nivel;
    int vida;
    int vidaMaxima;

    int forca;
    int resistencia;
    int agilidade;
    int precisao;

    int pontosAtributo;

    int sangramento;
    int queimadura;
    int envenenamento;
} Luke;

void iniciarLuke(Luke *luke);

#endif