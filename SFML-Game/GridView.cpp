#include "GridView.h"
#include <iostream>

//contructor
GridView::GridView(std::shared_ptr<sf::RenderWindow> win, int grid_size) : window(win), grid_sz(grid_size) {

    
    tile_size_x = window->getSize().x / grid_sz;
    tile_size_y = window->getSize().y / grid_sz;

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

void GridView::setTileColor(int x_pos, int y_pos, sf::Color col)
{
    grid[x_pos][y_pos].setFillColor(col);
}

