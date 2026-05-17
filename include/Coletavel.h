#ifndef COLETAVEL_H
#define COLETAVEL_H
#include <string>
#include <ostream>
#include "Placar.h"

using namespace std;

class Coletavel {

    private: 
        int posicaoX;
        int posicaoY;
        string simbolo;

    public:
        Coletavel(int x, int y, const string& simb);
        virtual ~Coletavel();
        virtual void aplicarEfeito(Placar& p) = 0; 
        virtual string getTipo() const = 0;
        int getPosicaoX() const;
        int getPosicaoY() const;
        string getSimbolo() const;
        friend ostream& operator<<(ostream& saida, const Coletavel& coletavel);

};

#endif