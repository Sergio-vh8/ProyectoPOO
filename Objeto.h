#ifndef PROYECTOPOO_OBJETO_H
#define PROYECTOPOO_OBJETO_H
#include <string>
using namespace std;

class Jugador;

class Objeto {
protected:
    string nombre;
    int valor;

public:
    Objeto(string nombre, int valor);
    virtual ~Objeto() = default;

    virtual void usar(Jugador* jugador) = 0;
    virtual bool esConsumible() const;

    string getNombre() const;
    int getValor() const;
};

#endif //PROYECTOPOO_OBJETO_H