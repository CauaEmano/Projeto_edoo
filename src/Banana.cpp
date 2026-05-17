#include "../include/Banana.h"
#include "../include/Placar.h" //Pronto para quando o placar tiver feito
#include <iostream>

Banana::Banana(int x, int y) : Coletavel(x, y, "🍌") {}

/* void Banana::aplicarEfeito(Placar& placar) {
    Para quando o placar tiver feito
} */

string Banana::getTipo() const { return "Banana"; }