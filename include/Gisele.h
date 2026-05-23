#ifndef GISELE_H 
#define GISELE_H
#include <string>
#include <iostream>
#include "Coletavel.h"

class Gisele {
private:
    int posicaoY;
    bool pulando;
    bool agachada;
    float velocidade;
    std::string estado;
    std::string simbolo;

    static const int POSICAO_CHAO = 0;
    static const int POSICAO_PULO = 3;
    static const int ALTURA_AGACHADA = -1;

public:
    
    Gisele();
    
    void pular();
    void agachar();
    void atualizarFisica();
    
    
    bool detectarColisao(const Coletavel& c) const;

    
    int getPosicaoY() const;
    std::string getEstado() const;
    std::string getSimbolo() const;
    
    friend std::ostream& operator<<(std::ostream& saida, const Gisele& g);
};

#endif
