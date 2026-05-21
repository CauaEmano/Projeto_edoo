#ifndef PLACAR_H
#define PLACAR_H
#include <ostream>
using namespace std;

class Placar {
private:
	int rosas;
	int bananas;
	int cameras;

	static const int MAX_PENALIDADES = 3;
public:
	Placar();

	void addRosas(int pts);
	void zerarRosas();
	int getRosas() const;

	void incrementarBananas();
	int getBananas() const;

	void incrementarCameras();
	int getCameras() const;

	bool gameOver() const;

	friend ostream& operator<<(ostream& os, const Placar& p);
};

#endif