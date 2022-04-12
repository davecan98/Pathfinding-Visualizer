#include <SFML/Graphics.hpp>
#include "GridView.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 800), "Pathfinding Visualizer", sf::Style::Titlebar | sf::Style::Close);
    GridView gridView(&window, 20);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        gridView.drawGrid();
        window.display();
    }
    return 0;
}