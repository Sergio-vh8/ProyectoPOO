#include "Cofre.h"
#include "Objeto.h"
#include "Jugador.h"
#include <iostream>

Cofre::Cofre() : abierto(false) {}

Cofre::~Cofre() {
    // Si el cofre nunca se abrió, aún es dueño de lo que guarda
    for (Objeto* obj : contenido) delete obj;
}

void Cofre::agregarObjeto(Objeto* obj) {
    contenido.push_back(obj);
}

void Cofre::abrir(Jugador* jugador) {
    if (abierto) {
        cout << "El cofre ya está vacío.\n";
        return;
    }
    abierto = true;
    cout << "Abres el cofre y encuentras:\n";
    for (Objeto* obj : contenido) {
        cout << "  - " << obj->getNombre() << "\n";
        jugador->agregarObjeto(obj);   // el objeto pasa al inventario
    }
    contenido.clear();                 // el cofre ya no es dueño de nada
}

bool Cofre::estaAbierto() const { return abierto; }