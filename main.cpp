//g++ -Wall -Wextra main.cpp Filtro.h Filme.hpp Cinema.h TodosFilmes.h TodosCinemas.h -o main.exe
#include <iostream>
#include <string.h>
#include <windows.h>

#include "Filme.hpp"
#include "Cinema.h"
#include "Filtro.h"
#include "TodosFilmes.h"
#include "TodosCinemas.h"
#include "FiltroCinemas.hpp"
#include "ClasseFiltroFilmes.hpp"

using namespace std;
// versao legal 
int main(){
    SetConsoleOutputCP(CP_UTF8);
    cout<<"ini_main\n";
      TodosFilmes todosFilmes;
    todosFilmes.CarregaListaFilmes("filmes.txt");
    cout << "Filmes carregados: " << todosFilmes.filmes.size() << endl;

    TodosCinemas todosCinemas;
    todosCinemas.criarListaDeCinemasPorArquivo("cinemas.txt", todosFilmes);
    cout << "Cinemas carregados: " << todosCinemas.cinemas.size() << endl;
    
    
    Filtro filtro(todosFilmes, todosCinemas);
    vector<Filme> filmesFiltrados = filtro.listaDeFilmes;
    vector<Cinema> cinemasFiltrados = filtro.listaDeCinemas;

    string filtroString = "c-(#v=10)&(#d=20,80)&(#t=short|tvEpisode)&(#g=Comedy|Drama|Romance)";
    string filtroString1 = "f-(#a=2017)&(#t=short|tvEpisode)&(#g=Comedy|Drama|Romance)";

    filtro.filtrarFilmeCinema(filtroString1, filmesFiltrados, cinemasFiltrados);
    
    cout << "\nFilmes filtrados (" << filmesFiltrados.size() << "):\n";
    for (const Filme& f : filmesFiltrados) {
        f.imprime();
    }
    
    filtro.filtrarFilmeCinema(filtroString, filmesFiltrados, cinemasFiltrados);
    cout << "\nCinemas filtrados (" << cinemasFiltrados.size() << "):\n";
    for (const Cinema& c : cinemasFiltrados) {
        cout << "Cinema: " << c.nomeCinema << ", Preço ingresso: " << c.precoIngresso << endl;
        cout << "Filmes em exibição:\n";
        for (const Filme& f : c.filmesEmExibicao) {
            f.imprime();
        }
        cout << "----------------------\n";
    }
    
    return 0;
}
