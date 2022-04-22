#include "GridController.h"
#include <iostream>


GridController::GridController(int grid_sz) :
         
    window(std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 800), "Pathfinding Visualizer", sf::Style::Titlebar | sf::Style::Close)),
    view(std::make_shared<GridView>(window, grid_sz))
    {


    
    }


void GridController::run()
{

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
           processEvents(event);
        }

        window->clear();
        view->drawGrid();
        window->display();
    }
}

void GridController::processEvents(sf::Event event) {

    if (event.type == sf::Event::Closed)
        window->close();

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        std::tuple<int, int> tile_pos = CoordToGrid(event.mouseButton.x, event.mouseButton.y);
        view->setTileColor(std::get<0>(tile_pos), std::get<1>(tile_pos), sf::Color::Black);
        mouseHeld = true;
    }


    //if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
    //{
    //    int tile_x = static_cast<float>(event.mouseButton.x / tile_size_x);
    //    int tile_y = static_cast<float>(event.mouseButton.y / tile_size_y);

    //    grid[tile_x][tile_y].setFillColor(sf::Color::Blue);

    //    if (selectedTarget) //previously selected target
    //    {
    //        selectedTarget->setFillColor(sf::Color::White); //set transparent color
    //    }

    //    selectedTarget = &grid[tile_x][tile_y]; //remember the selected target

    //}

    if (event.type == sf::Event::MouseMoved && mouseHeld)
    {
        std::tuple<int,int> tile_pos=CoordToGrid(event.mouseMove.x,event.mouseMove.y);
        view->setTileColor(std::get<0>(tile_pos), std::get<1>(tile_pos), sf::Color::Black);
    }

    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
        mouseHeld = false;
    }
}

std::tuple<int, int> GridController::CoordToGrid(int coord_x, int coord_y) 
{
    int tile_x = static_cast<float>(coord_x / view->getTileSize_X());
    int tile_y = static_cast<float>(coord_y / view->getTileSize_Y());

    return std::tuple<int, int>(tile_x, tile_y);
}

