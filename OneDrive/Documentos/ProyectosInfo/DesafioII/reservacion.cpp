#include "reservacion.h"
#include "alojamiento.h"
#include "huesped.h"

Reservacion::Reservacion(const std::string& cod, Alojamiento* aloj, Huesped* huesp,
                         const std::string& fechaEnt, int dur, const std::string& metodo,
                         const std::string& fechaPag, double mont, const std::string& notas)
    : codigo(cod), alojamiento(aloj), huesped(huesp), fechaEntrada(fechaEnt),
    duracion(dur), metodoPago(metodo), fechaPago(fechaPag), monto(mont), anotaciones(notas) {}

Reservacion::~Reservacion() {}

std::string Reservacion::getCodigo() const {
    return codigo;
}
