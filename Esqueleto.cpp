#include "Esqueleto.h"
#include <iostream>

Esqueleto::Esqueleto() : Enemigo("Esqueleto", 35, 8, 1, 10, 15) {}

void Esqueleto::atacar(Entidad* objetivo) {
    cout << nombre << " te golpea dos veces con sus huesos.\n";
    objetivo->recibirDanio(ataque / 2 + 1);
    objetivo->recibirDanio(ataque / 2 + 1);
}