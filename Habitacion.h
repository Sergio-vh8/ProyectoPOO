#ifndef PROYECTOPOO_HABITACION_H
#define PROYECTOPOO_HABITACION_H
#include <string>
#include <map>
#include <vector>
using namespace std;

class Enemigo;
class Cofre;
class NPC;

class Habitacion {
private:
    string nombre;
    string descripcion;
    map<string, Habitacion*> salidas;
    vector<Enemigo*> enemigos;
    Cofre* cofre;
    NPC* npc;

public:
    Habitacion(string nombre, string descripcion);
    ~Habitacion();
    Habitacion(const Habitacion&) = delete;
    Habitacion& operator=(const Habitacion&) = delete;

    void mostrarInfo() const;
    void conectar(string salida, Habitacion* destino);
    Habitacion* getSalida(string salida) const;

    bool hayEnemigos() const;
    void agregarEnemigo(Enemigo* enemigo);
    vector<Enemigo*>& getEnemigos();
    void eliminarEnemigo(int indice);

    void setCofre(Cofre* c);
    Cofre* getCofre() const;
    void setNPC(NPC* n);
    NPC* getNPC() const;

    string getNombre() const;
};

#endif //PROYECTOPOO_HABITACION_H