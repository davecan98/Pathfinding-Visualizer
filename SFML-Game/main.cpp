#include <SFML/Graphics.hpp>
#include "GridView.h"
#include <iostream>

int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 800), "Pathfinding Visualizer", sf::Style::Titlebar | sf::Style::Close);
    GridView gridView(&window, 20);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            gridView.processEvents(event);
        }

        window.clear();
        gridView.drawGrid();
        window.display();
    }
    return 0;
}