#ifndef GISELE_H 
#define GISELE_H
#include <string>
#include <iostream>
#include "Coletavel.h"

using namespace std;

class Gisele {
private:
    int posicaoY;
    bool pulando;
    bool agachada;
    float velocidade;
    string estado;
    string simbolo;

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
    string getEstado() const;
    string getSimbolo() const;
    
    friend ostream& operator<<(ostream& saida, const Gisele& g);
};

#endif
