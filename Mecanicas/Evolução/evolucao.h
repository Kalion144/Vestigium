#ifndef EVOLUCAO_H
#define EVOLUCAO_H

#include "luke.h"

void subirNivel(Luke *luke);
void distribuirAtributos(Luke *luke);

int calcularResistencia(Luke *luke);
int calcularEvasaoAtiva(Luke *luke);
int calcularEvasaoPassiva(Luke *luke);
int calcularCritico(Luke *luke);
int calcularPenetracao(Luke *luke);

#endif