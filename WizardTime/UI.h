#ifndef UI_H
#define UI_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

using namespace std;

class UI
{
public:
	UI(int x, int y, TTF_Font* font);
	UI(const char* word, int x, int y, TTF_Font* font);
	~UI();

	void update(const char* words);
	void renderer(SDL_Renderer* renderer);
	int x = 0;
	int y = 0;
	
	SDL_Color textColour = { 255, 255, 255 };
	SDL_Rect rect = {};
	SDL_Surface* surface = nullptr;
	SDL_Texture* texture = nullptr;
	TTF_Font* mFont = nullptr;
};

#endif // !UI_H
