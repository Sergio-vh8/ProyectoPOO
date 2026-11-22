#ifndef PROYECTOPOO_HERRERO_H
#define PROYECTOPOO_HERRERO_H
#include "NPC.h"
using namespace std;

class Herrero : public NPC {
public:
    Herrero(string nombre);
    void interactuar(Jugador* jugador) override;
};

#endif //PROYECTOPOO_HERRERO_H