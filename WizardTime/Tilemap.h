#ifndef TILEMAP
#define TILEMAP

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class Tilemap
{
public:
	Tilemap(SDL_Renderer* renderer);
	~Tilemap();

	void loadMap(const char* mapFile);
	void render();

private:
	SDL_Renderer* mapRenderer;
	vector<SDL_Texture*> tileTextures;
	vector<vector<int>> mapTilemap;

	int tileSize;
	int mapWidth;
	int mapHeight;
};

#endif // !TILEMAP