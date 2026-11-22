#include <iostream>
#include <memory>
#include <vector>
#include "Entidad.h"
#include "Orco.h"
#include "Esqueleto.h"
#include "Mago.h"
#include "Arma.h"
#include "Armadura.h"
#include "Pocion.h"

// Subclase temporal solo para probar polimorfismo con Entidad sin tocar Jugador.cpp todavía
class DummyEntidad : public Entidad {
public:
    DummyEntidad(string nombre, int vida, int ataque, int defensa)
        : Entidad(nombre, vida, ataque, defensa) {}

    void atacar(Entidad* objetivo) override {
        if (!objetivo) return;
        cout << nombre << " realiza un ataque básico contra " << objetivo->getNombre() << ".\n";
        objetivo->recibirDanio(ataque);
    }
};

int main() {
    cout << "=== PRUEBA TEMPORAL DE CLASES POO ===\n\n";

    // 1. Probar objetos (Arma, Armadura, Pocion)
    Arma espada("Espada de Esporas", 25, 6);
    Armadura coraza("Coraza Quitina", 30, "Buena");
    Pocion pocion("Pocion de Hongo Azul", 15, 20);

    espada.mejorar(2);
    cout << "Objeto: " << espada.getNombre()
         << " | Valor: " << espada.getValor()
         << " | Bonus Ataque: " << espada.getBonusAtaque()
         << " | Consumible: " << (espada.esConsumible() ? "Si" : "No") << "\n";

    cout << "Objeto: " << coraza.getNombre()
         << " | Calidad: " << coraza.getCalidad()
         << " | Bonus Defensa: " << coraza.getBonusDefensa()
         << " | Consumible: " << (coraza.esConsumible() ? "Si" : "No") << "\n";

    cout << "Objeto: " << pocion.getNombre()
         << " | Valor: " << pocion.getValor()
         << " | Consumible: " << (pocion.esConsumible() ? "Si" : "No") << "\n\n";

    // 2. Probar enemigos y polimorfismo mediante Entidad*
    DummyEntidad objetivoPrueba("Explorador de Prueba", 60, 12, 3);
    vector<unique_ptr<Enemigo>> enemigos;
    enemigos.push_back(make_unique<Orco>());
    enemigos.push_back(make_unique<Esqueleto>());
    enemigos.push_back(make_unique<Mago>());

    for (const auto& enemigo : enemigos) {
        cout << "--- Turno de " << enemigo->getNombre()
             << " (Vida: " << enemigo->getVida()
             << ", ATK: " << enemigo->getAtaque()
             << ", DEF: " << enemigo->getDefensa()
             << ", XP: " << enemigo->getRecompensaXP()
             << ", Micelio: " << enemigo->getRecompensaMicelio()
             << ", Jefe: " << (enemigo->esJefe() ? "Si" : "No") << ") ---\n";

        enemigo->atacar(&objetivoPrueba);
        cout << "Vida restante de " << objetivoPrueba.getNombre()
             << ": " << objetivoPrueba.getVida()
             << " | Vivo: " << (objetivoPrueba.estaVivo() ? "Si" : "No") << "\n\n";
    }

    // 3. Probar recibirDanio y limite minimo de vida (0)
    objetivoPrueba.recibirDanio(999);
    cout << "Tras recibir 999 de dano -> Vida de " << objetivoPrueba.getNombre()
         << ": " << objetivoPrueba.getVida()
         << " | Vivo: " << (objetivoPrueba.estaVivo() ? "Si" : "No") << "\n";

    return 0;
}