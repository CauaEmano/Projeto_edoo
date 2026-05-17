#include "../include/Placar.h"

Placar::Placar() : rosas(0), bananas(0), cameras(0) {}

void Placar::addRosas(int pts) {
	rosas += pts;
}
void Placar::zerarRosas() {
	rosas = 0;
}
int Placar::getRosas() const {
	return this->rosas;
}

void Placar::incrementarBananas() {
	bananas++;
}
int Placar::getBananas() const {
	return this->bananas;
}

void Placar::incrementarCameras() {
	cameras++;
}
int Placar::getCameras() const {
	return this->cameras;
}

bool Placar::gameOver() const {
	return cameras >= 3 || bananas >= 3;
}

ostream& operator<<(ostream& os, const Placar& p) {
	os << "=== Placar ===\n"
		<< "Rosas  : " << p.rosas << "\n"
		<< "Bananas: " << p.bananas << "\n"
		<< "Cameras: " << p.cameras << "\n";
	return os;
} 