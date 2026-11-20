#ifndef PROYECTOPOO_ORCO_H
#define PROYECTOPOO_ORCO_H
#include "Enemigo.h"
using namespace std;

class Orco : public Enemigo {
public:
    Orco();
    void atacar(Entidad* objetivo) override;
};

#endif //PROYECTOPOO_ORCO_H