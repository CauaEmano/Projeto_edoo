#include "../include/Gisele.h"

Gisele::Gisele() : posicaoY(525), pulando(false), agachada(false), velocidade(0.0f), estado("PARADA"), simbolo("👧") {}

void Gisele::pular() {
    if (!this->pulando) {
        this->velocidade = -14.0f;
        this->agachada = false;
        this->posicaoY = 550;
        this->pulando = true;
        this->estado = "PULANDO";
        this->simbolo = "🤸‍♀️"; 
        cout << "[Gisele] Pulou! Posição Y: " << posicaoY << "\n";
    }
}

void Gisele::agachar() {
    if (!this->pulando) {
        this->agachada = true;
        this->posicaoY = 500;
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
    } else if (this->agachada){
        this->agachada = false;
        this->posicaoY = 525;
        this->estado = "PARADA";
        this->simbolo = "👧";
    }
}

bool Gisele::detectarColisao(const Coletavel& c) const {
    
    return (c.getPosicaoX() == 0) && (c.getPosicaoY() == this->posicaoY);
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
