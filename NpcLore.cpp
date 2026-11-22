#include "NpcLore.h"
#include <iostream>

NpcLore::NpcLore(string nombre, string dialogo)
    : NPC(nombre), dialogo(dialogo) {}

void NpcLore::interactuar(Jugador* jugador) {
    cout << nombre << ": \"" << dialogo << "\"\n";
}