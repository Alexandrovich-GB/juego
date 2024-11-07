CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Archivos de tu proyecto
SOURCES = menu.cpp Game.cpp Player.cpp Enemy.cpp EnemiesManager.cpp #main.cpp 
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = space_invaders

# Librerías de SFML
SFML_INCLUDE = -I/opt/homebrew/include
SFML_LIB_PATH = -L/opt/homebrew/lib
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Regla de compilación
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE) $(SFML_LIB_PATH) $(SFML_LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
