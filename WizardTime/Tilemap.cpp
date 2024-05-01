#include "Tilemap.h"

void Tilemap::loadTM(const char* filename, SDL_Renderer* renderer)
{
	if (!tileMap.empty())
	{
		tileMap.clear();
	}
	
	Obj temporary{};
	int current, tileMX, tileMY, tileMW, tileMH;
	ifstream mapFile(filename);
	
	if (!mapFile.is_open())
	{
		return;
	}

	mapFile >> tileMW;
	mapFile >> tileMH;
	mapFile >> tileMX;
	mapFile >> tileMY;

	for (int i = 0; i < tileMH; i++)
	{
		for (int j = 0; j < tileMW; j++)
		{
			if (mapFile.eof())
			{
				return;
			}

			mapFile >> current;
			
			if (current != 0)
			{
				temporary.setImage("assets/Tile_Brick_1.png", renderer);
				temporary.setSource((current - 1) * 32, 0, 32, 32);
				temporary.setDestination(V2D((j * 32) + tileMX, (i * 32) + tileMY), 32, 32);
				temporary.setID(current);
				temporary.makeSolid(true);
				tileMap.push_back(temporary);
			}
		}
	}
	mapFile.close();
}

void Tilemap::drawTM(SDL_Renderer* renderer)
{
	for (int i = 0; i < tileMap.size(); i++)
	{
		if (tileMap[i].getDestinationX() >= 0 - 32 && tileMap[i].getDestinationY() >= 0 - 32 && tileMap[i].getDestinationX() <= 0 + 640 + 32 && tileMap[i].getDestinationY() <= 0 + 480 + 32)
		{
			drawTiles(tileMap[i], renderer);
		}
	}
}

void Tilemap::drawTiles(Obj obj, SDL_Renderer* renderer)
{
	SDL_Rect destination = obj.getDestination();
	SDL_Rect source = obj.getSource();
	SDL_RenderCopyEx(renderer, obj.getTexture(), &source, &destination, 0, NULL, SDL_FLIP_NONE);
}
