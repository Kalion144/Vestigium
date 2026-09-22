package personagens;
public class Lucius {
    public int vida, vidaMaxima, forca, resistenciaBase, resistencia, evasao, sangramento, bonusExoesqueleto;
    public Lucius() {
        vidaMaxima = 300; vida = vidaMaxima; forca = 22;
        resistenciaBase = 20; bonusExoesqueleto = 40;
        resistencia = resistenciaBase + (resistenciaBase * bonusExoesqueleto / 100);
        evasao = 12; sangramento = 0;
    }
}
