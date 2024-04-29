#ifndef GAME
#define GAME

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include "Splashscreen.h"
#include "Gameworld.h"

using namespace std;

class Game
{
public:
	Game();
	~Game();
	void init();

	void loop();
	void update();
	void render();
	void input();

	static SDL_Renderer* renderer;

private:
	int frameTime;
	int fpsCount;

	bool isFullscreen;
	bool isRunning;

	SDL_Window* window;
	SDL_Event event;

	Uint32 Startframe;
};

#endif // !GAME