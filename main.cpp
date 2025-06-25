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

    string filtroString = "c-(#v=10)&(#t=short|tvEpisode)&(#g=Comedy|Drama|Romance)";

    filtro.filtrarFilmeCinema(filtroString, filmesFiltrados, cinemasFiltrados);

    // cout << "\nFilmes filtrados (" << filmesFiltrados.size() << "):\n";
    // for (const Filme& f : filmesFiltrados) {
    //     f.imprime();
    // }

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
    
        
        // for (const Filme &filme : todosFilmes.filmes)
        //     cout<<"\t"<<filme.titleType<<endl;
        
        // for (const Cinema &cinema : todosCinemas.cinemas){
        //     cout<<cinema.nomeCinema<<endl;
        //     for (const Filme &filme : cinema.filmesEmExibicao)
        //         cout<<"\t"<<filme.titleType<<endl;
        // }
        
        /*TodosFilmes todosFilmes;
        todosFilmes.CarregaListaFilmes("filmes.txt");
        TodosCinemas todosCinemas;
        todosCinemas.criarListaDeCinemasPorArquivo("cinemas.txt", todosFilmes);
        Filtro filtro(todosFilmes,todosCinemas);
        string parse = "c-(#g=Action|Drama)&(#v=25)&(#r=10,20,5)";
    
        filtro.filtrarFilmeCinema(parse, filtro.listaDeFilme, filtro.listaDeCinema);
    
        cout << "\n>>> Resultado do Filtro:\n";
        for (const Cinema& c : todosCinemas) {
            cout << "- " << c.nomeCinema << " [R$" << c.precoIngresso << "]\n";
            for (const Filme& f : c.filmesEmExibicao) {
                cout << "   > " << f.primaryTitle << " (" << f.startYear << ")\n";
            }
        }
        
        
        FiltroFilmes FF;
        FiltroCinemas FC;
        vector<string> generos = {"Action","Short"};
        FF.filtroGenero(todosFilmes.filmes, generos);
        for(const Filme& f : todosFilmes.filmes){
            f.imprime();
        }*/