#include "Pocion.h"
#include "Jugador.h"
#include <iostream>

Pocion::Pocion(string nombre, int valor, int curacion)
    : Objeto(nombre, valor), curacion(curacion) {}

void Pocion::usar(Jugador* jugador) {
    cout << "Usas " << nombre << ".\n";
    jugador->curar(curacion);
}

bool Pocion::esConsumible() const { return true; }