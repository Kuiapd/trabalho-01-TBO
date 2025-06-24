#ifndef CINEMA_H
#define CINEMA_H
#include <iostream>
#include <string.h>
#include <list>
#include <vector>
#include <fstream>
#include <sstream>
#include "Filme.hpp"
using namespace std;

class Cinema{
    public:
        string cinemaID;
        string nomeCinema; 
        int coordenadaX;
        int coordenadaY;
        double precoIngresso;
        vector<Filme> filmesEmExibicao;
    
};

#endif