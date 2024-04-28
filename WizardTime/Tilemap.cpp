#include "Tilemap.h"

void Tilemap::loadMap(const char* filename, SDL_Renderer* renderer)
{
	if (!map.empty())
	{
		map.clear();
	}
	Obj temporary{};
	int current, mapX, mapY, mapW, mapH;
	ifstream file(filename);
	if (!file.is_open())
	{
		cout << "Cant find file\n";
		return;
	}

	file >> mapX;
	file >> mapY;
	file >> mapW;
	file >> mapH;

	for (int i = 0; i < mapH; i++)
	{
		for (int j = 0; j < mapW; j++)
		{
			if (file.eof())
			{
				return;
			}
			file >> current;
			if (current != 0)
			{
				temporary.setImage("assets/Tile_Brick_1.png", renderer);
				temporary.setSource((current - 1) * 32, 0, 32, 32);
				map.push_back(temporary);
			}
		}
	}
	file.close();
}

void Tilemap::drawMap(SDL_Renderer* renderer)
{
	for (int i = 0; i < map.size(); i++)
	{
		if (map[i].getDestinationX() >= 0 - 32 && map[i].getDestinationY() >= 0 - 32 && map[i].getDestinationX() <= 0 + 640 + 32 && map[i].getDestinationY() <= 0 + 480 + 32)
		{
			drawTiles(map[i], renderer);
		}
	}

}

void Tilemap::drawTiles(Obj o, SDL_Renderer* ren)
{
	SDL_Rect dest = o.getDestination();
	SDL_Rect src = o.getSource();
	SDL_RenderCopyEx(ren, o.getTexture(), &src, &dest, 0, NULL, SDL_FLIP_NONE);
}