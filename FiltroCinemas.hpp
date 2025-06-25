#pragma once
#include "Filme.hpp"
#include "Cinema.h"
#include <iostream>
#include <cmath>

using namespace std;

class FiltroCinemas
{
public:
    void filtrarCinemasComFilmeQueAtendeTodosOsFiltros(
    vector<Cinema>& cinemas,bool usaAno, int anoMin, int anoMax,
    bool usaDuracao, int durMin, int durMax,bool usaGenero, const vector<string>& generos,
    bool usaTipo, const vector<string>& tipos) 
    {
        vector<Cinema> filtrados;

        for (const Cinema& cinema : cinemas) {
            bool contemFilmeValido = false;

            for (const Filme& f : cinema.filmesEmExibicao) {
                bool passa = true;

                if (usaAno && (f.startYear < anoMin || f.startYear > anoMax)) {
                    passa = false;
                }

                if (usaDuracao && (f.runtimeMinutes < durMin || f.runtimeMinutes > durMax)) {
                    passa = false;
                }

                if (usaGenero) {
                    bool encontrouGenero = false;
                    for (const string& g : generos) {
                        for (const string& generoFilme : f.genres) {
                            if (generoFilme == g) {
                                encontrouGenero = true;
                                break;
                            }
                        }
                        if (encontrouGenero) break;
                    }
                    if (!encontrouGenero) {
                        passa = false;
                    }
                }

                if (usaTipo) {
                    bool tipoEncontrado = false;
                    for (const string& tipo : tipos) {
                        if (tipo == f.titleType) {
                            tipoEncontrado = true;
                            break;
                        }
                    }
                    if (!tipoEncontrado) {
                        passa = false;
                    }
                }

                if (passa) {
                    contemFilmeValido = true;
                    break;
                }
            }

            if (contemFilmeValido) {
                filtrados.push_back(cinema);
            }
        }

        cinemas = filtrados;
    }




    void filtroCinemasPorLocalizacao(vector<Cinema> &cinemas, int usuarioX, int usuarioY, float raio)
    {
        vector<Cinema> filtrados;

        for (const Cinema &cinema : cinemas)
        {
            float dx = cinema.coordenadaX - usuarioX;
            float dy = cinema.coordenadaY - usuarioY;
            float distancia = sqrt(dx * dx + dy * dy);

            if (distancia <= raio)
            {
                filtrados.push_back(cinema);
            }
        }

        cinemas = filtrados;
    }

    void filtroCinemasPorPreco(vector<Cinema>& cinemas, double precoMaximo) {
        vector<Cinema> filtrados;

        for (const Cinema& cinema : cinemas) {
            if (cinema.precoIngresso <= precoMaximo) {
                filtrados.push_back(cinema);
            }
        }

        cinemas = filtrados;
    }
};

