#include "Vendedor.h"
#include "Jugador.h"
#include "Pocion.h"
#include "Armadura.h"
#include <iostream>

Vendedor::Vendedor(string nombre) : NPC(nombre) {}

void Vendedor::interactuar(Jugador* jugador) {
    if (jugador == nullptr) {
        return;
    }

    cout << nombre << " | Micelio: " << jugador->getMicelio() << "\n";
    cout << "1. Pocion (15)\n";
    cout << "2. Armadura (20)\n";
    cout << "0. Salir\n";
    cout << "Opcion: ";

    int opcion;
    cin >> opcion;

    if (opcion == 1) {
        if (jugador->gastarMicelio(15)) {
            jugador->agregarObjeto(new Pocion("Pocion", 15, 20));
            cout << "Objeto comprado.\n";
        } else {
            cout << "Micelio insuficiente.\n";
        }
    } else if (opcion == 2) {
        if (jugador->gastarMicelio(20)) {
            jugador->agregarObjeto(new Armadura("Armadura", 20, "Común"));
            cout << "Objeto comprado.\n";
        } else {
            cout << "Micelio insuficiente.\n";
        }
    }
}