#ifndef GRID_VIEW
#define GRID_VIEW

#include <SFML/Graphics.hpp>
#include <string.h>

class GridView{

	public:
		GridView(sf::RenderWindow* win, int);
		GridView(const GridView&) = delete;  //no copy 
		GridView& operator=(const GridView&) = delete; //no copy assign
		void drawGrid();
		void processEvents(sf::Event);

	private:
		int grid_sz;
		int tile_size_x;
		int tile_size_y;
		sf::RenderWindow *window;
		std::vector<std::vector<sf::RectangleShape>> grid;
};

#endif GRID_VIEW