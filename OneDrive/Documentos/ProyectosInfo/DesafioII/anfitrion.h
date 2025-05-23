#ifndef ANFITRION_H
#define ANFITRION_H

#include "usuario.h"
#include <vector>
#include <string>

class Alojamiento; // Declaración adelantada

class Anfitrion : public Usuario {
private:
    std::vector<Alojamiento*> alojamientos;

public:
    Anfitrion(const std::string& doc, int ant, float punt);
    ~Anfitrion();

    void agregarAlojamiento(Alojamiento* alojamiento);
    const std::vector<Alojamiento*>& getAlojamientos() const;
};

#endif
