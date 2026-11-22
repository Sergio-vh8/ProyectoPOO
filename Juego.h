#ifndef PROYECTOPOO_JUEGO_H
#define PROYECTOPOO_JUEGO_H
#include <string>
#include <vector>
using namespace std;

class Jugador;
class Habitacion;

class Juego {
private:
    Jugador* jugador;
    vector<Habitacion*> mapa;
    bool enEjecucion;
    bool victoria;

    void crearMundo();
    void mostrarAyuda() const;
    void mover(const string& salida);

public:
    Juego();
    ~Juego();
    Juego(const Juego&) = delete;
    Juego& operator=(const Juego&) = delete;

    void iniciar();
    void bucleCentral();
    void combatir(Habitacion* sala);
    void procesarComando(string cmd);
};

#endif //PROYECTOPOO_JUEGO_H