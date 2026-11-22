cmake_minimum_required(VERSION 3.20)
project(ProyectoPOO)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES CONFIGURE_DEPENDS "*.cpp")
add_executable(ProyectoPOO ${SOURCES})