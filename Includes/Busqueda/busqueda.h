#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <string>
#include <iostream>
#include <unordered_map>
#include "../ClasePersona/ClasePersona.h"

int calcularEdad(const std::string& fechaNacimiento);

std::unordered_map<std::string, ClasePersona> buscarClasePersonaLongevaPorValor(std::vector<ClasePersona> personas);

std::unordered_map<std::string, const ClasePersona*> buscarClasePersonaLongevaPorReferencia(const std::vector<ClasePersona>& personas);

std::unordered_map<std::string, StructPersona> buscarStructPersonaLongevaPorValor(std::vector<StructPersona> personas);

std::unordered_map<std::string, const StructPersona*> buscarStructPersonaLongevaPorReferencia(const std::vector<StructPersona>& personas);

std::unordered_map<std::string, ClasePersona> buscarClasePersonaPatrimonioPorValor(std::vector<ClasePersona> personas);

std::unordered_map<std::string, const ClasePersona*> buscarClasePersonaPatrimonioPorReferencia(const std::vector<ClasePersona>& personas);

std::unordered_map<std::string, StructPersona> buscarStructPersonaPatrimonioPorValor(std::vector<StructPersona> personas);

std::unordered_map<std::string, const StructPersona*> buscarStructPersonaPatrimonioPorReferencia(const std::vector<StructPersona>& personas);

std::unordered_map<std::string, int> contarClasePersonaGrupoPorValor(std::vector<ClasePersona> personas);

std::unordered_map<std::string, int> contarClasePersonaGrupoPorReferencia(const std::vector<ClasePersona>& personas);

std::unordered_map<std::string, int> contarStructPersonaGrupoPorValor(std::vector<StructPersona> personas);

std::unordered_map<std::string, int> contarStructPersonaGrupoPorReferencia(const std::vector<StructPersona>& personas);

std::string buscarClasePersonaCiudadMasPobladaPorValor(std::vector<ClasePersona> personas);

std::string buscarClasePersonaCiudadMasPobladaPorReferencia(const std::vector<ClasePersona>& personas);

std::string buscarStructPersonaCiudadMasPobladaPorValor(std::vector<StructPersona> personas);

std::string buscarStructPersonaCiudadMasPobladaPorReferencia(const std::vector<StructPersona>& personas);

std::unordered_map<std::string, ClasePersona> buscarClasePersonaEndeudadaPorValor(std::vector<ClasePersona> personas);

std::unordered_map<std::string, const ClasePersona*> buscarClasePersonaEndeudadaPorReferencia(const std::vector<ClasePersona>& personas);

std::unordered_map<std::string, StructPersona> buscarStructPersonaEndeudadaPorValor(std::vector<StructPersona> personas);

std::unordered_map<std::string, const StructPersona*> buscarStructPersonaEndeudadaPorReferencia(const std::vector<StructPersona>& personas);

float buscarClasePersonaPorcentajeIngresosAltosPorValor(std::vector<ClasePersona> personas);

float buscarClasePersonaPorcentajeIngresosAltosPorReferencia(const std::vector<ClasePersona>& personas);

float buscarStructPersonaPorcentajeIngresosAltosPorValor(std::vector<StructPersona> personas);

float buscarStructPersonaPorcentajeIngresosAltosPorReferencia(const std::vector<StructPersona>& personas);

#endif