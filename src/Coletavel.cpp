#include "../include/Coletavel.h"

Coletavel::Coletavel(int x, int y, const string& simb) : posicaoX(x), posicaoY(y), simbolo(simb) {};

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
    saida << "Símbolo: " << coletavel.simbolo << "\n Ponto: (" << coletavel.posicaoX << ", " << coletavel.posicaoY << ")";
    return saida;
}