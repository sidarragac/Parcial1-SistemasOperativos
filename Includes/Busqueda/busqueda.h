#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <string>
#include <iostream>
#include <unordered_map>
#include "../ClasePersona/ClasePersona.h"

long buscarClasePersonaLongevaPorValor(std::vector<ClasePersona> personas);

long buscarClasePersonaLongevaPorReferencia(const std::vector<ClasePersona>& personas);

long buscarStructPersonaLongevaPorValor(std::vector<StructPersona> personas);

long buscarStructPersonaLongevaPorReferencia(const std::vector<StructPersona>& personas);

long buscarClasePersonaPatrimonioPorValor(std::vector<ClasePersona> personas);

long buscarClasePersonaPatrimonioPorReferencia(const std::vector<ClasePersona>& personas);

long buscarStructPersonaPatrimonioPorValor(std::vector<StructPersona> personas);

long buscarStructPersonaPatrimonioPorReferencia(const std::vector<StructPersona>& personas);

long contarClasePersonaGrupoPorValor(std::vector<ClasePersona> personas);

long contarClasePersonaGrupoPorReferencia(const std::vector<ClasePersona>& personas);

long contarStructPersonaGrupoPorValor(std::vector<StructPersona> personas);

long contarStructPersonaGrupoPorReferencia(const std::vector<StructPersona>& personas);

long buscarClasePersonaCiudadMasPobladaPorValor(std::vector<ClasePersona> personas);

long buscarClasePersonaCiudadMasPobladaPorReferencia(const std::vector<ClasePersona>& personas);

long buscarStructPersonaCiudadMasPobladaPorValor(std::vector<StructPersona> personas);

long buscarStructPersonaCiudadMasPobladaPorReferencia(const std::vector<StructPersona>& personas);

long buscarClasePersonaEndeudadaPorValor(std::vector<ClasePersona> personas);

long buscarClasePersonaEndeudadaPorReferencia(const std::vector<ClasePersona>& personas);

long buscarStructPersonaEndeudadaPorValor(std::vector<StructPersona> personas);

long buscarStructPersonaEndeudadaPorReferencia(const std::vector<StructPersona>& personas);

long buscarClasePersonaPorcentajeIngresosAltosPorValor(std::vector<ClasePersona> personas);

long buscarClasePersonaPorcentajeIngresosAltosPorReferencia(const std::vector<ClasePersona>& personas);

long buscarStructPersonaPorcentajeIngresosAltosPorValor(std::vector<StructPersona> personas);

long buscarStructPersonaPorcentajeIngresosAltosPorReferencia(const std::vector<StructPersona>& personas);

#endif