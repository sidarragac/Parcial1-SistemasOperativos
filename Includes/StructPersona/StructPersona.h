#ifndef STRUCTPERSONA_H
#define STRUCTPERSONA_H

#include <string>
#include <iostream>
#include <iomanip>

// Estructura que representa una persona con datos personales y fiscales
struct StructPersona {
    // Datos básicos de identificación
    std::string nombre;           // Nombre de pila
    std::string apellido;         // Apellidos
    std::string id;               // Identificador único
    std::string ciudadNacimiento; // Ciudad de nacimiento en Colombia
    std::string fechaNacimiento;  // Fecha en formato DD/MM/AAAA
    
    // Datos fiscales y económicos
    double ingresosAnuales;       // Ingresos anuales en pesos colombianos
    double patrimonio;            // Valor total de bienes y activos
    double deudas;                // Deudas pendientes
    bool declaranteRenta;         // Si está obligado a declarar renta
    char grupo;

    // --- Métodos de visualización ---
    void mostrar() const;         // Muestra todos los detalles completos
    void mostrarResumen() const;  // Muestra versión compacta para listados
    char calcularGrupo() const;
};

#endif // PERSONA_H