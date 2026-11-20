#ifndef PROYECTOPOO_ARMA_H
#define PROYECTOPOO_ARMA_H
#include "Objeto.h"
using namespace std;

class Arma : public Objeto {
private:
    int bonusAtaque;

public:
    Arma(string nombre, int valor, int bonusAtaque);
    void usar(Jugador* jugador) override;
    int getBonusAtaque() const;
    void mejorar(int extra);
};

#endif //PROYECTOPOO_ARMA_H