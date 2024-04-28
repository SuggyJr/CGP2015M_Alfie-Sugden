#include "Obj.h"

void Obj::update()
{

}

void Obj::renderer(SDL_Renderer* renderer)
{
	SDL_Rect destination = getDestination();
	SDL_Rect source = getSource();
	SDL_RenderCopyEx(renderer, texture, &source, &destination, NULL, NULL, flip);
}

void Obj::setImage(string filename, SDL_Renderer* renderer)
{
	SDL_Surface* surface = IMG_Load(filename.c_str());
	texture = SDL_CreateTextureFromSurface(renderer, surface);
}

void Obj::setSource(int x, int y, int w, int h)
{
	source.x = x;
	source.y = y;
	source.w = w;
	source.h = h;
}