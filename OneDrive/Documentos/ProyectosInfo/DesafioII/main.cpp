// main.cpp (continuación y modificaciones necesarias)
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "huesped.h"
#include "anfitrion.h"
#include "alojamiento.h"
#include "reservacion.h"

using namespace std;

vector<Huesped*> huespedes;
vector<Anfitrion*> anfitriones;
vector<Alojamiento*> alojamientos;
vector<Reservacion*> reservaciones;

void menuHuesped(Huesped* h) {
    cout << "\n=== Menu Huesped ===\n";
    cout << "Bienvenido, Huesped: " << h->getDocumento() << endl;
    // Aquí se podrían agregar funcionalidades específicas del huésped
    cout << "(Funcionalidad en desarrollo...)\n";
}

void menuAnfitrion(Anfitrion* a) {
    cout << "\n=== Menu Anfitrion ===\n";
    cout << "Bienvenido, Anfitrion: " << a->getDocumento() << endl;
    // Aquí se podrían agregar funcionalidades específicas del anfitrión
    cout << "(Funcionalidad en desarrollo...)\n";
}

// ================= FUNCIONES DE PERSISTENCIA =================

void cargarHuespedes() {
    ifstream file("huespedes.txt");
    if (!file.is_open()) return;

    string linea;
    while (getline(file, linea)) {
        istringstream iss(linea);
        string doc;
        int antig;
        float punt;

        getline(iss, doc, '|');
        iss >> antig;
        iss.ignore(1);
        iss >> punt;

        huespedes.push_back(new Huesped(doc, antig, punt));
    }

    file.close();
}

void guardarHuespedes() {
    ofstream file("huespedes.txt");
    for (auto h : huespedes) {
        file << h->getDocumento() << "|"
             << h->getAntiguedad() << "|"
             << h->getPuntuacion() << "\n";
    }
    file.close();
}

void cargarAnfitriones() {
    ifstream file("anfitriones.txt");
    if (!file.is_open()) return;

    string linea;
    while (getline(file, linea)) {
        istringstream iss(linea);
        string doc;
        int antig;
        float punt;

        getline(iss, doc, '|');
        iss >> antig;
        iss.ignore(1);
        iss >> punt;

        anfitriones.push_back(new Anfitrion(doc, antig, punt));
    }

    file.close();
}

void guardarAnfitriones() {
    ofstream file("anfitriones.txt");
    for (auto a : anfitriones) {
        file << a->getDocumento() << "|"
             << a->getAntiguedad() << "|"
             << a->getPuntuacion() << "\n";
    }
    file.close();
}

// NUEVO: guardar alojamientos y reservas
void guardarAlojamientos() {
    ofstream file("alojamientos.txt");
    for (auto a : alojamientos) {
        file << a->getCodigo() << "|";
        file << a->getReservaciones().size() << "\n"; // Por ahora, solo ejemplo de cantidad
    }
    file.close();
}

void guardarReservaciones() {
    ofstream file("reservaciones.txt");
    for (auto r : reservaciones) {
        file << r->getCodigo() << "\n";
    }
    file.close();
}

// ================= FUNCIONES PRINCIPALES =================

void registrarHuesped() {
    string doc;
    int ant;
    float punt;

    cout << "Documento: ";
    cin >> doc;
    cout << "Antiguedad (meses): ";
    cin >> ant;
    cout << "Puntuacion (0.0 a 5.0): ";
    cin >> punt;

    Huesped* nuevo = new Huesped(doc, ant, punt);
    huespedes.push_back(nuevo);
    guardarHuespedes();
    cout << "Huesped registrado.\n";
}

void registrarAnfitrion() {
    string doc;
    int ant;
    float punt;

    cout << "Documento: ";
    cin >> doc;
    cout << "Antiguedad (meses): ";
    cin >> ant;
    cout << "Puntuacion (0.0 a 5.0): ";
    cin >> punt;

    Anfitrion* nuevo = new Anfitrion(doc, ant, punt);
    anfitriones.push_back(nuevo);
    guardarAnfitriones();
    cout << "Anfitrion registrado.\n";
}

Huesped* buscarHuesped(const string& doc) {
    for (auto h : huespedes) {
        if (h->getDocumento() == doc) return h;
    }
    return nullptr;
}

Anfitrion* buscarAnfitrion(const string& doc) {
    for (auto a : anfitriones) {
        if (a->getDocumento() == doc) return a;
    }
    return nullptr;
}

int main() {
    cargarHuespedes();
    cargarAnfitriones();

    int opcion;
    do {
        cout << "\n=== Sistema de Alojamiento ===\n";
        cout << "1. Registrar huesped\n";
        cout << "2. Registrar anfitrion\n";
        cout << "3. Ingresar como huesped\n";
        cout << "4. Ingresar como anfitrion\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            registrarHuesped();
            break;
        case 2:
            registrarAnfitrion();
            break;
        case 3: {
            string doc;
            cout << "Documento del huesped: ";
            cin >> doc;
            {
                Huesped* h = buscarHuesped(doc);
                if (h) menuHuesped(h);
                else cout << "Huesped no encontrado.\n";
            }
            break;
        }
        case 4: {
            string doc;
            cout << "Documento del anfitrion: ";
            cin >> doc;
            {
                Anfitrion* a = buscarAnfitrion(doc);
                if (a) menuAnfitrion(a);
                else cout << "Anfitrion no encontrado.\n";
            }
            break;
        }
        }
    } while (opcion != 0);

    guardarHuespedes();
    guardarAnfitriones();
    guardarAlojamientos();
    guardarReservaciones();

    // Liberar memoria
    for (auto h : huespedes) delete h;
    for (auto a : anfitriones) delete a;
    for (auto r : reservaciones) delete r;
    for (auto a : alojamientos) delete a;

    return 0;
}
