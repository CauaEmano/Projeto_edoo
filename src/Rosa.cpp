#include "../include/Rosa.h"
#include "../include/Placar.h"
#include <iostream>

Rosa::Rosa(int x, int y, int pts) : Coletavel(x, y, "🌹"), pontos(pts) {}

void Rosa::aplicarEfeito(Placar& placar) {
    placar.addRosas(this->pontos);
    std::cout << "Rosa coletada! +" << this->pontos 
        << " ponto(s). Total: " << placar.getRosas() << '\n';
}

std::string Rosa::getTipo() const { return "Rosa"; }

int Rosa::getPontos() const {return this->pontos;}
