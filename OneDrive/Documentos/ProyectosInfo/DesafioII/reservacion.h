#ifndef RESERVACION_H
#define RESERVACION_H

#include <string>

class Reservacion {
    std::string codigo;
public:
    Reservacion(const std::string& cod);
    std::string getCodigo() const;
};

#endif
