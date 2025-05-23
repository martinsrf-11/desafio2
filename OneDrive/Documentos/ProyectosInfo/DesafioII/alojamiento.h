#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include <string>
#include <vector>
#include "reservacion.h"

class Alojamiento {
    std::string codigo;
    std::vector<Reservacion*> reservaciones;
public:
    Alojamiento(const std::string& cod);

    std::string getCodigo() const;
    void agregarReservacion(Reservacion* r);
    std::vector<Reservacion*> getReservaciones() const;
};

#endif
