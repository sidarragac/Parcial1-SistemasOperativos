#ifndef GENERADOR_H
#define GENERADOR_H

#include "ClasePersona.h"
#include "StructPersona.h"
#include <vector>
#include <string>

// Funciones para generación de datos aleatorios

std::string generarFechaNacimiento();

std::string generarID();

double randomDouble(double min, double max);

const ClasePersona* buscarPorID(const std::vector<ClasePersona>& personas, const std::string& id);

// Funciones para generar colecciones de datos
std::string generarDatos();
void generarColeccion(int n);

std::vector<ClasePersona> cargarColeccionClase();
std::vector<StructPersona> cargarColeccionStruct();

#endif // GENERADOR_H
