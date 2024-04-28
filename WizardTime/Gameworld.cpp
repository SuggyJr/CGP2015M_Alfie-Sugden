#include "Gameworld.h"

Tilemap* map = new Tilemap();

Gameworld::Gameworld()
{
	getKeys[SDLK_w] = false;
	getKeys[SDLK_a] = false;
	getKeys[SDLK_d] = false;
	getKeys[SDLK_SPACE] = false;
}

void Gameworld::init(SDL_Renderer* renderer)
{
	map->loadMap("Assets/TestMap.txt", renderer);
}

void Gameworld::input(SDL_Event event)
{

}

void Gameworld::update()
{

}

void Gameworld::render(SDL_Renderer* renderer)
{
	map->drawMap(renderer);
}