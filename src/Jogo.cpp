#include "../include/Jogo.h"
#include <iostream>
#include <vector>

using namespace std;

Jogo::Jogo() : rodando(false), ofuscado(false) {}

void Jogo::iniciar() {
    cout << "====================================\n";
    cout << "      INICIANDO A CORRIDA!          \n";
    cout << "====================================\n";
    rodando = true;

    cout << "Comandos: [w] pular | [s] agachar | [q] sair\n\n";

    while (rodando){
        renderizar();

        char entrada;
        cout << "Acao: ";
        cin >> entrada;

        processarEntrada(entrada);
        atualizar();
    }
}

void Jogo::processarEntrada(char entrada) {
    entrada = tolower(entrada);

    if (entrada == 'w') {
        gisele.pular();
    } else if (entrada == 's') {
        gisele.agachar();
    } else if (entrada == 'q') {
        rodando = false;
    } else {
        cout << "Entrada inválida!\n";
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

void Jogo::renderizar() const{
    cout << "\n------------------------------------\n";
    cout << placar; 
    cout << "Distância Percorrida: " << fase.getDistancia() << "/700\n";
    cout << "------------------------------------\n";
    cout << gisele << "\n"; 
    cout << "====================================\n";
}

bool Jogo::estaRodando() const{
    return rodando;
}

void Jogo::exibirResultado() const{
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