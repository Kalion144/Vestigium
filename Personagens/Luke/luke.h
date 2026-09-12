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
    int turnosSangramento;

    int queimadura;
    int turnosQueimadura;

    int envenenamento;
    int intensidadeVeneno;

    int frascoSangue;
    int pocaoCura;
    int antidoto;
    int ataduras;

} Luke;

void iniciarLuke(Luke *luke);

#endif