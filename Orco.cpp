#include "Orco.h"
#include <iostream>

Orco::Orco() : Enemigo("Orco", 40, 8, 2, 15, 20) {}

void Orco::atacar(Entidad* objetivo) {
    cout << nombre << " golpea con su hacha.\n";
    objetivo->recibirDanio(ataque);
}