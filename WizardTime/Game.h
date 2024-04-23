#ifndef GAME
#define GAME

#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

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

	void renderSplashScreen();

private:
	bool isFullscreen;
	bool isRunning;

	SDL_Window* window;
	SDL_Renderer* renderer;
};

#endif // !GAME