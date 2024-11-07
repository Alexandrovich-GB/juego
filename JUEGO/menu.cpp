#include <SFML/Graphics.hpp>
#include "Game.hpp"

enum MenuOptions {
    PLAY,
    EXIT
};

int main() {
    // Crear ventana del menú
    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu Principal");
    sf::Font font;
    if (!font.loadFromFile("textures/font3.ttf")) {
        return -1;
    }

    sf::Text playText("Jugar", font, 50);
    playText.setPosition(300, 200);
    playText.setFillColor(sf::Color::White);

    sf::Text exitText("Salir", font, 50);
    exitText.setPosition(300, 300);
    exitText.setFillColor(sf::Color::White);

    MenuOptions selectedOption = PLAY;
    Game* game = nullptr;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    selectedOption = PLAY;
                    playText.setFillColor(sf::Color::Green);
                    exitText.setFillColor(sf::Color::White);
                }
                else if (event.key.code == sf::Keyboard::Down) {
                    selectedOption = EXIT;
                    exitText.setFillColor(sf::Color::Green);
                    playText.setFillColor(sf::Color::White);
                }
                else if (event.key.code == sf::Keyboard::Enter) {
                    if (selectedOption == PLAY) {
                        // Iniciar el juego
                        game = new Game(); // Crear instancia del juego
                        while (game->running()) {
                            game->update();
                            game->render();
                        }
                        delete game;
                    }
                    else if (selectedOption == EXIT) {
                        window.close();
                    }
                }
            }
        }

        // Dibujar menú
        window.clear();
        window.draw(playText);
        window.draw(exitText);
        window.display();
    }

    return 0;
}