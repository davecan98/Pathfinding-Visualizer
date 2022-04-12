#include "GridView.h"
#include <iostream>

//contructor
GridView::GridView() : window(sf::VideoMode(1000, 1000), "Pathfinding Visualizer", sf::Style::Titlebar | sf::Style::Close){

    for (int i = 0; i < grid_sz; i++) {
        for (int j = 0; j < grid_sz; j++) {
            sf::RectangleShape& rec = grid[i][j];
            rec.setSize(sf::Vector2f(tile_sz, tile_sz));
            rec.setPosition(i* tile_sz,j* tile_sz);
            rec.setOutlineColor(sf::Color::Black);
            rec.setOutlineThickness(1);
        }
    }
}

void GridView::drawRectangles() {

    for (int i = 0; i < grid_sz; i++) {
        for (int j = 0; j < grid_sz; j++) {
            window.draw(grid[i][j]);
        }
    }

}

void GridView::update() {

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        drawRectangles();
        window.display();
    }
}
