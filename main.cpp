//g++ -Wall -Wextra main.cpp Filtro.h Filme.hpp Cinema.h TodosFilmes.h TodosCinemas.h -o main.exe
#include <iostream>
#include <string.h>
#include <windows.h>
#include <chrono>

#include "Filme.hpp"
#include "Cinema.h"
#include "Filtro.h"
#include "TodosFilmes.h"
#include "TodosCinemas.h"
#include "FiltroCinemas.hpp"
#include "ClasseFiltroFilmes.hpp"

using namespace std;
using namespace chrono;
// versao legal 
int main(){
    SetConsoleOutputCP(CP_UTF8);
    cout<<"ini_main\n";
    
    auto inicio = high_resolution_clock::now();  // Marca o início 
    
   
   TodosFilmes todosFilmes;
   todosFilmes.CarregaListaFilmes("filmes.txt");
   cout << "Filmes carregados: " << todosFilmes.filmes.size() << endl;

   TodosCinemas todosCinemas;
   todosCinemas.criarListaDeCinemasPorArquivo("cinemas.txt", todosFilmes);
   cout << "Cinemas carregados: " << todosCinemas.cinemas.size() << endl;

    
    auto fim = high_resolution_clock::now();  // Marca o fim
    auto duracao = duration_cast<milliseconds>(fim - inicio);
    cout << "Tempo de execução para carregar Dados: " << duracao.count() << " ms" << endl;
    system("pause");
    
    Filtro filtro(todosFilmes, todosCinemas);
    vector<Filme> filmesFiltrados = filtro.listaDeFilmes;
    vector<Cinema> cinemasFiltrados = filtro.listaDeCinemas;

    string filtroString = "c-(#v=10)&(#d=50,80)&(#t=tvEpisode)&(#g=Comedy|Drama|Romance)";
    string filtroString1 = "f-(#a=2017)&(#t=short|tvEpisode)&(#g=Comedy|Drama|Romance)";
    
    auto inicio1 = high_resolution_clock::now();  // Marca o início
    filtro.filtrarFilmeCinema(filtroString1, filmesFiltrados, cinemasFiltrados);
    auto fim1 = high_resolution_clock::now();  // Marca o fim
    auto duracao1 = duration_cast<milliseconds>(fim1 - inicio1);
    cout << "Tempo de execução para Filtrar Filmes: " << duracao1.count() << " ms" << endl;
    cout << "\nFilmes filtrados (" << filmesFiltrados.size() << "):\n";
    system("pause");
    
    for (const Filme& f : filmesFiltrados) {
        f.imprime();
    }

    auto inicio2 = high_resolution_clock::now();  // Marca o início    
    filtro.filtrarFilmeCinema(filtroString, filmesFiltrados, cinemasFiltrados);
    auto fim2 = high_resolution_clock::now();  // Marca o fim
    auto duracao2 = duration_cast<milliseconds>(fim2 - inicio2);
    cout << "Tempo de execução para Filtrar Cinemas: " << duracao.count() << " ms" << endl;
    cout << "\nCinemas filtrados (" << cinemasFiltrados.size() << "):\n";
    system("pause");

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
