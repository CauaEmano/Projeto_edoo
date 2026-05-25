#ifndef FASE_H
#define FASE_H

#include <vector>
#include "Coletavel.h"
#include "Placar.h"

class Fase {

private:
    int distanciaPercorrida;
    float velocidadeAtual;
    int ciclo;
    int tempoNoUltimoCiclo;
    std::vector<Coletavel*> coletaveis;

    static const int DISTANCIA_TOTAL = 700;
    static const int DURACAO_CICLO = 10;
    static constexpr float VEL_INICIAL = 1.0f;
    static constexpr float VEL_AUMENTO = 0.2f;

public:
    Fase();
    ~Fase();

    void atualizar(int deltaT);
    void gerarColetavel();
    std::vector<Coletavel*>& getColetaveis();
    const std::vector<Coletavel*>& getColetaveis() const; //renderizar é const e precisa acessar aqui
    int getDistancia() const;
    float getVelocidade() const;
    int getCiclo() const;
    bool fimDaFase(const Placar& p) const;

};

#endif