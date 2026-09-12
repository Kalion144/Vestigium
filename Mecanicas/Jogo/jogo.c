#include "jogo.h"

#include "luke.h"
#include "mutante.h"
#include "seguranca.h"
#include "cientista.h"
#include "lucius.h"

#include "combate.h"
#include "evolucao.h"

void iniciarJogo() {
    Luke luke;
    Mutante mutante1;
    Mutante mutante2;
    Seguranca seguranca;
    Cientista cientista;
    Lucius lucius;

    iniciarLuke(&luke);

    iniciarMutante(&mutante1);
    iniciarMutante(&mutante2);
    iniciarSeguranca(&seguranca);
    iniciarCientista(&cientista);
    iniciarLucius(&lucius);

    distribuirAtributos(&luke);

    combateMutante(&luke, &mutante1);

    // história...

    combateMutante(&luke, &mutante2);

    // história...

    combateSeguranca(&luke, &seguranca);

    // história...

    combateCientista(&luke, &cientista);

    // história...

    combateLucius(&luke, &lucius);
}