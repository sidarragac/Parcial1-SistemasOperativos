
#include "StructPersona.h"
#include <string>
#include <iostream>

// Implementación de métodos inline para mantener la estructura simple
void StructPersona::mostrar() const {
    std::cout << "-------------------------------------\n";
    std::cout << "[" << id << "] Nombre: " << nombre << " " << apellido << "\n";
    std::cout << "   - Ciudad de nacimiento: " << ciudadNacimiento << "\n";
    std::cout << "   - Fecha de nacimiento: " << fechaNacimiento << "\n\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "   - Ingresos anuales: $" << ingresosAnuales << "\n";
    std::cout << "   - Patrimonio: $" << patrimonio << "\n";
    std::cout << "   - Deudas: $" << deudas << "\n";
    std::cout << "   - Declarante de renta: " << (declaranteRenta ? "Sí" : "No") << "\n";
}

void StructPersona::mostrarResumen() const {
    std::cout << "[" << id << "] " << nombre << " " << apellido
              << " | " << ciudadNacimiento 
              << " | $" << std::fixed << std::setprecision(2) << ingresosAnuales;
}

void StructPersona::calcularGrupo() {
    int ultimasCifrasId;

    if (this->id.length() >= 2) {
        ultimasCifrasId = std::stoi(this->id.substr(this->id.length() - 2));
    }

    if (ultimasCifrasId < 40) {
        this->grupo = 'A';
    } else if (ultimasCifrasId < 80) {
        this->grupo = 'B';
    } else {
        this->grupo = 'C';
    }
}