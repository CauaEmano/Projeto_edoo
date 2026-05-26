#include "../include/Placar.h"

Placar::Placar() : rosas(0), bananas(0), cameras(0) {}

void Placar::addRosas(int pts) {
	rosas += pts;
}
void Placar::zerarRosas() {
	rosas = 0;
}

void Placar::incrementarBananas() {
	bananas++;
}

void Placar::incrementarCameras() {
	cameras++;
}

bool Placar::gameOver() const {
	return cameras >= MAX_PENALIDADES || bananas >= MAX_PENALIDADES;
}

std::ostream& operator<<(std::ostream& os, const Placar& p) {
	os << "=== Placar ===\n"
	   << "Rosas  : " << p.rosas << "\n"
	   << "Bananas: " << p.bananas << "\n"
	   << "Cameras: " << p.cameras << "\n";
	return os;
} 