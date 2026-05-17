#ifndef GISELE_H 
#define GISELE_H
#include <string>
#include <ostream>

using namespace std;

class Coletavel; 

class Gisele {
private:
    int posicaoY;
    bool pulando;
    float velocidade;
    string estado;
    string simbolo;

public:
    
    Gisele();
    
    void pular();
    void agachar();
    void atualizarFisica();
    
    
    bool detectarColisao(Coletavel& c);

    
    int getPosicaoY() const;
    string getEstado() const;
    string getSimbolo() const;
    
    friend ostream& operator<<(ostream& saida, const Gisele& g);
};

#endif
