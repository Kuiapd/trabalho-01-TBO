#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
#include "Filme.hpp"
#include "Cinema.h"
using namespace std;

class Filtro
{
public:
    vector<Cinema> listaDeCinema;
    vector<Filme> listaDeFilme;

    void filtroGenero(vector<Filme> &filmes, vector<string> &generosBuscados)
    {

        for (const Filme &f : filmes)
        {
            if (f.contemAlgumGenero(generosBuscados))
            {
                listaDeFilme.push_back(f);
            }
        }
    }

    void filtroDuracao(vector<Filme> &filmes, int minDuracao, int maxDuracao)
    {
        for (const Filme &f : filmes)
        {
            if (f.estaNoIntervaloDeDuracao(minDuracao, maxDuracao))
            {
                listaDeFilme.push_back(f);
            }
        }
    }

    void filtroTipo(vector<Filme> &filmes, vector<string> &tiposBuscados)
    {
        for (const Filme &f : filmes)
        {
            if (f.contemTipo(tiposBuscados))
            {
                listaDeFilme.push_back(f);
            }
        }
    }

    void filtroAno(vector<Filme> &filmes, int anoMin, int anoMax)
    {
        for (const Filme &f : filmes)
        {
            if (f.estaNoIntervaloDeAnos(anoMin, anoMax))
            {
                listaDeFilme.push_back(f);
            }
        }
    }

    void filtrarFilmeCinema(const string parse, vector<Filme> &filmes)
    {
        bool ptf = false; // Primeiro tipo de Filtro já foi utilizado
        stringstream ssparse(parse);
        // Identificador prefixo
        string prefixo;
        getline(ssparse, prefixo, '-');

        // Resto do parse
        string filtros;
        getline(ssparse, filtros);
        stringstream filtroComp(filtros);
        string blocoAnd;
        int primeirof = 0;

        // Quebra cada filtro por &
        while (getline(filtroComp, blocoAnd, '&'))
        {
            // Remover espaços
            blocoAnd.erase(0, blocoAnd.find_first_not_of(" \t"));
            blocoAnd.erase(blocoAnd.find_last_not_of(" \t") + 1);

            if (blocoAnd.empty())
                continue;

            // Extrair tipo e valores
            size_t abre = blocoAnd.find("(#");
            size_t igual = blocoAnd.find('=');
            size_t fecha = blocoAnd.find(')', igual);

            if (abre == npos || igual == npos || fecha == npos)
            {
                cout << "Filtro inválido: " << blocoAnd << endl;
                continue;
            }

            string tipo = blocoAnd.substr(abre + 2, igual - (abre + 2));
            string valores = blocoAnd.substr(igual + 1, fecha - (igual + 1));

            stringstream ssvalores(valores);

            if (prefixo == "f")
            {
                if (tipo == "a")
                {
                    string val;
                    int a_min, a_max;
                    getline(ssvalores, val, ',');
                    a_min = stoi(val);
                    if (getline(ssvalores, val, ','))
                    {
                        a_max = stoi(val);
                    }
                    else
                    {
                        a_max = a_min;
                    }
                    filtroAno(filmes, a_min, a_max);
                }
                else if (tipo == "t")
                {
                    string val;
                    vector<string> tipos;
                    while (getline(ssvalores, val, '|'))
                    {
                        tipos.push_back(val);
                    }
                    if (!ptf)
                    {
                        filtroTipo(tipos, filmes);
                    }
                    else
                    {
                        vector<Filme> copy = listaDefilme;
                        listaDefilme.clear();
                        filtroTipo(tipos, copy);
                    }
                }
                else if (tipo == "g")
                {
                    string val;
                    vector<string> generos;
                    while (getline(ssvalores, val, '|'))
                    {
                        generos.push_back(val);
                    }
                    if (!ptf)
                    {
                        filtroGenero(filmes, generos);
                    }
                    else
                    {
                        vector<Filme> copy = listaDefilme;
                        listaDefilme.clear();
                        filtroGenero(copy, generos);
                    }
                }
                else if (tipo == "d")
                {
                    string val;
                    int d_min, d_max;
                    getline(ssvalores, val, ',');
                    d_min = stoi(val);
                    if (getline(ssvalores, val, ','))
                    {
                        d_max = stoi(val);
                    }
                    else
                    {
                        d_max = d_min;
                    }
                    if (!ptf)
                    {
                        filtroDuracao(filmes, d_min, d_max);
                    }
                    else
                    {
                        vector<Filme> copy = listaDefilme;
                        listaDefilme.clear();
                        filtroDuracao(copy, d_min, d_max);
                    }
                }
                ptf = listaDeFilme.size() > 0;
            }
            else if (prefixo == "c")
            { // filtro cinema
                            if (tipo == "a") { // ano
                string val;
                int a_min, a_max;
                getline(ssvalores, val, ',');
                a_min = stoi(val);
                if (getline(ssvalores, val, ',')) {
                    a_max = stoi(val);
                } else {
                    a_max = a_min;
                }
                /*
                if (!ptf) {
                    filtroAnoCinema(cinemas, a_min, a_max);
                } else {
                    vector<Cinema> copy = listaDeCinema;
                    listaDeCinema.clear();
                    filtroAnoCinema(copy, a_min, a_max);
                }*/
            } else if (tipo == "t") { // tipo de título
                string val;
                vector<string> tipos;
                while (getline(ssvalores, val, '|')) {
                    tipos.push_back(val);
                }
                /*
                if (!ptf) {
                    filtroTipoCinema(cinemas, tipos);
                } else {
                    vector<Cinema> copy = listaDeCinema;
                    listaDeCinema.clear();
                    filtroTipoCinema(copy, tipos);
                }*/
            } else if (tipo == "g") { // gêneros
                string val;
                vector<string> generos;
                while (getline(ssvalores, val, '|')) {
                    generos.push_back(val);
                }
                /*
                if (!ptf) {
                    filtroGeneroCinema(cinemas, generos);
                } else {
                    vector<Cinema> copy = listaDeCinema;
                    listaDeCinema.clear();
                    filtroGeneroCinema(copy, generos);
                }
                */
            } else if (tipo == "d") { // duração
                string val;
                int d_min, d_max;
                getline(ssvalores, val, ',');
                d_min = stoi(val);
                if (getline(ssvalores, val, ',')) {
                    d_max = stoi(val);
                } else {
                    d_max = d_min;
                }
                
                /*
                if (!ptf) {
                    filtroDuracaoCinema(cinemas, d_min, d_max);
                } else {
                    vector<Cinema> copy = listaDeCinema;
                    listaDeCinema.clear();
                    filtroDuracaoCinema(copy, d_min, d_max);
                }
                */
            } else if (tipo == "r") { // raio: y, x, raio
                string val;
                double y, x, raio;
                getline(ssvalores, val, ',');
                y = stod(val);
                getline(ssvalores, val, ',');
                x = stod(val);
                getline(ssvalores, val);
                raio = stod(val);
                /*
                if (!ptf) {
                    filtroRaioCinema(cinemas, y, x, raio);
                } else {
                    vector<Cinema> copy = listaDeCinema;
                    listaDeCinema.clear();
                    filtroRaioCinema(copy, y, x, raio);
                }
                */
            } else if (tipo == "v") { // valor máximo do ingresso
                string val;
                double v_max;
                getline(ssvalores, val);
                v_max = stod(val);
                
                /*
                if (!ptf) {
                    filtroValorCinema(cinemas, v_max);
                } else {
                    vector<Cinema> copy = listaDeCinema;
                    listaDeCinema.clear();
                    filtroValorCinema(copy, v_max);
                }*/
            }
            ptf = listaDeCinema.size() > 0;
            }
        }
    }
};
