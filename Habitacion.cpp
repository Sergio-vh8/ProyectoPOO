#include "Habitacion.h"
#include "Enemigo.h"
#include "Cofre.h"
#include "NPC.h"
#include <iostream>

Habitacion::Habitacion(string nombre, string descripcion)
    : nombre(nombre), descripcion(descripcion), cofre(nullptr), npc(nullptr) {}

Habitacion::~Habitacion() {
    for (Enemigo* e : enemigos) {
        delete e;
    }
    enemigos.clear();
    delete cofre;
    delete npc;
}

void Habitacion::mostrarInfo() const {
    cout << "\n=== " << nombre << " ===\n";
    cout << descripcion << "\n";

    if (hayEnemigos()) {
        cout << "Enemigos:\n";
        for (size_t i = 0; i < enemigos.size(); i++) {
            cout << "  [" << i << "] " << enemigos[i]->getNombre()
                 << " (Vida: " << enemigos[i]->getVida() << ")\n";
        }
    }

    if (cofre != nullptr) {
        cout << "Cofre: " << (cofre->estaAbierto() ? "abierto" : "cerrado") << "\n";
    }

    if (npc != nullptr) {
        cout << "NPC: " << npc->getNombre() << "\n";
    }

    cout << "Salidas: ";
    if (salidas.empty()) {
        cout << "ninguna";
    } else {
        for (const auto& par : salidas) {
            cout << par.first << " ";
        }
    }
    cout << "\n";
}

void Habitacion::conectar(string direccion, Habitacion* destino) {
    salidas[direccion] = destino;
}

Habitacion* Habitacion::getSalida(string direccion) const {
    auto it = salidas.find(direccion);
    if (it != salidas.end()) {
        return it->second;
    }
    return nullptr;
}

bool Habitacion::hayEnemigos() const {
    return !enemigos.empty();
}

void Habitacion::agregarEnemigo(Enemigo* enemigo) {
    if (enemigo != nullptr) {
        enemigos.push_back(enemigo);
    }
}

vector<Enemigo*> Habitacion::getEnemigos() const {
    return enemigos;
}

void Habitacion::eliminarEnemigo(int indice) {
    if (indice >= 0 && static_cast<size_t>(indice) < enemigos.size()) {
        delete enemigos[indice];
        enemigos.erase(enemigos.begin() + indice);
    }
}

void Habitacion::setCofre(Cofre* c) {
    delete cofre;
    cofre = c;
}

Cofre* Habitacion::getCofre() const {
    return cofre;
}

void Habitacion::setNPC(NPC* n) {
    delete npc;
    npc = n;
}

NPC* Habitacion::getNPC() const {
    return npc;
}

string Habitacion::getNombre() const {
    return nombre;
}