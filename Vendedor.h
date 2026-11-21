#ifndef PROYECTOPOO_VENDEDOR_H
#define PROYECTOPOO_VENDEDOR_H
#include "NPC.h"
#include <vector>
using namespace std;

class Objeto;

class Vendedor : public NPC {
private:
    vector<Objeto*> catalogo;

public:
    Vendedor(string nombre);
    ~Vendedor() override;
    void agregarObjeto(Objeto* obj);
    void interactuar(Jugador* jugador) override;
};

#endif //PROYECTOPOO_VENDEDOR_H