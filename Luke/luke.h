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
} Luke;

void iniciarLuke(Luke *luke);

#endif