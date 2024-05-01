#include "Obj.h"

void Obj::update()
{
	if (visible)
	{
		updateAnim();
	}
}

void Obj::renderer(SDL_Renderer* renderer)
{
	if (visible)
	{
		SDL_Rect destination = getDestination();
		SDL_Rect source = getSource();
		SDL_RenderCopyEx(renderer, texture, &source, &destination, NULL, NULL, flip);
	}
}

int Obj::createAnim(int row, int number, int freq)
{
	cycle temporary{};
	
	temporary.row = row - 1;
	temporary.width = getDestinationW();
	temporary.height = getDestinationH();
	temporary.number = number;
	temporary.freq = freq;
	temporary.tick = 0;
	Anim.push_back(temporary);
	
	return static_cast<int>(Anim.size() - 1);
}

void Obj::updateAnim()
{
	setSource(Anim[currentAnim].width * Anim[currentAnim].tick, Anim[currentAnim].row * Anim[currentAnim].height, Anim[currentAnim].width, Anim[currentAnim].height);
	if (beginAnim > Anim[currentAnim].freq) { Anim[currentAnim].tick++; beginAnim = 0; }
	beginAnim++;

	if (Anim[currentAnim].tick >= Anim[currentAnim].number) { Anim[currentAnim].tick = 0; }
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