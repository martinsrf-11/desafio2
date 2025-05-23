#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
protected:
    std::string documento;
    int antiguedad;
    float puntuacion;

public:
    Usuario(std::string doc, int ant, float punt);
    virtual ~Usuario();

    std::string getDocumento() const;
    int getAntiguedad() const;
    float getPuntuacion() const;
    virtual std::string getTipoUsuario() const = 0;
};

#endif

