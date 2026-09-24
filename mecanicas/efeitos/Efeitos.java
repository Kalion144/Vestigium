package mecanicas.efeitos;

import personagens.Cientista;
import personagens.Lucius;
import personagens.Luke;
import personagens.Mutante;
import personagens.Seguranca;

public class Efeitos {

    public static void aplicarSangramento(Luke luke) {
        if (luke.sangramento == 0) {
            luke.sangramento = 1;
            luke.turnosSangramento = 0;
        }
    }

    public static void aplicarQueimadura(Luke luke) {
        if (luke.queimadura == 0) {
            luke.queimadura = 1;
            luke.turnosQueimadura = 0;

            int dano = luke.vidaMaxima * 10 / 100;
            luke.vida -= Math.max(dano, 1);

            if (luke.vida < 0) {
                luke.vida = 0;
            }
        }
    }

    public static void aplicarEnvenenamento(Luke luke) {
        if (luke.envenenamento == 0) {
            luke.envenenamento = 1;
            luke.intensidadeVeneno = 1;
        }
    }

    public static void processarEfeitos(Luke luke) {
        processarSangramento(luke);
        if (luke.vida <= 0) return;

        processarQueimadura(luke);
        if (luke.vida <= 0) return;

        processarEnvenenamento(luke);
    }

    public static void processarSangramento(Luke luke) {
        if (luke.sangramento == 0) return;

        luke.turnosSangramento++;

        if (luke.turnosSangramento > 7) {
            luke.vida = 0;
            return;
        }

        int dano = Math.max(luke.vidaMaxima * 5 / 100, 1);
        luke.vida -= dano;

        if (luke.vida < 0) {
            luke.vida = 0;
        }
    }

    public static void processarQueimadura(Luke luke) {
        if (luke.queimadura == 0) return;

        luke.turnosQueimadura++;

        if (luke.turnosQueimadura >= 5) {
            removerQueimadura(luke);
        }
    }

    public static void processarEnvenenamento(Luke luke) {
        if (luke.envenenamento == 0) return;

        int dano = Math.max(luke.vidaMaxima * luke.intensidadeVeneno / 100, 1);
        luke.vida -= dano;

        if (luke.vida < 0) {
            luke.vida = 0;
        }

        luke.intensidadeVeneno++;
    }

    public static void removerSangramento(Luke luke) {
        luke.sangramento = 0;
        luke.turnosSangramento = 0;
    }

    public static void removerQueimadura(Luke luke) {
        luke.queimadura = 0;
        luke.turnosQueimadura = 0;
    }

    public static void removerEnvenenamento(Luke luke) {
        luke.envenenamento = 0;
        luke.intensidadeVeneno = 1;
    }

    public static int calcularForcaAtual(Luke luke, int forcaBase) {
        if (luke.queimadura == 1) {
            return forcaBase * 70 / 100;
        }

        return forcaBase;
    }

    public static void aplicarSangramento(Mutante inimigo) {
        if (inimigo.sangramento == 0) {
            inimigo.sangramento = 1;
            inimigo.turnosSangramento = 0;
        }
    }

    public static void aplicarSangramento(Seguranca inimigo) {
        if (inimigo.sangramento == 0) {
            inimigo.sangramento = 1;
            inimigo.turnosSangramento = 0;
        }
    }

    public static void aplicarSangramento(Cientista inimigo) {
        if (inimigo.sangramento == 0) {
            inimigo.sangramento = 1;
            inimigo.turnosSangramento = 0;
        }
    }

    public static void aplicarSangramento(Lucius inimigo) {
        if (inimigo.sangramento == 0) {
            inimigo.sangramento = 1;
            inimigo.turnosSangramento = 0;
        }
    }

    public static void processarSangramento(Mutante inimigo) {
        if (inimigo.sangramento == 0) return;
        inimigo.turnosSangramento++;
        inimigo.vida = calcularVidaAposSangramento(
                inimigo.vida,
                inimigo.vidaMaxima,
                inimigo.turnosSangramento
        );
    }

    public static void processarSangramento(Seguranca inimigo) {
        if (inimigo.sangramento == 0) return;
        inimigo.turnosSangramento++;
        inimigo.vida = calcularVidaAposSangramento(
                inimigo.vida,
                inimigo.vidaMaxima,
                inimigo.turnosSangramento
        );
    }

    public static void processarSangramento(Cientista inimigo) {
        if (inimigo.sangramento == 0) return;
        inimigo.turnosSangramento++;
        inimigo.vida = calcularVidaAposSangramento(
                inimigo.vida,
                inimigo.vidaMaxima,
                inimigo.turnosSangramento
        );
    }

    public static void processarSangramento(Lucius inimigo) {
        if (inimigo.sangramento == 0) return;
        inimigo.turnosSangramento++;
        inimigo.vida = calcularVidaAposSangramento(
                inimigo.vida,
                inimigo.vidaMaxima,
                inimigo.turnosSangramento
        );
    }

    private static int calcularVidaAposSangramento(
            int vida,
            int vidaMaxima,
            int turnosSangramento) {

        if (turnosSangramento > 7) {
            return 0;
        }

        int dano = Math.max(vidaMaxima * 5 / 100, 1);
        return Math.max(vida - dano, 0);
    }
}
