#include "Mago.h"
#include <iostream>

Mago::Mago() : Enemigo("Mago", 45, 10, 0, 20, 25) {}

void Mago::atacar(Entidad* objetivo) {
    cout << nombre << " lanza un hechizo que atraviesa la armadura.\n";
    objetivo->recibirDanio(ataque + objetivo->getDefensa());
}