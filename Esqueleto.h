#ifndef PROYECTOPOO_ESQUELETO_H
#define PROYECTOPOO_ESQUELETO_H
#include "Enemigo.h"
using namespace std;

class Esqueleto : public Enemigo {
public:
    Esqueleto();
    void atacar(Entidad* objetivo) override;
};

#endif //PROYECTOPOO_ESQUELETO_H