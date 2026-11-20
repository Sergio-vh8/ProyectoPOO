#include "Arma.h"
#include "Jugador.h"

Arma::Arma(string nombre, int valor, int bonusAtaque)
    : Objeto(nombre, valor), bonusAtaque(bonusAtaque) {}

void Arma::usar(Jugador* jugador) {
    jugador->equiparArma(this);
}

int Arma::getBonusAtaque() const { return bonusAtaque; }
void Arma::mejorar(int extra) { bonusAtaque += extra; }