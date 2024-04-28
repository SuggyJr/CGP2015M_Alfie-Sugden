#ifndef TILEMAP_H
#define TILEMAP_H

#include "Obj.h"

class Tilemap : public Obj
{
public:
    void loadMap(const char* filename, SDL_Renderer* renderer);
    void drawMap(SDL_Renderer* renderer);
    void drawTiles(Obj o, SDL_Renderer* renderer);
    int getDestinationX() const { return destination.x; }
    int getDestinationY() const { return destination.y; }
    vector<Obj> map;

private:
    SDL_Rect destination{};
};

#endif // !TILEMAP_H
