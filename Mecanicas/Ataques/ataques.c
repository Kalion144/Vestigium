#include <stdio.h>
#include <stdlib.h>
#include "ataques.h"
#include "../Efeitos/efeitos.h"
#include "../Evolução/evolucao.h"

static int reduzirDanoPorResistenciaLuke(Luke *luke, int dano) {
    int resistencia = calcularResistencia(luke);

    dano = dano * (100 - resistencia) / 100;

    if (dano < 1) {
        dano = 1;
    }

    return dano;
}

int corteEspada(Luke *luke) {
    int forcaAtual = calcularForcaAtual(luke, luke->forca);
    return 10 + (luke->nivel * 2) + (forcaAtual * 3);
}

int socoDireto(Luke *luke) {
    int forcaAtual = calcularForcaAtual(luke, luke->forca);
    int dano = 8 + (luke->nivel * 2) + (forcaAtual * 3);

    if (rand() % 100 < calcularCritico(luke)) {
        dano = dano * 150 / 100;
        printf("\nAcerto critico de Luke!\n");
    }

    return dano;
}

int corteCarmesim(Luke *luke) {
    if (luke->nivel < 3) {
        return 0;
    }

    int forcaAtual = calcularForcaAtual(luke, luke->forca);
    return 13 + (luke->nivel * 2) + (forcaAtual * 3);
}

int julgamento(Luke *luke) {
    if (luke->nivel < 5) {
        return 0;
    }

    int forcaAtual = calcularForcaAtual(luke, luke->forca);
    int dano = 16 + (luke->nivel * 2) + (forcaAtual * 3);

    if (rand() % 100 < calcularCritico(luke)) {
        dano = dano * 150 / 100;
        printf("\nJulgamento foi um acerto critico!\n");
    }

    return dano;
}

void ataqueFuria(Mutante *mutante, Luke *luke) {
    int dano = reduzirDanoPorResistenciaLuke(luke, mutante->forca);

    printf("O Mutante usou Ataque de Furia!\n");

    luke->vida -= dano;
    if (luke->vida < 0) luke->vida = 0;

    printf("Luke recebeu %d de dano.\n", dano);

    if (rand() % 100 < 15) {
        int jaTinha = luke->sangramento;
        aplicarSangramento(luke);
        if (!jaTinha && luke->sangramento) {
            printf("Luke comecou a sangrar!\n");
        }
    }

    if (rand() % 100 < 15) {
        int jaTinha = luke->envenenamento;
        aplicarEnvenenamento(luke);
        if (!jaTinha && luke->envenenamento) {
            printf("Luke foi envenenado!\n");
        }
    }
}

void tiroRifle(Seguranca *seguranca, Luke *luke) {
    int dano = reduzirDanoPorResistenciaLuke(luke, seguranca->forca);

    printf("O Seguranca disparou o Rifle!\n");

    luke->vida -= dano;
    if (luke->vida < 0) luke->vida = 0;

    printf("Luke recebeu %d de dano.\n", dano);

    if (rand() % 100 < seguranca->chanceQueimadura) {
        int jaTinha = luke->queimadura;
        aplicarQueimadura(luke);
        if (!jaTinha && luke->queimadura) {
            printf("Luke sofreu uma queimadura!\n");
        }
    }
}

void coronhada(Seguranca *seguranca, Luke *luke) {
    int dano = reduzirDanoPorResistenciaLuke(luke, seguranca->forca);

    printf("O Seguranca usou Coronhada!\n");

    luke->vida -= dano;
    if (luke->vida < 0) luke->vida = 0;

    printf("Luke recebeu %d de dano.\n", dano);
}

void jogarAcido(Cientista *cientista, Luke *luke) {
    int dano = reduzirDanoPorResistenciaLuke(luke, cientista->forca);

    printf("O Cientista arremessou um Frasco de Acido!\n");

    luke->vida -= dano;
    if (luke->vida < 0) luke->vida = 0;

    printf("Luke recebeu %d de dano.\n", dano);

    if (rand() % 100 < cientista->chanceQueimadura) {
        int jaTinha = luke->queimadura;
        aplicarQueimadura(luke);
        if (!jaTinha && luke->queimadura) {
            printf("O acido queimou Luke!\n");
        }
    }
}

void jogarPocaoToxica(Cientista *cientista, Luke *luke) {
    int dano = reduzirDanoPorResistenciaLuke(luke, cientista->forca);

    printf("O Cientista arremessou uma Pocao Toxica!\n");

    luke->vida -= dano;
    if (luke->vida < 0) luke->vida = 0;

    printf("Luke recebeu %d de dano.\n", dano);

    if (rand() % 100 < cientista->chanceEnvenenamento) {
        int jaTinha = luke->envenenamento;
        aplicarEnvenenamento(luke);
        if (!jaTinha && luke->envenenamento) {
            printf("Luke foi envenenado!\n");
        }
    }
}

void arremessarObjeto(Cientista *cientista, Luke *luke) {
    int dano = reduzirDanoPorResistenciaLuke(luke, cientista->forca);

    printf("O Cientista arremessou um objeto contra Luke!\n");

    luke->vida -= dano;
    if (luke->vida < 0) luke->vida = 0;

    printf("Luke recebeu %d de dano.\n", dano);
}

void corteLamina(Lucius *lucius, Luke *luke) {
    int dano = reduzirDanoPorResistenciaLuke(luke, lucius->forca);

    printf("Lucius usou Corte de Lamina!\n");

    luke->vida -= dano;
    if (luke->vida < 0) luke->vida = 0;

    printf("Luke recebeu %d de dano.\n", dano);

    if (rand() % 100 < 20) {
        int jaTinha = luke->sangramento;
        aplicarSangramento(luke);
        if (!jaTinha && luke->sangramento) {
            printf("Luke comecou a sangrar!\n");
        }
    }
}

void disparoLaser(Lucius *lucius, Luke *luke) {
    int dano = reduzirDanoPorResistenciaLuke(luke, lucius->forca);

    printf("Lucius usou Disparo a Laser!\n");

    luke->vida -= dano;
    if (luke->vida < 0) luke->vida = 0;

    printf("Luke recebeu %d de dano.\n", dano);

    if (rand() % 100 < 25) {
        int jaTinha = luke->queimadura;
        aplicarQueimadura(luke);
        if (!jaTinha && luke->queimadura) {
            printf("Luke sofreu uma queimadura!\n");
        }
    }
}

void socoPesado(Lucius *lucius, Luke *luke) {
    int dano = lucius->forca;
    int critico = 0;

    if (rand() % 100 < 30) {
        dano = dano * 140 / 100;
        critico = 1;
    }

    dano = reduzirDanoPorResistenciaLuke(luke, dano);

    printf("Lucius usou Soco Pesado!\n");

    luke->vida -= dano;
    if (luke->vida < 0) luke->vida = 0;

    if (critico) printf("Acerto critico! ");
    printf("Luke recebeu %d de dano.\n", dano);
}

void socoLeve(Lucius *lucius, Luke *luke) {
    int dano = reduzirDanoPorResistenciaLuke(luke, lucius->forca);

    printf("Lucius usou Soco Leve!\n");

    luke->vida -= dano;
    if (luke->vida < 0) luke->vida = 0;

    printf("Luke recebeu %d de dano.\n", dano);
}
