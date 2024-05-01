#include "Gameworld.h"

Entity* player = new Entity();
Obj* enemy = new Obj();
Obj* worldMap = new Obj();
Tilemap* tilemap = new Tilemap();

Gameworld::Gameworld()
{
	getKeys[SDLK_w] = false;
	getKeys[SDLK_a] = false;
	getKeys[SDLK_s] = false;
	getKeys[SDLK_d] = false;
	getKeys[SDLK_SPACE] = false;
}

void Gameworld::init(SDL_Renderer* renderer)
{
	tilemap->loadTM("Assets/TestMap.map", renderer);

	player->setImage("Assets/PlayerSheet.png", renderer);
	anim = player->createAnim(1, 3, 10);
	player->setDestination(V2D(200, 200), 32, 32);


	//player->setImage("Assets/Enemy.png", renderer);
	//player->setDestination(V2D(440, 200), 32, 32);
}

void Gameworld::input(SDL_Event event)
{
	if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_w:
			getKeys[SDLK_w] = true;
			cout << "		W PRESSED\n";
			break;
		case SDLK_a:
			getKeys[SDLK_a] = true;
			cout << "		A PRESSED\n";
			break;
		case SDLK_s:
			getKeys[SDLK_s] = true;
			cout << "		S PRESSED\n";
			break;
		case SDLK_d:
			getKeys[SDLK_d] = true;
			cout << "		D PRESSED\n";
			break;
		case SDLK_SPACE:
			getKeys[SDLK_SPACE] = true;
			fire = true;
			cout << "		SPACE PRESSED\n";
			break;
		default:
			break;
		}
	}
}

void Gameworld::update()
{
		wall = true;

	if (player->velocity.x == 0 && player->velocity.y == 0) { if (player->getCurrAnim() != anim) { player->setCurrAnim(anim); } }
	if (player->velocity.x <= -1 && player->velocity.x <= - 1) { if (player->getCurrAnim() != anim) { player->setCurrAnim(anim); player->flip = SDL_FLIP_HORIZONTAL; } }
	if (player->velocity.x >= 1 && player->velocity.x >= 1) { if (player->getCurrAnim() != anim) { player->setCurrAnim(anim); player->flip = SDL_FLIP_NONE; } }

	if (player->isCollidingFloor()) { if (!getKeys[SDLK_s]) { player->velocity.y = player->velocity.y - 1; if (player->velocity.y != 0) { player->velocity.y = player->velocity.y - player->velocity.y; } } }
	if (player->isCollidingRoof()) { if (!getKeys[SDLK_w]) { player->velocity.y = player->velocity.y - 1; if (player->velocity.y != 0) { player->velocity.y = player->velocity.y - player->velocity.y; } } }
	if (player->isCollidingLeft()) { if (!getKeys[SDLK_a]) { player->velocity.x = player->velocity.x - 1; if (player->velocity.x != 0) { player->velocity.x = player->velocity.x - player->velocity.x; } } }
	if (player->isCollidingRight()) { if (!getKeys[SDLK_d]) { player->velocity.x = player->velocity.x - 1; if (player->velocity.x != 0) { player->velocity.x = player->velocity.x - player->velocity.x; } } }

	player->entityUpdate(tilemap);
}

void Gameworld::render(SDL_Renderer* renderer)
{
	tilemap->drawTM(renderer);
	player->entityRender(debug.getDebugger(), renderer);
}
