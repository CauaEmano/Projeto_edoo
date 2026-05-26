#ifndef BANANA_H
#define BANANA_H
#include "Coletavel.h"

class Banana : public Coletavel{

    public:
        Banana(int x, int y);   // Construtor da classe

        void aplicarEfeito(Placar& placar) override;   // Efeito de banana zera a quantidade de rosas coletadas, caso colete 3 dá game over

        inline std::string getTipo() const override { return "Banana"; }   // get para tipo do objeto

};

#endif