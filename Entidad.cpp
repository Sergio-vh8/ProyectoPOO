#include "Entidad.h"

Entidad::Entidad(string nombre, int vida, int ataque, int defensa)
    : nombre(nombre), vida(vida), ataque(ataque), defensa(defensa) {}

void Entidad::recibirDanio(int danio) {
    danio = danio - defensa;
    if (danio < 1) danio = 1;
    vida -= danio;
    if (vida < 0) vida = 0;
}

bool Entidad::estaVivo() const { return vida > 0; }

string Entidad::getNombre() const { return nombre; }
int Entidad::getVida() const { return vida; }
int Entidad::getAtaque() const { return ataque; }
int Entidad::getDefensa() const { return defensa; }