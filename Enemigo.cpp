#include "Enemigo.h"

Enemigo::Enemigo(string nombre, int vida, int ataque, int defensa, int recompensaMicelio, int recompensaXP)
    : Entidad(nombre, vida, ataque, defensa),
      recompensaMicelio(recompensaMicelio), recompensaXP(recompensaXP) {}

int Enemigo::getRecompensaMicelio() const { return recompensaMicelio; }
int Enemigo::getRecompensaXP() const { return recompensaXP; }
bool Enemigo::esJefe() const { return false; }