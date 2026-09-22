import java.io.IOException;
import java.util.Scanner;

public class Tela {
    public static final Scanner SC = new Scanner(System.in);

    public static void limparTela() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }

    public static void esperarEnter() {
        System.out.print("\n              Pressione Enter para continuar...");
        SC.nextLine();
    }

    public static int lerInteiro() {
        while (true) {
            String linha = SC.nextLine();
            try { return Integer.parseInt(linha.trim()); }
            catch (NumberFormatException e) { System.out.print("Digite um numero valido: "); }
        }
    }

    public static void mostrarTexto(String linha1, String linha2, String linha3) {
        limparTela();
        System.out.println();
        System.out.println("====================================================");
        System.out.println("|                                                  ");
        System.out.println("|  " + linha1);
        System.out.println("|  " + linha2);
        System.out.println("|  " + linha3);
        System.out.println("|                                                  ");
        System.out.println("====================================================");
        esperarEnter();
    }
}
