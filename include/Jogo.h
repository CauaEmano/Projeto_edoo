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

public:
    Jogo();

    
    void iniciar();
    void processarEntrada(char entrada);
    void atualizar();
    void renderizar();
    bool estaRodando();
    void exibirResultado();
};

#endif 