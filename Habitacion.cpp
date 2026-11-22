#include "Habitacion.h"
#include "Enemigo.h"
#include "Cofre.h"
#include "NPC.h"
#include <iostream>

Habitacion::Habitacion(string nombre, string descripcion)
    : nombre(nombre), descripcion(descripcion), cofre(nullptr), npc(nullptr) {}

Habitacion::~Habitacion() {
    for (Enemigo* e : enemigos) delete e;
    delete cofre;
    delete npc;
}

void Habitacion::mostrarInfo() const {
    cout << "\n=== " << nombre << " ===\n" << descripcion << "\n";

    cout << "Salidas:";
    for (const auto& par : salidas) cout << " " << par.first;
    cout << "\n";

    if (!enemigos.empty()) {
        cout << "Enemigos:";
        for (Enemigo* e : enemigos) cout << " " << e->getNombre();
        cout << "\n";
    }
    // El cofre solo aparece cuando la sala está despejada
    if (cofre != nullptr && !cofre->estaAbierto() && enemigos.empty()) {
        cout << "Hay un cofre cerrado.\n";
    }
    if (npc != nullptr) cout << "Aquí está " << npc->getNombre() << ".\n";
}

void Habitacion::conectar(string salida, Habitacion* destino) {
    salidas[salida] = destino;
}

Habitacion* Habitacion::getSalida(string salida) const {
    auto it = salidas.find(salida);
    if (it == salidas.end()) return nullptr;
    return it->second;
}

bool Habitacion::hayEnemigos() const { return !enemigos.empty(); }

void Habitacion::agregarEnemigo(Enemigo* enemigo) { enemigos.push_back(enemigo); }

vector<Enemigo*>& Habitacion::getEnemigos() { return enemigos; }

void Habitacion::eliminarEnemigo(int indice) {
    delete enemigos[indice];
    enemigos.erase(enemigos.begin() + indice);
}

void Habitacion::setCofre(Cofre* c) { cofre = c; }
Cofre* Habitacion::getCofre() const { return cofre; }
void Habitacion::setNPC(NPC* n) { npc = n; }
NPC* Habitacion::getNPC() const { return npc; }
string Habitacion::getNombre() const { return nombre; }