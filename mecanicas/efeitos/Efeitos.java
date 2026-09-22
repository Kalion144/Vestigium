package mecanicas.efeitos;
import personagens.Luke;

public class Efeitos {
    public static void aplicarSangramento(Luke luke) {
        if (luke.sangramento == 0) { luke.sangramento = 1; luke.turnosSangramento = 0; }
    }
    public static void aplicarQueimadura(Luke luke) {
        if (luke.queimadura == 0) {
            luke.queimadura = 1; luke.turnosQueimadura = 0;
            int dano = luke.vidaMaxima * 10 / 100; if (dano < 1) dano = 1;
            luke.vida -= dano; if (luke.vida < 0) luke.vida = 0;
        }
    }
    public static void aplicarEnvenenamento(Luke luke) {
        if (luke.envenenamento == 0) { luke.envenenamento = 1; luke.intensidadeVeneno = 1; }
    }
    public static void processarSangramento(Luke luke) {
        if (luke.sangramento == 1) {
            luke.turnosSangramento++;
            if (luke.turnosSangramento > 7) { luke.vida = 0; return; }
            int dano = luke.vidaMaxima * 5 / 100; if (dano < 1) dano = 1;
            luke.vida -= dano; if (luke.vida < 0) luke.vida = 0;
        }
    }
    public static void processarQueimadura(Luke luke) {
        if (luke.queimadura == 1) { luke.turnosQueimadura++; if (luke.turnosQueimadura >= 5) removerQueimadura(luke); }
    }
    public static void processarEnvenenamento(Luke luke) {
        if (luke.envenenamento == 1) {
            int dano = luke.vidaMaxima * luke.intensidadeVeneno / 100; if (dano < 1) dano = 1;
            luke.vida -= dano; if (luke.vida < 0) luke.vida = 0; luke.intensidadeVeneno++;
        }
    }
    public static void processarEfeitos(Luke luke) {
        processarSangramento(luke); if (luke.vida <= 0) return;
        processarQueimadura(luke); if (luke.vida <= 0) return;
        processarEnvenenamento(luke);
    }
    public static void removerSangramento(Luke luke) { luke.sangramento = 0; luke.turnosSangramento = 0; }
    public static void removerQueimadura(Luke luke) { luke.queimadura = 0; luke.turnosQueimadura = 0; }
    public static void removerEnvenenamento(Luke luke) { luke.envenenamento = 0; luke.intensidadeVeneno = 1; }
    public static int calcularForcaAtual(Luke luke, int forcaBase) { return luke.queimadura == 1 ? forcaBase * 70 / 100 : forcaBase; }
}
