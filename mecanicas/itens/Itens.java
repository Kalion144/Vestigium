package mecanicas.itens;
import personagens.Luke;
import mecanicas.efeitos.Efeitos;

public class Itens {
    public static void usarFrascoSangue(Luke luke) {
        if (luke.frascoSangue <= 0) return;
        luke.vida = luke.vidaMaxima;
        Efeitos.removerSangramento(luke); Efeitos.removerQueimadura(luke); Efeitos.removerEnvenenamento(luke);
        luke.frascoSangue--;
    }
    public static void usarPocaoCura(Luke luke) {
        if (luke.pocaoCura <= 0) return;
        int cura = luke.vidaMaxima * 30 / 100;
        luke.vida += cura; if (luke.vida > luke.vidaMaxima) luke.vida = luke.vidaMaxima;
        luke.pocaoCura--;
    }
    public static void usarAntidoto(Luke luke) {
        if (luke.antidoto <= 0 || luke.envenenamento == 0) return;
        Efeitos.removerEnvenenamento(luke); luke.antidoto--;
    }
    public static void usarAtadura(Luke luke) {
        if (luke.ataduras <= 0 || (luke.sangramento == 0 && luke.queimadura == 0)) return;
        Efeitos.removerSangramento(luke); Efeitos.removerQueimadura(luke); luke.ataduras--;
    }
}
