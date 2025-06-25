#pragma once
#include "Filme.hpp"
#include <iostream>
using namespace std;

class FiltroFilmes {
public:
    void filtroFilmesComTodosOsFiltros(
        vector<Filme>& filmes,
        bool usaAno, int anoMin, int anoMax,
        bool usaDuracao, int durMin, int durMax,
        bool usaGenero, const vector<string>& generos,
        bool usaTipo, const vector<string>& tipos
    ) {
        vector<Filme> filtrados;

        for (const Filme& f : filmes) {
            if (usaAno && (f.startYear < anoMin || f.startYear > anoMax))
                continue;

            if (usaDuracao && (f.runtimeMinutes < durMin || f.runtimeMinutes > durMax))
                continue;

            if (usaGenero) {
                bool achouGenero = false;
                for (const string& g : generos) {
                    for (const string& fg : f.genres) {
                        if (fg == g) {
                            achouGenero = true;
                            break;
                        }
                    }
                    if (achouGenero) break;
                }
                if (!achouGenero) continue;
            }

            if (usaTipo) {
                bool achouTipo = false;
                for (const string& t : tipos) {
                    if (f.titleType == t) {
                        achouTipo = true;
                        break;
                    }
                }
                if (!achouTipo) continue;
            }

            filtrados.push_back(f);
        }

        filmes = filtrados;
    }

};
