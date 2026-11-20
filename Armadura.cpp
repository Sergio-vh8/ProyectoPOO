#include "Armadura.h"
#include "Jugador.h"

Armadura::Armadura(string nombre, int valor, string calidad)
    : Objeto(nombre, valor), calidad(calidad) {
    if (calidad == "Mala") bonusDefensa = 1;
    else if (calidad == "Común") bonusDefensa = 3;
    else if (calidad == "Buena") bonusDefensa = 5;
    else if (calidad == "Legendaria") bonusDefensa = 8;
    else bonusDefensa = 3;   // si escriben otra cosa, queda como Común
}

void Armadura::usar(Jugador* jugador) {
    jugador->equiparArmadura(this);
}

int Armadura::getBonusDefensa() const { return bonusDefensa; }
string Armadura::getCalidad() const { return calidad; }