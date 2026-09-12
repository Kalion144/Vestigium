#ifndef EFEITOS_H
#define EFEITOS_H

#include "../../Personagens/Luke/luke.h"

void aplicarSangramento(Luke *luke);
void aplicarQueimadura(Luke *luke);
void aplicarEnvenenamento(Luke *luke);

void processarSangramento(Luke *luke);
void processarQueimadura(Luke *luke);
void processarEnvenenamento(Luke *luke);
void processarEfeitos(Luke *luke);

void removerSangramento(Luke *luke);
void removerQueimadura(Luke *luke);
void removerEnvenenamento(Luke *luke);

int calcularForcaAtual(Luke *luke, int forcaBase);

#endif