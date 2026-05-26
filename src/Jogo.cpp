#include "../include/Jogo.h"
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

Jogo::Jogo() : rodando(false), ofuscado(false) {}

void Jogo::iniciar() {
    cout << "====================================\n";
    cout << "      INICIANDO A CORRIDA!          \n";
    cout << "====================================\n\n";
    rodando = true;
    
    cout << "Regras:\n"
        << "A passarela tem 700 metros de extensão.\n"
        << "A velocidade aumenta a cada 10 segundos de jogo.\n" 
        << "Banana → zera as rosas; 3 bananas = game over.\n" 
        << "Câmera → ofusca a tela por 1 segundo; 3 câmeras = game over.\n" 
        << "Rosa → adiciona pontos ao placar final.\n\n";

    cout << "====================================\n\n";
    
    cout << "Comandos: [w] pular | [s] agachar | [d] andar | [q] sair\n\n";
    cout << "====================================\n\n";

    cout << "Pronto para jogar?\n";

    while (rodando){
        renderizar();

        char entrada;
        bool entradaValida = false;

        while (!entradaValida) {
            cout << "Digite sua ação: ";
            cin >> entrada;
            cout << "\n";

            try {
                processarEntrada(entrada);
                entradaValida = true;
            }
            catch(const std::invalid_argument& e) {
                std::cerr << "Erro: " << e.what();
            }
        }

        atualizar();
    }
}

void Jogo::processarEntrada(char entrada) {
    entrada = tolower(entrada);

    if (entrada == 'w') {
        gisele.pular();
    } else if (entrada == 's') {
        gisele.agachar();
    } else if (entrada == 'd') {

    } else if (entrada == 'q') {
        rodando = false;
    } else {
        throw std::invalid_argument("Entrada inválida! Use [w], [s], [d] ou [q]!\n");
    }
}

void Jogo::atualizar() {

    fase.atualizar(1);

    auto& coletaveis = fase.getColetaveis();
    
    for (auto it = coletaveis.begin(); it != coletaveis.end(); ) {
        
        if (gisele.detectarColisao(**it)) {
            (*it)->aplicarEfeito(placar);
            delete *it; 
            it = coletaveis.erase(it);
        } 

        else if ((*it)->getPosicaoX() < 0) {
            delete *it;
            it = coletaveis.erase(it);
        }
        
        else {
            ++it; 
        }
    }

    gisele.atualizarFisica();

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
    
    const auto& coletaveis = fase.getColetaveis();
    
    for (const Coletavel* c: coletaveis){
        if (c->getPosicaoX() <= 5){
            cout << " >> Aproximando: " << c->getTipo() << " (distância: (x = " << c->getPosicaoX() << ", y = " << c->getPosicaoY() << "))\n";
        }
    }
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