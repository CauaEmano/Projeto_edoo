#include "../include/Fase.h"
#include "../include/Rosa.h"
#include "../include/Banana.h"
#include "../include/Camera.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Fase::Fase() : distanciaPercorrida(0), velocidadeAtual(VEL_INICIAL), ciclo(0), tempoNoUltimoCiclo(0) {
    std::srand(time(nullptr));
}

Fase::~Fase() {
    for (Coletavel* c : coletaveis) {
        delete c;
    }
    coletaveis.clear();
}

void Fase::atualizar(int deltaT) {

    distanciaPercorrida += static_cast<int>(velocidadeAtual * deltaT);   // Mantém em inteiro
    tempoNoUltimoCiclo += deltaT;

    if (tempoNoUltimoCiclo >= DURACAO_CICLO) {
        ciclo++;
        velocidadeAtual += VEL_AUMENTO;
        tempoNoUltimoCiclo = 0;
        std::cout << "[Fase] Ciclo " << ciclo
                << " — velocidade: " << velocidadeAtual << "\n";
    }

    for (Coletavel* c: coletaveis){
        c->mover(-1);
    }

    if (std::rand() % 4 == 0){
        gerarColetavel();
    }
}

void Fase::gerarColetavel() {

    int tipo = std::rand() % 3;
    int x = 10;
    int y = (std::rand() % 2) + 1;

    Coletavel* novo = nullptr;

    if (tipo == 0) {
        novo = new Rosa(x, y);
    }
    else if (tipo == 1) {
        novo = new Banana(x, y);
    }
    else {
        novo = new Camera(x, y);
    }

    coletaveis.push_back(novo);
}

bool Fase::fimDaFase(const Placar& p) const {
    return distanciaPercorrida >= DISTANCIA_TOTAL || p.gameOver();
} 