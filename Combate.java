import java.util.Random;
import personagens.*;
import mecanicas.ataques.Ataques;
import mecanicas.efeitos.Efeitos;
import mecanicas.evolucao.Evolucao;
import mecanicas.itens.Itens;

public class Combate {
    private static final Random RAND = new Random();

    public static void mostrarEfeitosLuke(Luke luke) {
        int possuiEfeito=0; System.out.print("Efeitos: ");
        if(luke.sangramento==1){System.out.printf("Sangramento (%d/7 turnos) ",luke.turnosSangramento);possuiEfeito=1;}
        if(luke.queimadura==1){System.out.printf("Queimadura (%d/5 turnos) ",luke.turnosQueimadura);possuiEfeito=1;}
        if(luke.envenenamento==1){System.out.printf("Envenenamento (%d%%) ",luke.intensidadeVeneno);possuiEfeito=1;}
        if(possuiEfeito==0)System.out.print("Nenhum"); System.out.println();
    }
    public static void mostrarEfeitosInimigo(int s,int q,int e){int p=0;
        System.out.print("Efeitos: ");
        if(s==1){System.out.print("Sangramento ");p=1;}if(q==1){System.out.print("Queimadura ");p=1;}if(e==1){System.out.print("Envenenamento ");p=1;}if(p==0)System.out.print("Nenhum");
        System.out.println();}
    public static void mostrarStatusCombate(Luke l,String n,int v,int vm,int s,int q,int e){System.out.println("\n====================================");
        System.out.println("LUKE");
        System.out.printf("Vida: %d/%d\n",l.vida,l.vidaMaxima);mostrarEfeitosLuke(l);
        System.out.println("\n"+n);
        System.out.printf("Vida: %d/%d\n",v,vm);mostrarEfeitosInimigo(s,q,e);
        System.out.println("====================================");}
    static int escolherAcao(){System.out.println("\nACOES\n1. Atacar\n2. Esquivar\n3. Bolsa");
        System.out.print("\nEscolha: ");
        return Tela.lerInteiro();}
    static int escolherAtaqueLuke(Luke l){System.out.println("\nATAQUES\n1. Corte de Espada\n2. Soco Direto");
        if(l.nivel>=3)System.out.println("3. Corte Carmesim");
        if(l.nivel>=5)System.out.println("4. Julgamento");
        System.out.print("\nEscolha: ");
        return Tela.lerInteiro();}
    static int calcularDanoNoInimigo(int dano,int res,int pen){int re=res-pen;
        if(re<0)re=0;dano=dano*(100-re)/100;
        return Math.max(dano,1);}
    static int[] executarAtaqueLuke(Luke l){int op=escolherAtaqueLuke(l),pen=0,d=0;
        switch(op){case 1:d=Ataques.corteEspada(l);
        break;case 2:d=Ataques.socoDireto(l);
        break;case 3:if(l.nivel>=3)d=Ataques.corteCarmesim(l);
        break;case 4:if(l.nivel>=5){pen=Evolucao.calcularPenetracao(l);d=Ataques.julgamento(l);}break;}return new int[]{d,pen};}
    static int abrirBolsa(Luke l){System.out.printf("\nBOLSA\n1. Frasco de Sangue: %d\n2. Pocao de Cura: %d\n3. Antidoto: %d\n4. Ataduras: %d\n5. Voltar\n",l.frascoSangue,l.pocaoCura,l.antidoto,l.ataduras);
        System.out.print("\nEscolha: ");
        int op=Tela.lerInteiro();
        switch(op){case 1:if(l.frascoSangue>0){Itens.usarFrascoSangue(l);
        System.out.println("\nLuke usou um Frasco de Sangue.");
        return 1;}System.out.println("\nVoce nao possui Frasco de Sangue.");
        return 0;case 2:if(l.pocaoCura>0){Itens.usarPocaoCura(l);
        System.out.println("\nLuke usou uma Pocao de Cura.");
        return 1;}System.out.println("\nVoce nao possui Pocao de Cura.");
        return 0;case 3:if(l.antidoto>0&&l.envenenamento==1){Itens.usarAntidoto(l);
        System.out.println("\nLuke usou um Antidoto.");
        return 1;}System.out.println("\nNao foi possivel usar o Antidoto.");
        return 0;case 4:if(l.ataduras>0&&(l.sangramento==1||l.queimadura==1)){Itens.usarAtadura(l);
        System.out.println("\nLuke usou uma Atadura.");
        return 1;}System.out.println("\nNao foi possivel usar a Atadura.");
        return 0;case 5:return 0;default:System.out.println("\nOpcao invalida.");
        return 0;}}
    static boolean verificarEsquiva(Luke l,int ativa){int chance=ativa==1?Evolucao.calcularEvasaoAtiva(l):Evolucao.calcularEvasaoPassiva(l);
        return RAND.nextInt(100)<chance;}
    static boolean verificarEvasaoInimigo(int evasao){return RAND.nextInt(100)<evasao;}
    static void processarDropSeguranca(Luke l){int achou=0;
        System.out.println("\nVerificando itens do Seguranca...");
        if(RAND.nextInt(100)<30){l.ataduras++;
        System.out.println("Luke encontrou uma Atadura.");achou=1;}if(RAND.nextInt(100)<5){l.frascoSangue++;
        System.out.println("Luke encontrou um Frasco de Sangue.");achou=1;}if(achou==0)System.out.println("Nenhum item encontrado.");}
    static void processarDropCientista(Luke l){int achou=0;
        System.out.println("\nVerificando itens do Cientista...");
        if(RAND.nextInt(100)<10){l.frascoSangue++;
        System.out.println("Luke encontrou um Frasco de Sangue.");achou=1;}if(RAND.nextInt(100)<60){l.pocaoCura++;
        System.out.println("Luke encontrou uma Pocao de Cura.");achou=1;}if(RAND.nextInt(100)<60){l.antidoto++;
        System.out.println("Luke encontrou um Antidoto.");achou=1;}if(achou==0)System.out.println("Nenhum item encontrado.");}

    public static void combateMutante(Luke l,Mutante m){int esquivaAtiva;while(l.vida>0&&m.vida>0){Tela.limparTela();
        System.out.println("===== TURNO DE LUKE =====");mostrarStatusCombate(l,"MUTANTE",m.vida,m.vidaMaxima,m.sangramento,0,m.envenenamento);esquivaAtiva=0;
        int acao=escolherAcao();
        switch(acao){case 1->{int[]r=executarAtaqueLuke(l);
        int dano=r[0],pen=r[1];
        if(dano<=0){System.out.println("\nAtaque invalido.");
        Tela.esperarEnter();
        continue;}if(verificarEvasaoInimigo(m.evasao))System.out.println("\nO Mutante desviou do ataque.");else{dano=calcularDanoNoInimigo(dano,m.resistencia,pen);
        m.vida-=dano;
        if(m.vida<0)m.vida=0;
        System.out.printf("\nLuke causou %d de dano.\n",dano);}}
            case 2->{esquivaAtiva=1;
        System.out.println("\nLuke se prepara para esquivar.");}
            case 3->{if(abrirBolsa(l)==0){Tela.esperarEnter();
        continue;}}default->{System.out.println("\nOpcao invalida.");
        Tela.esperarEnter();
        continue;}}Tela.esperarEnter();
        if(m.vida<=0)break;
        Tela.limparTela();
        System.out.println("===== TURNO DO MUTANTE =====");mostrarStatusCombate(l,"MUTANTE",m.vida,m.vidaMaxima,m.sangramento,0,m.envenenamento);
        if(verificarEsquiva(l,esquivaAtiva))System.out.println("\nO Mutante atacou, mas Luke esquivou!");else{System.out.println();
        Ataques.ataqueFuria(m,l);}if(l.vida>0)Efeitos.processarEfeitos(l);
        Tela.esperarEnter();}Tela.limparTela();
        if(l.vida<=0){System.out.println("\nLuke foi derrotado.");
        Tela.esperarEnter();
        return;}System.out.println("\nMutante derrotado!");
        Evolucao.subirNivel(l);
        Tela.esperarEnter();}

    public static void combateSeguranca(Luke l,Seguranca s){int esquivaAtiva;while(l.vida>0&&s.vida>0){Tela.limparTela();
        System.out.println("===== TURNO DE LUKE =====");mostrarStatusCombate(l,"SEGURANCA",s.vida,s.vidaMaxima,0,0,0);esquivaAtiva=0;
        int acao=escolherAcao();
        switch(acao){case 1->{int[]r=executarAtaqueLuke(l);
        int dano=r[0],pen=r[1];
        if(dano<=0){System.out.println("\nAtaque invalido.");
        Tela.esperarEnter();
        continue;}if(verificarEvasaoInimigo(s.evasao))System.out.println("\nO Seguranca desviou do ataque.");else{dano=calcularDanoNoInimigo(dano,s.resistencia,pen);
        s.vida-=dano;
        if(s.vida<0)s.vida=0;
        System.out.printf("\nLuke causou %d de dano.\n",dano);}}
            case 2->{esquivaAtiva=1;
        System.out.println("\nLuke se prepara para esquivar.");}
            case 3->{if(abrirBolsa(l)==0){Tela.esperarEnter();
        continue;}}default->{System.out.println("\nOpcao invalida.");
        Tela.esperarEnter();
        continue;}}Tela.esperarEnter();
        if(s.vida<=0)break;
        Tela.limparTela();
        System.out.println("===== TURNO DO SEGURANCA =====");mostrarStatusCombate(l,"SEGURANCA",s.vida,s.vidaMaxima,0,0,0);
        if(verificarEsquiva(l,esquivaAtiva))System.out.println("\nO Seguranca atacou, mas Luke esquivou!");else{System.out.println();
        if(RAND.nextInt(2)==0)Ataques.tiroRifle(s,l);else Ataques.coronhada(s,l);}if(l.vida>0)Efeitos.processarEfeitos(l);
        Tela.esperarEnter();}Tela.limparTela();
        if(l.vida<=0){System.out.println("\nLuke foi derrotado.");
        Tela.esperarEnter();
        return;}System.out.println("\nSeguranca derrotado!");processarDropSeguranca(l);
        Evolucao.subirNivel(l);
        Tela.esperarEnter();}

    public static void combateCientista(Luke l,Cientista c){int esquivaAtiva;while(l.vida>0&&c.vida>0){Tela.limparTela();
        System.out.println("===== TURNO DE LUKE =====");mostrarStatusCombate(l,"CIENTISTA",c.vida,c.vidaMaxima,0,0,0);esquivaAtiva=0;
        int acao=escolherAcao();
        switch(acao){case 1->{int[]r=executarAtaqueLuke(l);
        int dano=r[0],pen=r[1];
        if(dano<=0){System.out.println("\nAtaque invalido.");
        Tela.esperarEnter();
        continue;}if(verificarEvasaoInimigo(c.evasao))System.out.println("\nO Cientista desviou do ataque.");else{dano=calcularDanoNoInimigo(dano,c.resistencia,pen);
        c.vida-=dano;
        if(c.vida<0)c.vida=0;
        System.out.printf("\nLuke causou %d de dano.\n",dano);}}
            case 2->{esquivaAtiva=1;
        System.out.println("\nLuke se prepara para esquivar.");}
            case 3->{if(abrirBolsa(l)==0){Tela.esperarEnter();
        continue;}}default->{System.out.println("\nOpcao invalida.");
        Tela.esperarEnter();
        continue;}}Tela.esperarEnter();
        if(c.vida<=0)break;
        Tela.limparTela();
        System.out.println("===== TURNO DO CIENTISTA =====");mostrarStatusCombate(l,"CIENTISTA",c.vida,c.vidaMaxima,0,0,0);
        if(verificarEsquiva(l,esquivaAtiva))System.out.println("\nO Cientista atacou, mas Luke esquivou!");else{System.out.println();
        switch(RAND.nextInt(3)){case 0->Ataques.jogarAcido(c,l);case 1->Ataques.jogarPocaoToxica(c,l);case 2->Ataques.arremessarObjeto(c,l);}}if(l.vida>0)Efeitos.processarEfeitos(l);
        Tela.esperarEnter();}Tela.limparTela();
        if(l.vida<=0){System.out.println("\nLuke foi derrotado.");
        Tela.esperarEnter();
        return;}System.out.println("\nCientista derrotado!");processarDropCientista(l);
        Evolucao.subirNivel(l);
        Tela.esperarEnter();}

    public static void combateLucius(Luke l,Lucius x){int esquivaAtiva;while(l.vida>0&&x.vida>0){Tela.limparTela();
        System.out.println("===== TURNO DE LUKE =====");mostrarStatusCombate(l,"LUCIUS VARN",x.vida,x.vidaMaxima,x.sangramento,0,0);esquivaAtiva=0;
        int acao=escolherAcao();
        switch(acao){case 1->{int[]r=executarAtaqueLuke(l);
        int dano=r[0],pen=r[1];
        if(dano<=0){System.out.println("\nAtaque invalido.");
        Tela.esperarEnter();
        continue;}if(verificarEvasaoInimigo(x.evasao))System.out.println("\nLucius desviou do ataque.");else{dano=calcularDanoNoInimigo(dano,x.resistencia,pen);
        x.vida-=dano;
        if(x.vida<0)x.vida=0;
        System.out.printf("\nLuke causou %d de dano.\n",dano);}}
            case 2->{esquivaAtiva=1;
        System.out.println("\nLuke se prepara para esquivar.");}
            case 3->{if(abrirBolsa(l)==0){Tela.esperarEnter();
        continue;}}default->{System.out.println("\nOpcao invalida.");
        Tela.esperarEnter();
        continue;}}Tela.esperarEnter();
        if(x.vida<=0)break;
        Tela.limparTela();
        System.out.println("===== TURNO DE LUCIUS =====");mostrarStatusCombate(l,"LUCIUS VARN",x.vida,x.vidaMaxima,x.sangramento,0,0);
        if(verificarEsquiva(l,esquivaAtiva))System.out.println("\nLucius atacou, mas Luke esquivou!");else{System.out.println();
        switch(RAND.nextInt(4)){case 0->Ataques.corteLamina(x,l);case 1->Ataques.disparoLaser(x,l);case 2->Ataques.socoPesado(x,l);case 3->Ataques.socoLeve(x,l);}}if(l.vida>0)Efeitos.processarEfeitos(l);
        Tela.esperarEnter();}Tela.limparTela();
        if(l.vida<=0){System.out.println("\nLuke foi derrotado por Lucius Varn.");
        Tela.esperarEnter();
        return;}System.out.println("\nLucius Varn foi derrotado!");
        System.out.println("Luke venceu a batalha final.");
        Tela.esperarEnter();}
}
