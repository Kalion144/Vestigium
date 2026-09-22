package mecanicas.ataques;
import java.util.Random;
import personagens.*;
import mecanicas.efeitos.Efeitos;
import mecanicas.evolucao.Evolucao;

public class Ataques {
    private static final Random RAND = new Random();
    private static int reduzirDanoPorResistenciaLuke(Luke luke, int dano) {
        int resistencia = Evolucao.calcularResistencia(luke);
        dano = dano * (100 - resistencia) / 100;
        return Math.max(dano, 1);
    }
    public static int corteEspada(Luke luke) { int f=Efeitos.calcularForcaAtual(luke,luke.forca); return 10+(luke.nivel*2)+(f*3); }
    public static int socoDireto(Luke luke) {
        int f=Efeitos.calcularForcaAtual(luke,luke.forca); int dano=8+(luke.nivel*2)+(f*3);
        if (RAND.nextInt(100) < Evolucao.calcularCritico(luke)) { dano=dano*150/100; System.out.println("\nAcerto critico de Luke!"); }
        return dano;
    }
    public static int corteCarmesim(Luke luke) { if (luke.nivel<3) return 0; int f=Efeitos.calcularForcaAtual(luke,luke.forca); return 13+(luke.nivel*2)+(f*3); }
    public static int julgamento(Luke luke) {
        if (luke.nivel<5) return 0; int f=Efeitos.calcularForcaAtual(luke,luke.forca); int dano=16+(luke.nivel*2)+(f*3);
        if (RAND.nextInt(100) < Evolucao.calcularCritico(luke)) { dano=dano*150/100; System.out.println("\nJulgamento foi um acerto critico!"); }
        return dano;
    }
    public static void ataqueFuria(Mutante m, Luke l) {
        int dano=reduzirDanoPorResistenciaLuke(l,m.forca); System.out.println("O Mutante usou Ataque de Furia!");
        l.vida-=dano; if(l.vida<0)l.vida=0; System.out.printf("Luke recebeu %d de dano.\n",dano);
        if(RAND.nextInt(100)<15){int j=l.sangramento;
        Efeitos.aplicarSangramento(l);
        if(j==0&&l.sangramento==1)System.out.println("Luke comecou a sangrar!");}
        if(RAND.nextInt(100)<15){int j=l.envenenamento;
        Efeitos.aplicarEnvenenamento(l);
        if(j==0&&l.envenenamento==1)System.out.println("Luke foi envenenado!");}
    }
    public static void tiroRifle(Seguranca s,Luke l){int dano=reduzirDanoPorResistenciaLuke(l,s.forca);
        System.out.println("O Seguranca disparou o Rifle!");
        l.vida-=dano;
        if(l.vida<0)l.vida=0;
        System.out.printf("Luke recebeu %d de dano.\n",dano);
        if(RAND.nextInt(100)<s.chanceQueimadura){int j=l.queimadura;
        Efeitos.aplicarQueimadura(l);
        if(j==0&&l.queimadura==1)System.out.println("Luke sofreu uma queimadura!");}}
    public static void coronhada(Seguranca s,Luke l){int dano=reduzirDanoPorResistenciaLuke(l,s.forca);
        System.out.println("O Seguranca usou Coronhada!");
        l.vida-=dano;
        if(l.vida<0)l.vida=0;
        System.out.printf("Luke recebeu %d de dano.\n",dano);}
    public static void jogarAcido(Cientista c,Luke l){int dano=reduzirDanoPorResistenciaLuke(l,c.forca);
        System.out.println("O Cientista arremessou um Frasco de Acido!");
        l.vida-=dano;
        if(l.vida<0)l.vida=0;
        System.out.printf("Luke recebeu %d de dano.\n",dano);
        if(RAND.nextInt(100)<c.chanceQueimadura){int j=l.queimadura;
        Efeitos.aplicarQueimadura(l);
        if(j==0&&l.queimadura==1)System.out.println("O acido queimou Luke!");}}
    public static void jogarPocaoToxica(Cientista c,Luke l){int dano=reduzirDanoPorResistenciaLuke(l,c.forca);
        System.out.println("O Cientista arremessou uma Pocao Toxica!");
        l.vida-=dano;
        if(l.vida<0)l.vida=0;
        System.out.printf("Luke recebeu %d de dano.\n",dano);
        if(RAND.nextInt(100)<c.chanceEnvenenamento){int j=l.envenenamento;
        Efeitos.aplicarEnvenenamento(l);
        if(j==0&&l.envenenamento==1)System.out.println("Luke foi envenenado!");}}
    public static void arremessarObjeto(Cientista c,Luke l){int dano=reduzirDanoPorResistenciaLuke(l,c.forca);
        System.out.println("O Cientista arremessou um objeto contra Luke!");
        l.vida-=dano;
        if(l.vida<0)l.vida=0;
        System.out.printf("Luke recebeu %d de dano.\n",dano);}
    public static void corteLamina(Lucius x,Luke l){int dano=reduzirDanoPorResistenciaLuke(l,x.forca);
        System.out.println("Lucius usou Corte de Lamina!");
        l.vida-=dano;
        if(l.vida<0)l.vida=0;
        System.out.printf("Luke recebeu %d de dano.\n",dano);
        if(RAND.nextInt(100)<20){int j=l.sangramento;
        Efeitos.aplicarSangramento(l);
        if(j==0&&l.sangramento==1)System.out.println("Luke comecou a sangrar!");}}
    public static void disparoLaser(Lucius x,Luke l){int dano=reduzirDanoPorResistenciaLuke(l,x.forca);
        System.out.println("Lucius usou Disparo a Laser!");
        l.vida-=dano;
        if(l.vida<0)l.vida=0;
        System.out.printf("Luke recebeu %d de dano.\n",dano);
        if(RAND.nextInt(100)<25){int j=l.queimadura;
        Efeitos.aplicarQueimadura(l);
        if(j==0&&l.queimadura==1)System.out.println("Luke sofreu uma queimadura!");}}
    public static void socoPesado(Lucius x,Luke l){int dano=x.forca;
        int crit=0;
        if(RAND.nextInt(100)<30){dano=dano*140/100;crit=1;}dano=reduzirDanoPorResistenciaLuke(l,dano);
        System.out.println("Lucius usou Soco Pesado!");
        l.vida-=dano;
        if(l.vida<0)l.vida=0;
        if(crit==1)System.out.print("Acerto critico! ");
        System.out.printf("Luke recebeu %d de dano.\n",dano);}
    public static void socoLeve(Lucius x,Luke l){int dano=reduzirDanoPorResistenciaLuke(l,x.forca);
        System.out.println("Lucius usou Soco Leve!");
        l.vida-=dano;
        if(l.vida<0)l.vida=0;
        System.out.printf("Luke recebeu %d de dano.\n",dano);}
}
