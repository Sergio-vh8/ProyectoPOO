#include <iostream>
#include "Jugador.h"
#include "Orco.h"
#include "Esqueleto.h"
#include "Mago.h"
#include "HeroeLegendarioCorrupto.h"
#include "Arma.h"
#include "Armadura.h"
#include "Pocion.h"
using namespace std;

int main() {
    Jugador j("Clarius");

    // Objetos: se guardan en el inventario y se equipan
    j.agregarObjeto(new Arma("Espada de hierro", 20, 5));
    j.agregarObjeto(new Armadura("Peto de cuero", 15, "Común"));
    j.agregarObjeto(new Pocion("Poción de vida", 15, 40));
    j.mostrarInventario();
    j.usarObjeto(0);   // equipa la espada
    j.usarObjeto(1);   // equipa el peto
    j.mostrarEstado();

    // Enemigos: todos se manejan como Enemigo*, cada uno ataca a su manera
    Enemigo* enemigos[] = { new Orco(), new Esqueleto(), new Mago(), new HeroeLegendarioCorrupto() };

    for (Enemigo* e : enemigos) {
        cout << "\n--- Combate contra " << e->getNombre() << " ---\n";
        while (j.estaVivo() && e->estaVivo()) {
            j.atacar(e);
            if (e->estaVivo()) e->atacar(&j);
        }
        if (!j.estaVivo()) {
            cout << "\nClarius ha caído.\n";
            break;
        }
        cout << e->getNombre() << " ha sido derrotado.\n";
        j.ganarMicelio(e->getRecompensaMicelio());
        j.ganarExperiencia(e->getRecompensaXP());
        j.mostrarEstado();
    }

    for (Enemigo* e : enemigos) delete e;
    return 0;
}