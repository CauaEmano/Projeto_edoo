#ifndef FASE_H
#define FASE_H

#include <vector>
#include <ostream>
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

public:
    Fase();
    ~Fase();

    void atualizar(int deltaT);
    void gerarColetavel();
    vector<Coletavel*>& getColetaveis();
    int getDistancia() const;
    float getVelocidade() const;
    bool fimDaFase(const Placar& p) const;

};

#endif