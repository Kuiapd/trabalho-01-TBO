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

    Filtro(const TodosFilmes& todosFilmes, const TodosCinemas& todosCinemas) {
        listaDeFilmes = todosFilmes.filmes;
        listaDeCinemas = todosCinemas.cinemas;
    }

    void filtrarFilmeCinema(const string& parse, vector<Filme>& filmes, vector<Cinema>& cinemas) {
        stringstream ssparse(parse);
        string prefixo;
        getline(ssparse, prefixo, '-');

        string filtros;
        getline(ssparse, filtros);
        stringstream filtroComp(filtros);
        string blocoAnd;

        bool usaAno = false, usaDuracao = false, usaGenero = false, usaTipo = false;
        int anoMin, anoMax;
        int durMin, durMax;
        vector<string> generosBuscados, tiposBuscados;

        bool usaPreco = false, usaLocalizacao = false;
        int x = 0, y = 0;
        double precoMax = 0.0, raio = 0.0;

        while (getline(filtroComp, blocoAnd, '&')) {
            blocoAnd.erase(0, blocoAnd.find_first_not_of(" \t"));
            blocoAnd.erase(blocoAnd.find_last_not_of(" \t") + 1);
            if (blocoAnd.empty()) continue;

            size_t abre = blocoAnd.find("(#");
            size_t igual = blocoAnd.find('=');
            size_t fecha = blocoAnd.find(')', igual);
            if (abre == string::npos || igual == string::npos || fecha == string::npos) continue;

            string tipo = blocoAnd.substr(abre + 2, igual - (abre + 2));
            string valores = blocoAnd.substr(igual + 1, fecha - (igual + 1));
            stringstream ssvalores(valores);
            string val;

            if (tipo == "a") {
                usaAno = true;
                getline(ssvalores, val, ',');
                anoMin = stoi(val);
                if (getline(ssvalores, val, ',')) anoMax = stoi(val);
                else anoMax = anoMin;
            }
            else if (tipo == "d") {
                usaDuracao = true;
                getline(ssvalores, val, ',');
                durMin = stoi(val);
                if (getline(ssvalores, val, ',')) durMax = stoi(val);
                else durMax = durMin;
            }
            else if (tipo == "g") {
                usaGenero = true;
                while (getline(ssvalores, val, '|')) generosBuscados.push_back(val);
            }
            else if (tipo == "t") {
                usaTipo = true;
                while (getline(ssvalores, val, '|')) tiposBuscados.push_back(val);
            }
            else if (tipo == "v") {
                usaPreco = true;
                getline(ssvalores, val);
                precoMax = stod(val);
            }
            else if (tipo == "r") {
                usaLocalizacao = true;
                getline(ssvalores, val, ',');
                y = stoi(val);
                getline(ssvalores, val, ',');
                x = stoi(val);
                getline(ssvalores, val);
                raio = stod(val);
            }
        }

        if (prefixo == "f") {
            filtroFilme.filtroFilmesComTodosOsFiltros(
                filmes,
                usaAno, anoMin, anoMax,
                usaDuracao, durMin, durMax,
                usaGenero, generosBuscados,
                usaTipo, tiposBuscados
            );
        }
        else if (prefixo == "c") {
            if (usaPreco) {
                filtroCinema.filtroCinemasPorPreco(cinemas, precoMax);
            }
            if (usaLocalizacao) {
                filtroCinema.filtroCinemasPorLocalizacao(cinemas, x, y, raio);
            }

            filtroCinema.filtrarCinemasComFilmeQueAtendeTodosOsFiltros(
                cinemas,
                usaAno, anoMin, anoMax,
                usaDuracao, durMin, durMax,
                usaGenero, generosBuscados,
                usaTipo, tiposBuscados
            );
        }
    }


};
