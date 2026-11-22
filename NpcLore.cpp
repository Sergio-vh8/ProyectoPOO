#include "NpcLore.h"
#include "Jugador.h"
#include <iostream>

NpcLore::NpcLore(string nombre, string dialogo)
    : NPC(nombre), dialogo(dialogo) {}

void NpcLore::interactuar(Jugador* jugador) {
    (void)jugador;
    cout << nombre << ": " << dialogo << "\n";
}