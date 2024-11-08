#include "Game.hpp"
#include "menu.cpp"

int main()
{
    Game game;
    sf::RenderWindow* window = game.getWindow();
    window->setFramerateLimit(60);
    while (game.running())
    {
        game.update();
        game.render();
    }
    return 0;
}