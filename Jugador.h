#ifndef PROYECTOPOO_JUGADOR_H
#define PROYECTOPOO_JUGADOR_H
#include "Entidad.h"
#include <vector>
using namespace std;

class Objeto;
class Arma;
class Armadura;
class Habitacion;

class Jugador : public Entidad {
private:
    int vidaMax;
    int micelio;
    int nivel;
    int experiencia;
    vector<Objeto*> inventario;
    Arma* armaEquipada;
    Armadura* armaduraEquipada;
    Habitacion* ubicacion;

public:
    Jugador(string nombre);
    ~Jugador() override;
    Jugador(const Jugador&) = delete;
    Jugador& operator=(const Jugador&) = delete;

    void atacar(Entidad* objetivo) override;
    bool moverse(string salida);

    void agregarObjeto(Objeto* obj);
    bool usarObjeto(int indice);
    void equiparArma(Arma* arma);
    void equiparArmadura(Armadura* armadura);
    void mejorarArma(int extra);
    bool tieneArmaEquipada() const;

    void curar(int cantidad);
    void ganarExperiencia(int xp);
    void subirNivel();
    void ganarMicelio(int cantidad);
    bool gastarMicelio(int cantidad);

    void mostrarEstado() const;
    void mostrarInventario() const;

    int getNivel() const;
    int getMicelio() const;
    Habitacion* getUbicacion() const;
    void setUbicacion(Habitacion* hab);
};

#endif //PROYECTOPOO_JUGADOR_H