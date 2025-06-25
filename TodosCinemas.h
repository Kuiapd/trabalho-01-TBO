#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Cinema.h"
#include "TodosFilmes.h"

class TodosCinemas
{
public:
    vector<Cinema> cinemas;

    void criarListaDeCinemasPorArquivo(const string &nomeDoArquivo, const TodosFilmes &todosFilmes)
{
    cinemas.clear();

    ifstream arquivo(nomeDoArquivo);

    if (!arquivo.is_open())
    {
        cout << "Não foi possível abrir o arquivo." << endl;
        return;
    }

    string linha;
    getline(arquivo, linha); // ignora o cabeçalho

    while (getline(arquivo, linha))
    {
        stringstream ss(linha);
        Cinema c;
        c.filmesEmExibicao.clear();

        string valor;

        getline(ss, c.cinemaID, ',');
        getline(ss, c.nomeCinema, ',');
        getline(ss, valor, ',');
        c.coordenadaX = stoi(valor);
        getline(ss, valor, ',');
        c.coordenadaY = stoi(valor);
        getline(ss, valor, ',');
        c.precoIngresso = stof(valor);

        while (getline(ss, valor, ','))
        {
            valor.erase(0, valor.find_first_not_of(" \t"));
            valor.erase(valor.find_last_not_of(" \t") + 1);

            const Filme* filme = todosFilmes.BuscaFilmePorTconst(valor);
            if (filme)
            {
                c.filmesEmExibicao.push_back(*filme);
            }
            // else
            // {
            //     cout << "Filme com tconst '" << valor << "' não encontrado." << endl;
            // }
        }

        cinemas.push_back(c);
    }

    arquivo.close();
}
};