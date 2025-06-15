#ifndef FILTRO_H
#define FILTRO_H
#include <iostream>
#include <string.h>
#include <list>
#include "Filme.h"
#include "Cinema.h"
using namespace std;

class Filtro{
    list<Cinema> listaDeCinema;
    list<Filme> listaDeFilme;
};

#endif