#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <Filme.h>
#include <Cinema.h>

using namespace std;

vector<Filme> geraListaFilmes(const string &nomeArquivo)
{
    vector<Filme> lista;
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open())
    {
        cout << "Erro ao abriar arquivo de Cinemas!!";
        return lista;
    }
    string cabecalho;
    getline(arquivo, cabecalho);
    string linha;
    while (getline(arquivo, linha))
    {
        istringstream ss(linha);
        string tconstStr, titleTypeStr, primaryTitleStr, originalTitleStr, isAdultStr, startYearStr, endYearStr, runtimeMinutesStr, genresStr;
        getline(ss, tconstStr, ' ');
        getline(ss, titleTypeStr, ' ');
        getline(ss, primaryTitleStr, ' ');
        getline(ss, originalTitleStr, ' ');
        getline(ss, isAdultStr, ' ');
        getline(ss, startYearStr, ' ');
        getline(ss, endYearStr, ' ');
        getline(ss, runtimeMinutesStr, ' ');
        getline(ss, genresStr, ' ');
        
        Filme a;
        a.tconst = tconstStr;
        a.titleType = titleTypeStr;
        a.primaryTitle = primaryTitleStr;
        a.originalTitle = originalTitleStr;
        a.isAdult = (isAdultStr == "1");
        a.startYear = static_cast<unsigned>(stoi(startYearStr));
        a.endYear = static_cast<unsigned>(stoi(endYearStr));
        a.runtimeMinutes = static_cast<unsigned>(stoi(runtimeMinutesStr));
        a.genres = genresStr;
    }

    arquivo.close();
    return lista;
}

void criarListaDeCinemasPorArquivo(string nomeDoArquivo, vector<Cinema> ListaDeCinemas){
    ListaDeCinemas.resize(0);
    ListaDeCinemas.reserve(100);

    ifstream arquivo(nomeDoArquivo);
    
    if (arquivo.is_open()) {
        string linha;
        getline(arquivo,linha);//ignora o cabeçalho

        while(getline(arquivo,linha)){
            stringstream ss(linha);
            Cinema c;
            c.filmesEmExibicao.resize(0);
            c.filmesEmExibicao.reserve(10);
            
            string valor;
            
            getline(ss,c.cinemaID,',');
            getline(ss,c.nomeCinema,',');
            getline(ss,valor,',');
            c.coordenadaX = stoi(valor);
            getline(ss,valor,',');
            c.coordenadaY = stoi(valor);
            getline(ss,valor,',');
            c.precoIngresso= stof(valor);
            while(getline(ss,linha,',')){
                getline(ss,valor,',');
                if (!valor.empty() && valor[0] == ' ')
                    valor = valor.substr(1);
            
                c.filmesEmExibicao.push_back(valor);
            }
        }
        arquivo.close();
    } else {
        cout << "Não foi possível abrir o arquivo." << endl;
    }
}