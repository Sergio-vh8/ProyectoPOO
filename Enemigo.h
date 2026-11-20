#ifndef PROYECTOPOO_ENEMIGO_H
#define PROYECTOPOO_ENEMIGO_H
#include "Entidad.h"
using namespace std;

class Enemigo : public Entidad {
protected:
    int recompensaMicelio;
    int recompensaXP;

public:
    Enemigo(string nombre, int vida, int ataque, int defensa, int recompensaMicelio, int recompensaXP);

    int getRecompensaMicelio() const;
    int getRecompensaXP() const;
    virtual bool esJefe() const;
};

#endif //PROYECTOPOO_ENEMIGO_H