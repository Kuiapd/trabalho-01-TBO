#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Filme.hpp"

using namespace std;

class TodosFilmes
{
public:
    vector<Filme> filmes;

    void CarregaListaFilmes(const string &nomeArquivo)
    {
        ifstream arquivo(nomeArquivo);
        if (!arquivo.is_open())
        {
            cout << "Erro ao abrir arquivo de Cinemas!!";
            return;
        }

        string cabecalho;
        getline(arquivo, cabecalho);
        string linha;
        while (getline(arquivo, linha))
        {
            istringstream ss(linha);
            string tconstStr, titleTypeStr, primaryTitleStr, originalTitleStr, isAdultStr, startYearStr, endYearStr, runtimeMinutesStr, genresStr;

            getline(ss, tconstStr, '\t');
            getline(ss, titleTypeStr, '\t');
            getline(ss, primaryTitleStr, '\t');
            getline(ss, originalTitleStr, '\t');
            getline(ss, isAdultStr, '\t');
            getline(ss, startYearStr, '\t');
            getline(ss, endYearStr, '\t');
            getline(ss, runtimeMinutesStr, '\t');
            getline(ss, genresStr, '\t');

            Filme a;
            a.tconst = tconstStr;
            a.titleType = titleTypeStr;
            a.primaryTitle = primaryTitleStr;
            a.originalTitle = originalTitleStr;
            a.isAdult = (isAdultStr == "1");

            a.startYear = (!startYearStr.empty() && startYearStr != "\\N") ? stoi(startYearStr) : -1;
            a.endYear = (!endYearStr.empty() && endYearStr != "\\N") ? stoi(endYearStr) : -1;
            a.runtimeMinutes = (!runtimeMinutesStr.empty() && runtimeMinutesStr != "\\N") ? stoi(runtimeMinutesStr) : -1;

            // Corrigir split dos gêneros
            istringstream ssGenres(genresStr);
            string genero;
            while (getline(ssGenres, genero, ','))
            {
                a.genres.push_back(genero);
            }

            filmes.push_back(a);
        }

        arquivo.close();
    }

    void ImprimeFilmeNaPosicao(int pos) const
    {
        if (pos < 0 || pos >= static_cast<int>(filmes.size()))
        {
            cout << "Posição inválida!" << endl;
            return;
        }

        const Filme &f = filmes[pos];
        cout << "----- Filme na posição " << pos << " -----" << endl;
        cout << "tconst: " << f.tconst << endl;
        cout << "titleType: " << f.titleType << endl;
        cout << "primaryTitle: " << f.primaryTitle << endl;
        cout << "originalTitle: " << f.originalTitle << endl;
        cout << "isAdult: " << (f.isAdult ? "Sim" : "Não") << endl;
        cout << "startYear: " << f.startYear << endl;
        cout << "endYear: " << f.endYear << endl;
        cout << "runtimeMinutes: " << f.runtimeMinutes << endl;
        cout << "genres: " << f.genres << endl;
        cout << "----------------------------" << endl;
    }
};
