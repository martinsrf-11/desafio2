#include "usuario.h"

Usuario::Usuario(const std::string& doc, int ant, float punt)
    : documento(doc), antiguedad(ant), puntuacion(punt) {}

Usuario::~Usuario() {}

std::string Usuario::getDocumento() const {
    return documento;
}

int Usuario::getAntiguedad() const {
    return antiguedad;
}

float Usuario::getPuntuacion() const {
    return puntuacion;
}
