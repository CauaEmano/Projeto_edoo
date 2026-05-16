#ifndef COLETAVEL_H
#define COLETAVEL_H
#include <string>
#include <ostream>

using namespace std;

class Coletavel {

    private: 
        int posicaoX;
        int posicaoY;
        string simbolo;

    public:
        Coletavel(int x, int y);
        virtual ~Coletavel();
        // virtual void aplicarEfeito(Placar& p) = 0; DEIXEI COMENTADO POIS AINDA NÃO EXISTE A CLASSE PLACAR
        virtual string getTipo() const = 0;
        int getPosicaoX() const;
        int getPosicaoY() const;
        string getSimbolo() const;
        friend ostream& operator<<(ostream& saida, const Coletavel& coletavel);

};

#endif