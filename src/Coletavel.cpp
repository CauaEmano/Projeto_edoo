#include "../include/Coletavel.h"

Coletavel::Coletavel(int x, int y, const std::string& simb) : posicaoX(x), posicaoY(y), simbolo(simb) {};

Coletavel::~Coletavel() {}

void Coletavel::mover(int dx){
    posicaoX += dx;
}

std::ostream& operator<<(std::ostream& saida, const Coletavel& coletavel) {
    saida << "Símbolo: " << coletavel.simbolo << "\n Ponto: (" << coletavel.posicaoX << ", " << coletavel.posicaoY << ")";
    return saida;
}