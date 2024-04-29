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

void Obj::setDestination(V2D vector)
{
	destination.x = vector.x;
	destination.y = vector.y;
}

void Obj::setDestination(V2D vector, int w, int h)
{
	destination.x = vector.x;
	destination.y = vector.y;
	destination.w = w;
	destination.h = h;
}

void Obj::setSource(int x, int y, int w, int h)
{
	source.x = x;
	source.y = y;
	source.w = w;
	source.h = h;
}