#include "Herrero.h"
#include "Jugador.h"
#include <iostream>

Herrero::Herrero(string nombre) : NPC(nombre) {}

void Herrero::interactuar(Jugador* jugador) {
    if (jugador == nullptr) {
        return;
    }

    if (!jugador->tieneArmaEquipada()) {
        cout << "No tienes un arma equipada.\n";
        return;
    }

    int costo = 10;
    int extra = 2;
    cout << "Mejorar esa arma +" << extra << " por " << costo << " de micelio. 1 si quieres. 0 si no tienes dinero: ";

    int opcion;
    cin >> opcion;

    if (opcion == 1) {
        if (jugador->gastarMicelio(costo)) {
            jugador->mejorarArma(extra);
            cout << "Tu arma ha sido mejorada.\n";
        } else {
            cout << "Si no tienes micelio, no me molestes.\n";
        }
    }
}