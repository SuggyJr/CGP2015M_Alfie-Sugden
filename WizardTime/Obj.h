#ifndef OBJ_H
#define OBJ_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>
#include "V2D.h"

using namespace std;


class Obj
{
public:
	void update();
	void renderer(SDL_Renderer* renderer);

	SDL_Rect getDestination() const { return destination; }
	SDL_Rect getSource() const { return source; }
	SDL_Texture* getTexture() const { return texture; }

	int getDestinationX() const { return destination.x; }
	int getDestinationY() const { return destination.y; }
	int getDestinationW() const { return destination.w; }
	int getDestinationH() const { return destination.h; }
	bool makeSolid() const { return itBeSolid; }
	int setID() const { return iD; }

	void setImage(string filename, SDL_Renderer* ren);
	void setSource(int x, int y, int w, int h);
	void setDestination(V2D vector);
	void setDestination(V2D vector, int x, int y);
	void makeSolid(bool solid) { itBeSolid = solid; }
	void setID(int i) { iD = i; }

	SDL_RendererFlip flip = SDL_FLIP_NONE;

private:
	SDL_Rect destination = { 0, 0, 0, 0 };
	SDL_Rect source = { 0, 0, 0, 0 };
	SDL_Texture* texture = nullptr;

	bool itBeSolid = false;
	int iD = 0;

};

#endif // !OBJ_H
