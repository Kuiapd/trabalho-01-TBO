#pragma once
#include "Filme.hpp"
#include "Cinema.h"
#include <iostream>
using namespace std;

class FiltroCinemas
{
public:
    void filtroCinemaPorTipoFilme(vector<Cinema> &cinemas, const vector<string> &tiposDesejados)
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

    void filtroCinemaPorGeneroFilme(vector<Cinema> &cinemas, const vector<string> &generosBuscados)
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
};
