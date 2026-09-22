package personagens;
public class Cientista {
    public int vida, vidaMaxima, forca, resistencia, precisao, evasao;
    public int chanceEnvenenamento, chanceQueimadura;
    public int chanceFrascoSangue, chancePocaoCura, chanceAntidoto;
    public Cientista() {
        vidaMaxima = 180; vida = vidaMaxima;
        forca = 20; resistencia = 10; precisao = 15; evasao = 10;
        chanceEnvenenamento = 30; chanceQueimadura = 30;
        chanceFrascoSangue = 10; chancePocaoCura = 60; chanceAntidoto = 60;
    }
}
