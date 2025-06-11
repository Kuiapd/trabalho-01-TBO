#ifndef CINEMA_H
#define CINEMA_H
#include <iostream>
#include <string.h>
#include <list>
#include <vector>
#include <fstream>
#include <sstream>
#include "Filme.h"
using namespace std;

class Cinema{
    public:
        string cinemaID;
        string nomeCinema; 
        int coordenadaX;
        int coordenadaY;
        double precoIngresso;
        vector<string> filmesEmExibicao;
    
};

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
#endif