#include "generador.h"
#include "../ClasePersona/ClasePersona.h"
#include "../StructPersona/StructPersona.h"
#include <cstdlib>
#include <ctime>
#include <random>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>

// Bases de datos para generación realista

// Nombres femeninos comunes en Colombia
const std::vector<std::string> nombresFemeninos = {
    "María", "Luisa", "Carmen", "Ana", "Sofía", "Isabel", "Laura", "Andrea", "Paula", "Valentina",
    "Camila", "Daniela", "Carolina", "Fernanda", "Gabriela", "Patricia", "Claudia", "Diana", "Lucía", "Ximena"
};

// Nombres masculinos comunes en Colombia
const std::vector<std::string> nombresMasculinos = {
    "Juan", "Carlos", "José", "James", "Andrés", "Miguel", "Luis", "Pedro", "Alejandro", "Ricardo",
    "Felipe", "David", "Jorge", "Santiago", "Daniel", "Fernando", "Diego", "Rafael", "Martín", "Óscar",
    "Edison", "Nestor", "Gertridis"
};

// Apellidos comunes en Colombia
const std::vector<std::string> apellidos = {
    "Gómez", "Rodríguez", "Martínez", "López", "García", "Pérez", "González", "Sánchez", "Ramírez", "Torres",
    "Díaz", "Vargas", "Castro", "Ruiz", "Álvarez", "Romero", "Suárez", "Rojas", "Moreno", "Muñoz", "Valencia",
};

// Principales ciudades colombianas
const std::vector<std::string> ciudadesColombia = {
    "Bogotá", "Medellín", "Cali", "Barranquilla", "Cartagena", "Bucaramanga", "Pereira", "Santa Marta", "Cúcuta", "Ibagué",
    "Manizales", "Pasto", "Neiva", "Villavicencio", "Armenia", "Sincelejo", "Valledupar", "Montería", "Popayán", "Tunja"
};

/**
 * Implementación de generarFechaNacimiento.
 * 
 * POR QUÉ: Simular fechas de nacimiento realistas.
 * CÓMO: Día (1-28), mes (1-12), año (1960-2009).
 * PARA QUÉ: Atributo fechaNacimiento de Persona.
 */
std::string generarFechaNacimiento() {
    int dia = 1 + rand() % 28;       // Día: 1 a 28 (evita problemas con meses)
    int mes = 1 + rand() % 12;        // Mes: 1 a 12
    int anio = 1960 + rand() % 50;    // Año: 1960 a 2009
    return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio);
}

/**
 * Implementación de generarID.
 * 
 * POR QUÉ: Generar identificadores únicos y secuenciales.
 * CÓMO: Contador estático que inicia en 1000000000 y se incrementa.
 * PARA QUÉ: Simular números de cédula.
 */
std::string generarID() {
    static long contador = 1000000000; // Inicia en 1,000,000,000
    return std::to_string(contador++); // Convierte a string e incrementa
}

/**
 * Implementación de randomDouble.
 * 
 * POR QUÉ: Generar números decimales aleatorios en un rango.
 * CÓMO: Mersenne Twister (mejor que rand()) y distribución uniforme.
 * PARA QUÉ: Valores de ingresos, patrimonio, etc.
 */
double randomDouble(double min, double max) {
    static std::mt19937 generator(time(nullptr)); // Semilla basada en tiempo
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(generator);
}

std::string generarDatos(){
    std::string csv;
    // Decide si es hombre o mujer
    bool esHombre = rand() % 2;

    // Selecciona nombre según género
    std::string nombre = esHombre ? 
        nombresMasculinos[rand() % nombresMasculinos.size()] :
        nombresFemeninos[rand() % nombresFemeninos.size()];
    
    // Construye apellido compuesto (dos apellidos aleatorios)
    std::string apellido = apellidos[rand() % apellidos.size()];
    apellido += " ";
    apellido += apellidos[rand() % apellidos.size()];

    csv += nombre + "," + apellido + ",";

    // Genera los demás atributos
    std::string id = generarID();
    std::string ciudad = ciudadesColombia[rand() % ciudadesColombia.size()];
    std::string fecha = generarFechaNacimiento();
    
    csv += id + "," + ciudad + "," + fecha + ",";

    // Genera datos financieros realistas
    double ingresos = randomDouble(10000000, 500000000);   // 10M a 500M COP
    double patrimonio = randomDouble(0, 2000000000);       // 0 a 2,000M COP
    double deudas = randomDouble(0, patrimonio * 0.7);     // Deudas hasta el 70% del patrimonio
    bool declarante = (ingresos > 50000000) && (rand() % 100 > 30); // Probabilidad 70% si ingresos > 50M
    
    csv += std::to_string(ingresos) + "," + 
           std::to_string(patrimonio) + "," + 
           std::to_string(deudas) + "," + 
           (declarante ? "1" : "0") + "\n"; // 1 si declarante, 0 si no

    return csv;
}

/**
 * Implementación de generarColeccion.
 * 
 * POR QUÉ: Generar un conjunto de n personas.
 * CÓMO: Reservando espacio y agregando n personas generadas.
 * PARA QUÉ: Crear datasets para pruebas.
 */
void generarColeccion(int n) {
    // Abrir archivo .csv
    std::ofstream archivo("personas.csv");
    if(!archivo) {
        std::cerr << "Error al abrir el archivo para escribir." << std::endl;
        return;
    }
    
    archivo << "nombre,apellido,id,ciudad,fechaNacimiento,ingresos,patrimonio,deudas,declarante" << std::endl;
    for (int i = 0; i < n; i++){
        std::string csv = generarDatos();
        archivo << csv;
    }

    archivo.close();
}

ClasePersona agregarClasePersona(std::string datos){
    std::stringstream ss(datos);
    std::string nombre, apellido, id, ciudad, fechaNacimiento, ingresosStr, patrimonioStr, deudasStr, declaranteStr;

    std::getline(ss, nombre, ',');
    std::getline(ss, apellido, ',');
    std::getline(ss, id, ',');
    std::getline(ss, ciudad, ',');
    std::getline(ss, fechaNacimiento, ',');
    std::getline(ss, ingresosStr, ',');
    std::getline(ss, patrimonioStr, ',');
    std::getline(ss, deudasStr, ',');
    std::getline(ss, declaranteStr, ',');

    double ingresos = std::stod(ingresosStr);
    double patrimonio = std::stod(patrimonioStr);
    double deudas = std::stod(deudasStr);
    bool declarante = (declaranteStr == "1");

    return ClasePersona(nombre, apellido, id, ciudad, fechaNacimiento, ingresos, patrimonio, deudas, declarante);
};

StructPersona agregarStructPersona(std::string datos){
    std::stringstream ss(datos);
    std::string nombre, apellido, id, ciudad, fechaNacimiento, ingresosStr, patrimonioStr, deudasStr, declaranteStr;

    std::getline(ss, nombre, ',');
    std::getline(ss, apellido, ',');
    std::getline(ss, id, ',');
    std::getline(ss, ciudad, ',');
    std::getline(ss, fechaNacimiento, ',');
    std::getline(ss, ingresosStr, ',');
    std::getline(ss, patrimonioStr, ',');
    std::getline(ss, deudasStr, ',');
    std::getline(ss, declaranteStr, ',');

    double ingresos = std::stod(ingresosStr);
    double patrimonio = std::stod(patrimonioStr);
    double deudas = std::stod(deudasStr);
    bool declarante = (declaranteStr == "1");
    
    StructPersona p;
    p.nombre = nombre;
    p.apellido = apellido;
    p.id = id;
    p.ciudadNacimiento = ciudad;
    p.fechaNacimiento = fechaNacimiento;
    p.ingresosAnuales = ingresos;
    p.patrimonio = patrimonio;
    p.deudas = deudas;
    p.declaranteRenta = declarante;
    p.calcularGrupo();

    return p;
}

std::vector<ClasePersona> cargarColeccionClase() {
    std::ifstream archivo("personas.csv");
    if(!archivo){
        std::cerr << "Error al abrir el archivo para lectura." << std::endl;
        return {};
    }

    std::vector<ClasePersona> personas;
    std::string linea;

    bool primeraLinea = true;
    while (std::getline(archivo, linea)) {
        if (primeraLinea) {
            primeraLinea = false;
            continue;
        }

        ClasePersona p = agregarClasePersona(linea);
        personas.push_back(p);
    }

    archivo.close();

    return personas;
}

std::vector<StructPersona> cargarColeccionStruct() {
    std::ifstream archivo("personas.csv");
    if(!archivo){
        std::cerr << "Error al abrir el archivo para lectura." << std::endl;
        return {};
    }

    std::vector<StructPersona> personas;
    std::string linea;

    bool primeraLinea = true;
    while (std::getline(archivo, linea)) {
        if (primeraLinea) {
            primeraLinea = false;
            continue;
        }

        StructPersona p = agregarStructPersona(linea);
        personas.push_back(p);
    }

    archivo.close();

    return personas;
}