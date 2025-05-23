#include "huesped.h"
#include "reservacion.h"

Huesped::Huesped(const std::string& doc, int ant, float punt)
    : Usuario(doc, ant, punt) {}

Huesped::~Huesped() {
    for (Reservacion* reserva : reservaciones) {
        delete reserva;
    }
}

void Huesped::agregarReservacion(Reservacion* reserva) {
    reservaciones.push_back(reserva);
}

const std::vector<Reservacion*>& Huesped::getReservaciones() const {
    return reservaciones;
}
