package personagens;

public class Mutante {
    public int vida;
    public int vidaMaxima;
    public int forca;
    public int resistencia;
    public int evasao;

    public int sangramento;
    public int turnosSangramento;
    public int envenenamento;

    public Mutante() {
        vidaMaxima = 85;
        vida = vidaMaxima;
        forca = 7;
        resistencia = 0;
        evasao = 8;

        sangramento = 0;
        turnosSangramento = 0;
        envenenamento = 0;
    }
}
