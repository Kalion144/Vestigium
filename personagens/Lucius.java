package personagens;

public class Lucius {
    public int vida;
    public int vidaMaxima;
    public int forca;
    public int resistenciaBase;
    public int resistencia;
    public int evasao;

    public int sangramento;
    public int turnosSangramento;
    public int bonusExoesqueleto;

    public Lucius() {
        vidaMaxima = 300;
        vida = vidaMaxima;
        forca = 22;

        resistenciaBase = 20;
        bonusExoesqueleto = 40;
        resistencia = resistenciaBase + (resistenciaBase * bonusExoesqueleto / 100);

        evasao = 12;
        sangramento = 0;
        turnosSangramento = 0;
    }
}
