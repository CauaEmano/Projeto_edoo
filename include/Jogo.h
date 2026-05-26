#ifndef JOGO_H
#define JOGO_H

#include "Gisele.h"
#include "Fase.h"
#include "Placar.h"

class Jogo {

    private:
        Gisele gisele;
        Fase fase;
        Placar placar;
        bool rodando;
        bool ofuscado;

        void processarEntrada(char entrada);   // Lê e executa qual entrada do jogador
        void atualizar();   // Atualiza os estados do jogo a cada ação
        void renderizar() const;   // Renderiza o jogo no terminal por linha de comando a cada ação
        bool estaRodando() const;   // Verifica se a partida acabou

    public:
        Jogo();   // Construtor da classe com valores padrão
        
        void iniciar();   // Inicia a partida para o jogador
        
        void exibirResultado() const;   // Exibe o resultado do jogador na partida

};

#endif 