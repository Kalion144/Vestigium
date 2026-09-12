#include <stdio.h>
#include <stdlib.h>

#include "combate.h"

#include "ataques.h"
#include "efeitos.h"
#include "evolucao.h"
#include "itens.h"


void mostrarStatusCombate(Luke *luke, int vidaInimigo, int vidaMaximaInimigo) {
    printf("\n====================================\n");

    printf("LUKE\n");
    printf("Vida: %d/%d\n", luke->vida, luke->vidaMaxima);

    printf("\nINIMIGO\n");
    printf("Vida: %d/%d\n", vidaInimigo, vidaMaximaInimigo);

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


int executarAtaqueLuke(Luke *luke) {
    int opcao;

    opcao = escolherAtaqueLuke(luke);

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
                return 1;
            }

            printf("\nVoce nao possui Frasco de Sangue.\n");
            return 0;

        case 2:
            if (luke->pocaoCura > 0) {
                usarPocaoCura(luke);
                return 1;
            }

            printf("\nVoce nao possui Pocao de Cura.\n");
            return 0;

        case 3:
            if (luke->antidoto > 0 && luke->envenenamento == 1) {
                usarAntidoto(luke);
                return 1;
            }

            printf("\nNao foi possivel usar o Antidoto.\n");
            return 0;

        case 4:
            if (luke->ataduras > 0 &&
                (luke->sangramento == 1 || luke->queimadura == 1)) {

                usarAtadura(luke);
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

    if (rand() % 100 < chance) {
        return 1;
    }

    return 0;
}


int verificarEvasaoInimigo(int evasao) {
    if (rand() % 100 < evasao) {
        return 1;
    }

    return 0;
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
    int esquivaAtiva;

    while (luke->vida > 0 && mutante->vida > 0) {

        mostrarStatusCombate(
            luke,
            mutante->vida,
            mutante->vidaMaxima
        );

        esquivaAtiva = 0;

        acao = escolherAcao();

        switch (acao) {
            case 1:
                dano = executarAtaqueLuke(luke);

                if (dano <= 0) {
                    printf("\nAtaque invalido.\n");
                    continue;
                }

                if (verificarEvasaoInimigo(mutante->evasao)) {
                    printf("\nO Mutante desviou do ataque.\n");
                } else {
                    mutante->vida -= dano;

                    if (mutante->vida < 0) {
                        mutante->vida = 0;
                    }

                    printf("\nLuke causou %d de dano.\n", dano);
                }

                break;

            case 2:
                esquivaAtiva = 1;
                printf("\nLuke se prepara para esquivar.\n");
                break;

            case 3:
                if (abrirBolsa(luke) == 0) {
                    continue;
                }

                break;

            default:
                printf("\nOpcao invalida.\n");
                continue;
        }

        if (mutante->vida <= 0) {
            break;
        }

        if (verificarEsquiva(luke, esquivaAtiva)) {
            printf("\nLuke esquivou do ataque do Mutante.\n");
        } else {
            ataqueFuria(mutante, luke);
        }

        processarEfeitos(luke);
    }

    if (luke->vida <= 0) {
        printf("\nLuke foi derrotado.\n");
        return;
    }

    printf("\nMutante derrotado!\n");

    subirNivel(luke);
}


void combateSeguranca(Luke *luke, Seguranca *seguranca) {
    int acao;
    int dano;
    int esquivaAtiva;
    int ataqueInimigo;

    while (luke->vida > 0 && seguranca->vida > 0) {

        mostrarStatusCombate(
            luke,
            seguranca->vida,
            seguranca->vidaMaxima
        );

        esquivaAtiva = 0;

        acao = escolherAcao();

        switch (acao) {
            case 1:
                dano = executarAtaqueLuke(luke);

                if (dano <= 0) {
                    printf("\nAtaque invalido.\n");
                    continue;
                }

                if (verificarEvasaoInimigo(seguranca->evasao)) {
                    printf("\nO Seguranca desviou do ataque.\n");
                } else {
                    seguranca->vida -= dano;

                    if (seguranca->vida < 0) {
                        seguranca->vida = 0;
                    }

                    printf("\nLuke causou %d de dano.\n", dano);
                }

                break;

            case 2:
                esquivaAtiva = 1;
                printf("\nLuke se prepara para esquivar.\n");
                break;

            case 3:
                if (abrirBolsa(luke) == 0) {
                    continue;
                }

                break;

            default:
                printf("\nOpcao invalida.\n");
                continue;
        }

        if (seguranca->vida <= 0) {
            break;
        }

        if (verificarEsquiva(luke, esquivaAtiva)) {
            printf("\nLuke esquivou do ataque do Seguranca.\n");
        } else {
            ataqueInimigo = rand() % 2;

            if (ataqueInimigo == 0) {
                tiroRifle(seguranca, luke);
            } else {
                coronhada(seguranca, luke);
            }
        }

        processarEfeitos(luke);
    }

    if (luke->vida <= 0) {
        printf("\nLuke foi derrotado.\n");
        return;
    }

    printf("\nSeguranca derrotado!\n");

    processarDropSeguranca(luke);

    subirNivel(luke);
}


void combateCientista(Luke *luke, Cientista *cientista) {
    int acao;
    int dano;
    int esquivaAtiva;
    int ataqueInimigo;

    while (luke->vida > 0 && cientista->vida > 0) {

        mostrarStatusCombate(
            luke,
            cientista->vida,
            cientista->vidaMaxima
        );

        esquivaAtiva = 0;

        acao = escolherAcao();

        switch (acao) {
            case 1:
                dano = executarAtaqueLuke(luke);

                if (dano <= 0) {
                    printf("\nAtaque invalido.\n");
                    continue;
                }

                if (verificarEvasaoInimigo(cientista->evasao)) {
                    printf("\nO Cientista desviou do ataque.\n");
                } else {
                    cientista->vida -= dano;

                    if (cientista->vida < 0) {
                        cientista->vida = 0;
                    }

                    printf("\nLuke causou %d de dano.\n", dano);
                }

                break;

            case 2:
                esquivaAtiva = 1;
                printf("\nLuke se prepara para esquivar.\n");
                break;

            case 3:
                if (abrirBolsa(luke) == 0) {
                    continue;
                }

                break;

            default:
                printf("\nOpcao invalida.\n");
                continue;
        }

        if (cientista->vida <= 0) {
            break;
        }

        if (verificarEsquiva(luke, esquivaAtiva)) {
            printf("\nLuke esquivou do ataque do Cientista.\n");
        } else {
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

        processarEfeitos(luke);
    }

    if (luke->vida <= 0) {
        printf("\nLuke foi derrotado.\n");
        return;
    }

    printf("\nCientista derrotado!\n");

    processarDropCientista(luke);

    subirNivel(luke);
}


void combateLucius(Luke *luke, Lucius *lucius) {
    int acao;
    int dano;
    int esquivaAtiva;
    int ataqueInimigo;

    while (luke->vida > 0 && lucius->vida > 0) {

        mostrarStatusCombate(
            luke,
            lucius->vida,
            lucius->vidaMaxima
        );

        esquivaAtiva = 0;

        acao = escolherAcao();

        switch (acao) {
            case 1:
                dano = executarAtaqueLuke(luke);

                if (dano <= 0) {
                    printf("\nAtaque invalido.\n");
                    continue;
                }

                if (verificarEvasaoInimigo(lucius->evasao)) {
                    printf("\nLucius desviou do ataque.\n");
                } else {
                    lucius->vida -= dano;

                    if (lucius->vida < 0) {
                        lucius->vida = 0;
                    }

                    printf("\nLuke causou %d de dano.\n", dano);
                }

                break;

            case 2:
                esquivaAtiva = 1;
                printf("\nLuke se prepara para esquivar.\n");
                break;

            case 3:
                if (abrirBolsa(luke) == 0) {
                    continue;
                }

                break;

            default:
                printf("\nOpcao invalida.\n");
                continue;
        }

        if (lucius->vida <= 0) {
            break;
        }

        if (verificarEsquiva(luke, esquivaAtiva)) {
            printf("\nLuke esquivou do ataque de Lucius.\n");
        } else {
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

        processarEfeitos(luke);
    }

    if (luke->vida <= 0) {
        printf("\nLuke foi derrotado por Lucius Varn.\n");
        return;
    }

    printf("\nLucius Varn foi derrotado!\n");
    printf("Luke venceu a batalha final.\n");
}