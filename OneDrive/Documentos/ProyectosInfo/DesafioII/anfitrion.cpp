#include "anfitrion.h"

Anfitrion::Anfitrion(std::string documento, int antiguedad, float puntuacion)
    : Usuario(documento, antiguedad, puntuacion) {}

void Anfitrion::agregarAlojamiento(Alojamiento* a) {
    alojamientos.push_back(a);
}

std::vector<Alojamiento*> Anfitrion::getAlojamientos() const {
    return alojamientos;
}

std::string Anfitrion::getTipoUsuario() const {
    return "Anfitrion";
}
