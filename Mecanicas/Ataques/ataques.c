#include <stdlib.h>
#include "ataques.h"
#include "../Efeitos/efeitos.h"

int corteEspada(Luke *luke) {
    int dano = luke->forca;

    return dano;
}

int socoDireto(Luke *luke) {
    int dano = luke->forca;

    return dano;
}

int corteCarmesim(Luke *luke) {
    if (luke->nivel < 3) {
        return 0;
    }

    int dano = luke->forca;

    return dano;
}

int julgamento(Luke *luke) {
    if (luke->nivel < 5) {
        return 0;
    }

    int dano = luke->forca;

    return dano;
}

void ataqueFuria(Mutante *mutante, Luke *luke) {
    int dano = mutante->forca;

    luke->vida -= dano;

    if (rand() % 100 < 15) {
        luke->sangramento = 1;
    }

    if (rand() % 100 < 15) {
        luke->envenenamento = 1;
    }
}

void tiroRifle(Seguranca *seguranca, Luke *luke) {
    int dano = seguranca->forca;

    luke->vida -= dano;

    if (rand() % 100 < 30) {
        luke->sangramento = 1;
    }
}

void coronhada(Seguranca *seguranca, Luke *luke) {
    int dano = seguranca->forca;

    luke->vida -= dano;
}

void jogarAcido(Cientista *cientista, Luke *luke) {
    int dano = cientista->forca;

    luke->vida -= dano;

    if (rand() % 100 < 30) {
        luke->queimadura = 1;
    }
}

void jogarPocaoToxica(Cientista *cientista, Luke *luke) {
    int dano = cientista->forca;

    luke->vida -= dano;

    if (rand() % 100 < 30) {
        luke->envenenamento = 1;
    }
}

void arremessarObjeto(Cientista *cientista, Luke *luke) {
    int dano = cientista->forca;

    luke->vida -= dano;
}

void corteLamina(Lucius *lucius, Luke *luke) {
    int dano = lucius->forca;

    luke->vida -= dano;

    if (rand() % 100 < 20) {
        luke->sangramento = 1;
    }
}

void disparoLaser(Lucius *lucius, Luke *luke) {
    int dano = lucius->forca;

    luke->vida -= dano;

    if (rand() % 100 < 25) {
        luke->queimadura = 1;
    }
}

void socoPesado(Lucius *lucius, Luke *luke) {
    int dano = lucius->forca;

    if (rand() % 100 < 30) {
        dano = dano * 140 / 100;
    }

    luke->vida -= dano;
}

void socoLeve(Lucius *lucius, Luke *luke) {
    int dano = lucius->forca;

    luke->vida -= dano;
}