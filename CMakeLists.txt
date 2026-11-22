cmake


cmake_minimum_required(VERSION 4.3)
project(ProyectoPOO)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProyectoPOO main.cpp
        Entidad.cpp
        Jugador.cpp
        Jugador.h
        Objeto.cpp
        Objeto.h
        Pocion.cpp
        Pocion.h
        Armadura.cpp
        Armadura.h
        Arma.cpp
        Arma.h
        Orco.cpp
        Orco.h
        Mago.cpp
        Mago.h
        Esqueleto.cpp
        Esqueleto.h
        Enemigo.cpp
        Enemigo.h
        HeroeLegendarioCorrupto.cpp
        HeroeLegendarioCorrupto.h
        NPC.cpp
        NPC.h
        NpcLore.cpp
        NpcLore.h
        Vendedor.cpp
        Vendedor.h
        Herrero.cpp
        Herrero.h
        Cofre.cpp
        Cofre.h
        Habitacion.cpp
        Habitacion.h
)
