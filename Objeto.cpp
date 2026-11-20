#include "Objeto.h"

Objeto::Objeto(string nombre, int valor) : nombre(nombre), valor(valor) {}

bool Objeto::esConsumible() const { return false; }
string Objeto::getNombre() const { return nombre; }
int Objeto::getValor() const { return valor; }