#ifndef GENERADOR_H
#define GENERADOR_H

#include "../ClasePersona/ClasePersona.h"
#include "../StructPersona/StructPersona.h"
#include <vector>

extern const std::vector<std::string> ciudadesColombia;

// Funciones para generación de datos aleatorios

std::string generarFechaNacimiento();

std::string generarID();

double randomDouble(double min, double max);

//std::vector<ClasePersona> generarColeccion(int n);
std::vector<StructPersona> generarColeccion(int n);

//const ClasePersona* buscarPorID(const std::vector<ClasePersona>& personas, const std::string& id);
const StructPersona* buscarPorID(const std::vector<StructPersona>& personas, const std::string& id);

// Funciones para generar colecciones de datos

#endif // GENERADOR_H