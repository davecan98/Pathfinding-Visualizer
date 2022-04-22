#ifndef GRID_VIEW
#define GRID_VIEW

#include <SFML/Graphics.hpp>
#include <string.h>

class GridView{

	public:
		GridView(std::shared_ptr<sf::RenderWindow>, int);
		GridView(const GridView&) = delete;  //no copy 
		GridView& operator=(const GridView&) = delete; //no copy assign
		void drawGrid();
		void setTileColor(int, int, sf::Color);
		int getTileSize_X() { return tile_size_x; }
		int getTileSize_Y() { return tile_size_y; }

	private:
		int grid_sz;
		int tile_size_x;
		int tile_size_y;
		std::shared_ptr<sf::RenderWindow> window;
		std::vector<std::vector<sf::RectangleShape>> grid;
		

};

#endif GRID_VIEW