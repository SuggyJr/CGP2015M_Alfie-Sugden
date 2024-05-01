#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "Obj.h"
#include "V2D.h"
#include "Tilemap.h"

class Entity : public Obj
{
public:
	void entityUpdate(Tilemap* tilemap);
	bool onColl(Obj* a, Obj b);
	void entityRender(bool b, SDL_Renderer* renderer);

	SDL_Rect updateEntityBox(SDL_Rect rect) { return rect; }
	SDL_Rect EntityBox(SDL_Renderer* renderer, int x, int y, SDL_Rect rect);

	bool isCollidingFloor() const { return isCollidingFloor; }
	bool isCollidingRoof() const { return isCollidingRoof; }
	bool isCollidingLeft() const { return isCollidingLeft; }
	bool isCollidingRight() const { return isCollidingRight; }

	Obj* collisionFloor = new Obj;
	Obj* collisionRoof = new Obj;
	Obj* collisionLeft = new Obj;
	Obj* collisionRight = new Obj;

private:
	V2D vector;

	bool collidingFloor = false;
	bool collidingRoof = false;
	bool collidingLeft = false;
	bool collidingRight = false;
};

#endif // !ENTITY_H
