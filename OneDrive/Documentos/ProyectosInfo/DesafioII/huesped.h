#ifndef HUESPED_H
#define HUESPED_H

#include "usuario.h"

class Huesped : public Usuario {
public:
    Huesped(std::string documento, int antiguedad, float puntuacion);
    std::string getTipoUsuario() const override;
};

#endif
