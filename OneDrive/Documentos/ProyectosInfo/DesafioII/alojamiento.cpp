#include "alojamiento.h"
#include "reservacion.h"
#include "anfitrion.h"

Alojamiento::Alojamiento(const std::string& nom, const std::string& cod, Anfitrion* anfit,
                         const std::string& depto, const std::string& muni,
                         const std::string& tipo, const std::string& dir, double precio)
    : nombre(nom), codigo(cod), anfitrion(anfit), departamento(depto),
    municipio(muni), tipo(tipo), direccion(dir), precioPorNoche(precio) {}

Alojamiento::~Alojamiento() {
    for (Reservacion* reserva : reservaciones) {
        delete reserva;
    }
}

void Alojamiento::agregarAmenidad(const std::string& amenidad) {
    amenidades.push_back(amenidad);
}

void Alojamiento::agregarReservacion(Reservacion* reserva) {
    reservaciones.push_back(reserva);
}

std::string Alojamiento::getCodigo() const {
    return codigo;
}

const std::vector<Reservacion*>& Alojamiento::getReservaciones() const {
    return reservaciones;
}
