#ifndef GRID_VIEW
#define GRID_VIEW

#include <SFML/Graphics.hpp>
#include <string.h>

class GridView{

	public:
		GridView();
		
		
		GridView(const GridView&) = delete;  //no copy 
		GridView& operator=(const GridView&) = delete; //no copy assign
		~GridView() = default; //default detructor

		void update();

	private:
		static constexpr int tile_sz = 20;
		static constexpr int grid_sz = 50;
		sf::RenderWindow window;
		sf::RectangleShape grid[grid_sz][grid_sz];

		void drawRectangles();
		
		
};

#endif GRID_VIEW