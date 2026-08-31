#include <stdio.h>
#include <stdlib.h>

#include "informacoes.h"

void mostrarInformacoes(void) {

    int opcao;

    do{

        limparTela();

        printf("╔══════════════════════════════════════╗\n");
        printf("║              INFORMAÇÕES             ║\n");
        printf("╠══════════════════════════════════════╣\n");
        printf("║                                      ║\n");
        printf("║   1 - Combate                        ║\n");
        printf("║   2 - Turnos                         ║\n");
        printf("║   3 - Efeitos                        ║\n");
        printf("║   4 - Itens                          ║\n");
        printf("║   5 - Voltar                         ║\n");
        printf("║                                      ║\n");
        printf("╚══════════════════════════════════════╝\n");
        printf("\n");
        printf("Escolha uma opção: ");

        scanf("%d", &opcao);

        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                mostrarCombate();
                break;

            case 2:
                mostrarTurnos();
                break;

            case 3:
                mostrarEfeitos();
                break;

            case 4:
                mostrarItens();
                break;

            case 5:
                break;

            default:
                printf("\nOpção inválida!\n");
                esperarEnter();
                break;
        }

    } while (opcao != 5);
}



void mostrarCombate(void) {

    limparTela();

    printf("=============== COMBATE ===============\n\n");

    printf("O combate em VESTIGIUM acontece por turnos.\n");
    printf("Luke enfrenta diferentes inimigos e deve utilizar\n");
    printf("suas habilidades, armas e itens para sobreviver.\n\n");

    printf("OBJETIVO\n");
    printf("O objetivo do combate e reduzir a vida do inimigo\n");
    printf("a 0 HP antes que a vida de Luke chegue a 0 HP.\n\n");

    printf("DURANTE O COMBATE\n");
    printf("Em seu turno, Luke pode escolher uma acao.\n");
    printf("As acoes podem causar dano, utilizar itens ou\n");
    printf("interagir com os efeitos presentes no combate.\n\n");

    printf("ATAQUES\n");
    printf("Cada ataque possui um valor de dano proprio.\n");
    printf("Alguns ataques tambem podem aplicar efeitos negativos\n");
    printf("ao inimigo.\n\n");

    printf("EFEITOS\n");
    printf("Alguns ataques possuem chance de causar efeitos,\n");
    printf("como sangramento, queimadura ou envenenamento.\n");
    printf("Esses efeitos podem alterar o resultado do combate\n");
    printf("mesmo depois que o ataque termina.\n\n");

    printf("VIDA\n");
    printf("Luke inicia seus combates com 100 HP.\n");
    printf("Caso seus HP cheguem a 0, Luke sera derrotado.\n");
    printf("O inimigo tambem sera derrotado ao chegar a 0 HP.\n\n");

    printf("VITORIA\n");
    printf("O combate termina quando a vida do inimigo chega\n");
    printf("a 0 HP.\n\n");

    printf("DERROTA\n");
    printf("Se a vida de Luke chegar a 0 HP, o combate sera\n");
    printf("encerrado e o jogador sera derrotado.\n");

    esperarEnter();
}

    void mostrarTurnos(void) {

    limparTela();

    printf("================ TURNOS ================\n\n");

    printf("O combate e dividido em turnos.\n");
    printf("Cada turno representa uma nova rodada de acoes\n");
    printf("entre Luke e seu inimigo.\n\n");

    printf("INICIO DO TURNO\n");
    printf("No inicio de cada turno, o jogo verifica os efeitos\n");
    printf("que estao ativos em Luke e no inimigo.\n\n");

    printf("TURNO DE LUKE\n");
    printf("O jogador escolhe uma acao para Luke realizar.\n");
    printf("A acao escolhida pode ser um ataque ou a utilizacao\n");
    printf("de um item, dependendo das opcoes disponiveis.\n\n");

    printf("TURNO DO INIMIGO\n");
    printf("Depois da acao de Luke, o inimigo realiza sua acao.\n");
    printf("Cada inimigo possui comportamentos e ataques proprios.\n\n");

    printf("EFEITOS\n");
    printf("Os efeitos ativos continuam sendo considerados\n");
    printf("durante os turnos, seguindo suas regras especificas.\n\n");

    printf("PROXIMO TURNO\n");
    printf("Depois que Luke e o inimigo realizarem suas acoes,\n");
    printf("o turno termina e uma nova rodada comeca.\n\n");

    printf("O combate continua dessa forma ate que Luke ou\n");
    printf("o inimigo seja derrotado.\n");

    esperarEnter();
}

void mostrarEfeitos(void) {

    limparTela();

    printf("================ EFEITOS ================\n\n");

    printf("Os efeitos sao condicoes que alteram o estado de\n");
    printf("Luke ou dos inimigos durante o combate.\n\n");

    printf("SANGRAMENTO\n");
    printf("O sangramento representa uma perda continua de vida.\n\n");
    printf("- Causa 5%% de dano por turno.\n");
    printf("- O dano continua enquanto o efeito estiver ativo.\n");
    printf("- O efeito deve ser tratado para ser removido.\n");
    printf("- Se nao for tratado dentro de 7 turnos,\n");
    printf("  Luke sofrera morte por hemorragia no turno seguinte.\n\n");

    printf("QUEIMADURA\n");
    printf("A queimadura representa danos causados por fogo ou\n");
    printf("outras fontes de calor extremo.\n\n");
    printf("- Causa 10%% de dano quando aplicada.\n");
    printf("- Reduz a forca de Luke em 30%% enquanto estiver ativa.\n");
    printf("- Pode permanecer ativa por no maximo 5 turnos.\n\n");

    printf("ENVENENAMENTO\n");
    printf("O veneno causa um dano que aumenta progressivamente.\n\n");
    printf("- Comeca causando 1%% de dano.\n");
    printf("- O dano aumenta em 1%% a cada turno.\n");
    printf("- O efeito continua aumentando enquanto estiver ativo.\n");
    printf("- Pode ser removido utilizando o item adequado.\n\n");

    printf("ACUMULO DE EFEITOS\n");
    printf("Os efeitos nao podem ser acumulados.\n");
    printf("Se Luke ja estiver sob determinado efeito, o mesmo\n");
    printf("efeito nao podera ser aplicado novamente enquanto\n");
    printf("a condicao ainda estiver ativa.\n");

    esperarEnter();
}

void mostrarItens(void) {

    limparTela();

    printf("================ ITENS ================\n\n");

    printf("Os itens sao recursos que podem auxiliar Luke\n");
    printf("durante sua jornada e principalmente durante os combates.\n\n");

    printf("UTILIZACAO\n");
    printf("Os itens podem ser utilizados para recuperar recursos,\n");
    printf("tratar efeitos negativos ou obter vantagens durante\n");
    printf("determinadas situacoes.\n\n");

    printf("ITENS DE CURA\n");
    printf("Itens de cura recuperam parte da vida de Luke.\n");
    printf("Eles devem ser utilizados com cuidado para evitar\n");
    printf("que Luke seja derrotado durante o combate.\n\n");

    printf("ANTIDOTO\n");
    printf("O antidoto e utilizado para remover o envenenamento.\n");
    printf("Sua utilizacao pode ser importante contra inimigos\n");
    printf("que possuem ataques capazes de envenenar Luke.\n\n");

    printf("TRATAMENTO DE EFEITOS\n");
    printf("Alguns itens possuem a funcao de remover efeitos\n");
    printf("negativos aplicados durante o combate.\n\n");

    printf("ESTRATEGIA\n");
    printf("Os itens sao recursos limitados. Por isso, o jogador\n");
    printf("deve avaliar o momento correto para utiliza-los.\n");
    printf("Usar um item muito cedo pode desperdiçar um recurso,\n");
    printf("enquanto esperar demais pode resultar na derrota.\n");

    esperarEnter();
}