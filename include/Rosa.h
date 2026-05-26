#ifndef ROSA_H
#define ROSA_H

#include "Coletavel.h"
class Rosa : public Coletavel{

    private:
        int pontos;

    public:
        Rosa(int x, int y, int pts = 1);   // Construtor da classe

        void aplicarEfeito(Placar& placar) override;   // Efeito de rosa é aumentar a quantidade de pontos

        inline std::string getTipo() const override { return "Rosa"; }   // get para tipo do objeto
        int getPontos() const;   // get para quantidade de pontos

};

#endif