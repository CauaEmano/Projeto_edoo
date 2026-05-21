#ifndef FASE_H
#define FASE_H

#include <vector>
#include <iostream>
#include "Coletavel.h"
#include "Placar.h"

using namespace std;

class Fase {

private:
    int distanciaPercorrida;
    float velocidadeAtual;
    int ciclo;
    int tempoNoUltimoCiclo;
    vector<Coletavel*> coletaveis;

    static const int DISTANCIA_TOTAL = 700;
    static const int DURACAO_CICLO = 10;
    static constexpr float VEL_INICIAL = 1.0f;
    static constexpr float VEL_AUMENTO = 0.2f;

public:
    Fase();
    ~Fase();

    void atualizar(int deltaT);
    void gerarColetavel();
    vector<Coletavel*>& getColetaveis();
    int getDistancia() const;
    float getVelocidade() const;
    int getCiclo() const;
    bool fimDaFase(const Placar& p) const;

};

#endif