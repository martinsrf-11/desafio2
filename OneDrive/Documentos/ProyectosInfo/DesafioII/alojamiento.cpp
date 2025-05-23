#include "alojamiento.h"

Alojamiento::Alojamiento(const std::string& cod) : codigo(cod) {}

std::string Alojamiento::getCodigo() const {
    return codigo;
}

void Alojamiento::agregarReservacion(Reservacion* r) {
    reservaciones.push_back(r);
}

std::vector<Reservacion*> Alojamiento::getReservaciones() const {
    return reservaciones;
}
