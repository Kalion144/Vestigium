#ifndef COMBATE_H
#define COMBATE_H

#include "luke.h"
#include "mutante.h"
#include "seguranca.h"
#include "cientista.h"
#include "lucius.h"

void combateMutante(Luke *luke, Mutante *mutante);
void combateSeguranca(Luke *luke, Seguranca *seguranca);
void combateCientista(Luke *luke, Cientista *cientista);
void combateLucius(Luke *luke, Lucius *lucius);

#endif