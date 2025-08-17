#include <iostream>
#include <vector>
#include <limits>
#include <memory>
#include <unordered_map>
#include "./Includes/ClasePersona/ClasePersona.h"
#include "./Includes/StructPersona/StructPersona.h"
#include "./Includes/Generador/generador.h"
#include "./Includes/Monitor/Monitor.h"
#include "./Includes/Busqueda/busqueda.h"

#include <chrono>

/**
 * Muestra el menú principal de la aplicación.
 * 
 * POR QUÉ: Guiar al usuario a través de las funcionalidades disponibles.
 * CÓMO: Imprimiendo las opciones en consola.
 * PARA QUÉ: Interacción amigable con el usuario.
 */
void mostrarMenu() {
    std::cout << "\n\n=== MENÚ PRINCIPAL ===";
    std::cout << "\n0. Crear nuevo conjunto de datos";
    std::cout << "\n1. Mostrar resumen de todas las personas";
    std::cout << "\n2. Mostrar detalle completo por índice";
    std::cout << "\n3. Realizar Busquedas";
    std::cout << "\n4. Mostrar estadísticas de rendimiento";
    std::cout << "\n5. Exportar estadísticas a CSV";
    std::cout << "\n6. Salir";
    std::cout << "\nSeleccione una opción: ";
}


/**
 * Punto de entrada principal del programa.
 * 
 * POR QUÉ: Iniciar la aplicación y manejar el flujo principal.
 * CÓMO: Mediante un bucle que muestra el menú y procesa la opción seleccionada.
 * PARA QUÉ: Ejecutar las funcionalidades del sistema.
 */
int main() {
    try{
    srand(time(nullptr)); // Semilla para generación aleatoria
    
    // Puntero inteligente para gestionar la colección de personas
    // POR QUÉ: Evitar fugas de memoria y garantizar liberación automática.
    std::unique_ptr<std::vector<StructPersona>> personas = nullptr;
    
    Monitor monitor; // Monitor para medir rendimiento
    
    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;
        
        // Variables locales para uso en los casos
        size_t tam = 0;
        int indice;
        std::string idBusqueda;
        
        // Iniciar medición de tiempo y memoria para la operación actual
        
        switch(opcion) {
            case 0: { // Crear nuevo conjunto de datos
                int n;
                std::cout << "\nIngrese el número de personas a generar: ";
                std::cin >> n;
                
                if (n <= 0) {
                    std::cout << "Error: Debe generar al menos 1 persona\n";
                    break;
                }

                std::cout << "Numero de personas ingresado con exito\n";
                
                // Generar el nuevo conjunto de personas
                auto nuevasPersonas = generarColeccion(n);
                tam = nuevasPersonas.size();
                
                // Mover el conjunto al puntero inteligente (propiedad única)
                personas = std::make_unique<std::vector<StructPersona>>(std::move(nuevasPersonas));



                auto inicio1 = std::chrono::high_resolution_clock::now();
                std::unordered_map mapaPersonas1 = buscarStructPersonaLongevaPorValor(*personas);
                auto fin1 = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> duracion1 = fin1 - inicio1;
                

                auto inicio2 = std::chrono::high_resolution_clock::now();
                std::unordered_map mapaPersonas2 = buscarStructPersonaLongevaPorReferencia(*personas);
                auto fin2 = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> duracion2 = fin2 - inicio2;
                std::cout << "Tiempo transcurrido 1: " << duracion1.count() << " ms\n";
                std::cout << "Tiempo transcurrido 2: " << duracion2.count() << " ms\n";

                auto inicio3 = std::chrono::high_resolution_clock::now();
                std::unordered_map mapaPersonas3 = buscarStructPersonaPatrimonioPorValor(*personas);
                auto fin3 = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> duracion3 = fin3 - inicio3;

                auto inicio4 = std::chrono::high_resolution_clock::now();
                std::unordered_map mapaPersonas4 = buscarStructPersonaPatrimonioPorReferencia(*personas);
                auto fin4 = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> duracion4 = fin4 - inicio4;
                std::cout << "Tiempo transcurrido 3: " << duracion3.count() << " ms\n";
                std::cout << "Tiempo transcurrido 4: " << duracion4.count() << " ms\n";

                auto inicio5 = std::chrono::high_resolution_clock::now();
                std::unordered_map mapaPersonas5 = contarStructPersonaGrupoPorValor(*personas);
                auto fin5 = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> duracion5 = fin5 - inicio5;

                auto inicio6 = std::chrono::high_resolution_clock::now();
                std::unordered_map mapaPersonas6 = contarStructPersonaGrupoPorValor(*personas);
                auto fin6 = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> duracion6 = fin6 - inicio6;
                std::cout << "Tiempo transcurrido 5: " << duracion5.count() << " ms\n";
                std::cout << "Tiempo transcurrido 6: " << duracion6.count() << " ms\n";

                auto inicio7 = std::chrono::high_resolution_clock::now();
                std::string ciudadMasPoblada1 = buscarStructPersonaCiudadMasPobladaPorValor(*personas);
                auto fin7 = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> duracion7 = fin7 - inicio7;

                auto inicio8 = std::chrono::high_resolution_clock::now();
                std::string ciudadMasPoblada2 = buscarStructPersonaCiudadMasPobladaPorReferencia(*personas);
                auto fin8 = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> duracion8 = fin8 - inicio8;
                std::cout << "Tiempo transcurrido 7: " << duracion7.count() << " ms\n";
                std::cout << "Tiempo transcurrido 8: " << duracion8.count() << " ms\n";

                auto inicio9 = std::chrono::high_resolution_clock::now();
                std::unordered_map mapaPersonas7 = buscarStructPersonaEndeudadaPorReferencia(*personas);
                auto fin9 = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> duracion9 = fin9 - inicio9;

                auto inicio10 = std::chrono::high_resolution_clock::now();
                std::unordered_map mapaPersonas8 = buscarStructPersonaEndeudadaPorReferencia(*personas);
                auto fin10 = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> duracion10 = fin10 - inicio10;
                std::cout << "Tiempo transcurrido 9: " << duracion9.count() << " ms\n";
                std::cout << "Tiempo transcurrido 10: " << duracion10.count() << " ms\n";

                auto inicio11 = std::chrono::high_resolution_clock::now();
                float porcentaje1 = buscarStructPersonaPorcentajeIngresosAltosPorValor(*personas);
                auto fin11 = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> duracion11 = fin11 - inicio11;

                auto inicio12 = std::chrono::high_resolution_clock::now();
                float porcentaje2 = buscarStructPersonaPorcentajeIngresosAltosPorReferencia(*personas);
                auto fin12 = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> duracion12 = fin12 - inicio12;
                std::cout << "Tiempo transcurrido 11: " << duracion11.count() << " ms\n";
                std::cout << "Tiempo transcurrido 12: " << duracion12.count() << " ms\n";

                break;
            }
                
            case 1: { // Mostrar resumen de todas las personas
                if (!personas || personas->empty()) {
                    std::cout << "\nNo hay datos disponibles. Use opción 0 primero.\n";
                    break;
                }
                
                tam = personas->size();
                std::cout << "\n=== RESUMEN DE PERSONAS (" << tam << ") ===\n";
                for(size_t i = 0; i < tam; ++i) {
                    std::cout << i << ". ";
                    (*personas)[i].mostrarResumen();
                    std::cout << "\n";
                }
                
                break;
            }
                
            case 2: { // Mostrar detalle por índice
                if (!personas || personas->empty()) {
                    std::cout << "\nNo hay datos disponibles. Use opción 0 primero.\n";
                    break;
                }
                
                tam = personas->size();
                std::cout << "\nIngrese el índice (0-" << tam-1 << "): ";
                if(std::cin >> indice) {
                    if(indice >= 0 && static_cast<size_t>(indice) < tam) {
                        (*personas)[indice].mostrar();
                    } else {
                        std::cout << "Índice fuera de rango!\n";
                    }
                } else {
                    std::cout << "Entrada inválida!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                
                break;
            }
                
            case 3: { // Buscar por ID
                if (!personas || personas->empty()) {
                    std::cout << "\nNo hay datos disponibles. Use opción 0 primero.\n";
                    break;
                }
                
                std::cout << "\nIngrese el ID a buscar: ";
                std::cin >> idBusqueda;
                /*
                if(const ClasePersona* encontrada = buscarPorID(*personas, idBusqueda)) {
                    encontrada->mostrar();
                } else {
                    std::cout << "No se encontró persona con ID " << idBusqueda << "\n";
                }*/
                
                break;
            }
                
            case 4: // Mostrar estadísticas de rendimiento
                break;
                
            case 5: // Exportar estadísticas a CSV
                break;
                
            case 6: // Salir
                std::cout << "Saliendo...\n";
                break;
                
            default:
                std::cout << "Opción inválida!\n";
        }
        
        // Mostrar estadísticas de la operación (excepto para opciones 4,5,6)
        
    } while(opcion != 6);}
    catch (const std::out_of_range& ex) {
        std::cerr << "¡Excepción capturada! out_of_range: " << ex.what() << "\n";
        return EXIT_FAILURE;
    }

    return 0;
}