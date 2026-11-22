#include "Cofre.h"
#include "Objeto.h"
#include "Jugador.h"
#include <iostream>

Cofre::Cofre() : abierto(false) {}

Cofre::~Cofre() {
    if (!abierto) {
        for (Objeto* obj : objetos) {
            delete obj;
        }
    }
    objetos.clear();
}

void Cofre::agregarObjeto(Objeto* obj) {
    if (obj != nullptr) {
        objetos.push_back(obj);
    }
}

void Cofre::abrir(Jugador* jugador) {
    if (abierto) {
        cout << "El cofre ya esta abierto.\n";
        return;
    }

    abierto = true;
    cout << "Abres el cofre.\n";

    if (jugador == nullptr) {
        return;
    }

    for (Objeto* obj : objetos) {
        if (obj != nullptr) {
            cout << "Obtienes: " << obj->getNombre() << "\n";
            jugador->agregarObjeto(obj);
        }
    }
    objetos.clear();
}

bool Cofre::estaAbierto() const {
    return abierto;
}