#pragma once
#include "Filme.hpp"
#include "Cinema.h"
#include <iostream>
#include <cmath>

using namespace std;

class FiltroCinemas
{
public:
    void filtroCinemasPorTipoFilme(vector<Cinema> &cinemas, const vector<string> &tiposDesejados)
    {
        vector<Cinema> filtrados;

        for (const Cinema &cinema : cinemas)
        {
            bool contemTipo = false;
            for (const Filme &f : cinema.filmesEmExibicao)
            {
                for (const string &tipoDesejado : tiposDesejados)
                {
                    if (f.titleType == tipoDesejado)
                    {
                        contemTipo = true;
                        break;
                    }
                }
                if (contemTipo)
                    break;
            }

            if (contemTipo)
            {
                filtrados.push_back(cinema);
            }
        }

        cinemas = filtrados;
    }

    void filtroCinemasPorGeneroFilme(vector<Cinema> &cinemas, const vector<string> &generosBuscados)
    {
        vector<Cinema> filtrados;

        for (const Cinema &cinema : cinemas)
        {
            bool contemGenero = false;

            for (const Filme &f : cinema.filmesEmExibicao)
            {
                // Percorre os gêneros do filme
                for (const string &generoFilme : f.genres)
                {
                    for (const string &generoBuscado : generosBuscados)
                    {
                        if (generoFilme == generoBuscado)
                        {
                            contemGenero = true;
                            break;
                        }
                    }
                    if (contemGenero)
                        break;
                }

                if (contemGenero)
                    break;
            }

            if (contemGenero)
            {
                filtrados.push_back(cinema);
            }
        }

        cinemas = filtrados;
    }

    void filtroCinemasPorDuracaoFilme(vector<Cinema> &cinemas, int minDuracao, int maxDuracao)
    {
        vector<Cinema> filtrados;

        for (const Cinema &cinema : cinemas)
        {
            bool contemDuracaoValida = false;

            for (const Filme &f : cinema.filmesEmExibicao)
            {
                if (f.runtimeMinutes >= minDuracao && f.runtimeMinutes <= maxDuracao)
                {
                    contemDuracaoValida = true;
                    break;
                }
            }

            if (contemDuracaoValida)
            {
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
    
    void filtroCinemasPorAnoFilme(vector<Cinema>& cinemas, int anoMin, int anoMax) {
        vector<Cinema> filtrados;

        for (const Cinema& cinema : cinemas) {
            bool contemAnoValido = false;

            for (const Filme& f : cinema.filmesEmExibicao) {
                if (f.startYear >= anoMin && f.startYear <= anoMax) {
                    contemAnoValido = true;
                    break;
                }
            }

            if (contemAnoValido) {
                filtrados.push_back(cinema);
            }
        }

        cinemas = filtrados;
    }
};
