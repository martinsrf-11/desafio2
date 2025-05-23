#ifndef RESERVACION_H
#define RESERVACION_H

#include <string>

class Alojamiento;
class Huesped;

class Reservacion {
private:
    std::string codigo;
    Alojamiento* alojamiento;
    Huesped* huesped;
    std::string fechaEntrada;
    int duracion; // en noches
    std::string metodoPago;
    std::string fechaPago;
    double monto;
    std::string anotaciones;

public:
    Reservacion(const std::string& cod, Alojamiento* aloj, Huesped* huesp,
                const std::string& fechaEnt, int dur, const std::string& metodo,
                const std::string& fechaPag, double mont, const std::string& notas);
    ~Reservacion();

    std::string getCodigo() const;
    // Otros getters y setters según necesidad
};

#endif
