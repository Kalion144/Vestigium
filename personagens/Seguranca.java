package personagens;

public class Seguranca {
    public int vida;
    public int vidaMaxima;
    public int forca;
    public int resistencia;
    public int precisao;
    public int evasao;

    public int sangramento;
    public int turnosSangramento;

    public int chanceQueimadura;
    public int chanceAtadura;
    public int chanceFrascoSangue;

    public Seguranca() {
        vidaMaxima = 110;
        vida = vidaMaxima;
        forca = 15;
        resistencia = 10;
        precisao = 10;
        evasao = 5;

        sangramento = 0;
        turnosSangramento = 0;

        chanceQueimadura = 30;
        chanceAtadura = 30;
        chanceFrascoSangue = 5;
    }
}
