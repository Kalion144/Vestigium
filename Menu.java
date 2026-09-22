public class Menu {
    public static void mostrarMenu() {
        int opcao;
        do {
            Tela.limparTela();
            System.out.println("╔══════════════════════════════════════╗");
            System.out.println("║              VESTIGIUM               ║");
            System.out.println("╠══════════════════════════════════════╣");
            System.out.println("║  1. Iniciar Jogo                     ║");
            System.out.println("║  2. Informações                      ║");
            System.out.println("║  3. Créditos                         ║");
            System.out.println("║  4. Sair                             ║");
            System.out.println("╚══════════════════════════════════════╝");
            System.out.print("\nEscolha uma opção: ");
            opcao = Tela.lerInteiro();
            switch (opcao) {
                case 1 -> Jogo.iniciarJogo();
                case 2 -> Informacoes.mostrarInformacoes();
                case 3 -> Creditos.mostrarCreditos();
                case 4 -> { Tela.limparTela(); System.out.println("Encerrando VESTIGIUM..."); }
                default -> { System.out.println("\nOpção inválida."); Tela.esperarEnter(); }
            }
        } while (opcao != 4);
    }
}
