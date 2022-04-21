#include "GridView.h"
#include <iostream>

//contructor
GridView::GridView(sf::RenderWindow *win, int grid_size=20) : window(win), grid_sz(grid_size) {

    
    tile_size_x = window->getSize().x / grid_size;
    tile_size_y = window->getSize().y / grid_size;

    for (int i = 0; i < grid_size; i++) {

        grid.push_back(std::vector<sf::RectangleShape>());

        for (int j = 0; j < grid_size; j++) {

            grid[i].emplace_back(sf::Vector2f(tile_size_x, tile_size_y)); //create a new rectangle and push into vector

            sf::RectangleShape &rec = grid[i][j];
            rec.setPosition(i* tile_size_x,j* tile_size_y);
            rec.setOutlineColor(sf::Color::Black);
            rec.setOutlineThickness(1);
        }
    }
}

void GridView::drawGrid() {

    for (int i = 0; i < grid_sz; i++) {
        for (int j = 0; j < grid_sz; j++) {
            window->draw(grid[i][j]);
        }
    }
}

void GridView::processEvents(sf::Event event) {

    if (event.type == sf::Event::Closed)
        window->close();

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        setTile(event.mouseButton.x, event.mouseButton.y, sf::Color::Black);
        mouseHeld = true;
    }


    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
    {
        int tile_x = static_cast<float>(event.mouseButton.x / tile_size_x);
        int tile_y = static_cast<float>(event.mouseButton.y / tile_size_y);

        grid[tile_x][tile_y].setFillColor(sf::Color::Blue);

        if (selectedTarget) //previously selected target
        {
            selectedTarget->setFillColor(sf::Color::White); //set transparent color
        }

        selectedTarget = &grid[tile_x][tile_y]; //remember the selected target

    }

    if (event.type == sf::Event::MouseMoved && mouseHeld)
    {
        setTile(event.mouseMove.x, event.mouseMove.y, sf::Color::Black);
    }

    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
        std::cout << "released";
        mouseHeld = false;
    }
}

void GridView::setTile(int x_pos, int y_pos, sf::Color col)
{
    int tile_x = static_cast<float>(x_pos / tile_size_x);
    int tile_y = static_cast<float>(y_pos / tile_size_y);

    grid[tile_x][tile_y].setFillColor(col);
}
