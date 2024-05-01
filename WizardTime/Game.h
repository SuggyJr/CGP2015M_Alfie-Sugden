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
#include "Timelimit.h"
#include "Endscreen.h"

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

private:
	int seconds;
	int time;
	const int D_TIME = 0;
	Timelimit timelimit;

	bool isFullscreen;
	bool isRunning;

	SDL_Window* window;
	static SDL_Renderer* renderer;

	Uint32 Startframe;
};

#endif // !GAME