#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "tela.h"
#include "menu.h"
#include "informacoes.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);    // Configura a saída do console para UTF-8

    mostrarTexto( //Caixa 1
        "Por milhares de anos, a humanidade caminhou sobre esta terra. ",
        "Impérios nasceram, guerras foram travadas, ",
        "e o mundo continuou a mudar. "
    );

    mostrarTexto( //Caixa 2
        "O tempo trouxe conhecimento. ",
        "O conhecimento trouxe progresso. ", 
        "E o progresso transformou o mundo. "
    );

    mostrarTexto( //Caixa 3
        "Mas toda mudança deixa vestígios. ",  
        "Alguns desaparecem com o tempo. ",  
        "Outros permanecem. "
    );

    mostrarTexto( //Caixa 4
        "Entre aqueles que caminharam por eras, ", 
        "poucos ainda carregam consigo  ",
        "as memórias de um mundo que já não existe."
    );

    mostrarTexto( //Caixa 5
        "Luke Carmesin é um deles.",
        "Um vampiro que observa a humanidade  ",
        "há aproximadamente 2.500 anos."
    );

    mostrarTexto ( //Caixa 6
        "Ele viu civilizações surgirem e desaparecerem.  ",
        "Viu o homem alcançar grandes feitos ",
        "e cometer grandes erros."
    );

    mostrarTexto( //Caixa 7
        "Agora, algo chama sua atenção.",
        "E, desta vez, Luke decide não permanecer  ",
        "apenas como um observador."
    );
    
    mostrarTexto(
        "",
        "Algumas marcas não podem ser ignoradas.",
        ""
    );

     mostrarMenu();

    




    return 0;
}

