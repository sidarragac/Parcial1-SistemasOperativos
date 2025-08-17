# Makefile para compilación automatizada

# Configuración del compilador
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++14

# Archivos fuente y objeto
SRCS := main.cpp ./Includes/StructPersona/StructPersona.cpp ./Includes/ClasePersona/ClasePersona.cpp ./Includes/Busqueda/busqueda.cpp ./Includes/Generador/generador.cpp ./Includes/Monitor/Monitor.cpp
OBJS := $(SRCS:.cpp=.o)
EXEC := programa

# Objeto principal: Para compilar el ejecutable
all: $(EXEC)

# Enlaza los objetos para crear el ejecutable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Reglas especificas para compilar los archivos objeto
clasePersona.o: ./Includes/ClasePersona/ClasePersona.cpp ./Includes/ClasePersona/ClasePersona.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Reglas especificas para compilar los archivos objeto
structPersona.o: ./Includes/StructPersona/StructPersona.cpp ./Includes/StructPersona/StructPersona.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

generador.o: ./Includes/Generador/generador.cpp ./Includes/Generador/generador.h ./Includes/ClasePersona/ClasePersona.h ./Includes/StructPersona/StructPersona.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

busqueda.o: ./Includes/Busqueda/busqueda.cpp ./Includes/Busqueda/busqueda.h ./Includes/ClasePersona/ClasePersona.h ./Includes/StructPersona/StructPersona.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

monitor.o: ./Includes/Monitor/Monitor.cpp ./Includes/Monitor/Monitor.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.cpp ./Includes/ClasePersona/ClasePersona.h ./Includes/StructPersona/StructPersona.h ./Includes/Busqueda/busqueda.h ./Includes/Generador/generador.h ./Includes/Monitor/Monitor.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpieza de archivos generados
clean:
	rm -f $(OBJS) $(EXEC)

# Ejecuta el programa después de compilar
run: $(EXEC)
	./$(EXEC)