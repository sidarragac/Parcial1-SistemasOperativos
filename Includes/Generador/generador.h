#ifndef GENERADOR_H
#define GENERADOR_H

#include "ClasePersona.h"
#include "StructPersona.h"
#include <vector>

// Funciones para generación de datos aleatorios

std::string generarFechaNacimiento();

std::string generarID();

double randomDouble(double min, double max);

const ClasePersona* buscarPorID(const std::vector<Persona>& personas, const std::string& id);

// Funciones para generar colecciones de datos

void generarColeccionJSON(int n);
void guardarEnJSON()

std::vector<ClasePersona> generarColeccionClase();
std::vector<StructPersona> generarColeccionStruct();

#endif // GENERADOR_H