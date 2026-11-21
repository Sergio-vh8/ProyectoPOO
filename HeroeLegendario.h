//
// Created by elpan on 20/11/2026.
//
#ifndef PROYECTOPOO_HEROELEGENDARIO_H
#define PROYECTOPOO_HEROELEGENDARIO_H
#include "Enemigo.h"
#include <string>
using namespace std;

class HeroeLegendarioCorrupto : public Enemigo {
private:
    string habilidadEspecial;
    int turnosParaHabilidad;
    int turnoActual;

public:
    HeroeLegendarioCorrupto();
    void atacar(Entidad* objetivo) override;
    void usarHabilidadEspecial(Entidad* objetivo);
    bool esJefe() const override;
};

#endif //PROYECTOPOO_HEROELEGENDARIO_H