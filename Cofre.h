#ifndef PROYECTOPOO_COFRE_H
#define PROYECTOPOO_COFRE_H
#include <vector>
using namespace std;

class Objeto;
class Jugador;

class Cofre {
private:
    bool abierto;
    vector<Objeto*> objetos;

public:
    Cofre();
    ~Cofre();
    void agregarObjeto(Objeto* obj);
    void abrir(Jugador* jugador);
    bool estaAbierto() const;
};

#endif //PROYECTOPOO_COFRE_H