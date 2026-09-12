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
        "Luke continua avançando pela floresta devastada.",
        "Entre árvores mortas e solo contaminado,",
        "ele encontra um rio cortando a região."
    );

    mostrarTexto(
        "A água está completamente corrompida.",
        "Uma corrente escura, coberta por resíduos,",
        "carrega um forte cheiro químico."
    );

    mostrarTexto(
        "Luke observa a direção da correnteza.",
        "A contaminação não surgiu ali.",
        "Algo estava despejando aquilo no rio."
    );

    mostrarTexto(
        "Ele começa a seguir contra a correnteza,",
        "procurando a origem daquela destruição.",
        ""
    );

    mostrarTexto(
        "Depois de algum tempo, um som rompe o silêncio.",
        "Não era um rugido.",
        "Era um gemido de dor."
    );

    mostrarTexto(
        "Luke encontra uma criatura entre as árvores.",
        "Seu corpo está tão deformado que é difícil",
        "reconhecer que tipo de animal aquilo um dia foi."
    );

    mostrarTexto(
        "Membros irregulares e feridas cobrem seu corpo.",
        "Entre as deformações, alguns poucos traços",
        "ainda lembram vagamente os de um cachorro."
    );

    mostrarTexto(
        "A criatura se debate violentamente contra o chão.",
        "Morde a própria carne e golpeia o próprio corpo,",
        "desesperada para fazer a dor parar."
    );

    mostrarTexto(
        "Sangue escorre das feridas que ela mesma abriu.",
        "Mesmo assim, continua se mutilando.",
        "A dor parece maior que seu instinto de sobrevivência."
    );

    mostrarTexto(
        "Luke permanece imóvel por alguns segundos.",
        "Depois de 2.500 anos observando a humanidade,",
        "poucas coisas ainda conseguiam perturbá-lo."
    );

    mostrarTexto(
        "",
        "Aquilo conseguiu.",
        ""
    );

    mostrarTexto(
        "A criatura finalmente percebe a presença de Luke.",
        "Confusa, enlouquecida pela dor e pelo medo,",
        "ela avança."
    );

    mostrarTexto(
        "Luke desembainha sua espada.",
        "Desta vez, ele sabe que vencer aquela criatura",
        "também significa colocar fim ao seu sofrimento."
    );


    combateMutante(&luke, &mutante2);


    if (luke.vida <= 0) {
        return;
    }


    mostrarTexto(
        "O corpo da criatura finalmente para de se debater.",
        "Os gemidos desaparecem.",
        "A floresta volta ao silêncio."
    );

    mostrarTexto(
        "Luke observa as feridas espalhadas pelo corpo.",
        "Muitas não foram causadas pela batalha.",
        "A própria criatura havia rasgado sua carne."
    );

    mostrarTexto(
        "Aquilo não era um monstro.",
        "Era um animal condenado a uma existência",
        "de dor por algo que jamais poderia compreender."
    );

    mostrarTexto(
        "Luke fecha os olhos do animal.",
        "Depois cava uma pequena sepultura",
        "e enterra o que restou dele."
    );

    mostrarTexto(
        "Não havia honra naquela morte.",
        "Não havia vitória.",
        "Apenas uma vítima a menos sofrendo."
    );

    mostrarTexto(
        "Luke retorna para a margem do rio.",
        "Agora, a contaminação diante dele",
        "carregava um significado diferente."
    );

    mostrarTexto(
        "Alguém havia provocado aquilo.",
        "E se alguém conhecia as consequências",
        "e ainda assim continuava..."
    );

    mostrarTexto(
        "Luke fecha os punhos com força.",
        "A indignação que sentia até então",
        "havia se transformado em fúria."
    );

    mostrarTexto(
        "Durante séculos, ele viu homens destruírem",
        "vidas em nome de poder, riqueza e progresso.",
        "Mas aquilo havia ultrapassado qualquer limite."
    );

    mostrarTexto(
        "Se havia alguém por trás daquela atrocidade,",
        "Luke não pretendia apenas encontrá-lo.",
        "Pretendia fazê-lo responder pelo que havia feito."
    );


    distribuirAtributos(&luke);
}