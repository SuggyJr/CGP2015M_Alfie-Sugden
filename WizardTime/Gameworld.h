#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <iostream>
#include <SDL.h>

#include "Obj.h"
#include "Tilemap.h"

#define maxKeys (256)

class Gameworld
{
public:
	Gameworld();
	
	void init(SDL_Renderer* renderer);
	void input(SDL_Event event);
	void update();
	void render(SDL_Renderer* renderer);
	void loadLevel(SDL_Renderer* renderer);

	bool getKeys[maxKeys];

private:
	int speed = 10;
	bool fire = false;
	bool playerIdle = false;
};

#endif // !GAMEWORLD_H
