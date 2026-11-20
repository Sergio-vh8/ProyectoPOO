#ifndef PROYECTOPOO_POCION_H
#define PROYECTOPOO_POCION_H
#include "Objeto.h"
using namespace std;

class Pocion : public Objeto {
private:
    int curacion;

public:
    Pocion(string nombre, int valor, int curacion);
    void usar(Jugador* jugador) override;
    bool esConsumible() const override;
};

#endif //PROYECTOPOO_POCION_H