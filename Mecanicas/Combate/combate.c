#include <stdio.h>
#include <stdlib.h>

#include "combate.h"
#include "tela.h"
#include "ataques.h"
#include "efeitos.h"
#include "evolucao.h"
#include "itens.h"

void mostrarEfeitosLuke(Luke *luke) {
    int possuiEfeito = 0;

    printf("Efeitos: ");

    if (luke->sangramento == 1) {
        printf("Sangramento (%d/7 turnos) ", luke->turnosSangramento);
        possuiEfeito = 1;
    }

    if (luke->queimadura == 1) {
        printf("Queimadura (%d/5 turnos) ", luke->turnosQueimadura);
        possuiEfeito = 1;
    }

    if (luke->envenenamento == 1) {
        printf("Envenenamento (%d%%) ", luke->intensidadeVeneno);
        possuiEfeito = 1;
    }

    if (possuiEfeito == 0) {
        printf("Nenhum");
    }

    printf("\n");
}

void mostrarEfeitosInimigo(int sangramento, int queimadura, int envenenamento) {
    int possuiEfeito = 0;

    printf("Efeitos: ");

    if (sangramento == 1) {
        printf("Sangramento ");
        possuiEfeito = 1;
    }

    if (queimadura == 1) {
        printf("Queimadura ");
        possuiEfeito = 1;
    }

    if (envenenamento == 1) {
        printf("Envenenamento ");
        possuiEfeito = 1;
    }

    if (possuiEfeito == 0) {
        printf("Nenhum");
    }

    printf("\n");
}

void mostrarStatusCombate(
    Luke *luke,
    const char *nomeInimigo,
    int vidaInimigo,
    int vidaMaximaInimigo,
    int sangramentoInimigo,
    int queimaduraInimigo,
    int envenenamentoInimigo
) {
    printf("\n====================================\n");
    printf("LUKE\n");
    printf("Vida: %d/%d\n", luke->vida, luke->vidaMaxima);
    mostrarEfeitosLuke(luke);

    printf("\n%s\n", nomeInimigo);
    printf("Vida: %d/%d\n", vidaInimigo, vidaMaximaInimigo);
    mostrarEfeitosInimigo(
        sangramentoInimigo,
        queimaduraInimigo,
        envenenamentoInimigo
    );

    printf("====================================\n");
}

int escolherAcao() {
    int opcao;

    printf("\nACOES\n");
    printf("1. Atacar\n");
    printf("2. Esquivar\n");
    printf("3. Bolsa\n");

    printf("\nEscolha: ");
    scanf("%d", &opcao);

    return opcao;
}

int escolherAtaqueLuke(Luke *luke) {
    int opcao;

    printf("\nATAQUES\n");
    printf("1. Corte de Espada\n");
    printf("2. Soco Direto\n");

    if (luke->nivel >= 3) {
        printf("3. Corte Carmesim\n");
    }

    if (luke->nivel >= 5) {
        printf("4. Julgamento\n");
    }

    printf("\nEscolha: ");
    scanf("%d", &opcao);

    return opcao;
}

int calcularDanoNoInimigo(int dano, int resistencia, int penetracao) {
    int resistenciaEfetiva = resistencia - penetracao;

    if (resistenciaEfetiva < 0) {
        resistenciaEfetiva = 0;
    }

    dano = dano * (100 - resistenciaEfetiva) / 100;

    if (dano < 1) {
        dano = 1;
    }

    return dano;
}

int executarAtaqueLuke(Luke *luke, int *penetracao) {
    int opcao = escolherAtaqueLuke(luke);
    *penetracao = 0;

    switch (opcao) {
        case 1:
            return corteEspada(luke);
        case 2:
            return socoDireto(luke);
        case 3:
            if (luke->nivel >= 3) {
                return corteCarmesim(luke);
            }
            break;
        case 4:
            if (luke->nivel >= 5) {
                *penetracao = calcularPenetracao(luke);
                return julgamento(luke);
            }
            break;
    }

    return 0;
}

int abrirBolsa(Luke *luke) {
    int opcao;

    printf("\nBOLSA\n");
    printf("1. Frasco de Sangue: %d\n", luke->frascoSangue);
    printf("2. Pocao de Cura: %d\n", luke->pocaoCura);
    printf("3. Antidoto: %d\n", luke->antidoto);
    printf("4. Ataduras: %d\n", luke->ataduras);
    printf("5. Voltar\n");

    printf("\nEscolha: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            if (luke->frascoSangue > 0) {
                usarFrascoSangue(luke);
                printf("\nLuke usou um Frasco de Sangue.\n");
                return 1;
            }
            printf("\nVoce nao possui Frasco de Sangue.\n");
            return 0;

        case 2:
            if (luke->pocaoCura > 0) {
                usarPocaoCura(luke);
                printf("\nLuke usou uma Pocao de Cura.\n");
                return 1;
            }
            printf("\nVoce nao possui Pocao de Cura.\n");
            return 0;

        case 3:
            if (luke->antidoto > 0 && luke->envenenamento == 1) {
                usarAntidoto(luke);
                printf("\nLuke usou um Antidoto.\n");
                return 1;
            }
            printf("\nNao foi possivel usar o Antidoto.\n");
            return 0;

        case 4:
            if (luke->ataduras > 0 &&
                (luke->sangramento == 1 || luke->queimadura == 1)) {
                usarAtadura(luke);
                printf("\nLuke usou uma Atadura.\n");
                return 1;
            }
            printf("\nNao foi possivel usar a Atadura.\n");
            return 0;

        case 5:
            return 0;

        default:
            printf("\nOpcao invalida.\n");
            return 0;
    }
}

int verificarEsquiva(Luke *luke, int esquivaAtiva) {
    int chance;

    if (esquivaAtiva == 1) {
        chance = calcularEvasaoAtiva(luke);
    } else {
        chance = calcularEvasaoPassiva(luke);
    }

    return rand() % 100 < chance;
}

int verificarEvasaoInimigo(int evasao) {
    return rand() % 100 < evasao;
}

void processarDropSeguranca(Luke *luke) {
    int encontrouItem = 0;

    printf("\nVerificando itens do Seguranca...\n");

    if (rand() % 100 < 30) {
        luke->ataduras++;
        printf("Luke encontrou uma Atadura.\n");
        encontrouItem = 1;
    }

    if (rand() % 100 < 5) {
        luke->frascoSangue++;
        printf("Luke encontrou um Frasco de Sangue.\n");
        encontrouItem = 1;
    }

    if (encontrouItem == 0) {
        printf("Nenhum item encontrado.\n");
    }
}

void processarDropCientista(Luke *luke) {
    int encontrouItem = 0;

    printf("\nVerificando itens do Cientista...\n");

    if (rand() % 100 < 10) {
        luke->frascoSangue++;
        printf("Luke encontrou um Frasco de Sangue.\n");
        encontrouItem = 1;
    }

    if (rand() % 100 < 60) {
        luke->pocaoCura++;
        printf("Luke encontrou uma Pocao de Cura.\n");
        encontrouItem = 1;
    }

    if (rand() % 100 < 60) {
        luke->antidoto++;
        printf("Luke encontrou um Antidoto.\n");
        encontrouItem = 1;
    }

    if (encontrouItem == 0) {
        printf("Nenhum item encontrado.\n");
    }
}

void combateMutante(Luke *luke, Mutante *mutante) {
    int acao;
    int dano;
    int penetracao;
    int esquivaAtiva;

    while (luke->vida > 0 && mutante->vida > 0) {
        limparTela();
        printf("===== TURNO DE LUKE =====\n");
        mostrarStatusCombate(
            luke,
            "MUTANTE",
            mutante->vida,
            mutante->vidaMaxima,
            mutante->sangramento,
            0,
            mutante->envenenamento
        );

        esquivaAtiva = 0;
        acao = escolherAcao();

        switch (acao) {
            case 1:
                dano = executarAtaqueLuke(luke, &penetracao);

                if (dano <= 0) {
                    printf("\nAtaque invalido.\n");
                    esperarEnter();
                    continue;
                }

                if (verificarEvasaoInimigo(mutante->evasao)) {
                    printf("\nO Mutante desviou do ataque.\n");
                } else {
                    dano = calcularDanoNoInimigo(dano, mutante->resistencia, penetracao);
                    mutante->vida -= dano;
                    if (mutante->vida < 0) mutante->vida = 0;
                    printf("\nLuke causou %d de dano.\n", dano);
                }
                break;

            case 2:
                esquivaAtiva = 1;
                printf("\nLuke se prepara para esquivar.\n");
                break;

            case 3:
                if (abrirBolsa(luke) == 0) {
                    esperarEnter();
                    continue;
                }
                break;

            default:
                printf("\nOpcao invalida.\n");
                esperarEnter();
                continue;
        }

        esperarEnter();

        if (mutante->vida <= 0) break;

        limparTela();
        printf("===== TURNO DO MUTANTE =====\n");
        mostrarStatusCombate(
            luke,
            "MUTANTE",
            mutante->vida,
            mutante->vidaMaxima,
            mutante->sangramento,
            0,
            mutante->envenenamento
        );

        if (verificarEsquiva(luke, esquivaAtiva)) {
            printf("\nO Mutante atacou, mas Luke esquivou!\n");
        } else {
            printf("\n");
            ataqueFuria(mutante, luke);
        }

        if (luke->vida > 0) {
            processarEfeitos(luke);
        }

        esperarEnter();
    }

    limparTela();

    if (luke->vida <= 0) {
        printf("\nLuke foi derrotado.\n");
        esperarEnter();
        return;
    }

    printf("\nMutante derrotado!\n");
    subirNivel(luke);
    esperarEnter();
}

void combateSeguranca(Luke *luke, Seguranca *seguranca) {
    int acao;
    int dano;
    int penetracao;
    int esquivaAtiva;
    int ataqueInimigo;

    while (luke->vida > 0 && seguranca->vida > 0) {
        limparTela();
        printf("===== TURNO DE LUKE =====\n");
        mostrarStatusCombate(
            luke,
            "SEGURANCA",
            seguranca->vida,
            seguranca->vidaMaxima,
            0,
            0,
            0
        );

        esquivaAtiva = 0;
        acao = escolherAcao();

        switch (acao) {
            case 1:
                dano = executarAtaqueLuke(luke, &penetracao);
                if (dano <= 0) {
                    printf("\nAtaque invalido.\n");
                    esperarEnter();
                    continue;
                }

                if (verificarEvasaoInimigo(seguranca->evasao)) {
                    printf("\nO Seguranca desviou do ataque.\n");
                } else {
                    dano = calcularDanoNoInimigo(dano, seguranca->resistencia, penetracao);
                    seguranca->vida -= dano;
                    if (seguranca->vida < 0) seguranca->vida = 0;
                    printf("\nLuke causou %d de dano.\n", dano);
                }
                break;

            case 2:
                esquivaAtiva = 1;
                printf("\nLuke se prepara para esquivar.\n");
                break;

            case 3:
                if (abrirBolsa(luke) == 0) {
                    esperarEnter();
                    continue;
                }
                break;

            default:
                printf("\nOpcao invalida.\n");
                esperarEnter();
                continue;
        }

        esperarEnter();

        if (seguranca->vida <= 0) break;

        limparTela();
        printf("===== TURNO DO SEGURANCA =====\n");
        mostrarStatusCombate(
            luke,
            "SEGURANCA",
            seguranca->vida,
            seguranca->vidaMaxima,
            0,
            0,
            0
        );

        if (verificarEsquiva(luke, esquivaAtiva)) {
            printf("\nO Seguranca atacou, mas Luke esquivou!\n");
        } else {
            printf("\n");
            ataqueInimigo = rand() % 2;

            if (ataqueInimigo == 0) {
                tiroRifle(seguranca, luke);
            } else {
                coronhada(seguranca, luke);
            }
        }

        if (luke->vida > 0) {
            processarEfeitos(luke);
        }

        esperarEnter();
    }

    limparTela();

    if (luke->vida <= 0) {
        printf("\nLuke foi derrotado.\n");
        esperarEnter();
        return;
    }

    printf("\nSeguranca derrotado!\n");
    processarDropSeguranca(luke);
    subirNivel(luke);
    esperarEnter();
}

void combateCientista(Luke *luke, Cientista *cientista) {
    int acao;
    int dano;
    int penetracao;
    int esquivaAtiva;
    int ataqueInimigo;

    while (luke->vida > 0 && cientista->vida > 0) {
        limparTela();
        printf("===== TURNO DE LUKE =====\n");
        mostrarStatusCombate(
            luke,
            "CIENTISTA",
            cientista->vida,
            cientista->vidaMaxima,
            0,
            0,
            0
        );

        esquivaAtiva = 0;
        acao = escolherAcao();

        switch (acao) {
            case 1:
                dano = executarAtaqueLuke(luke, &penetracao);
                if (dano <= 0) {
                    printf("\nAtaque invalido.\n");
                    esperarEnter();
                    continue;
                }

                if (verificarEvasaoInimigo(cientista->evasao)) {
                    printf("\nO Cientista desviou do ataque.\n");
                } else {
                    dano = calcularDanoNoInimigo(dano, cientista->resistencia, penetracao);
                    cientista->vida -= dano;
                    if (cientista->vida < 0) cientista->vida = 0;
                    printf("\nLuke causou %d de dano.\n", dano);
                }
                break;

            case 2:
                esquivaAtiva = 1;
                printf("\nLuke se prepara para esquivar.\n");
                break;

            case 3:
                if (abrirBolsa(luke) == 0) {
                    esperarEnter();
                    continue;
                }
                break;

            default:
                printf("\nOpcao invalida.\n");
                esperarEnter();
                continue;
        }

        esperarEnter();

        if (cientista->vida <= 0) break;

        limparTela();
        printf("===== TURNO DO CIENTISTA =====\n");
        mostrarStatusCombate(
            luke,
            "CIENTISTA",
            cientista->vida,
            cientista->vidaMaxima,
            0,
            0,
            0
        );

        if (verificarEsquiva(luke, esquivaAtiva)) {
            printf("\nO Cientista atacou, mas Luke esquivou!\n");
        } else {
            printf("\n");
            ataqueInimigo = rand() % 3;

            switch (ataqueInimigo) {
                case 0:
                    jogarAcido(cientista, luke);
                    break;
                case 1:
                    jogarPocaoToxica(cientista, luke);
                    break;
                case 2:
                    arremessarObjeto(cientista, luke);
                    break;
            }
        }

        if (luke->vida > 0) {
            processarEfeitos(luke);
        }

        esperarEnter();
    }

    limparTela();

    if (luke->vida <= 0) {
        printf("\nLuke foi derrotado.\n");
        esperarEnter();
        return;
    }

    printf("\nCientista derrotado!\n");
    processarDropCientista(luke);
    subirNivel(luke);
    esperarEnter();
}

void combateLucius(Luke *luke, Lucius *lucius) {
    int acao;
    int dano;
    int penetracao;
    int esquivaAtiva;
    int ataqueInimigo;

    while (luke->vida > 0 && lucius->vida > 0) {
        limparTela();
        printf("===== TURNO DE LUKE =====\n");
        mostrarStatusCombate(
            luke,
            "LUCIUS VARN",
            lucius->vida,
            lucius->vidaMaxima,
            lucius->sangramento,
            0,
            0
        );

        esquivaAtiva = 0;
        acao = escolherAcao();

        switch (acao) {
            case 1:
                dano = executarAtaqueLuke(luke, &penetracao);
                if (dano <= 0) {
                    printf("\nAtaque invalido.\n");
                    esperarEnter();
                    continue;
                }

                if (verificarEvasaoInimigo(lucius->evasao)) {
                    printf("\nLucius desviou do ataque.\n");
                } else {
                    dano = calcularDanoNoInimigo(dano, lucius->resistencia, penetracao);
                    lucius->vida -= dano;
                    if (lucius->vida < 0) lucius->vida = 0;
                    printf("\nLuke causou %d de dano.\n", dano);
                }
                break;

            case 2:
                esquivaAtiva = 1;
                printf("\nLuke se prepara para esquivar.\n");
                break;

            case 3:
                if (abrirBolsa(luke) == 0) {
                    esperarEnter();
                    continue;
                }
                break;

            default:
                printf("\nOpcao invalida.\n");
                esperarEnter();
                continue;
        }

        esperarEnter();

        if (lucius->vida <= 0) break;

        limparTela();
        printf("===== TURNO DE LUCIUS =====\n");
        mostrarStatusCombate(
            luke,
            "LUCIUS VARN",
            lucius->vida,
            lucius->vidaMaxima,
            lucius->sangramento,
            0,
            0
        );

        if (verificarEsquiva(luke, esquivaAtiva)) {
            printf("\nLucius atacou, mas Luke esquivou!\n");
        } else {
            printf("\n");
            ataqueInimigo = rand() % 4;

            switch (ataqueInimigo) {
                case 0:
                    corteLamina(lucius, luke);
                    break;
                case 1:
                    disparoLaser(lucius, luke);
                    break;
                case 2:
                    socoPesado(lucius, luke);
                    break;
                case 3:
                    socoLeve(lucius, luke);
                    break;
            }
        }

        if (luke->vida > 0) {
            processarEfeitos(luke);
        }

        esperarEnter();
    }

    limparTela();

    if (luke->vida <= 0) {
        printf("\nLuke foi derrotado por Lucius Varn.\n");
        esperarEnter();
        return;
    }

    printf("\nLucius Varn foi derrotado!\n");
    printf("Luke venceu a batalha final.\n");
    esperarEnter();
}
