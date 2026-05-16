#include "Coletavel.h"
#include <string>

Coletavel::Coletavel(int x, int y) : posicaoX(x), posicaoY(y) {};

int Coletavel::getPosicaoX() const {
    return this->posicaoX;
}

int Coletavel::getPosicaoY() const {
    return this->posicaoY;
}

string Coletavel::getSimbolo() const {
    return this->simbolo;
}

ostream& operator<<(ostream& saida, const Coletavel& coletavel) {
    saida << "símbolo: " << coletavel.simbolo << " Ponto: (" << coletavel.posicaoX << ", " << coletavel.posicaoY << ")";
    return saida;
}