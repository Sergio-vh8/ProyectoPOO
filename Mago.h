#ifndef PROYECTOPOO_MAGO_H
#define PROYECTOPOO_MAGO_H
#include "Enemigo.h"
using namespace std;

class Mago : public Enemigo {
public:
    Mago();
    void atacar(Entidad* objetivo) override;
};

#endif //PROYECTOPOO_MAGO_H