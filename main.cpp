#include "Jugador.h"
#include "Habitacion.h"
#include "Cofre.h"
#include "NpcLore.h"
#include "Vendedor.h"
#include "Herrero.h"
#include "Orco.h"
#include "Esqueleto.h"
#include "Mago.h"
#include "HeroeLegendarioCorrupto.h"
#include "Pocion.h"
#include "Arma.h"
#include "Armadura.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

int leerEntero() {
    int valor;
    while (!(cin >> valor)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Ingresa un numero: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return valor;
}

void combatirEnemigos(Jugador* jugador, Habitacion* sala) {
    if (jugador == nullptr || sala == nullptr || !sala->hayEnemigos()) {
        return;
    }

    cout << "\nCombate en " << sala->getNombre() << "\n";

    while (sala->hayEnemigos() && jugador->estaVivo()) {
        vector<Enemigo*> enemigos = sala->getEnemigos();
        cout << "\n" << jugador->getNombre() << " (Vida: " << jugador->getVida() << ")\n";
        cout << "Enemigos:\n";
        for (size_t i = 0; i < enemigos.size(); i++) {
            cout << "[" << i << "] " << enemigos[i]->getNombre()
                 << " (Vida: " << enemigos[i]->getVida() << ")\n";
        }

        cout << "1. Atacar\n";
        cout << "2. Usar objeto\n";
        cout << "Opcion: ";
        int accion = leerEntero();

        bool turnoGastado = false;

        if (accion == 1) {
            int idx = 0;
            if (enemigos.size() > 1) {
                cout << "Objetivo: ";
                idx = leerEntero();
            }
            if (idx < 0 || static_cast<size_t>(idx) >= enemigos.size()) {
                idx = 0;
            }

            jugador->atacar(enemigos[idx]);
            turnoGastado = true;

            if (!enemigos[idx]->estaVivo()) {
                cout << enemigos[idx]->getNombre() << " derrotado.\n";
                jugador->ganarMicelio(enemigos[idx]->getRecompensaMicelio());
                jugador->ganarExperiencia(enemigos[idx]->getRecompensaXP());
                sala->eliminarEnemigo(idx);
            }
        } else if (accion == 2) {
            jugador->mostrarInventario();
            cout << "Indice de objeto (-1 para cancelar): ";
            int objIdx = leerEntero();
            if (objIdx >= 0) {
                if (jugador->usarObjeto(objIdx)) {
                    turnoGastado = true;
                } else {
                    cout << "No se pudo usar el objeto.\n";
                }
            } else {
                cout << "Cancelado.\n";
            }
        } else {
            cout << "Opcion no valida.\n";
        }

        if (turnoGastado) {
            enemigos = sala->getEnemigos();
            for (size_t i = 0; i < enemigos.size() && jugador->estaVivo(); i++) {
                enemigos[i]->atacar(jugador);
            }
        }
    }
}

int main() {
    Habitacion* entrada = new Habitacion(
        "Entrada de la Cueva",
        "Aire humedo y oscuro con hongos luminosos entre raices gruesas."
    );
    Habitacion* mercado = new Habitacion(
        "Mercado del Micelio",
        "Claro iluminado por esporas doradas donde se escuchan frascos."
    );
    Habitacion* tunel = new Habitacion(
        "Tunel de Esporas",
        "Pasadizo estrecho con nubes de esporas y ecos de huesos."
    );
    Habitacion* armeria = new Habitacion(
        "Armeria Olvidada",
        "Camara de roca con viejas armaduras y el sonido de un yunque."
    );
    Habitacion* ciudadFungi = new Habitacion(
        "Ciudad Fungi",
        "Caverna gigantesca con hongos colosales y manchas de corrupcion."
    );
    Habitacion* castillo = new Habitacion(
        "Castillo Subterraneo",
        "Portones en ruinas envueltos en niebla oscura y raices pulsantes."
    );

    entrada->conectar("mercado", mercado);
    entrada->conectar("tunel", tunel);
    mercado->conectar("entrada", entrada);
    tunel->conectar("entrada", entrada);
    tunel->conectar("armeria", armeria);
    tunel->conectar("ciudad", ciudadFungi);
    armeria->conectar("tunel", tunel);
    ciudadFungi->conectar("tunel", tunel);
    ciudadFungi->conectar("castillo", castillo);
    castillo->conectar("ciudad", ciudadFungi);

    entrada->agregarEnemigo(new Orco());
    entrada->agregarEnemigo(new Orco());
    entrada->setNPC(new NpcLore(
        "Anciano Hongo",
        "El Heroe Legendario vencio a Ezpok, pero las esporas corrompieron su mente y ahora pudren el micelio desde el castillo."
    ));

    mercado->setNPC(new Vendedor("Vendedora"));

    tunel->agregarEnemigo(new Esqueleto());
    tunel->agregarEnemigo(new Esqueleto());
    Cofre* cofreTunel = new Cofre();
    cofreTunel->agregarObjeto(new Arma("Espada de hierro", 20, 5));
    tunel->setCofre(cofreTunel);

    armeria->setNPC(new Herrero("Herrero"));

    ciudadFungi->agregarEnemigo(new Mago());
    Cofre* cofreCiudad = new Cofre();
    cofreCiudad->agregarObjeto(new Armadura("Peto de cuero", 25, "Buena"));
    cofreCiudad->agregarObjeto(new Pocion("Pocion de vida", 15, 20));
    cofreCiudad->agregarObjeto(new Pocion("Pocion de vida", 15, 20));
    ciudadFungi->setCofre(cofreCiudad);

    castillo->agregarEnemigo(new HeroeLegendarioCorrupto());

    Jugador clarius("Clarius");
    clarius.setUbicacion(entrada);

    bool jugando = true;
    while (jugando && clarius.estaVivo()) {
        Habitacion* actual = clarius.getUbicacion();
        actual->mostrarInfo();

        if (actual->hayEnemigos()) {
            combatirEnemigos(&clarius, actual);
            if (!clarius.estaVivo()) {
                break;
            }
            if (actual == castillo && !actual->hayEnemigos()) {
                cout << "\n=== FINAL BUENO: LA RED PURIFICADA ===\n";
                cout << "Las esporas se disipan y la luz vuelve al micelio.\n";
                break;
            }
        }

        cout << "\nComandos: estado | inventario | usar | hablar | abrir | ir <direccion> | salir\n";
        cout << "> ";
        string comando;
        if (!(cin >> comando)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (comando == "estado") {
            clarius.mostrarEstado();
        } else if (comando == "inventario") {
            clarius.mostrarInventario();
        } else if (comando == "usar") {
            clarius.mostrarInventario();
            cout << "Indice del objeto: ";
            int idx = leerEntero();
            clarius.usarObjeto(idx);
        } else if (comando == "hablar") {
            if (actual->getNPC() != nullptr) {
                actual->getNPC()->interactuar(&clarius);
            } else {
                cout << "No hay nadie aqui para hablar.\n";
            }
        } else if (comando == "abrir") {
            if (actual->getCofre() != nullptr) {
                actual->getCofre()->abrir(&clarius);
            } else {
                cout << "No hay cofre aqui.\n";
            }
        } else if (comando == "ir") {
            string dir;
            cin >> dir;
            if (!clarius.moverse(dir)) {
                cout << "No puedes ir en esa direccion.\n";
            }
        } else if (comando == "salir") {
            jugando = false;
        } else {
            cout << "Comando no reconocido.\n";
        }
    }

    if (!clarius.estaVivo()) {
        cout << "\n=== FINAL MALO: LA PODREDUMBRE ETERNA ===\n";
        cout << "Clarius cae sobre las raices marchitas y la oscuridad consume la cueva.\n";
    }

    delete entrada;
    delete mercado;
    delete tunel;
    delete armeria;
    delete ciudadFungi;
    delete castillo;

    return 0;
}