#include "Herrero.h"
#include "Jugador.h"
#include <iostream>

Herrero::Herrero(string nombre) : NPC(nombre) {}

void Herrero::interactuar(Jugador* jugador) {
    cout << nombre << ": \"Hacía tiempo que no veía acero nuevo por estas cuevas. "
         << "Dame algo de micelio y reforzaré tu arma para que corte incluso la corrupción más densa.\"\n";

    if (!jugador->tieneArmaEquipada()) {
        cout << "Necesitas tener un arma equipada para que la refuerce.\n";
    } else if (jugador->gastarMicelio(20)) {
        cout << "El herrero refuerza tu arma por 20 de micelio.\n";
        jugador->mejorarArma(2);
    } else {
        cout << "Reforzar el arma cuesta 20 de micelio y no te alcanza.\n";
    }
}