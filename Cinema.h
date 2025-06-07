#ifndef CINEMA_H
#define CINEMA_H
#include <iostream>
#include <string.h>
#include <list>
#include "Filme.h"
using namespace std;

class Cinema{
    string cinemaID;
    string nomeCinema; 
    int coordenadaX;
    int coordenadaaY;
    double precoIngresso;
    list<Filme> filmesEmExibicao;
    
};

#endif