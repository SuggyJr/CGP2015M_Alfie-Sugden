#include "Gameworld.h"

Tilemap* map = new Tilemap();
Obj* player = new Obj();

Gameworld::Gameworld()
{
	getKeys[SDLK_w] = false;
	getKeys[SDLK_a] = false;
	getKeys[SDLK_d] = false;
	getKeys[SDLK_SPACE] = false;
}

void Gameworld::init(SDL_Renderer* renderer)
{
	loadLevel(renderer);

	player->setImage("Assets/Player_1.png", renderer);
	player->setID(1);
	player->setDestination(V2D(640,320), 32, 32);
}

void Gameworld::input(SDL_Event event)
{
	if (event.type == SDL_KEYDOWN && event.key.repeat == NULL)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_a:
			getKeys[SDLK_a] = true;
			break;
		case SDLK_d:
			getKeys[SDLK_d] = true;
			break;
		case SDLK_SPACE:
			getKeys[SDLK_SPACE] = true;
			break;
		default:
			break;
		}
	}
}

void Gameworld::update()
{

}

void Gameworld::render(SDL_Renderer* renderer)
{
	map->drawMap(renderer);
	player->renderer(renderer);
}

void Gameworld::loadLevel(SDL_Renderer* renderer)
{
	map->loadMap("Assets/Map.map", renderer);
}