import java.io.IOException;
import java.util.Scanner;

public class Tela {

    public static final Scanner SC = new Scanner(System.in);

    public static void limparTela() {
        try {
            if (System.getProperty("os.name").toLowerCase().contains("windows")) {

                new ProcessBuilder("cmd", "/c", "cls")
                        .inheritIO()
                        .start()
                        .waitFor();

            } else {

                System.out.print("\033[H\033[2J");
                System.out.flush();
            }

        } catch (IOException | InterruptedException e) {
            System.out.println("\n".repeat(50));
        }
    }

    public static void esperarEnter() {
        System.out.print(
            "\n              Pressione Enter para continuar..."
        );

        SC.nextLine();
    }

    public static int lerInteiro() {

        while (true) {

            String entrada = SC.nextLine();

            try {
                return Integer.parseInt(entrada.trim());

            } catch (NumberFormatException e) {
                System.out.print("Digite um número válido: ");
            }
        }
    }

    public static void mostrarTexto(
            String linha1,
            String linha2,
            String linha3) {

        limparTela();

        System.out.println();
        System.out.println(
            "===================================================="
        );
        System.out.println("|");
        System.out.println("|  " + linha1);
        System.out.println("|  " + linha2);
        System.out.println("|  " + linha3);
        System.out.println("|");
        System.out.println(
            "===================================================="
        );

        esperarEnter();
    }
}