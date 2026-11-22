#include "Vendedor.h"
#include "Jugador.h"
#include "Pocion.h"
#include <iostream>

Vendedor::Vendedor(string nombre) : NPC(nombre) {}

void Vendedor::interactuar(Jugador* jugador) {
    cout << nombre << ": \"Bienvenido al Mercado del Micelio, viajero. Pocos llegan hasta aquí de una pieza. "
         << "Tengo pociones de vida frescas por solo quince unidades de micelio.\"\n";

    if (jugador->gastarMicelio(15)) {
        jugador->agregarObjeto(new Pocion("Poción de vida", 15, 40));
        cout << "Le compras una Poción de vida por 15 de micelio.\n";
    } else {
        cout << nombre << ": \"Vuelve cuando tengas micelio, viajero.\"\n";
    }
}