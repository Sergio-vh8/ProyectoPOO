#include "Jugador.h"
#include "Objeto.h"
#include "Arma.h"
#include "Armadura.h"
#include "Habitacion.h"
#include <iostream>

Jugador::Jugador(string nombre)
    : Entidad(nombre, 100, 10, 2), vidaMax(100), micelio(0), nivel(1), experiencia(0),
      armaEquipada(nullptr), armaduraEquipada(nullptr), ubicacion(nullptr) {}

Jugador::~Jugador() {
    for (Objeto* obj : inventario) delete obj;
}

void Jugador::atacar(Entidad* objetivo) {
    cout << nombre << " ataca a " << objetivo->getNombre() << ".\n";
    objetivo->recibirDanio(ataque);
    cout << objetivo->getNombre() << " queda con " << objetivo->getVida() << " de vida.\n";
}

bool Jugador::moverse(string salida) {
    Habitacion* destino = ubicacion->getSalida(salida);
    if (destino == nullptr) {
        cout << "No hay salida hacia " << salida << ".\n";
        return false;
    }
    ubicacion = destino;
    return true;
}

void Jugador::agregarObjeto(Objeto* obj) {
    inventario.push_back(obj);
}

bool Jugador::usarObjeto(int indice) {
    if (indice < 0 || indice >= (int)inventario.size()) {
        cout << "Ese objeto no existe.\n";
        return false;
    }
    Objeto* obj = inventario[indice];
    obj->usar(this);
    if (obj->esConsumible()) {
        inventario.erase(inventario.begin() + indice);
        delete obj;
    }
    return true;
}

void Jugador::equiparArma(Arma* arma) {
    if (arma == armaEquipada) {
        cout << "Ya tienes equipada esa arma.\n";
        return;
    }
    if (armaEquipada != nullptr) ataque -= armaEquipada->getBonusAtaque();
    armaEquipada = arma;
    ataque += arma->getBonusAtaque();
    cout << "Equipas " << arma->getNombre() << " (+" << arma->getBonusAtaque() << " de ataque).\n";
}

void Jugador::equiparArmadura(Armadura* armadura) {
    if (armadura == armaduraEquipada) {
        cout << "Ya tienes equipada esa armadura.\n";
        return;
    }
    if (armaduraEquipada != nullptr) defensa -= armaduraEquipada->getBonusDefensa();
    armaduraEquipada = armadura;
    defensa += armadura->getBonusDefensa();
    cout << "Equipas " << armadura->getNombre() << " (+" << armadura->getBonusDefensa() << " de defensa).\n";
}

void Jugador::mejorarArma(int extra) {
    armaEquipada->mejorar(extra);
    ataque += extra;
    cout << armaEquipada->getNombre() << " ahora da +" << armaEquipada->getBonusAtaque() << " de ataque.\n";
}

bool Jugador::tieneArmaEquipada() const {
    return armaEquipada != nullptr;
}

void Jugador::curar(int cantidad) {
    vida += cantidad;
    if (vida > vidaMax) vida = vidaMax;
    cout << "Recuperas vida. Vida actual: " << vida << "/" << vidaMax << ".\n";
}

void Jugador::ganarExperiencia(int xp) {
    experiencia += xp;
    cout << "Ganas " << xp << " de experiencia.\n";
    while (experiencia >= nivel * 50) {
        experiencia -= nivel * 50;
        subirNivel();
    }
}

void Jugador::subirNivel() {
    nivel++;
    vidaMax += 15;
    vida = vidaMax;
    ataque += 2;
    defensa += 1;
    cout << "¡SUBES AL NIVEL " << nivel << "! (vida " << vidaMax << ", ataque " << ataque
         << ", defensa " << defensa << ")\n";
}

void Jugador::ganarMicelio(int cantidad) {
    micelio += cantidad;
    cout << "Ganas " << cantidad << " de micelio.\n";
}

bool Jugador::gastarMicelio(int cantidad) {
    if (micelio < cantidad) return false;
    micelio -= cantidad;
    return true;
}

void Jugador::mostrarEstado() const {
    cout << "\n[" << nombre << " | Nivel " << nivel << " | Vida " << vida << "/" << vidaMax
         << " | Ataque " << ataque << " | Defensa " << defensa
         << " | Micelio " << micelio << " | XP " << experiencia << "/" << nivel * 50 << "]\n";
}

void Jugador::mostrarInventario() const {
    if (inventario.empty()) {
        cout << "Tu inventario está vacío.\n";
        return;
    }
    cout << "Inventario:\n";
    for (size_t i = 0; i < inventario.size(); i++) {
        Objeto* obj = inventario[i];
        cout << "  " << i + 1 << ". " << obj->getNombre() << " (valor " << obj->getValor() << ")";
        if (obj == armaEquipada || obj == armaduraEquipada) cout << " [equipado]";
        cout << "\n";
    }
}

int Jugador::getNivel() const { return nivel; }
int Jugador::getMicelio() const { return micelio; }
Habitacion* Jugador::getUbicacion() const { return ubicacion; }
void Jugador::setUbicacion(Habitacion* hab) { ubicacion = hab; }