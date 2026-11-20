#ifndef PROYECTOPOO_ARMADURA_H
#define PROYECTOPOO_ARMADURA_H
#include "Objeto.h"
using namespace std;

class Armadura : public Objeto {
private:
    int bonusDefensa;
    string calidad;   // Mala, Común, Buena, Legendaria

public:
    Armadura(string nombre, int valor, string calidad);
    void usar(Jugador* jugador) override;
    int getBonusDefensa() const;
    string getCalidad() const;
};

#endif //PROYECTOPOO_ARMADURA_H