package personagens;
public class Seguranca {
    public int vida, vidaMaxima, forca, resistencia, precisao, evasao;
    public int chanceQueimadura, chanceAtadura, chanceFrascoSangue;
    public Seguranca() {
        vidaMaxima = 80; vida = vidaMaxima;
        forca = 15; resistencia = 10; precisao = 10; evasao = 5;
        chanceQueimadura = 30; chanceAtadura = 30; chanceFrascoSangue = 5;
    }
}
