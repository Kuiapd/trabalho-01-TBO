//g++ -Wall -Wextra main.cpp Filtro.h Filme.h Cinema.h TodosFilmes.h TodosCinemas.h -o main.exe
#include <iostream>
#include <string.h>
#include <windows.h>
#include "Filme.hpp"
#include "Cinema.h"
#include "TodosFilmes.h"
#include "TodosCinemas.h"
#include "FiltroCinemas.hpp"
#include "ClasseFiltroFilmes.hpp"

using namespace std;

int main(){
    SetConsoleOutputCP(CP_UTF8);
    TodosFilmes todosFilmes;
    todosFilmes.CarregaListaFilmes("filmes.txt");
    TodosCinemas todosCinemas;
    todosCinemas.criarListaDeCinemasPorArquivo("cinemas.txt");
    FiltroFilmes FF;
    FiltroCinemas FC;
    vector<string> generos = {"Action","Short"};
    FF.filtroGenero(todosFilmes.filmes, generos);
    for(const Filme& f : todosFilmes.filmes){
        f.imprime();
    }

    return 0;
}