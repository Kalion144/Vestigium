#include "jogo.h"

#include "../../tela.h"

#include "../../Personagens/Luke/luke.h"
#include "../../Personagens/Mutante/mutante.h"
#include "../../Personagens/Segurança/seguranca.h"
#include "../../Personagens/Cientista/cientista.h"
#include "../../Personagens/Lucius/lucius.h"

#include "../Combate/combate.h"
#include "../Evolução/evolucao.h"

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

    //combate 3

    mostrarTexto(
    "Luke continua seguindo o rio contra a correnteza.",
    "A cada passo, os sinais de destruição",
    "se tornam mais intensos."
);

mostrarTexto(
    "Árvores foram derrubadas em grandes extensões.",
    "O solo foi rasgado por máquinas pesadas",
    "e enormes áreas foram reduzidas a lama e resíduos."
);

mostrarTexto(
    "Depois de algum tempo, Luke encontra a origem",
    "de parte da contaminação.",
    "Um grande tubo despeja resíduos diretamente no rio."
);

mostrarTexto(
    "O líquido que sai dali é escuro e espesso.",
    "O mesmo material que corre pela floresta",
    "e transforma animais em criaturas deformadas."
);

mostrarTexto(
    "Luke observa o local ao redor.",
    "Máquinas, estruturas industriais e áreas de extração",
    "ocupam grande parte daquela região."
);

mostrarTexto(
    "Não era um acidente isolado.",
    "Aquilo fazia parte de uma operação organizada",
    "e continuava funcionando normalmente."
);

mostrarTexto(
    "Luke segue em direção às instalações.",
    "Sua expressão permanece fria,",
    "mas a fúria ainda cresce dentro dele."
);

mostrarTexto(
    "Antes que consiga entrar,",
    "um homem armado bloqueia sua passagem.",
    ""
);

mostrarTexto(
    "\"Pare aí.\"",
    "\"Esta área é restrita.\"",
    "\"Volte por onde veio.\""
);

mostrarTexto(
    "Luke observa o homem por alguns segundos.",
    "O uniforme e a arma deixam claro",
    "que ele trabalha para aquela instalação."
);

mostrarTexto(
    "\"Você sabe o que estão fazendo aqui?\"",
    "pergunta Luke.",
    ""
);

mostrarTexto(
    "\"Não é problema meu.\"",
    "\"Sou pago para proteger este lugar.\"",
    "\"E é exatamente isso que vou fazer.\""
);

mostrarTexto(
    "Luke olha novamente para o rio contaminado.",
    "Depois, para o homem diante dele.",
    ""
);

mostrarTexto(
    "\"Então você escolheu proteger isso.\"",
    "",
    ""
);

mostrarTexto(
    "O segurança segura o rifle com mais força.",
    "Luke não demonstra intenção de recuar.",
    "A conversa termina ali."
);


combateSeguranca(&luke, &seguranca);


if (luke.vida <= 0) {
    return;
}


mostrarTexto(
    "O segurança cai no chão.",
    "Luke se aproxima lentamente,",
    "mantendo os olhos sobre ele."
);

mostrarTexto(
    "\"Eu só estava fazendo meu trabalho...\"",
    "diz o homem, tentando recuperar o fôlego.",
    ""
);

mostrarTexto(
    "Luke permanece em silêncio por alguns segundos.",
    "Depois olha para as máquinas funcionando",
    "atrás dos muros da instalação."
);

mostrarTexto(
    "\"Todos escolhem o que estão dispostos",
    "a fazer em troca de dinheiro.\"",
    ""
);

mostrarTexto(
    "\"Cumprir ordens não apaga",
    "as consequências delas.\"",
    ""
);

mostrarTexto(
    "Luke deixa o segurança para trás.",
    "Ele não era a origem daquele problema.",
    "Era apenas mais uma peça mantendo tudo funcionando."
);

mostrarTexto(
    "Luke atravessa a entrada da instalação.",
    "Se queria encontrar o responsável,",
    "precisava continuar avançando."
);


distribuirAtributos(&luke);

//combate 4

mostrarTexto(
    "Luke avança pelos corredores da instalação.",
    "Tubulações, tanques e equipamentos ocupam",
    "boa parte daquele complexo."
);

mostrarTexto(
    "O cheiro químico é ainda mais forte ali dentro.",
    "Resíduos escorrem por canaletas no chão",
    "e desaparecem por sistemas de drenagem."
);

mostrarTexto(
    "Em uma das salas, Luke encontra",
    "um homem cercado por frascos, anotações",
    "e equipamentos de laboratório."
);

mostrarTexto(
    "O homem ergue os olhos lentamente.",
    "Ele não parece surpreso.",
    ""
);

mostrarTexto(
    "\"Então você conseguiu entrar.\"",
    "diz o cientista.",
    "\"Imaginei que o segurança não conseguiria pará-lo.\""
);

mostrarTexto(
    "Luke observa os recipientes espalhados pela sala.",
    "Alguns contêm líquidos escuros.",
    "Outros, amostras de tecido deformado."
);

mostrarTexto(
    "\"Você sabe o que isso está causando?\"",
    "pergunta Luke.",
    ""
);

mostrarTexto(
    "O cientista sorri discretamente.",
    "\"É claro que sei.\"",
    "\"Eu ajudei a desenvolver parte do processo.\""
);

mostrarTexto(
    "Luke permanece em silêncio.",
    "Por alguns segundos,",
    "a sala parece ainda mais fria."
);

mostrarTexto(
    "\"Animais estão sendo deformados.\"",
    "diz Luke.",
    "\"A floresta está morrendo.\""
);

mostrarTexto(
    "\"Consequências inevitáveis.\"",
    "responde o cientista.",
    "\"Todo avanço exige algum tipo de sacrifício.\""
);

mostrarTexto(
    "Luke encara o homem diante dele.",
    "A fúria retorna imediatamente.",
    ""
);

mostrarTexto(
    "\"Você chama isso de avanço?\"",
    "\"Transformar vidas em sofrimento",
    "apenas porque você consegue?\""
);

mostrarTexto(
    "O cientista ajusta as luvas.",
    "\"Conhecimento existe para ser usado.\"",
    "\"Limites são obstáculos impostos por quem tem medo.\""
);

mostrarTexto(
    "Luke dá um passo à frente.",
    "",
    ""
);

mostrarTexto(
    "\"Conhecimento sem responsabilidade",
    "não é inteligência.\"",
    ""
);

mostrarTexto(
    "\"É apenas poder nas mãos",
    "de alguém incapaz de compreender",
    "as consequências do que faz.\""
);

mostrarTexto(
    "O sorriso do cientista desaparece.",
    "Ele pega alguns frascos sobre a bancada.",
    ""
);

mostrarTexto(
    "\"Você fala como se estivesse acima de nós.\"",
    "\"Mas no fim, você também resolve tudo",
    "com violência.\""
);

mostrarTexto(
    "Luke desembainha sua espada.",
    "\"A diferença é que eu sei",
    "por que estou usando a minha.\""
);


combateCientista(&luke, &cientista);


if (luke.vida <= 0) {
    return;
}


mostrarTexto(
    "O cientista cai entre os equipamentos quebrados.",
    "Frascos e instrumentos estão espalhados",
    "pelo chão do laboratório."
);

mostrarTexto(
    "Luke se aproxima.",
    "O homem tenta se afastar,",
    "mas não consegue continuar lutando."
);

mostrarTexto(
    "\"Vai me matar?\"",
    "pergunta o cientista.",
    ""
);

mostrarTexto(
    "\"Não.\"",
    "responde Luke.",
    ""
);

mostrarTexto(
    "\"Morrer seria simples demais.\"",
    "\"Você sabia exatamente",
    "o que estava fazendo.\""
);

mostrarTexto(
    "Luke encontra um par de algemas",
    "entre os equipamentos de segurança",
    "e prende as mãos do cientista."
);

mostrarTexto(
    "\"Você vai responder por isso.\"",
    "\"Não para mim.\"",
    "\"Para todos que foram afetados por suas escolhas.\""
);

mostrarTexto(
    "Luke deixa o cientista imobilizado.",
    "O laboratório já não parece",
    "um lugar de conhecimento."
);

mostrarTexto(
    "Parece apenas o resultado",
    "do que acontece quando inteligência",
    "e responsabilidade deixam de caminhar juntas."
);


distribuirAtributos(&luke);

//combate final

mostrarTexto(
    "Luke deixa o laboratório para trás",
    "e continua avançando pelo complexo.",
    "Quanto mais se aproxima do centro da instalação,"
);

mostrarTexto(
    "mais sofisticados se tornam os equipamentos.",
    "Máquinas automatizadas, estruturas metálicas",
    "e sistemas de controle ocupam toda a área."
);

mostrarTexto(
    "Ao fim de um grande corredor,",
    "Luke encontra uma sala ampla",
    "cercada por painéis e estruturas industriais."
);

mostrarTexto(
    "No centro da sala, um homem o aguarda.",
    "Diferente dos outros,",
    "ele não demonstra surpresa."
);

mostrarTexto(
    "\"Luke Carmesin.\"",
    "diz o homem.",
    "\"Finalmente.\""
);

mostrarTexto(
    "Luke permanece em silêncio.",
    "Seu olhar percorre a sala",
    "antes de voltar para o homem."
);

mostrarTexto(
    "\"Lucius Varn.\"",
    "responde Luke.",
    ""
);

mostrarTexto(
    "Lucius sorri.",
    "\"Então você já sabe quem eu sou.\"",
    ""
);

mostrarTexto(
    "\"Sei o suficiente.\"",
    "diz Luke.",
    "\"Sei o que sua operação está fazendo lá fora.\""
);

mostrarTexto(
    "\"Florestas destruídas.\"",
    "\"Água contaminada.\"",
    "\"Animais transformados em aberrações.\""
);

mostrarTexto(
    "Lucius permanece tranquilo.",
    "\"Você fala como se isso fosse novidade.\"",
    ""
);

mostrarTexto(
    "\"Toda civilização foi construída",
    "sobre algum tipo de destruição.\"",
    "\"A diferença é que eu não finjo que não vejo.\""
);

mostrarTexto(
    "Luke fecha os punhos.",
    "\"Então você sabe exatamente",
    "o que está causando.\""
);

mostrarTexto(
    "\"É claro que sei.\"",
    "responde Lucius.",
    "\"E continuo mesmo assim.\""
);

mostrarTexto(
    "\"Porque enquanto homens como você",
    "se preocupam com consequências,",
    "homens como eu constroem o futuro.\""
);

mostrarTexto(
    "Luke encara Lucius sem desviar o olhar.",
    "\"Você não está construindo um futuro.\"",
    ""
);

mostrarTexto(
    "\"Está consumindo tudo ao seu redor",
    "e chamando a destruição",
    "de progresso.\""
);

mostrarTexto(
    "Lucius ri discretamente.",
    "\"Progresso sempre teve um preço.\"",
    ""
);

mostrarTexto(
    "\"A diferença entre nós",
    "é que eu estou disposto a pagá-lo.\"",
    ""
);

mostrarTexto(
    "Luke dá um passo à frente.",
    "\"Não.\"",
    ""
);

mostrarTexto(
    "\"Você nunca pagou esse preço.\"",
    "\"Quem pagou foram aqueles",
    "que nunca tiveram escolha.\""
);

mostrarTexto(
    "Por alguns segundos,",
    "o sorriso de Lucius desaparece.",
    ""
);

mostrarTexto(
    "\"Você vive há séculos, Luke.\"",
    "\"Viu impérios nascerem e desaparecerem.\"",
    "\"Deveria entender melhor que ninguém.\""
);

mostrarTexto(
    "\"O mundo sempre pertenceu",
    "a quem teve força para moldá-lo.\"",
    ""
);

mostrarTexto(
    "Luke responde sem hesitar.",
    "\"E eu também vi o que acontece",
    "com homens que acreditam nisso.\""
);

mostrarTexto(
    "Lucius se afasta alguns passos.",
    "Atrás dele, uma grande estrutura metálica",
    "começa a se movimentar."
);

mostrarTexto(
    "Braços mecânicos se encaixam",
    "ao redor de seu corpo.",
    "Placas metálicas cobrem seus braços e torso."
);

mostrarTexto(
    "Um exoesqueleto envolve Lucius.",
    "Motores e sistemas de energia",
    "entram em funcionamento."
);

mostrarTexto(
    "\"Você atravessou meus homens.\"",
    "\"Destruiu meu laboratório.\"",
    "\"E agora acredita que pode me julgar.\""
);

mostrarTexto(
    "Luke desembainha sua espada.",
    "\"Não estou aqui para julgá-lo.\"",
    ""
);

mostrarTexto(
    "\"Suas próprias escolhas",
    "já fizeram isso por você.\"",
    ""
);

mostrarTexto(
    "Lucius fecha os punhos mecânicos.",
    "O impacto do metal ecoa pela sala.",
    ""
);

mostrarTexto(
    "\"Então venha, vampiro.\"",
    "\"Vamos descobrir qual de nós",
    "merece permanecer de pé.\""
);

combateLucius(&luke, &lucius);

if (luke.vida <= 0) {

    mostrarTexto(
        "Luke cai diante de Lucius.",
        "Sua espada escapa de sua mão",
        "e desliza pelo chão."
    );

    mostrarTexto(
        "Lucius observa o corpo de Luke.",
        "\"No fim, você era apenas",
        "mais um obstáculo.\""
    );

    mostrarTexto(
        "As máquinas continuam funcionando.",
        "Os resíduos continuam sendo despejados.",
        "A floresta continua morrendo."
    );

    mostrarTexto(
        "Novas criaturas começam a surgir.",
        "Mais violentas.",
        "Mais deformadas."
    );

    mostrarTexto(
        "Com o passar dos anos,",
        "a contaminação deixa de atingir",
        "apenas aquela região."
    );

    mostrarTexto(
        "Ela se espalha.",
        "Novas espécies sofrem mutações.",
        "Ecossistemas inteiros entram em colapso."
    );

    mostrarTexto(
        "A humanidade continua avançando",
        "como se nada estivesse acontecendo.",
        "Até que já não existe mais volta."
    );

    mostrarTexto(
        "No fim, as criaturas que surgiram",
        "das consequências humanas",
        "se tornam numerosas demais para controlar."
    );

    mostrarTexto(
        "O mundo que os homens tentaram dominar",
        "se torna incapaz de sustentar",
        "aqueles que o destruíram."
    );

    mostrarTexto(
        "",
        "DERROTA",
        ""
    );

    return;
}

mostrarTexto(
    "O exoesqueleto de Lucius começa a falhar.",
    "Faíscas escapam das placas metálicas",
    "enquanto seus sistemas perdem força."
);

mostrarTexto(
    "Lucius cai de joelhos.",
    "Pela primeira vez,",
    "sua confiança desaparece."
);

mostrarTexto(
    "\"Você acha que isso muda alguma coisa?\"",
    "pergunta Lucius.",
    ""
);

mostrarTexto(
    "\"Sempre haverá alguém",
    "disposto a continuar",
    "o que eu comecei.\""
);

mostrarTexto(
    "Luke observa Lucius no chão.",
    "\"Talvez.\"",
    ""
);

mostrarTexto(
    "\"Mas isso não transforma",
    "suas escolhas em inevitáveis.\"",
    ""
);

mostrarTexto(
    "\"O mundo não chegou a este ponto sozinho.\"",
    "\"Pessoas escolheram trazê-lo até aqui.\"",
    ""
);

mostrarTexto(
    "Luke olha através das grandes janelas",
    "da instalação.",
    "Ao longe, a floresta ainda está destruída."
);

mostrarTexto(
    "O rio continua contaminado.",
    "Animais já morreram.",
    "Outros jamais voltarão ao que eram."
);

mostrarTexto(
    "Vencer Lucius não desfazia",
    "o que havia acontecido.",
    ""
);

mostrarTexto(
    "Mas interrompia aquilo",
    "antes que as marcas",
    "se tornassem ainda maiores."
);

mostrarTexto(
    "As atividades da instalação são interrompidas.",
    "Pela primeira vez em muito tempo,",
    "os resíduos deixam de correr para o rio."
);

mostrarTexto(
    "Luke sabe que a floresta",
    "não se recuperará da noite para o dia.",
    ""
);

mostrarTexto(
    "Algumas marcas levarão décadas para desaparecer.",
    "Outras permanecerão.",
    ""
);

mostrarTexto(
    "Mas enquanto ainda existir algo",
    "capaz de ser protegido,",
    "a destruição não precisa ser o único caminho."
);

mostrarTexto(
    "",
    "VITÓRIA",
    ""
);

mostrarTexto(
    "",
    "Alguns vestígios contam o que aconteceu.",
    "Outros servem para lembrar o que não deve se repetir."
);
}