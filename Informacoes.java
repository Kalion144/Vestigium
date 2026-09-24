public class Informacoes {

    public static void mostrarInformacoes() {
        int opcao;

        do {
            Tela.limparTela();

            System.out.println("╔══════════════════════════════════════╗");
            System.out.println("║              INFORMAÇÕES             ║");
            System.out.println("╠══════════════════════════════════════╣");
            System.out.println("║                                      ║");
            System.out.println("║   1 - Combate                        ║");
            System.out.println("║   2 - Turnos                         ║");
            System.out.println("║   3 - Atributos                      ║");
            System.out.println("║   4 - Ataques de Luke                ║");
            System.out.println("║   5 - Efeitos                        ║");
            System.out.println("║   6 - Itens e Drops                  ║");
            System.out.println("║   7 - Evolução                       ║");
            System.out.println("║   8 - Voltar                         ║");
            System.out.println("║                                      ║");
            System.out.println("╚══════════════════════════════════════╝");
            System.out.print("\nEscolha uma opção: ");

            opcao = Tela.lerInteiro();

            switch (opcao) {
                case 1 -> mostrarCombate();
                case 2 -> mostrarTurnos();
                case 3 -> mostrarAtributos();
                case 4 -> mostrarAtaques();
                case 5 -> mostrarEfeitos();
                case 6 -> mostrarItens();
                case 7 -> mostrarEvolucao();
                case 8 -> { }
                default -> {
                    System.out.println("\nOpção inválida!");
                    Tela.esperarEnter();
                }
            }

        } while (opcao != 8);
    }

    public static void mostrarCombate() {
        Tela.limparTela();

        System.out.println("=============== COMBATE ===============\n");
        System.out.println("O combate de VESTIGIUM acontece por turnos.");
        System.out.println("O objetivo é reduzir a vida do inimigo a 0 antes");
        System.out.println("que a vida de Luke chegue a 0.\n");

        System.out.println("AÇÕES DE LUKE");
        System.out.println("1. Atacar   - Escolhe um dos ataques disponíveis.");
        System.out.println("2. Esquivar - Gasta o turno para aumentar bastante");
        System.out.println("              a chance de evitar o próximo ataque.");
        System.out.println("3. Bolsa    - Permite utilizar um item.\n");

        System.out.println("RESISTÊNCIA DO INIMIGO");
        System.out.println("Parte do dano de Luke pode ser reduzida pela resistência");
        System.out.println("do inimigo. O ataque Julgamento possui penetração e");
        System.out.println("consegue ignorar parte dessa resistência.\n");

        System.out.println("EVASÃO");
        System.out.println("Luke e os inimigos podem desviar de ataques.");
        System.out.println("A Agilidade aumenta a esquiva de Luke.\n");

        System.out.println("VITÓRIA E DERROTA");
        System.out.println("O combate termina quando Luke ou o inimigo chega a 0 HP.");

        Tela.esperarEnter();
    }

    public static void mostrarTurnos() {
        Tela.limparTela();

        System.out.println("================ TURNOS ================\n");
        System.out.println("Cada rodada é formada pelo turno de Luke e pelo turno");
        System.out.println("do inimigo.\n");

        System.out.println("1. Luke escolhe uma ação.");
        System.out.println("2. Se Luke atacar, o inimigo ainda pode desviar.");
        System.out.println("3. Se o inimigo sobreviver, ele realiza seu ataque.");
        System.out.println("4. A esquiva de Luke é verificada.");
        System.out.println("5. Os efeitos ativos de Luke são processados.");
        System.out.println("6. Se o inimigo estiver sangrando, o sangramento dele");
        System.out.println("   também é processado.");
        System.out.println("7. Uma nova rodada começa.\n");

        System.out.println("Usar um item consome o turno quando o item é utilizado.");
        System.out.println("Voltar da Bolsa ou escolher uma opção inválida não");
        System.out.println("consome o turno.");

        Tela.esperarEnter();
    }

    public static void mostrarAtributos() {
        Tela.limparTela();

        System.out.println("=============== ATRIBUTOS ===============\n");
        System.out.println("Luke possui quatro atributos distribuíveis.");
        System.out.println("Cada atributo pode chegar no máximo a 5 pontos.\n");

        System.out.println("FORÇA");
        System.out.println("Aumenta diretamente o dano dos ataques de Luke.");
        System.out.println("Cada ponto acrescenta 3 ao cálculo base dos ataques.\n");

        System.out.println("RESISTÊNCIA");
        System.out.println("Reduz o dano físico recebido por Luke.");
        System.out.println("Cada ponto representa 10% de resistência.");
        System.out.println("No nível máximo do atributo, Luke possui 50%.\n");

        System.out.println("AGILIDADE");
        System.out.println("Aumenta a chance de esquiva.");
        System.out.println("A esquiva ativa começa em 5% e aumenta 14% por ponto.");
        System.out.println("A esquiva passiva corresponde a aproximadamente 1/3");
        System.out.println("da chance da esquiva ativa.\n");

        System.out.println("PRECISÃO");
        System.out.println("Aumenta a chance de crítico do Soco Direto e Julgamento.");
        System.out.println("Também aumenta a penetração do Julgamento.");
        System.out.println("Crítico: 5% + 9% por ponto.");
        System.out.println("Penetração: 6% por ponto.");

        Tela.esperarEnter();
    }

    public static void mostrarAtaques() {
        Tela.limparTela();

        System.out.println("============= ATAQUES DE LUKE =============\n");

        System.out.println("CORTE DE ESPADA - disponível desde o nível 1");
        System.out.println("Dano: 10 + (nível x 2) + (força x 3)");
        System.out.println("Efeito: 5% de chance de causar Sangramento.\n");

        System.out.println("SOCO DIRETO - disponível desde o nível 1");
        System.out.println("Dano: 8 + (nível x 2) + (força x 3)");
        System.out.println("Efeito: pode causar acerto crítico.");
        System.out.println("O crítico causa 50% de dano adicional e sua chance");
        System.out.println("depende da Precisão de Luke.\n");

        System.out.println("CORTE CARMESIM - desbloqueado no nível 3");
        System.out.println("Dano: 13 + (nível x 2) + (força x 3)");
        System.out.println("Efeito: 20% de chance de causar Sangramento.\n");

        System.out.println("JULGAMENTO - desbloqueado no nível 5");
        System.out.println("Dano: 16 + (nível x 2) + (força x 3)");
        System.out.println("Efeito: pode causar crítico e utiliza Penetração.");
        System.out.println("A Penetração ignora parte da resistência do inimigo.\n");

        System.out.println("SANGRAMENTO CAUSADO POR LUKE");
        System.out.println("Quando Corte de Espada ou Corte Carmesim aplica o efeito,");
        System.out.println("o inimigo perde 5% da vida máxima ao fim de cada rodada.");
        System.out.println("O mesmo Sangramento não acumula nem pode ser reaplicado");
        System.out.println("enquanto ainda estiver ativo.");

        Tela.esperarEnter();
    }

    public static void mostrarEfeitos() {
        Tela.limparTela();

        System.out.println("================ EFEITOS ================\n");

        System.out.println("SANGRAMENTO");
        System.out.println("- Causa 5% da vida máxima por rodada.");
        System.out.println("- Se ultrapassar 7 turnos sem tratamento, causa morte");
        System.out.println("  por hemorragia no processamento seguinte.");
        System.out.println("- Luke pode remover o efeito com Atadura ou Sangue.");
        System.out.println("- Luke também pode causar Sangramento nos inimigos com");
        System.out.println("  Corte de Espada (5%) e Corte Carmesim (20%).\n");

        System.out.println("QUEIMADURA");
        System.out.println("- Causa imediatamente 10% da vida máxima de Luke.");
        System.out.println("- Reduz a Força de Luke em 30% enquanto estiver ativa.");
        System.out.println("- Dura no máximo 5 turnos.");
        System.out.println("- Pode ser removida com Atadura ou Frasco de Sangue.\n");

        System.out.println("ENVENENAMENTO");
        System.out.println("- Começa causando 1% da vida máxima.");
        System.out.println("- A intensidade aumenta em 1 ponto percentual por rodada.");
        System.out.println("- Não possui limite de intensidade enquanto permanecer ativo.");
        System.out.println("- Pode ser removido com Antídoto ou Frasco de Sangue.\n");

        System.out.println("REGRAS GERAIS");
        System.out.println("Efeitos diferentes podem existir ao mesmo tempo.");
        System.out.println("O mesmo efeito não acumula enquanto já estiver ativo.");
        System.out.println("Os efeitos de Luke permanecem entre os combates.");

        Tela.esperarEnter();
    }

    public static void mostrarItens() {
        Tela.limparTela();

        System.out.println("============= ITENS E DROPS =============\n");

        System.out.println("FRASCO DE SANGUE");
        System.out.println("Recupera toda a vida de Luke e remove Sangramento,");
        System.out.println("Queimadura e Envenenamento. Luke começa com 1.\n");

        System.out.println("POÇÃO DE CURA");
        System.out.println("Recupera 30% da vida máxima de Luke.");
        System.out.println("Não remove efeitos negativos.\n");

        System.out.println("ANTÍDOTO");
        System.out.println("Remove o Envenenamento.\n");

        System.out.println("ATADURA");
        System.out.println("Remove Sangramento e Queimadura. Luke começa com 1.\n");

        System.out.println("DROPS DO SEGURANÇA");
        System.out.println("- 30% de chance de encontrar uma Atadura.");
        System.out.println("- 5% de chance de encontrar um Frasco de Sangue.\n");

        System.out.println("DROPS DO CIENTISTA");
        System.out.println("- 10% de chance de Frasco de Sangue.");
        System.out.println("- 60% de chance de Poção de Cura.");
        System.out.println("- 60% de chance de Antídoto.\n");

        System.out.println("Cada drop é calculado separadamente, então é possível");
        System.out.println("encontrar mais de um item depois do mesmo combate.");

        Tela.esperarEnter();
    }

    public static void mostrarEvolucao() {
        Tela.limparTela();

        System.out.println("=============== EVOLUÇÃO ===============\n");
        System.out.println("Luke começa no nível 1 com 100 de vida máxima e");
        System.out.println("3 pontos de atributo para distribuir.\n");

        System.out.println("Após cada um dos quatro primeiros combates vencidos:");
        System.out.println("- Luke sobe 1 nível.");
        System.out.println("- A vida máxima aumenta em 20.");
        System.out.println("- A vida atual é restaurada até a vida máxima.");
        System.out.println("- Luke recebe mais 3 pontos de atributo.\n");

        System.out.println("Vida máxima por nível:");
        System.out.println("Nível 1: 100");
        System.out.println("Nível 2: 120");
        System.out.println("Nível 3: 140");
        System.out.println("Nível 4: 160");
        System.out.println("Nível 5: 180\n");

        System.out.println("IMPORTANTE");
        System.out.println("Subir de nível recupera a vida, mas NÃO remove efeitos.");
        System.out.println("Sangramento, Queimadura e Envenenamento podem continuar");
        System.out.println("ativos no combate seguinte até serem removidos.");

        Tela.esperarEnter();
    }
}
