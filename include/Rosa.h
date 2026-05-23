#ifndef ROSA_H
#define ROSA_H

#include "Coletavel.h"
class Rosa : public Coletavel{
    private:
        int pontos;

    public:
        Rosa(int x, int y, int pts = 1);

        void aplicarEfeito(Placar& placar) override;

        std::string getTipo() const override;
        int getPontos() const;
};

#endif