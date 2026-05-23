#ifndef COLETAVEL_H
#define COLETAVEL_H
#include <string>
#include <ostream>
#include "Placar.h"

class Coletavel {

    private: 
        int posicaoX;
        int posicaoY;
        std::string simbolo;

    public:
        Coletavel(int x, int y, const std::string& simb);
        virtual ~Coletavel();
        virtual void aplicarEfeito(Placar& p) = 0; 
        virtual std::string getTipo() const = 0;
        int getPosicaoX() const;
        int getPosicaoY() const;
        std::string getSimbolo() const;
        friend std::ostream& operator<<(std::ostream& saida, const Coletavel& coletavel);

};

#endif