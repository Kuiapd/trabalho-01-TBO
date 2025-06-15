#pragma once
#include "Filme.hpp"
#include <iostream>
using namespace std;

class FiltroFilmes {

    bool filtroGenero(const Filme &filme, vector<string> &generosBuscados) {
        return filme.contemAlgumGenero(generosBuscados);
    }

    bool filtroDuracao(const Filme &filme, int minDuracao, int maxDuracao) {
        return filme.estaNoIntervaloDeDuracao(minDuracao, maxDuracao);
    }

    bool filtroTipo(const Filme &filme, vector<string> &tiposBuscados) {
        for (const auto &tipos : tiposBuscados) {
            if (filme.titleType == tipos)
                return true;
        }
        return false;
    }

    bool filtroAno(const Filme &filme, int anoMin, int anoMax) {
        return filme.estaNoIntervaloDeAnos(anoMin, anoMax);
    }
};