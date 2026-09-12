#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#include "tela.h"
#include "Menu/menu.h"


int main() {

    SetConsoleOutputCP(CP_UTF8);

    srand(time(NULL));

    mostrarTexto(
        "Por milhares de anos, a humanidade caminhou sobre esta terra. ",
        "Impérios nasceram, guerras foram travadas, ",
        "e o mundo continuou a mudar. "
    );

    mostrarTexto(
        "O tempo trouxe conhecimento. ",
        "O conhecimento trouxe progresso. ",
        "E o progresso transformou o mundo. "
    );

    mostrarTexto(
        "Mas toda mudança deixa vestígios. ",
        "Alguns desaparecem com o tempo. ",
        "Outros permanecem. "
    );

    mostrarTexto(
        "Entre aqueles que caminharam por eras, ",
        "poucos ainda carregam consigo ",
        "as memórias de um mundo que já não existe."
    );

    mostrarTexto(
        "Luke Carmesin é um deles.",
        "Um vampiro que observa a humanidade ",
        "há aproximadamente 2.500 anos."
    );

    mostrarTexto(
        "Ele viu civilizações surgirem e desaparecerem. ",
        "Viu o homem alcançar grandes feitos ",
        "e cometer grandes erros."
    );

    mostrarTexto(
        "Agora, algo chama sua atenção.",
        "E, desta vez, Luke decide não permanecer ",
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