#include "Juego.h"
#include "Jugador.h"
#include "Habitacion.h"
#include "Enemigo.h"
#include "Orco.h"
#include "Esqueleto.h"
#include "Mago.h"
#include "HeroeLegendarioCorrupto.h"
#include "Cofre.h"
#include "NPC.h"
#include "NpcLore.h"
#include "Vendedor.h"
#include "Herrero.h"
#include "Pocion.h"
#include "Arma.h"
#include "Armadura.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <cstdlib>

static string leerLinea() {
    string linea;
    if (!getline(cin, linea)) exit(0);
    return linea;
}

static int leerEntero() {
    string linea = leerLinea();
    try {
        return stoi(linea);
    } catch (...) {
        return -1;
    }
}

static void unir(Habitacion* a, const string& salidaA, Habitacion* b, const string& salidaB) {
    a->conectar(salidaA, b);
    b->conectar(salidaB, a);
}

Juego::Juego() : jugador(nullptr), enEjecucion(false), victoria(false) {}

Juego::~Juego() {
    delete jugador;
    for (Habitacion* h : mapa) delete h;
}

void Juego::crearMundo() {
    Habitacion* entrada = new Habitacion("Entrada de la Cueva",
        "El aire es pesado y húmedo. Los hongos luminosos brotan entre raíces gruesas.");
    Habitacion* mercado = new Habitacion("Mercado del Micelio",
        "Un refugio iluminado por esporas doradas, con un mostrador hecho de troncos y raíces.");
    Habitacion* tunel = new Habitacion("Túnel de Esporas",
        "Un corredor asfixiante donde el eco de tus pasos rebota entre nubes de esporas.");
    Habitacion* armeria = new Habitacion("Armería Olvidada",
        "Una antigua cámara excavada en la piedra, con musgo y restos de viejas armaduras.");
    Habitacion* ciudad = new Habitacion("Ciudad Fungi",
        "Una inmensa bóveda de hongos gigantes, marchitos y cubiertos de manchas de corrupción.");
    Habitacion* castillo = new Habitacion("Castillo Subterráneo",
        "Una fortaleza en ruinas envuelta en niebla oscura. Las raíces laten con un pulso enfermizo.");

    mapa = {entrada, mercado, tunel, armeria, ciudad, castillo};

    unir(entrada, "mercado", mercado, "entrada");
    unir(entrada, "tunel", tunel, "entrada");
    unir(tunel, "armeria", armeria, "tunel");
    unir(tunel, "ciudad", ciudad, "tunel");
    unir(ciudad, "castillo", castillo, "ciudad");

    entrada->setNPC(new NpcLore("Anciano Hongo",
        "Así que otro viajero se atreve a bajar a las profundidades... Durante siglos, esta red de "
        "micelio alimentó a tu aldea. Hace poco descendió el Héroe Legendario para destruir a Ezpok "
        "el Corrupto. Logró vencerlo, pero el precio fue su propia cordura: las esporas de Ezpok "
        "infectaron su mente y ahora él mismo pudre la red desde el castillo subterráneo. Si quieres "
        "salvar tu hogar, reúne micelio, fortalece tu equipo y libéralo de su tormento."));
    mercado->setNPC(new Vendedor("Vendedora"));
    armeria->setNPC(new Herrero("Herrero"));

    entrada->agregarEnemigo(new Orco());
    entrada->agregarEnemigo(new Orco());
    tunel->agregarEnemigo(new Esqueleto());
    tunel->agregarEnemigo(new Esqueleto());
    ciudad->agregarEnemigo(new Mago());
    castillo->agregarEnemigo(new HeroeLegendarioCorrupto());

    Cofre* cofreTunel = new Cofre();
    cofreTunel->agregarObjeto(new Arma("Espada de hierro", 20, 5));
    tunel->setCofre(cofreTunel);

    Cofre* cofreCiudad = new Cofre();
    cofreCiudad->agregarObjeto(new Armadura("Peto de cuero", 15, "Común"));
    cofreCiudad->agregarObjeto(new Pocion("Poción de vida", 15, 40));
    cofreCiudad->agregarObjeto(new Pocion("Poción de vida", 15, 40));
    ciudad->setCofre(cofreCiudad);
}

void Juego::mostrarAyuda() const {
    cout << "\nComandos:\n"
         << "  ir <sala>    - moverte a una sala conectada (ejemplo: ir tunel)\n"
         << "  mirar        - ver la sala actual\n"
         << "  abrir        - abrir el cofre de la sala\n"
         << "  hablar       - hablar con el personaje de la sala\n"
         << "  inventario   - ver tus objetos\n"
         << "  usar <n>     - usar o equipar el objeto número n\n"
         << "  estado       - ver tus estadísticas\n"
         << "  ayuda        - mostrar esta lista\n"
         << "  salir        - terminar el juego\n";
}

void Juego::iniciar() {
    cout << "=== AVENTURA DE MICELIO ===\n";

    jugador = new Jugador("Clarius");
    crearMundo();
    jugador->setUbicacion(mapa[0]);

    mostrarAyuda();
    cout << "\nEl aire pesado y húmedo recibe a Clarius al descender desde las montañas. "
         << "La oscuridad de la caverna apenas cede ante el resplandor azulado de los hongos. "
         << "De entre las sombras emergen dos Orcos, blandiendo sus hachas oxidadas.\n";
    mapa[0]->mostrarInfo();

    enEjecucion = true;

    if (mapa[0]->hayEnemigos()) {
        combatir(mapa[0]);
        if (jugador->estaVivo()) {
            cout << "Los Orcos se disuelven en hebras brillantes de micelio.\n";
            mapa[0]->mostrarInfo();
        }
    }

    bucleCentral();
}

void Juego::bucleCentral() {
    while (enEjecucion) {
        if (!jugador->estaVivo()) {
            cout << "\n=== FINAL MALO: LA PODREDUMBRE ETERNA ===\n"
                 << "Superado por la fuerza de la corrupción, Clarius cae derrotado sobre las raíces "
                 << "marchitas. La oscuridad de las esporas termina de consumir el núcleo del micelio, "
                 << "apagando para siempre el brillo de los hongos y condenando a la aldea de la "
                 << "superficie a la ruina.\n";
            enEjecucion = false;
            break;
        }
        if (victoria) {
            cout << "\n=== FINAL BUENO: LA RED PURIFICADA ===\n"
                 << "Tras un último embate, el Héroe Legendario Corrupto cae de rodillas y su arma se "
                 << "quiebra contra el suelo. Al instante, las esporas oscuras se disipan y un "
                 << "resplandor cálido recorre las raíces de toda la caverna, devolviendo la vida al "
                 << "micelio.\n"
                 << "Héroe Legendario Corrupto: \"Gracias... por liberarme... Protege la aldea...\"\n"
                 << "Clarius observa cómo la luz asciende hacia la superficie, restaurando el sustento "
                 << "de su pueblo, y emprende el regreso como el nuevo guardián del valle.\n";
            enEjecucion = false;
            break;
        }

        cout << "\n> ";
        procesarComando(leerLinea());
    }
}

void Juego::mover(const string& salida) {
    if (!jugador->moverse(salida)) return;

    Habitacion* sala = jugador->getUbicacion();
    sala->mostrarInfo();

    if (sala->hayEnemigos()) {
        combatir(sala);
        if (jugador->estaVivo() && !victoria) sala->mostrarInfo();
    }
}

void Juego::combatir(Habitacion* sala) {
    cout << "\n¡COMBATE!\n";

    while (jugador->estaVivo() && sala->hayEnemigos()) {
        vector<Enemigo*>& enemigos = sala->getEnemigos();

        jugador->mostrarEstado();
        cout << "Enemigos:\n";
        for (size_t i = 0; i < enemigos.size(); i++) {
            cout << "  " << i + 1 << ". " << enemigos[i]->getNombre()
                 << " (vida " << enemigos[i]->getVida() << ")\n";
        }
        cout << "1) Atacar   2) Usar objeto\n> ";
        int opcion = leerEntero();

        if (opcion == 1) {
            int objetivo = 0;
            if (enemigos.size() > 1) {
                cout << "¿A qué enemigo? > ";
                objetivo = leerEntero() - 1;
            }
            if (objetivo < 0 || objetivo >= (int)enemigos.size()) {
                cout << "Objetivo inválido.\n";
                continue;
            }

            Enemigo* enemigo = enemigos[objetivo];
            jugador->atacar(enemigo);

            if (!enemigo->estaVivo()) {
                cout << enemigo->getNombre() << " ha sido derrotado.\n";
                jugador->ganarMicelio(enemigo->getRecompensaMicelio());
                jugador->ganarExperiencia(enemigo->getRecompensaXP());
                if (enemigo->esJefe()) victoria = true;
                sala->eliminarEnemigo(objetivo);
            }
        } else if (opcion == 2) {
            jugador->mostrarInventario();
            cout << "Número del objeto > ";
            int n = leerEntero();
            if (!jugador->usarObjeto(n - 1)) continue;
        } else {
            cout << "Opción inválida.\n";
            continue;
        }

        for (Enemigo* e : sala->getEnemigos()) {
            if (!jugador->estaVivo()) break;
            e->atacar(jugador);
        }
    }

    if (jugador->estaVivo() && !victoria) cout << "\nLa sala está despejada.\n";
}

void Juego::procesarComando(string cmd) {
    transform(cmd.begin(), cmd.end(), cmd.begin(),
              [](unsigned char c) { return tolower(c); });

    istringstream ss(cmd);
    string accion, arg;
    ss >> accion >> arg;

    Habitacion* sala = jugador->getUbicacion();

    if (accion == "ir") {
        if (arg.empty()) cout << "¿Hacia dónde? Ejemplo: ir tunel\n";
        else mover(arg);
    } else if (accion == "mirar") {
        sala->mostrarInfo();
    } else if (accion == "abrir") {
        if (sala->getCofre() == nullptr) cout << "No hay ningún cofre aquí.\n";
        else if (sala->hayEnemigos()) cout << "Primero debes derrotar a los enemigos.\n";
        else sala->getCofre()->abrir(jugador);
    } else if (accion == "hablar") {
        if (sala->getNPC() == nullptr) cout << "No hay nadie con quien hablar.\n";
        else sala->getNPC()->interactuar(jugador);
    } else if (accion == "inventario") {
        jugador->mostrarInventario();
    } else if (accion == "usar") {
        if (arg.empty()) cout << "¿Cuál? Ejemplo: usar 1\n";
        else jugador->usarObjeto(atoi(arg.c_str()) - 1);
    } else if (accion == "estado") {
        jugador->mostrarEstado();
    } else if (accion == "ayuda") {
        mostrarAyuda();
    } else if (accion == "salir") {
        cout << "Hasta pronto, Clarius.\n";
        enEjecucion = false;
    } else if (!accion.empty()) {
        cout << "No entiendo ese comando. Escribe 'ayuda'.\n";
    }
}