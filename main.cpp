//g++ -Wall -Wextra main.cpp Filtro.h Filme.h Cinema.h TodosFilmes.h TodosCinemas.h -o main.exe
#include <iostream>
#include <string.h>
#include <windows.h>
#include "Filtro.h"
#include "Filme.h"
#include "Cinema.h"
#include "TodosFilmes.h"
#include "TodosCinemas.h"

using namespace std;

int main(){
    SetConsoleOutputCP(CP_UTF8);
    TodosFilmes todosFilmes;
    todosFilmes.CarregaListaFilmes("filmes.txt");
    todosFilmes.ImprimeFilmeNaPosicao(1);
    return 0;
}