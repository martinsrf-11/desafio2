#include "anfitrion.h"
#include "alojamiento.h"

Anfitrion::Anfitrion(const std::string& doc, int ant, float punt)
    : Usuario(doc, ant, punt) {}

Anfitrion::~Anfitrion() {
    for (Alojamiento* alojamiento : alojamientos) {
        delete alojamiento;
    }
}

void Anfitrion::agregarAlojamiento(Alojamiento* alojamiento) {
    alojamientos.push_back(alojamiento);
}

const std::vector<Alojamiento*>& Anfitrion::getAlojamientos() const {
    return alojamientos;
}
