#include "../include/Fase.h"
#include "../include/Rosa.h"
#include "../include/Banana.h"
#include "../include/Camera.h"
#include <cstdlib>
#include <ctime>

Fase::Fase() : distanciaPercorrida(0), velocidadeAtual(1.0f), ciclo(0), tempoNoUltimoCiclo(0) {
    srand(time(nullptr));
}

Fase::~Fase() {
    for (Coletavel* c : coletaveis) {
        delete c;
    }
    coletaveis.clear();
}

void Fase::atualizar(int deltaT) {

    distanciaPercorrida += velocidadeAtual * deltaT;
    tempoNoUltimoCiclo += deltaT;

    if (tempoNoUltimoCiclo >= 10) {
        ciclo++;
        velocidadeAtual += 0.5f;
        tempoNoUltimoCiclo = 0;
    }

    gerarColetavel();
}

void Fase::gerarColetavel() {

    int tipo = rand() % 3;
    int x = rand() % 100;
    int y = rand() % 100;

    Coletavel* novo = nullptr;

    if (tipo == 0) {
        novo = new Rosa(x, y, 10);
    }
    else if (tipo == 1) {
        novo = new Banana(x, y);
    }
    else {
        novo = new Camera(x, y);
    }

    coletaveis.push_back(novo);
}

vector<Coletavel*>& Fase::getColetaveis() {
    return coletaveis;
}

int Fase::getDistancia() const {
    return this->distanciaPercorrida;
}

float Fase::getVelocidade() const {
    return this->velocidadeAtual;
}

bool Fase::fimDaFase(const Placar& p) const {
    return distanciaPercorrida >= 700 || p.gameOver();
} 