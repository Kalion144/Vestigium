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

    limparTela();

    Luke luke;
    Mutante mutante1;
    Mutante mutante2;
    Seguranca seguranca;
    Cientista cientista;
    Lucius lucius;

    iniciarLuke(&luke);
    iniciarMutante(&mutante1);
    iniciarMutante(&mutante2);

    // O segundo mutante aparece mais tarde e representa uma ameaça maior.
    mutante2.vidaMaxima = 120;
    mutante2.vida = mutante2.vidaMaxima;
    mutante2.forca = 10;
    mutante2.resistencia = 5;
    mutante2.evasao = 10;

    iniciarSeguranca(&seguranca);
    iniciarCientista(&cientista);
    iniciarLucius(&lucius);

    mostrarTexto(
        "Antes de iniciar sua jornada,",
        "distribua seus pontos entre os atributos",
        "de Luke Carmesin."
    );

    limparTela();

    distribuirAtributos(&luke);

    limparTela();

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
    limparTela();

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
    limparTela();

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
    limparTela();

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
    limparTela();

    mostrarTexto(
        "Luke continua avançando pelas instalações.",
        "Até chegar a uma grande sala no centro",
        "do complexo industrial."
    );

    mostrarTexto(
        "No outro lado da sala,",
        "um homem o aguarda.",
        ""
    );

    mostrarTexto(
        "\"Luke Carmesin.\"",
        "diz o homem.",
        "\"Finalmente.\""
    );

    mostrarTexto(
        "Luke observa Lucius Varn.",
        "O homem responsável pela operação",
        "permanece completamente tranquilo."
    );

    mostrarTexto(
        "\"Florestas destruídas.\"",
        "\"Água contaminada.\"",
        "\"Animais transformados em aberrações.\""
    );

    mostrarTexto(
        "\"Você sabe exatamente",
        "o que está acontecendo aqui.\"",
        ""
    );

    mostrarTexto(
        "\"É claro que sei.\"",
        "responde Lucius.",
        "\"Eu apenas não finjo que o progresso é gratuito.\""
    );

    mostrarTexto(
        "\"Toda civilização foi construída",
        "sobre alguma forma de destruição.\"",
        "\"Eu só aceitei essa realidade.\""
    );

    mostrarTexto(
        "\"E mesmo conhecendo as consequências,",
        "você continua.\"",
        "diz Luke."
    );

    mostrarTexto(
        "\"Homens como eu constroem o futuro.\"",
        "\"Homens como você perdem tempo",
        "se preocupando com as consequências.\""
    );

    mostrarTexto(
        "\"Você não está construindo um futuro.\"",
        "\"Está consumindo tudo ao seu redor",
        "e chamando a destruição de progresso.\""
    );

    mostrarTexto(
        "\"Todo progresso tem um preço.\"",
        "diz Lucius.",
        "\"E eu estou disposto a pagá-lo.\""
    );

    mostrarTexto(
        "\"Você nunca pagou esse preço.\"",
        "responde Luke.",
        "\"Quem pagou foram aqueles que nunca tiveram escolha.\""
    );

    mostrarTexto(
        "Lucius sorri.",
        "\"O mundo sempre pertenceu",
        "àqueles fortes o bastante para moldá-lo.\""
    );

    mostrarTexto(
        "\"Eu já vi homens acreditarem nisso antes.\"",
        "diz Luke.",
        "\"Nenhum deles terminou como imaginava.\""
    );

    mostrarTexto(
        "Lucius aciona um mecanismo.",
        "Partes metálicas começam a envolver seu corpo.",
        ""
    );

    mostrarTexto(
        "Um exoesqueleto pesado se fecha ao redor dele.",
        "Motores e sistemas mecânicos entram em funcionamento.",
        ""
    );

    mostrarTexto(
        "\"Não estou aqui para julgá-lo.\"",
        "diz Luke.",
        "\"Suas próprias escolhas já fizeram isso por você.\""
    );

    combateLucius(&luke, &lucius);

    if (luke.vida <= 0) {

        mostrarTexto(
            "Luke cai no chão.",
            "Seu corpo já não consegue continuar lutando.",
            ""
        );

        mostrarTexto(
            "Lucius observa Luke por alguns segundos.",
            "\"Você poderia ter simplesmente ido embora.\"",
            ""
        );

        mostrarTexto(
            "\"No fim, você era apenas",
            "mais um obstáculo no caminho.\"",
            ""
        );

        mostrarTexto(
            "As máquinas continuam funcionando.",
            "Os resíduos continuam sendo despejados.",
            "Nada muda."
        );

        mostrarTexto(
            "Com o passar do tempo,",
            "novas criaturas surgem.",
            "A contaminação continua se espalhando."
        );

        mostrarTexto(
            "Florestas desaparecem.",
            "Rios morrem.",
            "Ecossistemas inteiros entram em colapso."
        );

        mostrarTexto(
            "A humanidade continua avançando",
            "até perceber tarde demais",
            "que havia destruído aquilo que a mantinha viva."
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
        "Faíscas escapam das placas metálicas.",
        "Os motores perdem força."
    );

    mostrarTexto(
        "Lucius cai de joelhos.",
        "Pela primeira vez,",
        "sua expressão demonstra incerteza."
    );

    mostrarTexto(
        "\"Você realmente acha que isso muda alguma coisa?\"",
        "pergunta Lucius.",
        ""
    );

    mostrarTexto(
        "\"Se eu parar, outro continuará.\"",
        "\"Sempre haverá alguém disposto",
        "a fazer o que eu fiz.\""
    );

    mostrarTexto(
        "\"Talvez.\"",
        "responde Luke.",
        "\"Mas escolhas não são inevitáveis.\""
    );

    mostrarTexto(
        "\"O mundo não chegou até aqui sozinho.\"",
        "\"Pessoas escolheram trazê-lo até aqui.\"",
        ""
    );

    mostrarTexto(
        "Com Lucius derrotado,",
        "a operação finalmente é interrompida.",
        ""
    );

    mostrarTexto(
        "As máquinas param.",
        "O tubo deixa de despejar resíduos no rio.",
        "O silêncio retorna lentamente."
    );

    mostrarTexto(
        "A floresta não se recuperará rapidamente.",
        "Talvez algumas marcas permaneçam",
        "por décadas."
    );

    mostrarTexto(
        "Mas, pela primeira vez em muito tempo,",
        "existe a possibilidade",
        "de que algo volte a crescer."
    );

    mostrarTexto(
        "",
        "VITÓRIA",
        ""
    );

    mostrarTexto(
        "Alguns vestígios contam o que aconteceu.",
        "Outros servem para lembrar",
        "o que não deve se repetir."
    );
}