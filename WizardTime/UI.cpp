#include "UI.h"

UI::UI(int x, int y, TTF_Font* font)
{
	if (!font)
	{
		cout << "Can't find font\n";
	}
	mFont = font;

	this->x = x;
	this->y = y;
}

UI::UI(const char* word, int x, int y, TTF_Font* font)
{
	if (!font)
	{
		cout << "Can't find font\n";
	}
	mFont = font;

	this->surface = TTF_RenderText_Solid(mFont, word, textColour);

	this->x = x;
	this->y = y;
}

UI::~UI()
{
	TTF_CloseFont(mFont);
}

void UI::update(const char* words)
{
	surface = TTF_RenderText_Solid(mFont, words, textColour);
}

void UI::renderer(SDL_Renderer* renderer)
{
	rect = { (x - surface->w) / 2, (y - surface->h) / 2, surface->w, surface->h };
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_RenderCopy(renderer, texture, NULL, &rect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}
