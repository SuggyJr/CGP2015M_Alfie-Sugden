#ifndef TILEMAP_H
#define TILEMAP_H

#include <fstream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "Obj.h"

class Tilemap
{
public:
	void loadTM(const char* filename, SDL_Renderer* renderer);
	void drawTM(SDL_Renderer* renderer);
	void drawTiles(Obj obj, SDL_Renderer* renderer);

	int getDestinationX() const { return destination.x; }
	int getDestinationY() const { return destination.y; }
	vector<Obj> tileMap;

private:
	SDL_Rect destination;
};

#endif // !TILEMAP_H
