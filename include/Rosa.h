#ifndef ROSA_H
#define ROSA_H

#include "Coletavel.h"
class Rosa : public Coletavel{
    private:
        int pontos;

    public:
        Rosa(int x, int y, int pts);

        void aplicarEfeito(Placar& placar) override;

        string getTipo() const override;
        int getPontos() const;
};

#endif