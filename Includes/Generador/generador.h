#ifndef GENERADOR_H
#define GENERADOR_H

#include "../ClasePersona/ClasePersona.h"
#include "../StructPersona/StructPersona.h"
#include <vector>
#include <string>

extern const std::vector<std::string> ciudadesColombia;

// Funciones para generación de datos aleatorios

std::string generarFechaNacimiento();

std::string generarID();

double randomDouble(double min, double max);

// Funciones para generar colecciones de datos
std::string generarDatos();
void generarColeccion(int n);

std::vector<ClasePersona> cargarColeccionClase();
std::vector<StructPersona> cargarColeccionStruct();

#endif // GENERADOR_H
