#ifndef PROYECTOPOO_NPCLORE_H
#define PROYECTOPOO_NPCLORE_H
#include "NPC.h"
#include <string>
using namespace std;

class NpcLore : public NPC {
private:
    string dialogo;

public:
    NpcLore(string nombre, string dialogo);
    void interactuar(Jugador* jugador) override;
};

#endif //PROYECTOPOO_NPCLORE_H