#ifndef COLETAVEL_H
#define COLETAVEL_H
#include <string>
#include <ostream>
#include "Placar.h"

class Coletavel {

    protected: 
        int posicaoX;
        int posicaoY;
        std::string simbolo;

    public:
        Coletavel(int x, int y, const std::string& simb);   // Construtor da classe
        virtual ~Coletavel();   // Destrutor virtual da classe para checar tipo do objeto
        
        virtual void aplicarEfeito(Placar& p) = 0;   // Método virtual puro para cada classe filha ter efeito próprio
        
        virtual std::string getTipo() const = 0;   // Método virtual puro pois cada classe filha tem seu próprio tipo
        inline int getPosicaoX() const { return this->posicaoX; }   // get para posição do coletável em relação ao eixo x
        inline int getPosicaoY() const { return this->posicaoY; }   // get para posição do coletável em relação ao eixo y
        inline std::string getSimbolo() const { return this->simbolo; }   // get para símbolo (emoji) que representa o coletável
        
        void mover(int dx);   // Método que move o objeto pelo mapa no eixo x
        
        friend std::ostream& operator<<(std::ostream& saida, const Coletavel& coletavel);   // Sobrecarga de operador << para saída formatada

};

#endif