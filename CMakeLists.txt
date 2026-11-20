cmake_minimum_required(VERSION 4.3)
project(ProyectoPOO)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProyectoPOO main.cpp
        Entidad.cpp
        Jugador.cpp
        Jugador.h
        Objeto.cpp
        Objeto.h)
