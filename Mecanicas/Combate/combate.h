#ifndef COMBATE_H
#define COMBATE_H

#include "../../Personagens/Luke/luke.h"
#include "../../Personagens/Mutante/mutante.h"
#include "../../Personagens/Segurança/seguranca.h"
#include "../../Personagens/Cientista/cientista.h"
#include "../../Personagens/Lucius/lucius.h"

void combateMutante(Luke *luke, Mutante *mutante);
void combateSeguranca(Luke *luke, Seguranca *seguranca);
void combateCientista(Luke *luke, Cientista *cientista);
void combateLucius(Luke *luke, Lucius *lucius);

#endif