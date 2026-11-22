#ifndef PROYECTOPOO_VENDEDOR_H
#define PROYECTOPOO_VENDEDOR_H
#include "NPC.h"

class Vendedor : public NPC {
public:
    Vendedor(string nombre);
    void interactuar(Jugador* jugador) override;
};

#endif //PROYECTOPOO_VENDEDOR_H