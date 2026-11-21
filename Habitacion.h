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

    void mostrarInfo() const;
    void conectar(string direccion, Habitacion* destino);
    Habitacion* getSalida(string direccion) const;

    bool hayEnemigos() const;
    void agregarEnemigo(Enemigo* enemigo);
    vector<Enemigo*> getEnemigos() const;
    void eliminarEnemigo(int indice);

    void setCofre(Cofre* c);
    Cofre* getCofre() const;

    void setNPC(NPC* n);
    NPC* getNPC() const;

    string getNombre() const;
};

#endif //PROYECTOPOO_HABITACION_H