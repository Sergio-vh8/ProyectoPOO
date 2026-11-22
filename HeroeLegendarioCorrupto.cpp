#include "HeroeLegendarioCorrupto.h"
#include <iostream>

HeroeLegendarioCorrupto::HeroeLegendarioCorrupto()
    : Enemigo("Héroe Legendario Corrupto", 120, 14, 4, 100, 100),
      habilidadEspecial("Estallido de Esporas"), turnosParaHabilidad(3), turnoActual(0) {}

void HeroeLegendarioCorrupto::atacar(Entidad* objetivo) {
    turnoActual++;
    if (turnoActual >= turnosParaHabilidad) {
        turnoActual = 0;
        usarHabilidadEspecial(objetivo);
    } else {
        cout << nombre << " descarga un tajo corrupto.\n";
        objetivo->recibirDanio(ataque);
    }
}

void HeroeLegendarioCorrupto::usarHabilidadEspecial(Entidad* objetivo) {
    cout << nombre << " canaliza las esporas oscuras y desata el " << habilidadEspecial << "!\n";
    objetivo->recibirDanio(ataque * 2 + objetivo->getDefensa());
}

bool HeroeLegendarioCorrupto::esJefe() const { return true; }