#include "../include/Banana.h"
#include "../include/Placar.h"
#include <iostream>

Banana::Banana(int x, int y) : Coletavel(x, y, "🍌") {}

void Banana::aplicarEfeito(Placar& placar) {
    placar.zerarRosas();
    placar.incrementarBananas();
    std::cout << simbolo << " Escorregou na banana! Rosas zeradas. "
              << "Bananas coletadas: " << placar.getBananas() << "/3\n";
}