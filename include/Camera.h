#ifndef CAMERA_H
#define CAMERA_H

#include "Coletavel.h"

class Camera : public Coletavel {

    private: 
        bool ofuscada;
    
    public:
        Camera(int x, int y);   // Construtor da classe

        void aplicarEfeito(Placar& placar) override;   // Efeito da câmera é "ofuscar" por 1 segundo, caso colete 3 dá game over
        
        inline std::string getTipo() const override { return "Câmera"; }   // get para tipo do objeto

        bool estaOfuscada() const;   // retorna se está "ofuscada" ou não

};

#endif