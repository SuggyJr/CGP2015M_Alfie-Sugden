#include "Entity.h"

void Entity::entityUpdate(Tilemap* tilemap)
{
	updateAnim();
	bool collidingFloor = false;
	bool collidingRoof = false;
	bool collidingLeft = false;
	bool collidingRight = false;

	for (int i = 0; i < tilemap->tileMap.size(); i++)
	{
		if (onColl(collisionFloor, tilemap->tileMap[i]))
		{
			collidingFloor = true;
		}

		if (onColl(collisionRoof, tilemap->tileMap[i]))
		{
			collidingRoof = true;
		}

		if (onColl(collisionLeft, tilemap->tileMap[i]))
		{
			collidingLeft = true;
		}

		if (onColl(collisionRight, tilemap->tileMap[i]))
		{
			collidingRight = true;
		}
	};

	this->setDestination(V2D(getDestinationX() + velocity.x, getDestinationY() + velocity.y));
	pos.x = this->destination.x;
	pos.y = this->destination.y;

	collisionFloor->setDestination(V2D(destination.x + 11, destination.y + 32), 11, 5);
	collisionRoof->setDestination(V2D(destination.x + 11, destination.y - 5), 11, 5);
	collisionLeft->setDestination(V2D(destination.x - 5, destination.y + 11), 5, 11);
	collisionRight->setDestination(V2D(destination.x + 32, destination.y + 11), 5, 11);

	update();
}

bool Entity::onColl(Obj* a, Obj b)
{
	if ((a->getDestinationX() < (b.getDestinationX() + b.getDestinationW())) && ((a->getDestinationX() + a->getDestinationW()) > b.getDestinationX()) && (a->getDestinationY() < (b.getDestinationY() + b.getDestinationH())) && ((a->getDestinationY() + a->getDestinationH()) > b.getDestinationY()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Entity::entityRender(bool b, SDL_Renderer* renderer)
{
	if (b)
	{
		collisionFloor->setBlock(255, 255, 0, 255, renderer);
		collisionRoof->setBlock(255, 255, 0, 255, renderer);
		collisionLeft->setBlock(255, 255, 0, 255, renderer);
		collisionRight->setBlock(255, 255, 0, 255, renderer);
	}
	//renderer(renderer);
}

SDL_Rect Entity::EntityBox(SDL_Renderer* renderer, int x, int y, SDL_Rect rect)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_Rect CollisionDestination = { destination.x + x, destination.y + y, 5, 5 };
	SDL_RenderFillRect(renderer, &CollisionDestination);

	return rect = CollisionDestination;
}
