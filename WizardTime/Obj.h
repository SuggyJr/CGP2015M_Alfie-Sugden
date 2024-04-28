#ifndef OBJ_H
#define OBJ_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;


class Obj
{
public:
	void update();
	void renderer(SDL_Renderer* renderer);

	SDL_Rect getDestination() const { return destination; }
	SDL_Rect getSource() const { return source; }

	int getDestinationX() const { return destination.x; }
	int getDestinationY() const { return destination.y; }
	int getDestinationW() const { return destination.w; }
	int getDestinationH() const { return destination.h; }
	
	SDL_Texture* getTexture() const { return texture; }

	void setImage(string filename, SDL_Renderer* ren);
	void setSource(int x, int y, int w, int h);


	SDL_RendererFlip flip = SDL_FLIP_NONE;

private:
	SDL_Rect destination = { 0, 0, 0, 0 };
	SDL_Rect source = { 0, 0, 0, 0 };
	SDL_Texture* texture = nullptr;


};

#endif // !OBJ_H
