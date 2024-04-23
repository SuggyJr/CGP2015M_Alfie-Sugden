#include "Tilemap.h"
#include "Game.h"

Tilemap::Tilemap(SDL_Renderer* renderer) : mapRenderer(renderer), tileSize(32), mapWidth(0), mapHeight(0)
{
	tileTextures.resize(256, nullptr);
}

Tilemap::~Tilemap()
{
	for (auto& texture : tileTextures)
	{
		if (texture != nullptr)
		{
			SDL_DestroyTexture(texture);
		}
	}
}

void Tilemap::loadMap(const char* mapFile)
{
	ifstream file(mapFile);
	if (!file.is_open())
	{
		cerr << "Failed to open the map file: " << mapFile << "\n";
		return;
	}

	file >> mapWidth >> mapHeight;

	mapTilemap.resize(mapHeight, vector <int>(mapWidth, 0));

	for (int y = 0; y < mapHeight; y++)
	{
		for (int x = 0; x < mapWidth; x++)
		{
			int tileIndex = mapTilemap[x][y];
		}
	}

	file.close();
}

void Tilemap::render() 
{
    for (int y = 0; y < mapHeight; ++y) 
    {
        for (int x = 0; x < mapWidth; ++x) 
        {
            int tileIndex = mapTilemap[y][x];

            if (tileTextures[tileIndex] == nullptr) 
            {
                string filePath = "assets/Tile_Brick1" + to_string(tileIndex) + ".png";
                SDL_Surface* surface = IMG_Load(filePath.c_str());
                if (surface == nullptr)
                {
                    cerr << "Failed to load texture: " << filePath << "\n";
                    continue;
                }
                tileTextures[tileIndex] = SDL_CreateTextureFromSurface(mapRenderer, surface);
                SDL_FreeSurface(surface);
                if (tileTextures[tileIndex] == nullptr) 
                {
                    cerr << "Failed to create texture from surface: " << SDL_GetError() << "\n";
                    continue;
                }
            }

            SDL_Rect destRect = { x * tileSize, y * tileSize, tileSize, tileSize };

            SDL_RenderCopy(mapRenderer, tileTextures[tileIndex], nullptr, &destRect);
        }
    }
}