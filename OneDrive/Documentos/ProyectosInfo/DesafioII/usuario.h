#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
protected:
    std::string documento;
    int antiguedad; // en meses
    float puntuacion; // de 0.0 a 5.0

public:
    Usuario(const std::string& doc, int ant, float punt);
    virtual ~Usuario();

    std::string getDocumento() const;
    int getAntiguedad() const;
    float getPuntuacion() const;
};

#endif
