#ifndef HUESPED_H
#define HUESPED_H

#include "usuario.h"
#include <vector>
#include <string>

class Reservacion; // Declaración adelantada

class Huesped : public Usuario {
private:
    std::vector<Reservacion*> reservaciones;

public:
    Huesped(const std::string& doc, int ant, float punt);
    ~Huesped();

    void agregarReservacion(Reservacion* reserva);
    const std::vector<Reservacion*>& getReservaciones() const;
};

#endif
