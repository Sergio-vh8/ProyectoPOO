#include "Jugador.h"
#include "Objeto.h"
#include "Arma.h"
#include "Armadura.h"
#include "Habitacion.h"
#include "Entidad.h"
#include <iostream>

Jugador::Jugador(string nombre)
    : Entidad(nombre, 100, 10, 2),
      vidaMax(100),
      micelio(0),
      nivel(1),
      experiencia(0),
      armaEquipada(nullptr),
      armaduraEquipada(nullptr),
      ubicacion(nullptr) {}

Jugador::~Jugador() {
    for (Objeto* obj : inventario) {
        if (obj != nullptr) {
            delete obj;
        }
    }
    inventario.clear();
    armaEquipada = nullptr;
    armaduraEquipada = nullptr;
    ubicacion = nullptr;
}

void Jugador::atacar(Entidad* objetivo) {
    if (objetivo == nullptr) {
        return;
    }

    int danioTotal = ataque;
    if (armaEquipada != nullptr) {
        danioTotal += armaEquipada->getBonusAtaque();
    }

    cout << nombre << " ataca a " << objetivo->getNombre() << ".\n";
    objetivo->recibirDanio(danioTotal);
}

bool Jugador::moverse(string direccion) {
    if (ubicacion == nullptr) {
        return false;
    }

    Habitacion* siguiente = ubicacion->getSalida(direccion);
    if (siguiente == nullptr) {
        return false;
    }

    ubicacion = siguiente;
    return true;
}

void Jugador::agregarObjeto(Objeto* obj) {
    if (obj != nullptr) {
        inventario.push_back(obj);
    }
}

bool Jugador::usarObjeto(int indice) {
    if (indice < 0 || static_cast<size_t>(indice) >= inventario.size()) {
        return false;
    }

    Objeto* obj = inventario[indice];
    if (obj == nullptr) {
        return false;
    }

    obj->usar(this);

    if (obj->esConsumible()) {
        delete obj;
        inventario.erase(inventario.begin() + indice);
    }

    return true;
}

void Jugador::equiparArma(Arma* arma) {
    armaEquipada = arma;
    if (armaEquipada != nullptr) {
        cout << "Equipaste " << armaEquipada->getNombre() << ".\n";
    }
}

void Jugador::equiparArmadura(Armadura* armadura) {
    if (armaduraEquipada != nullptr) {
        defensa -= armaduraEquipada->getBonusDefensa();
    }

    armaduraEquipada = armadura;

    if (armaduraEquipada != nullptr) {
        defensa += armaduraEquipada->getBonusDefensa();
        cout << "Equipaste " << armaduraEquipada->getNombre() << ".\n";
    }
}

void Jugador::mejorarArma(int extra) {
    if (armaEquipada != nullptr && extra > 0) {
        armaEquipada->mejorar(extra);
    }
}

bool Jugador::tieneArmaEquipada() const {
    return armaEquipada != nullptr;
}

void Jugador::curar(int cantidad) {
    if (cantidad <= 0) {
        return;
    }

    vida += cantidad;
    if (vida > vidaMax) {
        vida = vidaMax;
    }
    cout << "Vida actual: " << vida << "/" << vidaMax << "\n";
}

void Jugador::ganarExperiencia(int xp) {
    if (xp <= 0) {
        return;
    }

    experiencia += xp;
    cout << "Ganaste " << xp << " de XP.\n";

    while (experiencia >= nivel * 50) {
        experiencia -= nivel * 50;
        subirNivel();
    }
}

void Jugador::subirNivel() {
    nivel++;
    vidaMax += 20;
    ataque += 3;
    defensa += 1;
    vida = vidaMax;
    cout << "Subiste a nivel " << nivel << ".\n";
}

void Jugador::ganarMicelio(int cantidad) {
    if (cantidad > 0) {
        micelio += cantidad;
    }
}

bool Jugador::gastarMicelio(int cantidad) {
    if (cantidad < 0 || micelio < cantidad) {
        return false;
    }

    micelio -= cantidad;
    return true;
}

void Jugador::mostrarEstado() const {
    int ataqueTotal = ataque + (armaEquipada != nullptr ? armaEquipada->getBonusAtaque() : 0);
    cout << "\n--- Estado de " << nombre << " ---\n";
    cout << "Nivel: " << nivel << " | XP: " << experiencia << "/" << (nivel * 50) << "\n";
    cout << "Vida: " << vida << "/" << vidaMax << "\n";
    cout << "Ataque: " << ataqueTotal << " | Defensa: " << defensa << "\n";
    cout << "Micelio: " << micelio << "\n";
    cout << "Arma: " << (armaEquipada != nullptr ? armaEquipada->getNombre() : "Ninguna") << "\n";
    cout << "Armadura: " << (armaduraEquipada != nullptr ? armaduraEquipada->getNombre() : "Ninguna") << "\n";
}

void Jugador::mostrarInventario() const {
    cout << "\n--- Inventario ---\n";
    if (inventario.empty()) {
        cout << "Vacio.\n";
        return;
    }

    for (size_t i = 0; i < inventario.size(); i++) {
        if (inventario[i] != nullptr) {
            cout << "[" << i << "] " << inventario[i]->getNombre()
                 << " (Valor: " << inventario[i]->getValor() << ")\n";
        }
    }
}

int Jugador::getNivel() const {
    return nivel;
}

int Jugador::getMicelio() const {
    return micelio;
}

Habitacion* Jugador::getUbicacion() const {
    return ubicacion;
}

void Jugador::setUbicacion(Habitacion* hab) {
    ubicacion = hab;
}
