#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Filme {
public:
    string tconst;
    string titleType;
    string primaryTitle;
    string originalTitle;
    bool isAdult;
    int startYear;
    int endYear;
    int runtimeMinutes;
    vector<string> genres;

    Filme() {
        isAdult = false;
        endYear = -1;
        runtimeMinutes = -1;
    }

    // local para a função de leitura

    bool contemTipo(const vector<string>& tipos) const{
        for (const string& tipo: tipos) {
            if(titleType == tipo)
                return true;
        }
        return false;
    }

    bool contemGenero(const string &genero) const {
        for (const string& g : genres)
            if (g == genero)
                return true;
        return false;
    }

    bool contemAlgumGenero(const vector<string> &listaGeneros) const {
        for (const string& g : genres)
            for (const string& alvo : listaGeneros)
                if (g == alvo)
                    return true;
        return false;
    }

    bool estaNoIntervaloDeDuracao(int min, int max) const {
        if (runtimeMinutes == -1)
            return false;
        return runtimeMinutes >= min && runtimeMinutes <= max;
    }

    bool confereAno(int ano) const {
        return startYear == ano;
    }

    bool estaNoIntervaloDeAnos(int inicial, int final) const {
        return startYear >= inicial && startYear <= final;
    }

    void imprime() const {
        cout << "[" << tconst << "] " << titleType << " " << primaryTitle;
        cout << " " << startYear;
        if (runtimeMinutes != -1)
            cout << ", " << runtimeMinutes << "min";
        if (!genres.empty()) {
            cout << ", Generos: ";
            for (size_t i = 0; i < genres.size(); i++) {
                cout << genres[i];
                if (i < genres.size() - 1)
                    cout << ", ";
            }
        }
        cout << endl;
    }
};