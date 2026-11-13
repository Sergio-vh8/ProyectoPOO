#ifndef PROYECTOPOO_ENTIDAD_H
#define PROYECTOPOO_ENTIDAD_H
#include <string>
using namespace std;

class Entidad {
protected:
    string nombre;
    int vida;
    int ataque;
    int defensa;

public:
    Entidad(string nombre, int vida, int ataque, int defensa);
    virtual ~Entidad();
    virtual void atacar(Entidad* objetivo) = 0;

    void recibirDanio(int danio);
    bool estaVivo() const;

    string getNombre() const;
    int getVida() const;
    int getAtaque() const;
    int getDefensa() const;
};
#endif //PROYECTOPOO_ENTIDAD_H