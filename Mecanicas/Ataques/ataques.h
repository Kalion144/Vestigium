#ifndef ATAQUES_H
#define ATAQUES_H

#include "../../Personagens/Luke/luke.h"
#include "../../Personagens/Mutante/mutante.h"
#include "../../Personagens/Segurança/seguranca.h"
#include "../../Personagens/Cientista/cientista.h"
#include "../../Personagens/Lucius/lucius.h"

int corteEspada(Luke *luke);
int socoDireto(Luke *luke);
int corteCarmesim(Luke *luke);
int julgamento(Luke *luke);

void ataqueFuria(Mutante *mutante, Luke *luke);

void tiroRifle(Seguranca *seguranca, Luke *luke);
void coronhada(Seguranca *seguranca, Luke *luke);

void jogarAcido(Cientista *cientista, Luke *luke);
void jogarPocaoToxica(Cientista *cientista, Luke *luke);
void arremessarObjeto(Cientista *cientista, Luke *luke);

void corteLamina(Lucius *lucius, Luke *luke);
void disparoLaser(Lucius *lucius, Luke *luke);
void socoPesado(Lucius *lucius, Luke *luke);
void socoLeve(Lucius *lucius, Luke *luke);

#endif