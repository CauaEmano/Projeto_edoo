#ifndef FASE_H
#define FASE_H

#include <vector>
#include "Coletavel.h"
#include "Placar.h"

class Fase {

    private:
        int distanciaPercorrida;
        float velocidadeAtual;
        int ciclo;
        int tempoNoUltimoCiclo;
        std::vector<Coletavel*> coletaveis;

        static const int DISTANCIA_TOTAL = 700;
        static const int DURACAO_CICLO = 10;
        static constexpr float VEL_INICIAL = 1.0f;
        static constexpr float VEL_AUMENTO = 0.2f;

    public:
        Fase();   // Construtor da classe com valores padrão
        ~Fase();   // Destrutor da classe para não ocorrer vazamento de memória

        void atualizar(int deltaT);   // Atualiza atributos da fase a cada ciclo
        void gerarColetavel();   // Gera coletáveis aleatórios no limite da fase 
        
        inline std::vector<Coletavel*>& getColetaveis() { return this->coletaveis; }   // get para vetor de coletaveis
        inline const std::vector<Coletavel*>& getColetaveis() const { return this->coletaveis; }   // Renderizar é const e precisa acessar aqui
        
        inline int getDistancia() const { return this->distanciaPercorrida; }   // get para distância percorrida por Gisele
        inline float getVelocidade() const { return this->velocidadeAtual; }   // get para velocidade atual de Gisele
        inline int getCiclo() const { return this->ciclo; }   // get para qual o número do ciclo
        
        bool fimDaFase(const Placar& p) const;   // Verifica se percorreu a distância total da fase ou deu game over antes disso

};

#endif