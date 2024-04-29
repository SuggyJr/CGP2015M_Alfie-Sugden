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
}

void Gameworld::input(SDL_Event event, SDL_Renderer* renderer)
{
	if (event.type == SDL_KEYDOWN && event.key.repeat == NULL)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_a:
			getKeys[SDLK_a] = true;
			player->setImage("Assets/Player_1F.png",renderer);
			break;
		case SDLK_d:
			getKeys[SDLK_d] = true;
			player->setImage("Assets/Player_1.png", renderer);
			break;
		case SDLK_SPACE:
			getKeys[SDLK_SPACE] = true;
			player->setImage("Assets/Player_FIRE.png", renderer);
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
}

void Gameworld::loadLevel(SDL_Renderer* renderer)
{
	map->loadMap("Assets/TestMap.txt", renderer);
}