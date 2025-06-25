#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "Filme.hpp"
#include "Cinema.h"
#include "FiltroCinemas.hpp"
#include "ClasseFiltroFilmes.hpp"
#include "TodosCinemas.h"
#include "TodosFilmes.h"

using namespace std;

class Filtro {
public:
    vector<Cinema> listaDeCinemas;
    vector<Filme> listaDeFilmes;
    FiltroCinemas filtroCinema;
    FiltroFilmes filtroFilme;

    // Construtor recebe listas completas de filmes e cinemas
    Filtro(const TodosFilmes& todosFilmes, const TodosCinemas& todosCinemas) {
        listaDeFilmes = todosFilmes.filmes;
        listaDeCinemas = todosCinemas.cinemas;
    }

    // Aplica filtros aos vetores passados por referência
    void filtrarFilmeCinema(const string& parse, vector<Filme>& filmes, vector<Cinema>& cinemas) {
        stringstream ssparse(parse);
        string prefixo;
        getline(ssparse, prefixo, '-');

        string filtros;
        getline(ssparse, filtros);
        stringstream filtroComp(filtros);
        string blocoAnd;

        while (getline(filtroComp, blocoAnd, '&')) {
            // remove espaços em excesso
            blocoAnd.erase(0, blocoAnd.find_first_not_of(" \t"));
            blocoAnd.erase(blocoAnd.find_last_not_of(" \t") + 1);

            if (blocoAnd.empty()) continue;

            size_t abre = blocoAnd.find("(#");
            size_t igual = blocoAnd.find('=');
            size_t fecha = blocoAnd.find(')', igual);

            if (abre == string::npos || igual == string::npos || fecha == string::npos) {
                cout << "Filtro inválido: " << blocoAnd << endl;
                continue;
            }

            string tipo = blocoAnd.substr(abre + 2, igual - (abre + 2));
            string valores = blocoAnd.substr(igual + 1, fecha - (igual + 1));
            stringstream ssvalores(valores);

            if (prefixo == "f") {  // filtro para filmes
                if (tipo == "a") { // ano
                    string val;
                    int a_min, a_max;
                    getline(ssvalores, val, ',');
                    a_min = stoi(val);
                    if (getline(ssvalores, val, ',')) a_max = stoi(val);
                    else a_max = a_min;
                    filtroFilme.filtroAno(filmes, a_min, a_max);
                }
                else if (tipo == "t") { // tipo
                    string val;
                    vector<string> tipos;
                    while (getline(ssvalores, val, '|')) tipos.push_back(val);
                    filtroFilme.filtroTipo(filmes, tipos);
                }
                else if (tipo == "g") { // gênero
                    string val;
                    vector<string> generos;
                    while (getline(ssvalores, val, '|')) generos.push_back(val);
                    filtroFilme.filtroGenero(filmes, generos);
                }
                else if (tipo == "d") { // duração
                    string val;
                    int d_min, d_max;
                    getline(ssvalores, val, ',');
                    d_min = stoi(val);
                    if (getline(ssvalores, val, ',')) d_max = stoi(val);
                    else d_max = d_min;
                    filtroFilme.filtroDuracao(filmes, d_min, d_max);
                }
            }
            else if (prefixo == "c") {  // filtro para cinemas
                if (tipo == "a") { // ano filme
                    string val;
                    int a_min, a_max;
                    getline(ssvalores, val, ',');
                    a_min = stoi(val);
                    if (getline(ssvalores, val, ',')) a_max = stoi(val);
                    else a_max = a_min;
                    filtroCinema.filtroCinemasPorAnoFilme(cinemas, a_min, a_max);
                }
                else if (tipo == "t") { // tipo filme
                    string val;
                    vector<string> tipos;
                    while (getline(ssvalores, val, '|')) tipos.push_back(val);
                    filtroCinema.filtroCinemasPorTipoFilme(cinemas, tipos);
                    // for (const Cinema &cinema : cinemas) cout<<"----->>testeTipo"<<cinema.nomeCinema<<endl;
                }
                else if (tipo == "g") { // gênero filme
                    // cout<<"->>teste"<<endl;
                    string val;
                    vector<string> generos;
                    while (getline(ssvalores, val, '|')) generos.push_back(val);
                   
                    filtroCinema.filtroCinemasPorGeneroFilme(cinemas, generos);
                }
                else if (tipo == "d") { // duração filme
                    string val;
                    int d_min, d_max;
                    getline(ssvalores, val, ',');
                    d_min = stoi(val);
                    if (getline(ssvalores, val, ',')) d_max = stoi(val);
                    else d_max = d_min;
                    filtroCinema.filtroCinemasPorDuracaoFilme(cinemas, d_min, d_max);
                }
                else if (tipo == "r") { // raio localização
                    string val;
                    int x, y;
                    double raio;
                    getline(ssvalores, val, ',');
                    y = stoi(val);
                    getline(ssvalores, val, ',');
                    x = stoi(val);
                    getline(ssvalores, val);
                    raio = stod(val);
                    filtroCinema.filtroCinemasPorLocalizacao(cinemas, x, y, raio);
                }
                else if (tipo == "v") { // valor ingresso
                    string val;
                    double precoMax;
                    getline(ssvalores, val);
                    precoMax = stod(val);
                    filtroCinema.filtroCinemasPorPreco(cinemas, precoMax);
                }
            }
        }
    }
};
