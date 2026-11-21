#ifndef PROYECTOPOO_HERRERO_H
#define PROYECTOPOO_HERRERO_H
#include "NPC.h"
using namespace std;

class Herrero : public NPC {
private:
    int costoMejora;
    int bonusMejora;

public:
    Herrero(string nombre, int costoMejora = 10, int bonusMejora = 2);
    void interactuar(Jugador* jugador) override;
};

#endif //PROYECTOPOO_HERRERO_H