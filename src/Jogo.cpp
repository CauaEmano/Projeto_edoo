#include "../include/Jogo.h"
#include <iostream>
#include <vector>

using namespace std;

Jogo::Jogo() : rodando(false) {}

void Jogo::iniciar() {
    cout << "====================================\n";
    cout << "      INICIANDO A CORRIDA!          \n";
    cout << "====================================\n";
    rodando = true;
}

void Jogo::processarEntrada(char entrada) {
    entrada = tolower(entrada);

    if (entrada == 'w') {
        gisele.pular();
    } else if (entrada == 's') {
        gisele.agachar();
    }
}

void Jogo::atualizar() {
    gisele.atualizarFisica();

    fase.atualizar(1);

    auto& coletaveis = fase.getColetaveis();
    
    for (auto it = coletaveis.begin(); it != coletaveis.end(); ) {
        
        
        if (gisele.detectarColisao(**it)) {
            (*it)->aplicarEfeito(placar);
            
            delete *it; 
            it = coletaveis.erase(it);
        } else {
            ++it; 
        }
    }

    if (fase.fimDaFase(placar)) {
        rodando = false;
    }
}

void Jogo::renderizar() {
    cout << "\n------------------------------------\n";
    cout << placar; 
    cout << "Distância Percorrida: " << fase.getDistancia() << "/700\n";
    cout << "------------------------------------\n";
    cout << gisele << "\n"; 
    cout << "====================================\n";
}

bool Jogo::estaRodando() {
    return rodando;
}

void Jogo::exibirResultado() {
    cout << "\n====================================\n";
    cout << "            FIM DE JOGO!            \n";
    cout << "====================================\n";
    
    if (placar.gameOver()) {
        cout << "☠️ VOCÊ PERDEU! Excesso de penalidades (Muitas câmeras ou bananas).\n";
    } else {
        cout << "🎉 PARABÉNS! Gisele completou a corrida.\n";
    }
    
    cout << "Pontuação Final (Rosas): " << placar.getRosas() << "\n";
    cout << "====================================\n";
}