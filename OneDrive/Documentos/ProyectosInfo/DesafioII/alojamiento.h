#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include <string>
#include <vector>

class Anfitrion;
class Reservacion;

class Alojamiento {
private:
    std::string nombre;
    std::string codigo;
    Anfitrion* anfitrion;
    std::string departamento;
    std::string municipio;
    std::string tipo; // "casa" o "apartamento"
    std::string direccion;
    double precioPorNoche;
    std::vector<std::string> amenidades;
    std::vector<Reservacion*> reservaciones;

public:
    Alojamiento(const std::string& nom, const std::string& cod, Anfitrion* anfit,
                const std::string& depto, const std::string& muni,
                const std::string& tipo, const std::string& dir, double precio);
    ~Alojamiento();

    void agregarAmenidad(const std::string& amenidad);
    void agregarReservacion(Reservacion* reserva);

    std::string getCodigo() const;
    const std::vector<Reservacion*>& getReservaciones() const;
    // Otros getters y setters según necesidad
};

#endif
