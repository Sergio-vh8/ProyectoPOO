#include "HeroeLegendarioCorrupto.h"
#include <iostream>

HeroeLegendarioCorrupto::HeroeLegendarioCorrupto()
    : Enemigo("Heroe Legendario Corrupto", 80, 14, 4, 60, 100),
      habilidadEspecial("Golpe dimensional"),
      turnosParaHabilidad(3),
      turnoActual(0) {}

void HeroeLegendarioCorrupto::atacar(Entidad* objetivo) {
    if (objetivo == nullptr) {
        return;
    }

    turnoActual++;
    if (turnoActual >= turnosParaHabilidad) {
        turnoActual = 0;
        usarHabilidadEspecial(objetivo);
    } else {
        cout << nombre << " ataca.\n";
        objetivo->recibirDanio(ataque);
    }
}

void HeroeLegendarioCorrupto::usarHabilidadEspecial(Entidad* objetivo) {
    if (objetivo == nullptr) {
        return;
    }

    cout << nombre << " usa " << habilidadEspecial <<". nada puede escapar."<<endl;
    objetivo->recibirDanio(ataque + 6 + objetivo->getDefensa());
}

bool HeroeLegendarioCorrupto::esJefe() const {
    return true;
}