#ifndef CAMERA_H
#define CAMERA_H

#include "Coletavel.h"

class Camera : public Coletavel {
    private: 
        bool ofuscada;
    
    public:
        Camera(int x, int y);

        void aplicarEfeito(Placar& placar) override;
        string getTipo() const override;

        bool estaOfuscada() const;
};

#endif