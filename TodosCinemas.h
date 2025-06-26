#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Cinema.h"
#include "TodosFilmes.h"

using namespace std;

class TodosCinemas {
public:
    vector<Cinema> cinemas;

    int extrairNumero(const string& tconst) const {
        return stoi(tconst.substr(2));
    }

    const Filme* buscaBinariaFilme(const vector<Filme>& filmesOrdenados, const string& tconst) const {
        int alvo = extrairNumero(tconst);
        int ini = 0, fim = filmesOrdenados.size() - 1;

        while (ini <= fim) {
            int meio = (ini + fim) / 2;
            int num = extrairNumero(filmesOrdenados[meio].tconst);

            if (num == alvo)
                return &filmesOrdenados[meio];
            else if (num < alvo)
                ini = meio + 1;
            else
                fim = meio - 1;
        }

        return nullptr;
    }

    void criarListaDeCinemasPorArquivo(const string& nomeDoArquivo, const TodosFilmes& todosFilmes) {
        cinemas.clear();

        ifstream arquivo(nomeDoArquivo);
        if (!arquivo.is_open()) {
            cout << "Não foi possível abrir o arquivo." << endl;
            return;
        }

        const vector<Filme>& filmesOrdenados = todosFilmes.filmes;

        string linha;
        getline(arquivo, linha); // ignora cabeçalho

        while (getline(arquivo, linha)) {
            stringstream ss(linha);
            Cinema c;
            c.filmesEmExibicao.clear();

            string valor;

            getline(ss, c.cinemaID, ',');
            getline(ss, c.nomeCinema, ',');
            getline(ss, valor, ','); c.coordenadaX = stoi(valor);
            getline(ss, valor, ','); c.coordenadaY = stoi(valor);
            getline(ss, valor, ','); c.precoIngresso = stof(valor);

            while (getline(ss, valor, ',')) {
                valor.erase(0, valor.find_first_not_of(" \t"));
                valor.erase(valor.find_last_not_of(" \t") + 1);

                const Filme* filme = buscaBinariaFilme(filmesOrdenados, valor);
                if (filme) {
                    c.filmesEmExibicao.push_back(*filme);
                }
            }

            cinemas.push_back(c);
        }

        arquivo.close();
    }
};
