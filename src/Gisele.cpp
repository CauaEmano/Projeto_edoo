#include "../include/Gisele.h"

Gisele::Gisele() : posicaoY(POSICAO_CHAO), pulando(false), agachada(false), velocidade(0.0f), estado("PARADA"), simbolo("👧") {}

void Gisele::pular() {
    if (!this->pulando) {
        this->velocidade = -2.0f;
        this->agachada = false;
        this->posicaoY = POSICAO_PULO;
        this->pulando = true;
        this->estado = "PULANDO";
        this->simbolo = "🤸‍♀️"; 
        std::cout << "[Gisele] Pulou! Posição Y: " << posicaoY << "\n";
    }
}

void Gisele::agachar() {
    if (!this->pulando) {
        this->agachada = true;
        this->posicaoY = ALTURA_AGACHADA;
        this->estado = "AGACHADA";
        this->simbolo = "🧎‍♀️"; 
    }
}

void Gisele::atualizarFisica() {
    if (this->pulando) {
        this->velocidade += 0.5f; 
        this->posicaoY += static_cast<int>(this->velocidade);

        if (this->posicaoY >= POSICAO_CHAO) {
            this->posicaoY = POSICAO_CHAO;
            this->velocidade = 0.0f;
            this->pulando = false;
            this->estado = "PARADA"; 
            this->simbolo = "👧"; 
        }
    } else if (this->agachada){
        this->agachada = false;
        this->posicaoY = POSICAO_CHAO;
        this->estado = "PARADA";
        this->simbolo = "👧";
    }
}

bool Gisele::detectarColisao(const Coletavel& c) const {
    return (c.getPosicaoX() == 0) && (c.getPosicaoY() == this->posicaoY);
}

std::ostream& operator<<(std::ostream& saida, const Gisele& gisele) {
    saida << gisele.simbolo 
          << " [Estado: " << gisele.estado 
          << " | PosY: " << gisele.posicaoY 
          << " | Vel: " << gisele.velocidade << "]";
    return saida;
}
