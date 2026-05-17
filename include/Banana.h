#ifndef BANANA_H
#define BANANA_H
#include "Coletavel.h"

class Banana : public Coletavel{

    public:

        Banana(int x, int y);

        void aplicarEfeito(Placar& placar) override;

        std::string getTipo() const override;
};

#endif