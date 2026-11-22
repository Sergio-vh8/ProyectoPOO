#include "NPC.h"

NPC::NPC(string nombre) : nombre(nombre) {}

string NPC::getNombre() const {
    return nombre;
}