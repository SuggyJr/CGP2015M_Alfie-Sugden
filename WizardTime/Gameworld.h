#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <iostream>
#include <SDL.h>

#include "Obj.h"
#include "Tilemap.h"
#include "Entity.h"
#include "Debug.h"

#define maxKeys (256)

class Gameworld
{
public:
	Gameworld();
	
	void init(SDL_Renderer* renderer);
	void input(SDL_Event event);
	void update();
	void render(SDL_Renderer* renderer);

	bool getKeys[maxKeys];

	Debug debug;

private:
	int speed = 10;
	int floatingSpeed = 7;
	bool fire = false;

	bool anim = false;

	bool wall = false;
};

#endif // !GAMEWORLD_H
