#include "Herrero.h"
#include "Jugador.h"
#include <iostream>

Herrero::Herrero(string nombre, int costoMejora, int bonusMejora)
    : NPC(nombre), costoMejora(costoMejora), bonusMejora(bonusMejora) {}

void Herrero::interactuar(Jugador* jugador) {
    if (jugador == nullptr) {
        return;
    }

    if (!jugador->tieneArmaEquipada()) {
        cout << "No tienes un arma equipada.\n";
        return;
    }

    cout << "Mejorar arma +" << bonusMejora << " por " << costoMejora << " de micelio (1=Si, 0=No): ";

    int opcion;
    cin >> opcion;

    if (opcion == 1) {
        if (jugador->gastarMicelio(costoMejora)) {
            jugador->mejorarArma(bonusMejora);
            cout << "Arma mejorada.\n";
        } else {
            cout << "Micelio insuficiente.\n";
        }
    }
}