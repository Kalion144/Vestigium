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

    //combate 1

    mostrarTexto(
        "Luke deixa a cidade e segue em direção às florestas.",
        "Quanto mais avança, mais evidente se torna",
        "que algo naquele lugar está errado."
    );

    mostrarTexto(
        "Árvores quebradas, solo escurecido",
        "e um cheiro estranho tomam conta do ambiente.",
        ""
    );

    mostrarTexto(
        "Ao longe, Luke escuta um som agressivo.",
        "Galhos se quebram entre a vegetação.",
        "Algo se aproxima rapidamente."
    );

    mostrarTexto(
        "Uma criatura deformada surge entre as árvores.",
        "Seu corpo apresenta feridas e alterações incomuns.",
        "Ela avança contra Luke sem hesitar."
    );

    combateMutante(&luke, &mutante1);

    if (luke.vida <= 0) {
        return;
    }

    mostrarTexto(
        "Com a criatura caída, Luke se aproxima.",
        "Agora, com mais calma, consegue observar",
        "o que antes parecia apenas um monstro."
    );

    mostrarTexto(
        "A estrutura do corpo ainda lembra um animal.",
        "Apesar das deformações, Luke reconhece",
        "traços semelhantes aos de um macaco."
    );

    mostrarTexto(
        "Aquilo não nasceu daquela forma.",
        "Alguma coisa havia alterado completamente",
        "o corpo e o comportamento daquele animal."
    );

    mostrarTexto(
        "Luke observa o solo ao redor.",
        "Resíduos estranhos e marcas de contaminação",
        "se espalham pela floresta."
    );

    mostrarTexto(
        "A criatura não era a origem do problema.",
        "Era apenas um dos seus vestígios.",
        ""
    );

    distribuirAtributos(&luke);

    // comabte 2

    mostrarTexto(
    "Luke continua seguindo pela floresta.",
    "Pouco depois, encontra um rio",
    "atravessando aquela região."
);

mostrarTexto(
    "A água, porém, está longe de parecer normal.",
    "Sua coloração é escura e um forte odor",
    "se espalha pelas margens."
);

mostrarTexto(
    "Luke observa o fluxo da água.",
    "Se aquela contaminação veio de algum lugar,",
    "o rio poderia levá-lo até a origem."
);

mostrarTexto(
    "Ele decide seguir contra a correnteza.",
    "Quanto mais avança, mais sinais de destruição",
    "aparecem ao redor."
);

mostrarTexto(
    "De repente, Luke escuta um som à frente.",
    "Não parece um rugido ou um chamado.",
    "Parece dor."
);

mostrarTexto(
    "Entre a vegetação, ele encontra outra criatura.",
    "Seu corpo ainda lembra o de um cachorro,",
    "mas está profundamente deformado."
);

mostrarTexto(
    "A criatura se contorce e golpeia o próprio corpo.",
    "Como se tentasse desesperadamente",
    "se livrar daquilo que se tornou."
);

mostrarTexto(
    "Ao perceber Luke, o animal se torna agressivo.",
    "Confuso e tomado pela dor,",
    "ele avança contra Luke."
);

combateMutante(&luke, &mutante2);

if (luke.vida <= 0) {
    return;
}

mostrarTexto(
    "A criatura cai no chão.",
    "Por alguns instantes, Luke apenas observa",
    "o animal imóvel diante dele."
);

mostrarTexto(
    "Diferente da criatura anterior,",
    "aquele animal parecia lutar",
    "contra o próprio corpo."
);

mostrarTexto(
    "Luke entende que não enfrentou um monstro.",
    "Enfrentou um animal transformado",
    "em algo que nunca deveria ter sido."
);

mostrarTexto(
    "Sem dizer uma palavra, Luke cava a terra",
    "e enterra o corpo próximo à floresta.",
    ""
);

mostrarTexto(
    "Depois, retorna até o rio contaminado.",
    "A resposta ainda está em algum lugar",
    "acima daquela correnteza."
);

distribuirAtributos(&luke);
}