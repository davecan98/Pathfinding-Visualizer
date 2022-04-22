#ifndef GRID_CONTROLLER
#define GRID_CONTROLLER

#include <SFML/Graphics.hpp>
#include <string.h>
#include "GridView.h"

class GridController {

public:
	GridController(int);
	GridController(const GridController&) = delete;  //no copy 
	GridController& operator=(const GridController&) = delete; //no copy assign
	void run();

private:
	bool mouseHeld = false;
	int grid_sz;
	int tile_size_x;
	int tile_size_y;
	std::shared_ptr<sf::RenderWindow> window;
	std::shared_ptr<GridView> view;
	void processEvents(sf::Event);
	std::tuple<int, int> CoordToGrid(int, int);

};

#endif GRID_CONTROLLER