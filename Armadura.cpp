#include "Armadura.h"
#include "Jugador.h"

Armadura::Armadura(string nombre, int valor, int bonusDefensa, string calidad)
    : Objeto(nombre, valor), bonusDefensa(bonusDefensa), calidad(calidad) {}

void Armadura::usar(Jugador* jugador) {
    jugador->equiparArmadura(this);
}

int Armadura::getBonusDefensa() const { return bonusDefensa; }
string Armadura::getCalidad() const { return calidad; }