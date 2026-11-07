#ifndef PROYECTOPOO_ENTIDAD_H
#define PROYECTOPOO_ENTIDAD_H


class Entidad {
protected:
    int vida;
    int danio;
    int resistencia;

public:
    Entidad(int vida, int danio, int resistencia);
    ~virtual Entidad() const = 0;
    virtual void ataque() const = 0;


};


#endif //PROYECTOPOO_ENTIDAD_H
