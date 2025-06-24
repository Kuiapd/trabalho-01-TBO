#pragma once
#include "Filme.hpp"
#include "Cinema.h"
#include <iostream>
using namespace std;

class FiltroCinemas {
public:
    void filtroPorTipoFilme(vector<Cinema>& cinemas, const vector<string>& tiposDesejados, const vector<Filme>& filmes) {
        vector<Cinema> filtrados;

        for (const Cinema& cinema : cinemas) {
            bool contemTipo = false;
            for (const string& tconstCinema : cinema.filmesEmExibicao) {
                for (const Filme& f : filmes) {
                    if (f.tconst == tconstCinema) {
                        for (const string& tipoDesejado : tiposDesejados) {
                            if (f.titleType == tipoDesejado) {
                                contemTipo = true;
                                break;
                            }
                        }
                    }
                    if (contemTipo)
                        break;
                }
                if (contemTipo) 
                    break;
            }
            if (contemTipo) {
                filtrados.push_back(cinema);
            }
        }

        cinemas = filtrados;
    }

    void filtroPorGeneroFilme(vector<Cinema>& cinemas,
                              const vector<string>& generosBuscados,
                               vector<Filme>& filmes) {
        vector<Cinema> filtrados;

        for (const Cinema& cinema : cinemas) {
            bool contemGenero = false;

            for (const string& tconstCinema : cinema.filmesEmExibicao) {
                for (Filme& f : filmes) {
                    if (f.tconst == tconstCinema) {
                        for (string& generoFilme : f.genres) {
                            for (const string& generoBuscado : generosBuscados) {
                                if (generoFilme == generoBuscado) {
                                    contemGenero = true;
                                    break;
                                }
                            }
                            if (contemGenero)
                                break;
                        }
                    }
                    if (contemGenero)
                        break;
                }
                if (contemGenero)
                    break;
            }

            if (contemGenero) {
                filtrados.push_back(cinema);
            }
        }

        cinemas = filtrados;
    }

    void filtroPorDuracaoFilme(vector<Cinema>& cinemas, int minDuracao, int maxDuracao, const vector<Filme>& filmes) {
        vector<Cinema> filtrados;

        for (const Cinema& cinema : cinemas) {
            bool contemFilmeValido = false;

            for (const string& tconstCinema : cinema.filmesEmExibicao) {
                for (const Filme& f : filmes) {
                    if (f.tconst == tconstCinema && f.runtimeMinutes >= minDuracao && f.runtimeMinutes <= maxDuracao) {
                        contemFilmeValido = true;
                        break;
                    }
                }
                if (contemFilmeValido)
                    break;
            }

            if (contemFilmeValido) {
                filtrados.push_back(cinema);
            }
        }

        cinemas = filtrados;
    }
};
