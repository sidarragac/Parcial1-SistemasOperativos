
#include "StructPersona.h"
#include <string>
#include <iostream>

// Implementación de métodos inline para mantener la estructura simple
void Persona::mostrar() const {
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

void Persona::mostrarResumen() const {
    std::cout << "[" << id << "] " << nombre << " " << apellido
              << " | " << ciudadNacimiento 
              << " | $" << std::fixed << std::setprecision(2) << ingresosAnuales;
}

void Persona::calcularGrupo() const{
    ultimasCifrasId = std::stoi(id.substr(id.length() - 2));

    if (ultimasCifrasId < 40) {
        grupo = 'A';
    } else if (ultimasCifrasId < 80) {
        grupo = 'B';
    } else {
        grupo = 'C';
    }
}