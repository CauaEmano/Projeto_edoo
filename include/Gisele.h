#ifndef GISELE_H 
#define GISELE_H
#include <string>
#include <iostream>
#include "Coletavel.h"

class Gisele {

    private:
        int posicaoY;
        bool pulando;
        bool agachada;
        float velocidade;
        std::string estado;
        std::string simbolo;

        static const int POSICAO_CHAO = 0;
        static const int POSICAO_PULO = 3;
        static const int ALTURA_AGACHADA = -1;

    public:   
        Gisele();   // Construtor da classe com valores padrão
        
        void pular();   // Altera os atributos para caso pular
        void agachar();   // Altera os atributos para caso agachar
        void atualizarFisica();   // Altera a física dependendo do estado
        
        bool detectarColisao(const Coletavel& c) const;   // Detecta se colidiu com algum coletável
        
        inline int getPosicaoY() const { return this->posicaoY; }   // get para posição de Gisele em relação ao eixo y
        inline std::string getEstado() const { return this->estado; }   // get para estado de Gisele
        inline std::string getSimbolo() const { return this->simbolo; }   // get para símbolo (emoji) relacionado ao estado
        
        friend std::ostream& operator<<(std::ostream& saida, const Gisele& g);   // Sobrecarga de operador << para saída de atributos
        
};

#endif
