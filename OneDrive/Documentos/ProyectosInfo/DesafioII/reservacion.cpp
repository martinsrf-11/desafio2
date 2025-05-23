#include "reservacion.h"

Reservacion::Reservacion(const std::string& cod) : codigo(cod) {}

std::string Reservacion::getCodigo() const {
    return codigo;
}
