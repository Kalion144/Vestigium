package personagens;

public class Cientista {
    public int vida;
    public int vidaMaxima;
    public int forca;
    public int resistencia;
    public int precisao;
    public int evasao;

    public int sangramento;
    public int turnosSangramento;

    public int chanceEnvenenamento;
    public int chanceQueimadura;
    public int chanceFrascoSangue;
    public int chancePocaoCura;
    public int chanceAntidoto;

    public Cientista() {
        vidaMaxima = 160;
        vida = vidaMaxima;
        forca = 18;
        resistencia = 10;
        precisao = 15;
        evasao = 10;

        sangramento = 0;
        turnosSangramento = 0;

        chanceEnvenenamento = 30;
        chanceQueimadura = 30;
        chanceFrascoSangue = 10;
        chancePocaoCura = 60;
        chanceAntidoto = 60;
    }
}
