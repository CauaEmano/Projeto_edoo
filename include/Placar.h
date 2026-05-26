#ifndef PLACAR_H
#define PLACAR_H
#include <ostream>

class Placar {

	private:
		int rosas;
		int bananas;
		int cameras;

		static const int MAX_PENALIDADES = 3;

	public:
		Placar();   // Construtor da classe com valores padrão

		// Métodos relacionados a rosas
		void addRosas(int pts);   // Adiciona a quantidade de rosas aos pontos
		void zerarRosas();   // Zera a quantidade de rosas coletadas
		inline int getRosas() const { return this->rosas; }   // get para a quantidade de rosas coletadas

		// Métodos relacionados a bananas
		void incrementarBananas();   // Conta bananas coletadas para game over
		inline int getBananas() const { return this->bananas; }   // get para quantidade de bananas coletadas

		// Métodos relacionados a câmeras
		void incrementarCameras();   // Adiciona quantidade de câmeras coletadas
		inline int getCameras() const { return this->cameras; }   // get para quantidade de câmeras coletadas

		bool gameOver() const;   // Verifica casos de game over

		friend std::ostream& operator<<(std::ostream& os, const Placar& p);   // Sobrecarga de operador << para saída formatada do placar

};

#endif