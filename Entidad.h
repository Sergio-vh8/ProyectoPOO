#ifndef PROYECTOPOO_ENTIDAD_H
#define PROYECTOPOO_ENTIDAD_H


class Entidad {
protected:
    std::string nombre;
    int vida;
    int danio;
    int resistencia;

public:
    Entidad(int vida, int danio, int resistencia, std::string nombre);
    ~virtual Entidad() const = 0;
    virtual void ataque() const = 0;


};


#endif //PROYECTOPOO_ENTIDAD_H
