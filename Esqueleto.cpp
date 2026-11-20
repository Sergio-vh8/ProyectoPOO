#include "Esqueleto.h"
#include <iostream>

Esqueleto::Esqueleto() : Enemigo("Esqueleto", 30, 8, 1, 8, 15) {}

void Esqueleto::atacar(Entidad* objetivo) {
    cout << nombre << " te golpea dos veces con sus huesos.\n";
    objetivo->recibirDanio(ataque / 2 + 1);
    objetivo->recibirDanio(ataque / 2 + 1);
}