#include "../include/Rosa.h"
#include "../include/Placar.h"
#include <iostream>

Rosa::Rosa(int x, int y, int pts) : Coletavel(x, y, "🌹"), pontos(pts) {}

/*void Rosa::aplicarEfeito(Placar& placar) {
    Futuro
}*/

std::string Rosa::getTipo() const { return "Rosa"; }

int Rosa::getPontos() const {return this->pontos;}
