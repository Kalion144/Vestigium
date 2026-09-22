package mecanicas.evolucao;
import personagens.Luke;
import java.util.Scanner;

public class Evolucao {
    public static void subirNivel(Luke luke) {
        if (luke.nivel >= 5) return;
        luke.nivel++;
        luke.vidaMaxima += 20;
        luke.vida = luke.vidaMaxima;
        luke.pontosAtributo += 3;
    }

    public static void distribuirAtributos(Luke luke, Scanner sc) {
        while (luke.pontosAtributo > 0) {
            System.out.printf("\nPontos disponiveis: %d\n", luke.pontosAtributo);
            System.out.printf("1. Forca: %d/5\n", luke.forca);
            System.out.printf("2. Resistencia: %d/5\n", luke.resistencia);
            System.out.printf("3. Agilidade: %d/5\n", luke.agilidade);
            System.out.printf("4. Precisao: %d/5\n", luke.precisao);
            System.out.println("5. Sair");
            System.out.print("\nEscolha um atributo: ");
            int opcao = lerInteiro(sc);
            switch (opcao) {
                case 1 -> { if (luke.forca < 5) { luke.forca++; luke.pontosAtributo--; } }
            case 2 -> { if (luke.resistencia < 5) { luke.resistencia++; luke.pontosAtributo--; } }
            case 3 -> { if (luke.agilidade < 5) { luke.agilidade++; luke.pontosAtributo--; } }
            case 4 -> { if (luke.precisao < 5) { luke.precisao++; luke.pontosAtributo--; } }
            case 5 -> { return; }
            }
        }
    }

    private static int lerInteiro(Scanner sc) {
        while (true) {
            String s = sc.nextLine();
            try { return Integer.parseInt(s.trim()); }
            catch (NumberFormatException e) { System.out.print("Digite um numero valido: "); }
        }
    }

    public static int calcularResistencia(Luke luke) { return luke.resistencia * 10; }
    public static int calcularEvasaoAtiva(Luke luke) { return 5 + (luke.agilidade * 14); }
    public static int calcularEvasaoPassiva(Luke luke) { return calcularEvasaoAtiva(luke) / 3; }
    public static int calcularCritico(Luke luke) { return 5 + (luke.precisao * 9); }
    public static int calcularPenetracao(Luke luke) { return luke.precisao * 6; }
}
