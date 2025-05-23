#include "huesped.h"

Huesped::Huesped(std::string documento, int antiguedad, float puntuacion)
    : Usuario(documento, antiguedad, puntuacion) {}

std::string Huesped::getTipoUsuario() const {
    return "Huesped";
}
