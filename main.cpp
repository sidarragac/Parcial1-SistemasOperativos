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
    std::cout << "\n2. Realizar Busquedas por Clase y Valor";
    std::cout << "\n3. Realizar Busquedas por Clase y Referencia";
    std::cout << "\n4. Realizar Busquedas por Struct y Valor";
    std::cout << "\n5. Realizar Busquedas por Struct y Referencia";
    std::cout << "\n6. Mostrar Estadisticas";
    std::cout << "\n7. Salir";
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

    Monitor monitor; // Monitor para medir rendimiento

    int opcion;
    double tiempo;
    long memoriaInicial;
    long memoria;
    bool generated = false;
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
                generarColeccion(n);
                generated = true;
                break; 
            }
            case 1: { // Mostrar resumen de todas las personas
                std::vector<ClasePersona> personasClases = cargarColeccionClase();
                tam = personasClases.size();

                std::unique_ptr<std::vector<ClasePersona>> ptr_personasClases = std::make_unique<std::vector<ClasePersona>>(std::move(personasClases));

                if (!ptr_personasClases || ptr_personasClases->empty()) {
                    std::cout << "\nNo hay datos disponibles. Use opción 0 primero.\n";
                    break;
                }

                std::cout << "\n=== RESUMEN DE PERSONAS (" << tam << ") ===\n";
                for(size_t i = 0; i < tam; ++i) {
                    std::cout << i << ". ";
                    (*ptr_personasClases)[i].mostrarResumen();
                    std::cout << "\n";
                }
                break;
            }
            case 2: { // Realizar busquedas por clase y valor

                if (!generated) {
                    std::cout << "\nNo hay datos disponibles. Use opción 0 primero.\n";
                    break;
                }

                std::vector<ClasePersona> personasClases = cargarColeccionClase();
                tam = personasClases.size();

                std::unique_ptr<std::vector<ClasePersona>> ptr_personasClases = std::make_unique<std::vector<ClasePersona>>(std::move(personasClases));

                // Busqueda de persona más longeva por valor y clase
                std::cout << "\n--- Busqueda: Persona Longeva por Clase y Valor ---\n";
                monitor.iniciar_tiempo();
                memoriaInicial = monitor.obtener_memoria();
                buscarClasePersonaLongevaPorValor(*ptr_personasClases);
                tiempo = monitor.detener_tiempo();
                memoria = monitor.obtener_memoria() - memoriaInicial;
                monitor.registrar("Persona Longeva por Clase y Valor", tiempo, memoria);
                monitor.mostrar_estadistica("Persona Longeva por Clase y Valor", tiempo, memoria);

                // Busqueda de persona con mayor patrimonio por valor y clase
                std::cout << "\n--- Busqueda: Persona Mayor Patrimonio por Clase y Valor ---\n";
                monitor.iniciar_tiempo();
                memoriaInicial = monitor.obtener_memoria();
                buscarClasePersonaPatrimonioPorValor(*ptr_personasClases);
                tiempo = monitor.detener_tiempo();
                memoria = monitor.obtener_memoria() - memoriaInicial;
                monitor.registrar("Persona Mayor Patrimonio por Clase y Valor", tiempo, memoria);
                monitor.mostrar_estadistica("Persona Mayor Patrimonio por Clase y Valor", tiempo, memoria);

                // Contar grupos por valor y clase
                std::cout << "\n--- Busqueda: Contar grupos por Clase y Valor ---\n";
                monitor.iniciar_tiempo();
                memoriaInicial = monitor.obtener_memoria();
                contarClasePersonaGrupoPorValor(*ptr_personasClases);
                tiempo = monitor.detener_tiempo();
                memoria = monitor.obtener_memoria() - memoriaInicial;
                monitor.registrar("Contar grupos por Clase y Valor", tiempo, memoria);
                monitor.mostrar_estadistica("Contar grupos por Clase y Valor", tiempo, memoria);

                // Ciudad mayor número de personas
                std::cout << "\n--- Busqueda: Ciudad más poblada Clase y Valor ---\n";
                monitor.iniciar_tiempo();
                memoriaInicial = monitor.obtener_memoria();
                buscarClasePersonaCiudadMasPobladaPorValor(*ptr_personasClases);
                tiempo = monitor.detener_tiempo();
                memoria = monitor.obtener_memoria() - memoriaInicial;
                monitor.registrar("Ciudad más poblada Clase y Valor", tiempo, memoria);
                monitor.mostrar_estadistica("Ciudad más poblada Clase y Valor", tiempo, memoria);

                // Persona con más deuda
                std::cout << "\n--- Busqueda: Persona más endeudada Clase y Valor ---\n";
                monitor.iniciar_tiempo();
                memoriaInicial = monitor.obtener_memoria();
                buscarClasePersonaEndeudadaPorValor(*ptr_personasClases);
                tiempo = monitor.detener_tiempo();
                memoria = monitor.obtener_memoria() - memoriaInicial;
                monitor.registrar("Persona más endeudada Clase y Valor", tiempo, memoria);
                monitor.mostrar_estadistica("Persona más endeudada Clase y Valor", tiempo, memoria);
                
                // Porcentaje de personas con ingresos mayores a 400M
                std::cout << "\n--- Busqueda: Persona con ingresos mayores a 400M Clase y Valor ---\n";
                monitor.iniciar_tiempo();
                memoriaInicial = monitor.obtener_memoria();
                buscarClasePersonaPorcentajeIngresosAltosPorValor(*ptr_personasClases);
                tiempo = monitor.detener_tiempo();
                memoria = monitor.obtener_memoria() - memoriaInicial;
                monitor.registrar("Persona con ingresos mayores a 400M Clase y Valor", tiempo, memoria);
                monitor.mostrar_estadistica("Persona con ingresos mayores a 400M Clase y Valor", tiempo, memoria);
                break;
            }

            case 3: { // Busquedas por clase y referencia
                if (!generated) {
                    std::cout << "\nNo hay datos disponibles. Use opción 0 primero.\n";
                    break;
                }

                std::vector<ClasePersona> personasClases = cargarColeccionClase();
                tam = personasClases.size();

                std::unique_ptr<std::vector<ClasePersona>> ptr_personasClases = std::make_unique<std::vector<ClasePersona>>(std::move(personasClases));

                // Busqueda de persona más longeva por valor y referencia
                std::cout << "\n--- Busqueda: Persona Longeva por Clase y Referencia ---\n";
                monitor.iniciar_tiempo();
                memoriaInicial = monitor.obtener_memoria();
                buscarClasePersonaLongevaPorReferencia(*ptr_personasClases);
                tiempo = monitor.detener_tiempo();
                memoria = monitor.obtener_memoria() - memoriaInicial;
                monitor.registrar("Persona Longeva por Clase y Referencia", tiempo, memoria);
                monitor.mostrar_estadistica("Persona Longeva por Clase y Referencia", tiempo, memoria);

                // Busqueda de persona con mayor patrimonio por valor y referencia
                std::cout << "\n--- Busqueda: Persona Mayor Patrimonio por Clase y Referencia ---\n";
                monitor.iniciar_tiempo();
                memoriaInicial = monitor.obtener_memoria();
                buscarClasePersonaPatrimonioPorReferencia(*ptr_personasClases);
                tiempo = monitor.detener_tiempo();
                memoria = monitor.obtener_memoria() - memoriaInicial;
                monitor.registrar("Persona Mayor Patrimonio por Clase y Referencia", tiempo, memoria);
                monitor.mostrar_estadistica("Persona Mayor Patrimonio por Clase y Referencia", tiempo, memoria);

                // Contar grupos por valor y referencia
                std::cout << "\n--- Busqueda: Contar grupos por Clase y Referencia ---\n";
                monitor.iniciar_tiempo();
                memoriaInicial = monitor.obtener_memoria();
                contarClasePersonaGrupoPorReferencia(*ptr_personasClases);
                tiempo = monitor.detener_tiempo();
                memoria = monitor.obtener_memoria() - memoriaInicial;
                monitor.registrar("Contar grupos por Clase y Referencia", tiempo, memoria);
                monitor.mostrar_estadistica("Contar grupos por Clase y Referencia", tiempo, memoria);

                // Ciudad mayor número de personas valor y referencia
                std::cout << "\n--- Busqueda: Ciudad más poblada Clase y Referencia ---\n";
                monitor.iniciar_tiempo();
                memoriaInicial = monitor.obtener_memoria();
                buscarClasePersonaCiudadMasPobladaPorReferencia(*ptr_personasClases);
                tiempo = monitor.detener_tiempo();
                memoria = monitor.obtener_memoria() - memoriaInicial;
                monitor.registrar("Ciudad más poblada Clase y Referencia", tiempo, memoria);
                monitor.mostrar_estadistica("Ciudad más poblada Clase y Referencia", tiempo, memoria);

                // Persona con más deuda
                std::cout << "\n--- Busqueda: Persona más endeudada Clase y Referencia ---\n";
                monitor.iniciar_tiempo();
                memoriaInicial = monitor.obtener_memoria();
                buscarClasePersonaEndeudadaPorReferencia(*ptr_personasClases);
                tiempo = monitor.detener_tiempo();
                memoria = monitor.obtener_memoria() - memoriaInicial;
                monitor.registrar("Persona más endeudada Clase y Referencia", tiempo, memoria);
                monitor.mostrar_estadistica("Persona más endeudada Clase y Referencia", tiempo, memoria);

                // Porcentaje de personas con ingresos mayores a 400M
                std::cout << "\n--- Busqueda: Persona con ingresos mayores a 400M Clase y Referencia ---\n";
                monitor.iniciar_tiempo();
                memoriaInicial = monitor.obtener_memoria();
                buscarClasePersonaPorcentajeIngresosAltosPorReferencia(*ptr_personasClases);
                tiempo = monitor.detener_tiempo();
                memoria = monitor.obtener_memoria() - memoriaInicial;
                monitor.registrar("Persona con ingresos mayores a 400M Clase y Referencia", tiempo, memoria);
                monitor.mostrar_estadistica("Persona con ingresos mayores a 400M Clase y Referencia", tiempo, memoria);

                break;
            }

            case 4: { // Busquedas por struct y valor
                if (!generated) {
                    std::cout << "\nNo hay datos disponibles. Use opción 0 primero.\n";
                    break;
                }

                std::vector<StructPersona> personasStructs = cargarColeccionStruct();
                tam = personasStructs.size();

                std::unique_ptr<std::vector<StructPersona>> ptr_personasStructs = std::make_unique<std::vector<StructPersona>>(std::move(personasStructs));

                // Búsqueda de persona más longeva por valor y struct
                std::cout << "\n--- Busqueda: Persona Longeva por Struct y Valor ---\n";
                monitor.iniciar_tiempo();
                memoriaInicial = monitor.obtener_memoria();
                buscarStructPersonaLongevaPorValor(*ptr_personasStructs);
                tiempo = monitor.detener_tiempo();
                memoria = monitor.obtener_memoria() - memoriaInicial;
                monitor.registrar("Persona Longeva por Struct y Valor", tiempo, memoria);
                monitor.mostrar_estadistica("Persona Longeva por Struct y Valor", tiempo, memoria);

                // Búsqueda de persona con mayor patrimonio por valor y struct
                std::cout << "\n--- Busqueda: Persona Mayor Patrimonio por Struct y Valor ---\n";
                monitor.iniciar_tiempo();
                memoriaInicial = monitor.obtener_memoria();
                buscarStructPersonaPatrimonioPorValor(*ptr_personasStructs);
                tiempo = monitor.detener_tiempo();
                memoria = monitor.obtener_memoria() - memoriaInicial;
                monitor.registrar("Persona Mayor Patrimonio por Struct y Valor", tiempo, memoria);
                monitor.mostrar_estadistica("Persona Mayor Patrimonio por Struct y Valor", tiempo, memoria);

                // Contar grupos por valor y struct
                std::cout << "\n--- Busqueda: Contar grupos por Struct y Valor ---\n";
                monitor.iniciar_tiempo();
                memoriaInicial = monitor.obtener_memoria();
                contarStructPersonaGrupoPorValor(*ptr_personasStructs);
                tiempo = monitor.detener_tiempo();
                memoria = monitor.obtener_memoria() - memoriaInicial;
                monitor.registrar("Contar grupos por Struct y Valor", tiempo, memoria);
                monitor.mostrar_estadistica("Contar grupos por Struct y Valor", tiempo, memoria);

                // Ciudad con mayor número de personas por struct
                std::cout << "\n--- Busqueda: Ciudad más poblada Struct y Valor ---\n";
                monitor.iniciar_tiempo();
                memoriaInicial = monitor.obtener_memoria();
                buscarStructPersonaCiudadMasPobladaPorValor(*ptr_personasStructs);
                tiempo = monitor.detener_tiempo();
                memoria = monitor.obtener_memoria() - memoriaInicial;
                monitor.registrar("Ciudad más poblada Struct y Valor", tiempo, memoria);
                monitor.mostrar_estadistica("Ciudad más poblada Struct y Valor", tiempo, memoria);

                // Persona con más deuda por struct
                std::cout << "\n--- Busqueda: Persona más endeudada Struct y Valor ---\n";
                monitor.iniciar_tiempo();
                memoriaInicial = monitor.obtener_memoria();
                buscarStructPersonaEndeudadaPorValor(*ptr_personasStructs);
                tiempo = monitor.detener_tiempo();
                memoria = monitor.obtener_memoria() - memoriaInicial;
                monitor.registrar("Persona más endeudada Struct y Valor", tiempo, memoria);
                monitor.mostrar_estadistica("Persona más endeudada Struct y Valor", tiempo, memoria);

                // Porcentaje de personas con ingresos mayores a 400M por struct
                std::cout << "\n--- Busqueda: Persona con ingresos mayores a 400M Struct y Valor ---\n";
                monitor.iniciar_tiempo();
                memoriaInicial = monitor.obtener_memoria();
                buscarStructPersonaPorcentajeIngresosAltosPorValor(*ptr_personasStructs);
                tiempo = monitor.detener_tiempo();
                memoria = monitor.obtener_memoria() - memoriaInicial;
                monitor.registrar("Persona con ingresos mayores a 400M Struct y Valor", tiempo, memoria);
                monitor.mostrar_estadistica("Persona con ingresos mayores a 400M Struct y Valor", tiempo, memoria);

                break;
            }

            case 5: {// Busquedas por struct y referencia
                if (!generated) {
                    std::cout << "\nNo hay datos disponibles. Use opción 0 primero.\n";
                    break;
                }

                std::vector<StructPersona> personasStructs = cargarColeccionStruct();
                tam = personasStructs.size();

                std::unique_ptr<std::vector<StructPersona>> ptr_personasStructs = std::make_unique<std::vector<StructPersona>>(std::move(personasStructs));

                // Búsqueda de persona más longeva por referencia y struct
                std::cout << "\n--- Busqueda: Persona Longeva por Struct y Referencia ---\n";
                monitor.iniciar_tiempo();
                memoriaInicial = monitor.obtener_memoria();
                buscarStructPersonaLongevaPorReferencia(*ptr_personasStructs);
                tiempo = monitor.detener_tiempo();
                memoria = monitor.obtener_memoria() - memoriaInicial;
                monitor.registrar("Persona Longeva por Struct y Referencia", tiempo, memoria);
                monitor.mostrar_estadistica("Persona Longeva por Struct y Referencia", tiempo, memoria);

                // Búsqueda de persona con mayor patrimonio por referencia y struct
                std::cout << "\n--- Busqueda: Persona Mayor Patrimonio por Struct y Referencia ---\n";
                monitor.iniciar_tiempo();
                memoriaInicial = monitor.obtener_memoria();
                buscarStructPersonaPatrimonioPorReferencia(*ptr_personasStructs);
                tiempo = monitor.detener_tiempo();
                memoria = monitor.obtener_memoria() - memoriaInicial;
                monitor.registrar("Persona Mayor Patrimonio por Struct y Referencia", tiempo, memoria);
                monitor.mostrar_estadistica("Persona Mayor Patrimonio por Struct y Referencia", tiempo, memoria);

                // Contar grupos por referencia y struct
                std::cout << "\n--- Busqueda: Contar grupos por Struct y Referencia ---\n";
                monitor.iniciar_tiempo();
                memoriaInicial = monitor.obtener_memoria();
                contarStructPersonaGrupoPorReferencia(*ptr_personasStructs);
                tiempo = monitor.detener_tiempo();
                memoria = monitor.obtener_memoria() - memoriaInicial;
                monitor.registrar("Contar grupos por Struct y Referencia", tiempo, memoria);
                monitor.mostrar_estadistica("Contar grupos por Struct y Referencia", tiempo, memoria);

                // Ciudad con mayor número de personas por referencia y struct
                std::cout << "\n--- Busqueda: Ciudad más poblada Struct y Referencia ---\n";
                monitor.iniciar_tiempo();
                memoriaInicial = monitor.obtener_memoria();
                buscarStructPersonaCiudadMasPobladaPorReferencia(*ptr_personasStructs);
                tiempo = monitor.detener_tiempo();
                memoria = monitor.obtener_memoria() - memoriaInicial;
                monitor.registrar("Ciudad más poblada Struct y Referencia", tiempo, memoria);
                monitor.mostrar_estadistica("Ciudad más poblada Struct y Referencia", tiempo, memoria);

                // Persona con más deuda por referencia y struct
                std::cout << "\n--- Busqueda: Persona más endeudada Struct y Referencia ---\n";
                monitor.iniciar_tiempo();
                memoriaInicial = monitor.obtener_memoria();
                buscarStructPersonaEndeudadaPorReferencia(*ptr_personasStructs);
                tiempo = monitor.detener_tiempo();
                memoria = monitor.obtener_memoria() - memoriaInicial;
                monitor.registrar("Persona más endeudada Struct y Referencia", tiempo, memoria);
                monitor.mostrar_estadistica("Persona más endeudada Struct y Referencia", tiempo, memoria);

                // Porcentaje de personas con ingresos mayores a 400M por referencia y struct
                std::cout << "\n--- Busqueda: Persona con ingresos mayores a 400M Struct y Referencia ---\n";
                monitor.iniciar_tiempo();
                memoriaInicial = monitor.obtener_memoria();
                buscarStructPersonaPorcentajeIngresosAltosPorReferencia(*ptr_personasStructs);
                tiempo = monitor.detener_tiempo();
                memoria = monitor.obtener_memoria() - memoriaInicial;
                monitor.registrar("Persona con ingresos mayores a 400M Struct y Referencia", tiempo, memoria);
                monitor.mostrar_estadistica("Persona con ingresos mayores a 400M Struct y Referencia", tiempo, memoria);

                break;
            }

            case 6: { // Mostrar estadísticas
                monitor.mostrar_resumen();
                break;
            }

            case 7: { // Salir
                std::cout << "Saliendo...\n";
                break;
            }

            default:
                std::cout << "Opción inválida!\n";
        }

        // Mostrar estadísticas de la operación (excepto para opciones 4,5,6)

    } while(opcion != 7);}
    catch (const std::out_of_range& ex) {
        std::cerr << "¡Excepción capturada! out_of_range: " << ex.what() << "\n";
        return EXIT_FAILURE;
    }

    return 0;
}