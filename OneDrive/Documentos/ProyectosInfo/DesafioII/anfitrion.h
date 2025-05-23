#ifndef ANFITRION_H
#define ANFITRION_H

#include "usuario.h"
#include <vector>
#include "alojamiento.h"

class Anfitrion : public Usuario {
    std::vector<Alojamiento*> alojamientos;
public:
    Anfitrion(std::string documento, int antiguedad, float puntuacion);

    void agregarAlojamiento(Alojamiento* a);
    std::vector<Alojamiento*> getAlojamientos() const;
    std::string getTipoUsuario() const override;
};

#endif
