#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "huesped.h"
#include "anfitrion.h"
#include "alojamiento.h"
#include "reservacion.h"

using namespace std;

// Variables globales para mantener los datos cargados
vector<Huesped*> huespedes;
vector<Anfitrion*> anfitriones;
vector<Alojamiento*> alojamientos;
vector<Reservacion*> reservaciones;
void menuHuesped(Huesped* h);
void menuAnfitrion(Anfitrion* a);
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
        iss.ignore(1); // Saltar el '|'
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
void menuHuesped(Huesped* h) {
    int opcion;
    do {
        cout << "\n--- Menu Huesped ---\n";
        cout << "1. Ver historial de reservas\n";
        cout << "2. Buscar alojamiento (no implementado)\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            for (auto r : h->getReservaciones()) {
                cout << "- Reservacion codigo: " << r->getCodigo() << endl;
            }
            break;
        case 2:
            cout << "[Funcionalidad por implementar]\n";
            break;
        }

    } while (opcion != 0);
}

void menuAnfitrion(Anfitrion* a) {
    int opcion;
    do {
        cout << "\n--- Menu Anfitrion ---\n";
        cout << "1. Registrar alojamiento (no implementado)\n";
        cout << "2. Ver reservas (no implementado)\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "[Funcionalidad por implementar]\n";
            break;
        case 2:
            cout << "[Funcionalidad por implementar]\n";
            break;
        }

    } while (opcion != 0);
}

// ================= FIN FUNCIONES DE PERSISTENCIA =================

int main() {
    // 1. Cargar datos al inicio (no visible para el usuario)
    cargarHuespedes();
    cargarAnfitriones();

    int opcionPrincipal;
    do {
        cout << "\n====== UdeAStay - Sistema de Reservas ======\n";
        cout << "1. Ingresar como Huesped\n";
        cout << "2. Ingresar como Anfitrion\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcionPrincipal;

        if (opcionPrincipal == 1) {
            string doc;
            int antig;
            float punt;

            cout << "Documento: ";
            cin >> doc;
            cout << "Antiguedad (meses): ";
            cin >> antig;
            cout << "Puntuacion (0.0 a 5.0): ";
            cin >> punt;

            Huesped* h = new Huesped(doc, antig, punt);
            huespedes.push_back(h);
            menuHuesped(h);
        } else if (opcionPrincipal == 2) {
            string doc;
            int antig;
            float punt;

            cout << "Documento: ";
            cin >> doc;
            cout << "Antiguedad (meses): ";
            cin >> antig;
            cout << "Puntuacion (0.0 a 5.0): ";
            cin >> punt;

            Anfitrion* a = new Anfitrion(doc, antig, punt);
            anfitriones.push_back(a);
            menuAnfitrion(a);
        }

    } while (opcionPrincipal != 0);

    // 2. Guardar los datos actualizados al salir
    guardarHuespedes();
    guardarAnfitriones();

    // Liberar memoria
    for (auto h : huespedes) delete h;
    for (auto a : anfitriones) delete a;

    cout << "Gracias por usar UdeAStay.\n";
    return 0;
}
