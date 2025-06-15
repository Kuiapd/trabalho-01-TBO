#ifndef FILME_H
#define FILME_H

#include <iostream>
#include <string.h>
using namespace std;

class Filme{
public:
    string tconst;
    string titleType;
    string primaryTitle;	
    string originalTitle;
    bool isAdult;
    unsigned startYear;
    unsigned endYear;
    unsigned runtimeMinutes;
    string	genres;
};

#endif