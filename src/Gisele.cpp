#include "../include/Gisele.h"
#include "../include/Coletavel.h" 


Gisele::Gisele() : posicaoY(525), pulando(false), velocidade(0.0f), estado("PARADA"), simbolo("👧") {}

void Gisele::pular() {
    if (!this->pulando) {
        this->velocidade = -14.0f;
        this->pulando = true;
        this->estado = "PULANDO";
        this->simbolo = "🤸‍♀️"; 
    }
}

void Gisele::agachar() {
    if (!this->pulando) {
        this->estado = "AGACHADA";
        this->simbolo = "🧎‍♀️"; 
    }
}

void Gisele::atualizarFisica() {
    if (this->pulando) {
        this->velocidade += 1.0f; 
        this->posicaoY += static_cast<int>(this->velocidade);

        if (this->posicaoY >= 525) {
            this->posicaoY = 525;
            this->velocidade = 0.0f;
            this->pulando = false;
            this->estado = "PARADA"; 
            this->simbolo = "👧"; 
        }
    }
}

bool Gisele::detectarColisao(Coletavel& c) {
    
    return false;
}

int Gisele::getPosicaoY() const {
    return this->posicaoY;
}

string Gisele::getEstado() const {
    return this->estado;
}
string Gisele::getSimbolo() const {
    return this->simbolo;
}

ostream& operator<<(ostream& saida, const Gisele& gisele) {
    saida << gisele.simbolo << " [Estado: " << gisele.estado 
          << " | PosY: " << gisele.posicaoY 
          << " | Vel: " << gisele.velocidade << "]";
    return saida;
}
