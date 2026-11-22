#ifndef PROYECTOPOO_NPC_H
#define PROYECTOPOO_NPC_H
#include <string>
using namespace std;

class Jugador;

class NPC {
protected:
    string nombre;

public:
    NPC(string nombre);
    virtual ~NPC() = default;

    virtual void interactuar(Jugador* jugador) = 0;
    string getNombre() const;
};

#endif //PROYECTOPOO_NPC_H