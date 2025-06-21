#pragma once
#include "Filme.hpp"
#include <iostream>
using namespace std;

class FiltroFilmes {

    void filtroGenero(vector<Filme> &filmes, vector<string> &generosBuscados) {
        vector<Filme> filtrados;
        for(const Filme& f : filmes) {
            if(f.contemAlgumGenero(generosBuscados)) {
                filtrados.push_back(f);
            }
        }
        filmes = filtrados;
    }

    void filtroDuracao(vector<Filme> &filmes, int minDuracao, int maxDuracao) {
        vector<Filme> filtrados;
        for(const Filme& f : filmes) {
            if(f.estaNoIntervaloDeDuracao(minDuracao, maxDuracao)) {
                filtrados.push_back(f);
            }
        }
        filmes = filtrados;
    }

    void filtroTipo(vector<Filme> &filmes, vector<string> &tiposBuscados) {
        vector<Filme> filtrados;
        for(const Filme& f : filmes) {
            if(f.contemTipo(tiposBuscados)) {
                filtrados.push_back(f);
            }
        }
        filmes = filtrados;
    }

    void filtroAno(vector<Filme> &filmes, int anoMin, int anoMax) {
        vector<Filme> filtrados;
        for(const Filme& f : filmes) {
            if(f.estaNoIntervaloDeAnos(anoMin, anoMax)) {
                filtrados.push_back(f);
            }
        }
        filmes = filtrados;
    }
};