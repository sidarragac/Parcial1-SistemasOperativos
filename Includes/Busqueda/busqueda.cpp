#include "../ClasePersona/ClasePersona.h"
#include "../Generador/generador.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <sstream>

std::unordered_map<std::string, ClasePersona> buscarClasePersonaLongevaPorValor(std::vector<ClasePersona> personas) {
	// Se crea un map para guardar la persona mayor en todo el pais y por ciudad
	std::unordered_map<std::string, ClasePersona> mayores;

	ClasePersona personaInicial("nombre","apellido","000", "ciudad", "15/08/2025", 0, 0, 0, 0, false);

	mayores.emplace("Pais", personaInicial);

	for (std::string ciudad : ciudadesColombia){
		personaInicial.setCiudad(ciudad);
		mayores.emplace(ciudad, personaInicial);
	}

	for (const ClasePersona& p : personas) {
		auto itPais = mayores.find("Pais");
		if (itPais != mayores.end()) {
			if (p.getEdad() > itPais->second.getEdad()) {
				itPais->second = p;
			}
		} else {
			mayores.emplace("Pais", p);
		}

		const std::string& ciudad = p.getCiudadNacimiento();
		auto itCiudad = mayores.find(ciudad);
		if (itCiudad != mayores.end()) {
			if (p.getEdad() > itCiudad->second.getEdad()) {
				itCiudad->second = p;
			}
		} else {
			mayores.emplace(ciudad, p);
		}
	}

	for (const auto& par : mayores) {
        std::cout << par.first << " -> ";
        par.second.mostrar();
    }

	return mayores;
}

std::unordered_map<std::string, const ClasePersona*> buscarClasePersonaLongevaPorReferencia(const std::vector<ClasePersona>& personas) {
	// Se crea un map para guardar la persona mayor en todo el pais y por ciudad
	std::unordered_map<std::string, const ClasePersona*> mayores;

	const ClasePersona* personaInicial = &personas[0];
	mayores.emplace("Pais", personaInicial);

	for (const std::string& ciudad : ciudadesColombia) {
		mayores.emplace(ciudad, personaInicial);
	}

	for (const ClasePersona& p : personas) {
		// Encontrar el mas longevo por Pais
		auto itPais = mayores.find("Pais");
		if (itPais != mayores.end()) {
			if (p.getEdad() > itPais->second->getEdad()) {
				itPais->second = &p;
			}
		} else {
			mayores.emplace("Pais", &p);
		}

		// Encontrar el mas longevo por ciudad
		const std::string& ciudad = p.getCiudadNacimiento();
		auto itCiudad = mayores.find(ciudad);
		if (itCiudad != mayores.end()) {
			if (p.getEdad() > itCiudad->second->getEdad()) {
				itCiudad->second = &p;
			}
		} else {
			mayores.emplace(ciudad, &p);
		}
	}

	// Imprimir resultados
	for (const auto& par : mayores) {
		std::cout << par.first << " -> ";
		par.second->mostrar();
	}

	return mayores;
}

std::unordered_map<std::string, StructPersona> buscarStructPersonaLongevaPorValor(std::vector<StructPersona> personas) {
	// Se crea un map para guardar la persona mayor en todo el pais y por ciudad
	std::unordered_map<std::string, StructPersona> mayores;

	StructPersona personaInicial;
	personaInicial.fechaNacimiento = "15/08/2025";

	mayores.emplace("Pais", personaInicial);

	for (std::string ciudad : ciudadesColombia){
		personaInicial.ciudadNacimiento = ciudad;
		mayores.emplace(ciudad, personaInicial);
	}

	for (const StructPersona& p : personas) {
		auto itPais = mayores.find("Pais");
		if (itPais != mayores.end()) {
			if (p.edad > itPais->second.edad) {
				itPais->second = p;
			}
		} else {
			mayores.emplace("Pais", p);
		}

		const std::string& ciudad = p.ciudadNacimiento;
		auto itCiudad = mayores.find(ciudad);
		if (itCiudad != mayores.end()) {
			if (p.edad > itCiudad->second.edad) {
				itCiudad->second = p;
			}
		} else {
			mayores.emplace(ciudad, p);
		}
	}

	for (const auto& par : mayores) {
        std::cout << par.first << " -> ";
        par.second.mostrar();
    }

	return mayores;
}

std::unordered_map<std::string, const StructPersona*> buscarStructPersonaLongevaPorReferencia(const std::vector<StructPersona>& personas) {
	// Se crea un map para guardar la persona mayor en todo el pais y por ciudad
	std::unordered_map<std::string, const StructPersona*> mayores;

	const StructPersona* personaInicial = &personas[0];
	mayores.emplace("Pais", personaInicial);

	for (const std::string& ciudad : ciudadesColombia) {
		mayores.emplace(ciudad, personaInicial);
	}

	for (const StructPersona& p : personas) {
		// Encontrar el mas longevo por Pais
		auto itPais = mayores.find("Pais");
		if (itPais != mayores.end()) {
			if (p.edad > itPais->second->edad) {
				itPais->second = &p;
			}
		} else {
			mayores.emplace("Pais", &p);
		}

		// Encontrar el mas longevo por ciudad
		const std::string& ciudad = p.ciudadNacimiento;
		auto itCiudad = mayores.find(ciudad);
		if (itCiudad != mayores.end()) {
			if (p.edad > itCiudad->second->edad) {
				itCiudad->second = &p;
			}
		} else {
			mayores.emplace(ciudad, &p);
		}
	}

	// Imprimir resultados
	for (const auto& par : mayores) {
		std::cout << par.first << " -> ";
		par.second->mostrar();
	}

	return mayores;
}

std::unordered_map<std::string, ClasePersona> buscarClasePersonaPatrimonioPorValor(std::vector<ClasePersona> personas) {
	// Se crea un map para guardar la persona mayor en todo el pais y por ciudad
	std::unordered_map<std::string, ClasePersona> masRicos;

	ClasePersona personaInicial("nombre","apellido","000", "ciudad", "15/08/2025", 0, 0, 0, 0, false);

	masRicos.emplace("Pais", personaInicial);

	for (std::string ciudad : ciudadesColombia){
		personaInicial.setCiudad(ciudad);
		masRicos.emplace(ciudad, personaInicial);
	}
	
	// Por grupo de declaracion
	masRicos.emplace("A", personaInicial);
	masRicos.emplace("B", personaInicial);
	masRicos.emplace("C", personaInicial);

	for (const ClasePersona& p : personas) {
		// Buscar el mas rico en el pais
		auto itPais = masRicos.find("Pais");
		if (itPais != masRicos.end()) {
			if (p.getPatrimonio() > itPais->second.getPatrimonio()) {
				itPais->second = p;
			}
		} else {
			masRicos.emplace("Pais", p);
		}

		// Buscar el mas rico por ciudad
		const std::string& ciudad = p.getCiudadNacimiento();
		auto itCiudad = masRicos.find(ciudad);
		if (itCiudad != masRicos.end()) {
			if (p.getPatrimonio() > itCiudad->second.getPatrimonio()) {
				itCiudad->second = p;
			}
		} else {
			masRicos.emplace(ciudad, p);
		}

		// Buscar el mas rico por grupo
		const char& grupoChar = p.getGrupo();
		std::string grupo = std::string(1, grupoChar);
		auto itGrupo = masRicos.find(grupo);
		if (itGrupo != masRicos.end()) {
			if (p.getPatrimonio() > itGrupo->second.getPatrimonio()) {
				itGrupo->second = p;
			}
		} else {
			masRicos.emplace(grupo, p);
		}
	}

	for (const auto& par : masRicos) {
        std::cout << par.first << " -> ";
        par.second.mostrar();
    }

	return masRicos;
}

std::unordered_map<std::string, const ClasePersona*> buscarClasePersonaPatrimonioPorReferencia(const std::vector<ClasePersona>& personas) {
	// Se crea un map para guardar la persona mayor en todo el pais y por ciudad
	std::unordered_map<std::string, const ClasePersona*> masRicos;

	const ClasePersona* personaInicial = &personas[0];
	masRicos.emplace("Pais", personaInicial);

	for (const std::string& ciudad : ciudadesColombia) {
		masRicos.emplace(ciudad, personaInicial);
	}

	// Por grupo de declaracion
	masRicos.emplace("A", personaInicial);
	masRicos.emplace("B", personaInicial);
	masRicos.emplace("C", personaInicial);

	for (const ClasePersona& p : personas) {
		// Encontrar el mas rico por Pais
		auto itPais = masRicos.find("Pais");
		if (itPais != masRicos.end()) {
			if (p.getPatrimonio() > itPais->second->getPatrimonio()) {
				itPais->second = &p;
			}
		} else {
			masRicos.emplace("Pais", &p);
		}

		// Encontrar el mas rico por ciudad
		const std::string& ciudad = p.getCiudadNacimiento();
		auto itCiudad = masRicos.find(ciudad);
		if (itCiudad != masRicos.end()) {
			if (p.getPatrimonio() > itCiudad->second->getPatrimonio()) {
				itCiudad->second = &p;
			}
		} else {
			masRicos.emplace(ciudad, &p);
		}

		// Buscar el mas rico por grupo
		const char& grupoChar = p.getGrupo();
		std::string grupo = std::string(1, grupoChar);
		auto itGrupo = masRicos.find(grupo);
		if (itGrupo != masRicos.end()) {
			if (p.getPatrimonio() > itGrupo->second->getPatrimonio()) {
				itGrupo->second = &p;
			}
		} else {
			masRicos.emplace(grupo, &p);
		}
	}

	// Imprimir resultados
	for (const auto& par : masRicos) {
		std::cout << par.first << " -> ";
		par.second->mostrar();
	}

	return masRicos;
}

std::unordered_map<std::string, StructPersona> buscarStructPersonaPatrimonioPorValor(std::vector<StructPersona> personas) {
	// Se crea un map para guardar la persona mayor en todo el pais y por ciudad
	std::unordered_map<std::string, StructPersona> masRicos;

	StructPersona personaInicial;
	personaInicial.patrimonio = 0;

	masRicos.emplace("Pais", personaInicial);

	for (std::string ciudad : ciudadesColombia){
		personaInicial.ciudadNacimiento = ciudad;
		masRicos.emplace(ciudad, personaInicial);
	}
	
	// Por grupo de declaracion
	masRicos.emplace("A", personaInicial);
	masRicos.emplace("B", personaInicial);
	masRicos.emplace("C", personaInicial);

	for (const StructPersona& p : personas) {
		// Buscar el mas rico en el pais
		auto itPais = masRicos.find("Pais");
		if (itPais != masRicos.end()) {
			if (p.patrimonio > itPais->second.patrimonio) {
				itPais->second = p;
			}
		} else {
			masRicos.emplace("Pais", p);
		}

		// Buscar el mas rico por ciudad
		const std::string& ciudad = p.ciudadNacimiento;
		auto itCiudad = masRicos.find(ciudad);
		if (itCiudad != masRicos.end()) {
			if (p.patrimonio > itCiudad->second.patrimonio) {
				itCiudad->second = p;
			}
		} else {
			masRicos.emplace(ciudad, p);
		}

		// Buscar el mas rico por grupo
		const char& grupoChar = p.grupo;
		std::string grupo = std::string(1, grupoChar);
		auto itGrupo = masRicos.find(grupo);
		if (itGrupo != masRicos.end()) {
			if (p.patrimonio > itGrupo->second.patrimonio) {
				itGrupo->second = p;
			}
		} else {
			masRicos.emplace(grupo, p);
		}
	}

	for (const auto& par : masRicos) {
        std::cout << par.first << " -> ";
        par.second.mostrar();
    }

	return masRicos;
}

std::unordered_map<std::string, const StructPersona*> buscarStructPersonaPatrimonioPorReferencia(const std::vector<StructPersona>& personas) {
	// Se crea un map para guardar la persona mayor en todo el pais y por ciudad
	std::unordered_map<std::string, const StructPersona*> masRicos;

	const StructPersona* personaInicial = &personas[0];
	masRicos.emplace("Pais", personaInicial);

	for (const std::string& ciudad : ciudadesColombia) {
		masRicos.emplace(ciudad, personaInicial);
	}

	// Por grupo de declaracion
	masRicos.emplace("A", personaInicial);
	masRicos.emplace("B", personaInicial);
	masRicos.emplace("C", personaInicial);

	for (const StructPersona& p : personas) {
		// Encontrar el mas rico por Pais
		auto itPais = masRicos.find("Pais");
		if (itPais != masRicos.end()) {
			if (p.patrimonio > itPais->second->patrimonio) {
				itPais->second = &p;
			}
		} else {
			masRicos.emplace("Pais", &p);
		}

		// Encontrar el mas rico por ciudad
		const std::string& ciudad = p.ciudadNacimiento;
		auto itCiudad = masRicos.find(ciudad);
		if (itCiudad != masRicos.end()) {
			if (p.patrimonio > itCiudad->second->patrimonio) {
				itCiudad->second = &p;
			}
		} else {
			masRicos.emplace(ciudad, &p);
		}

		// Buscar el mas rico por grupo
		const char& grupoChar = p.grupo;
		std::string grupo = std::string(1, grupoChar);
		auto itGrupo = masRicos.find(grupo);
		if (itGrupo != masRicos.end()) {
			if (p.patrimonio > itGrupo->second->patrimonio) {
				itGrupo->second = &p;
			}
		} else {
			masRicos.emplace(grupo, &p);
		}
	}

	// Imprimir resultados
	for (const auto& par : masRicos) {
		std::cout << par.first << " -> ";
		par.second->mostrar();
	}

	return masRicos;
}

std::unordered_map<std::string, int> contarClasePersonaGrupoPorValor(std::vector<ClasePersona> personas){
	std::unordered_map<std::string, int> conteoPorGrupo;
	
	// Por grupo de declaracion
	conteoPorGrupo.emplace("A", 0);
	conteoPorGrupo.emplace("B", 0);
	conteoPorGrupo.emplace("C", 0);

	for (const ClasePersona& p : personas) {
		// Contar en cada grupo
		const char& grupoChar = p.getGrupo();
		std::string grupo = std::string(1, grupoChar);
		auto itGrupo = conteoPorGrupo.find(grupo);
		if (itGrupo != conteoPorGrupo.end()) {
			itGrupo->second++;
		}
	}

	for (const auto& par : conteoPorGrupo) {
        std::cout << par.first << " -> " << par.second << "\n";
    }

	return conteoPorGrupo;
}

std::unordered_map<std::string, int> contarClasePersonaGrupoPorReferencia(const std::vector<ClasePersona>& personas){
	std::unordered_map<std::string, int> conteoPorGrupo;
	
	// Por grupo de declaracion
	conteoPorGrupo.emplace("A", 0);
	conteoPorGrupo.emplace("B", 0);
	conteoPorGrupo.emplace("C", 0);

	for (const ClasePersona& p : personas) {
		// Contar en cada grupo
		const char& grupoChar = p.getGrupo();
		std::string grupo = std::string(1, grupoChar);
		auto itGrupo = conteoPorGrupo.find(grupo);
		if (itGrupo != conteoPorGrupo.end()) {
			itGrupo->second++;
		}
	}

	for (const auto& par : conteoPorGrupo) {
        std::cout << par.first << " -> " << par.second << "\n";
    }

	return conteoPorGrupo;
}

std::unordered_map<std::string, int> contarStructPersonaGrupoPorValor(std::vector<StructPersona> personas){
	std::unordered_map<std::string, int> conteoPorGrupo;
	
	// Por grupo de declaracion
	conteoPorGrupo.emplace("A", 0);
	conteoPorGrupo.emplace("B", 0);
	conteoPorGrupo.emplace("C", 0);

	for (const StructPersona& p : personas) {
		// Contar en cada grupo
		const char& grupoChar = p.grupo;
		std::string grupo = std::string(1, grupoChar);
		auto itGrupo = conteoPorGrupo.find(grupo);
		if (itGrupo != conteoPorGrupo.end()) {
			itGrupo->second++;
		}
	}

	for (const auto& par : conteoPorGrupo) {
        std::cout << par.first << " -> " << par.second << "\n";
    }

	return conteoPorGrupo;
}

std::unordered_map<std::string, int> contarStructPersonaGrupoPorReferencia(const std::vector<StructPersona>& personas){
	std::unordered_map<std::string, int> conteoPorGrupo;
	
	// Por grupo de declaracion
	conteoPorGrupo.emplace("A", 0);
	conteoPorGrupo.emplace("B", 0);
	conteoPorGrupo.emplace("C", 0);

	for (const StructPersona& p : personas) {
		// Contar en cada grupo
		const char& grupoChar = p.grupo;
		std::string grupo = std::string(1, grupoChar);
		auto itGrupo = conteoPorGrupo.find(grupo);
		if (itGrupo != conteoPorGrupo.end()) {
			itGrupo->second++;
		}
	}

	for (const auto& par : conteoPorGrupo) {
        std::cout << par.first << " -> " << par.second << "\n";
    }

	return conteoPorGrupo;
}

/*
BUSQUEDAS ADICIONALES:
- Ciudad con mayor numero de personas
- Persona con la deuda mas grande
- Porcentaje de personas con ingresos anuales mayores a 400M
*/

std::string buscarClasePersonaCiudadMasPobladaPorValor(std::vector<ClasePersona> personas){
	std::unordered_map<std::string, int> conteoPorCiudad;

	for (std::string ciudad : ciudadesColombia){
		conteoPorCiudad.emplace(ciudad, 0);
	}

	// Contar cuantas personas hay por ciudad
	for (const ClasePersona& p : personas) {
		const std::string& ciudad = p.getCiudadNacimiento();
		auto itCiudad = conteoPorCiudad.find(ciudad);
		if (itCiudad != conteoPorCiudad.end()) {
			itCiudad->second++;
		}
	}

	// Encontrar la ciudad mas poblada
	std::string ciudadMasPoblada;
	int max = 0;

	for (const auto& par : conteoPorCiudad) {
        if (par.second > max) {
            max = par.second;
            ciudadMasPoblada = par.first;
        }
    }

	// Imprimir la ciudad mas poblada
    std::cout << "La ciudad más poblada es " << ciudadMasPoblada << " con una población de " << max << "\n";

	return ciudadMasPoblada;
}

std::string buscarClasePersonaCiudadMasPobladaPorReferencia(const std::vector<ClasePersona>& personas){
	std::unordered_map<std::string, int> conteoPorCiudad;

	for (std::string ciudad : ciudadesColombia){
		conteoPorCiudad.emplace(ciudad, 0);
	}

	// Contar cuantas personas hay por ciudad
	for (const ClasePersona& p : personas) {
		const std::string& ciudad = p.getCiudadNacimiento();
		auto itCiudad = conteoPorCiudad.find(ciudad);
		if (itCiudad != conteoPorCiudad.end()) {
			itCiudad->second++;
		}
	}

	// Encontrar la ciudad mas poblada
	std::string ciudadMasPoblada;
	int max = 0;

	for (const auto& par : conteoPorCiudad) {
        if (par.second > max) {
            max = par.second;
            ciudadMasPoblada = par.first;
        }
    }

	// Imprimir la ciudad mas poblada
    std::cout << "La ciudad más poblada es " << ciudadMasPoblada << " con una población de " << max << "\n";

	return ciudadMasPoblada;
}

std::string buscarStructPersonaCiudadMasPobladaPorValor(std::vector<StructPersona> personas){
	std::unordered_map<std::string, int> conteoPorCiudad;

	for (std::string ciudad : ciudadesColombia){
		conteoPorCiudad.emplace(ciudad, 0);
	}

	// Contar cuantas personas hay por ciudad
	for (const StructPersona& p : personas) {
		const std::string& ciudad = p.ciudadNacimiento;
		auto itCiudad = conteoPorCiudad.find(ciudad);
		if (itCiudad != conteoPorCiudad.end()) {
			itCiudad->second++;
		}
	}

	// Encontrar la ciudad mas poblada
	std::string ciudadMasPoblada;
	int max = 0;

	for (const auto& par : conteoPorCiudad) {
        if (par.second > max) {
            max = par.second;
            ciudadMasPoblada = par.first;
        }
    }

	// Imprimir la ciudad mas poblada
    std::cout << "La ciudad más poblada es " << ciudadMasPoblada << " con una población de " << max << "\n";

	return ciudadMasPoblada;
}

std::string buscarStructPersonaCiudadMasPobladaPorReferencia(const std::vector<StructPersona>& personas){
	std::unordered_map<std::string, int> conteoPorCiudad;

	for (std::string ciudad : ciudadesColombia){
		conteoPorCiudad.emplace(ciudad, 0);
	}

	// Contar cuantas personas hay por ciudad
	for (const StructPersona& p : personas) {
		const std::string& ciudad = p.ciudadNacimiento;
		auto itCiudad = conteoPorCiudad.find(ciudad);
		if (itCiudad != conteoPorCiudad.end()) {
			itCiudad->second++;
		}
	}

	// Encontrar la ciudad mas poblada
	std::string ciudadMasPoblada;
	int max = 0;

	for (const auto& par : conteoPorCiudad) {
        if (par.second > max) {
            max = par.second;
            ciudadMasPoblada = par.first;
        }
    }

	// Imprimir la ciudad mas poblada
    std::cout << "La ciudad más poblada es " << ciudadMasPoblada << " con una población de " << max << "\n";

	return ciudadMasPoblada;
}

std::unordered_map<std::string, ClasePersona> buscarClasePersonaEndeudadaPorValor(std::vector<ClasePersona> personas) {
	// Se crea un map para guardar la persona mayor en todo el pais y por ciudad
	std::unordered_map<std::string, ClasePersona> mayorEndeudado;

	ClasePersona personaInicial("nombre","apellido","000", "ciudad", "15/08/2025", 0, 0, 0, 0, false);

	mayorEndeudado.emplace("Pais", personaInicial);

	for (const ClasePersona& p : personas) {
		auto itPais = mayorEndeudado.find("Pais");
		if (itPais != mayorEndeudado.end()) {
			if (p.getDeudas() > itPais->second.getDeudas()) {
				itPais->second = p;
			}
		} else {
			mayorEndeudado.emplace("Pais", p);
		}
	}

    mayorEndeudado.find("Pais")->second.mostrar();

	return mayorEndeudado;
}

std::unordered_map<std::string, const ClasePersona*> buscarClasePersonaEndeudadaPorReferencia(const std::vector<ClasePersona>& personas) {
	// Se crea un map para guardar la persona mayor en todo el pais y por ciudad
	std::unordered_map<std::string, const ClasePersona*> mayorEndeudado;

	const ClasePersona* personaInicial = &personas[0];
	mayorEndeudado.emplace("Pais", personaInicial);

	for (const std::string& ciudad : ciudadesColombia) {
		mayorEndeudado.emplace(ciudad, personaInicial);
	}

	for (const ClasePersona& p : personas) {
		auto itPais = mayorEndeudado.find("Pais");
		if (itPais != mayorEndeudado.end()) {
			if (p.getDeudas() > itPais->second->getDeudas()) {
				itPais->second = &p;
			}
		} else {
			mayorEndeudado.emplace("Pais", &p);
		}
	}

	mayorEndeudado.find("Pais")->second->mostrar();

	return mayorEndeudado;
}

std::unordered_map<std::string, StructPersona> buscarStructPersonaEndeudadaPorValor(std::vector<StructPersona> personas) {
	// Se crea un map para guardar la persona mayor en todo el pais y por ciudad
	std::unordered_map<std::string, StructPersona> mayorEndeudado;

	StructPersona personaInicial;
	personaInicial.deudas = 0;

	mayorEndeudado.emplace("Pais", personaInicial);

	for (const StructPersona& p : personas) {
		auto itPais = mayorEndeudado.find("Pais");
		if (itPais != mayorEndeudado.end()) {
			if (p.deudas > itPais->second.deudas) {
				itPais->second = p;
			}
		} else {
			mayorEndeudado.emplace("Pais", p);
		}
	}

    mayorEndeudado.find("Pais")->second.mostrar();

	return mayorEndeudado;
}

std::unordered_map<std::string, const StructPersona*> buscarStructPersonaEndeudadaPorReferencia(const std::vector<StructPersona>& personas) {
	// Se crea un map para guardar la persona mayor en todo el pais y por ciudad
	std::unordered_map<std::string, const StructPersona*> mayorEndeudado;

	const StructPersona* personaInicial = &personas[0];
	mayorEndeudado.emplace("Pais", personaInicial);

	for (const std::string& ciudad : ciudadesColombia) {
		mayorEndeudado.emplace(ciudad, personaInicial);
	}

	for (const StructPersona& p : personas) {
		auto itPais = mayorEndeudado.find("Pais");
		if (itPais != mayorEndeudado.end()) {
			if (p.deudas > itPais->second->deudas) {
				itPais->second = &p;
			}
		} else {
			mayorEndeudado.emplace("Pais", &p);
		}
	}

	mayorEndeudado.find("Pais")->second->mostrar();

	return mayorEndeudado;
}

float buscarClasePersonaPorcentajeIngresosAltosPorValor(std::vector<ClasePersona> personas) {
	float poblacion = 0;
	float numeroPersonasIngresosAltos = 0;

	for (const ClasePersona& p : personas) {
		if (p.getIngresosAnuales() > 400000000){
			numeroPersonasIngresosAltos++;
		}
		poblacion++;
	}

	float porcentaje = (numeroPersonasIngresosAltos/poblacion) * 100;

	std::cout << "El porcentaje de personas con ingresos anuales mayores a 400M es " << porcentaje << "%\n";

	return porcentaje;
}

float buscarClasePersonaPorcentajeIngresosAltosPorReferencia(const std::vector<ClasePersona>& personas) {
	float poblacion = 0;
	float numeroPersonasIngresosAltos = 0;

	for (const ClasePersona& p : personas) {
		if (p.getIngresosAnuales() > 400000000){
			numeroPersonasIngresosAltos++;
		}
		poblacion++;
	}

	float porcentaje = (numeroPersonasIngresosAltos/poblacion) * 100;

	std::cout << "El porcentaje de personas con ingresos anuales mayores a 400M es " << porcentaje << "%\n";

	return porcentaje;
}

float buscarStructPersonaPorcentajeIngresosAltosPorValor(std::vector<StructPersona> personas) {
	float poblacion = 0;
	float numeroPersonasIngresosAltos = 0;

	for (const StructPersona& p : personas) {
		if (p.ingresosAnuales > 400000000){
			numeroPersonasIngresosAltos++;
		}
		poblacion++;
	}

	float porcentaje = (numeroPersonasIngresosAltos/poblacion) * 100;

	std::cout << "El porcentaje de personas con ingresos anuales mayores a 400M es " << porcentaje << "%\n";

	return porcentaje;
}

float buscarStructPersonaPorcentajeIngresosAltosPorReferencia(const std::vector<StructPersona>& personas) {
	float poblacion = 0;
	float numeroPersonasIngresosAltos = 0;

	for (const StructPersona& p : personas) {
		if (p.ingresosAnuales > 400000000){
			numeroPersonasIngresosAltos++;
		}
		poblacion++;
	}

	float porcentaje = (numeroPersonasIngresosAltos/poblacion) * 100;

	std::cout << "El porcentaje de personas con ingresos anuales mayores a 400M es " << porcentaje << "%\n";

	return porcentaje;
}
