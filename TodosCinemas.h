#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Cinema.h"

class TodosCinemas
{
public:
    vector<Cinema> cinemas;

    void criarListaDeCinemasPorArquivo(const string &nomeDoArquivo, const TodosFilmes &todosFilmes)
{
    cinemas.clear();
    cinemas.reserve(100);

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
        c.filmesEmExibicao.reserve(10);

        string valor;

        getline(ss, c.cinemaID, ',');
        getline(ss, c.nomeCinema, ',');
        getline(ss, valor, ',');
        c.coordenadaX = stoi(valor);
        getline(ss, valor, ',');
        c.coordenadaY = stoi(valor);
        getline(ss, valor, ',');
        c.precoIngresso = stof(valor);

        // Agora lê todos os tconsts restantes da linha
        while (getline(ss, valor, ','))
        {
            if (!valor.empty() && valor[0] == ' ')
                valor = valor.substr(1); // remove espaço à esquerda

            const Filme* filme = todosFilmes.BuscaFilmePorTconst(valor);
            if (filme)
            {
                c.filmesEmExibicao.push_back(*filme); // copia o objeto Filme
            }
            else
            {
                cout << "Filme com tconst '" << valor << "' não encontrado." << endl;
            }
        }

        cinemas.push_back(c);
    }

    arquivo.close();
}
};