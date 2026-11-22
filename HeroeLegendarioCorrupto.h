#ifndef PROYECTOPOO_HEROELEGENDARIOCORRUPTO_H
#define PROYECTOPOO_HEROELEGENDARIOCORRUPTO_H
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

#endif //PROYECTOPOO_HEROELEGENDARIOCORRUPTO_H